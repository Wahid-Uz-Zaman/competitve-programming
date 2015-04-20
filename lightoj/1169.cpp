#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define mx 1005
using namespace std;

int dp[mx][2];
int a[mx][2];
int n;
int jump[mx][2];
int main()
{
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i][0]);

        for(int i=1;i<=n;i++) scanf("%d",&a[i][1]);

        for(int i=1;i<n;i++) scanf("%d",&jump[i][0]);

        for(int i=1;i<n;i++) scanf("%d",&jump[i][1]);

        //dp

        dp[1][1]=a[1][1],dp[1][0]=a[1][0];
        for(int i=2;i<=n;i++)
        {
            dp[i][0]=a[i][0]+min(dp[i-1][0],dp[i-1][1]+jump[i-1][1]);
             dp[i][1]=a[i][1]+min(dp[i-1][1],dp[i-1][0]+jump[i-1][0]);
        }
        int ans=min(dp[n][0],dp[n][1]);
        printf("Case %d: %d\n",cas,ans);
        memset(dp,0,sizeof dp);

    }
    return 0;
}
