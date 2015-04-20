#include<cstdio>
#include<cstring>
#define mx 100
#define mod 100000007
#define ll long long
using namespace std;
int dp[51][2500];
int v[51];
int c[51];
int main()
{
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {

        int n,x;

        scanf("%d %d",&n,&x);
        for(int i=1;i<=n;i++) scanf("%d",&v[i]);
        for(int i=1;i<=n;i++) scanf("%d",&c[i]);
        for(int i=0;i<=x;i++) dp[0][i]=0;
        for(int i=1;i<=n;i++) dp[i][0]=1;
        dp[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=x;j++)
            {
                dp[i][j]=0;
                for(int k=0;k<=c[i];k++)
                {
                    if(j-k*v[i]>=0)
                    dp[i][j]=(dp[i][j]+dp[i-1][j-k*v[i]])%mod;
                }
            }
        }
        printf("Case %d: %d\n",cas,dp[n][x]);

    }
    return 0;
}
