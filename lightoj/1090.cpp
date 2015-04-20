# include <stdio.h>
# include<math.h>
int a[2];
int b[2];


int pw(int n,int i)
{
    int j,ans=1;
    for(j=1;j<=i;j++) ans*=n;
    return ans;

}

void inpw(int n,int i)
{
    int j,sum=0;
    while(!(n%2))
    {
        a[0]++;
        n/=2;
    }
    while(!(n%5))
    {
        a[1]++;
        n/=5;
    }
    a[0]*=i;
    a[1]*=i;
    return;


}
int high(int n,int p)
{
    int h=(int)(log(n)/log(p));
    int j,ans=0;
    for(j=1;j<=h;j++)
    {
        ans+=(n/pw(p,j));
    }
    return ans;

}

int main(void)
{
    int i,t,n,p,r,q;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        int m,k,l;
        a[0]=a[1]=b[0]=b[1]=0;

        scanf("%d %d %d %d",&n,&r,&p,&q);
        m=high(n,2);
        k=high(r,2);
        l=high(n-r,2);
        b[0]=m-k-l;
        m=high(n,5);
        k=high(r,5);
        l=high(n-r,5);
        b[1]=m-k-l;
        inpw(p,q);
        a[0]+=b[0];
        a[1]+=b[1];
        if(a[0]>a[1]){

        printf("Case %d: %d\n",i,a[1]);}
        else printf("Case %d: %d\n",i,a[0]);


    }
    return 0;
}
