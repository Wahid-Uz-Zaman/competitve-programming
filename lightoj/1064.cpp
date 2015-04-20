#include<cstdio>
#include<cstring>
#define mx 155
#define ll long long int
using namespace std;
ll gcd(ll a,ll b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        ll n,x;
        scanf("%lld %lld",&n,&x);
        ll dp[n*6+1][n+1];
        for(int i=1;i<=n;i++) dp[0][i]=0;
        for(int i=1;i<=n*6;i++)dp[i][0]=0;
        dp[0][0]=1;
        for(int i=1;i<=n*6;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dp[i][j]=0;//dp[i][j-1];
                for(int k=1;k<=6;k++)
                {
                    if(i>=k) dp[i][j]+=dp[i-k][j-1];
                }
            }
        }
        ll tot=0,ans=0;
        for(int i=n;i<=n*6;i++)
        {
            tot+=dp[i][n];
            if(i>=x) ans+=dp[i][n];
        }
        //printf("%lld\n",tot);
        ll g=gcd(tot,ans);
        printf("Case %d: %lld",cas,ans/g);
        if(tot/g!=1)printf("/%lld",tot/g);
        printf("\n");


    }
    return 0;
}
