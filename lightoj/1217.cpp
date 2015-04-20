#include<cstdio>
#include<cstring>
#include<algorithm>
#define mx 1005
using namespace std;
int a[mx];
int dp[mx];
int main()
{
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        int n;
        scanf("%d",&n);
        for(int j=1;j<=n;j++) scanf("%d",&a[j]);
        dp[1]=a[1];
        dp[0]=0;
        int ans=dp[1];
        for(int i=2;i<=n-1;i++) dp[i]=max(dp[i-1],dp[i-2]+a[i]);
        for(int i=2;i<=n-1;i++) ans=max(ans,dp[i]);
        dp[2]=a[2];
        dp[3]=max(a[2],a[3]);
        for(int i=4;i<=n;i++) dp[i]=max(dp[i-1],dp[i-2]+a[i]);
        for(int i=2;i<=n;i++) ans=max(ans,dp[i]);


        printf("Case %d: %d\n",cas,ans);
    }
    return 0;
}
