#include<math.h>
# include<stdio.h>
# include<time.h>
#define llu unsigned long long



int  make(int a[],llu n)
{
    int i=0;
    while(n/10)
    {
        a[i]= n%10;
        n/=10;
        i++;
    }
    a[i]=n%10;
    return i;
}
void print(int b[])
{
    printf(" ");
    int j;
    for(j=20;j>=0;j--)
    {
        if(b[j]!=0) break;
    }
    for(;j>=0;j--) printf("%d",b[j]);

}

int main()

{
    int t,i;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        int a[21]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

        llu n,k;
        scanf("%llu",&n);
        if(n%10==0 && n%9==0 ){
        k=make(a,n);
        printf("Case %d:",i);

        int c,p=0;
        for(c=9;c>=0;c--)
        {
            int b[21]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
            b[1]=c;
            int carry=( b[1]+ a[0])/10;
            int j=1,m;
            while(j<=k+2)
            {
                m=a[j]+carry;
                if(m>b[j]) carry=1;
                else carry=0;
                b[j+1]=(b[j]-m)%10;
                if(b[j+1]<0) b[j+1]= 10 +b[j+1];
                j++;
            }
            b[0]=(a[0]+b[1])%10;
            if(b[j]==0) print(b);

        }
        }
        else{
         k=make(a,n);
        printf("Case %d:",i);

        int c,p=0;
        for(c=0;c<=9;c++)
        {
            int b[21]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
            b[1]=c;
            int carry=( b[1]+ a[0])/10;
            int j=1,m;
            while(j<=k+2)
            {
                m=a[j]+carry;
                if(m>b[j]) carry=1;
                else carry=0;
                b[j+1]=(b[j]-m)%10;
                if(b[j+1]<0) b[j+1]= 10 +b[j+1];
                j++;
            }
            b[0]=(a[0]+b[1])%10;
            if(b[j]==0) print(b);

        }
        }
         printf("\n");
    }
        return 0;
}


