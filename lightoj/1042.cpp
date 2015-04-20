#include<cstdio>
using namespace std;
int num(int a[],int s,int k)
{
    int ans=0,c=0;
    for(int j=k-1;j>=0;j--)
    {
        if(a[j]==1) c++;
    }
    for(int i=k;i<s;i++)
    {
        int b=a[i]<<i;
        ans=ans+b;

    }
    return ans +((1<<c)-1);
}
int make(int a[],int n)
{
    int j;
    for(j=0;n!=0;j++)
    {
        a[j]=n%2;
        n=n/2;
    }
    //for(int i=j-1;i>=0;i--) printf("%d", a[i]);
    int s=j,c=0;
    for(int i=0;i<s;i++)
    {
        if(a[i]==1 && (i+1)<s)
        {
            if(a[i+1]==0){
            a[i]=0;
            a[i+1]=1;
            return num(a,s,i);}
        }
    }
    for(int i=s-1;i>=0;i--)
    {
        if(a[i]==1) c++;
        else break;
    }
    if((c-1)==0) return (1<<s);
    else return (1<<s) + ((1<<(c-1)) -1);
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int n;
        scanf("%d",&n);
        int a[32];
        printf("Case %d: %d\n",i,make(a,n));

    }
    return 0;
}
