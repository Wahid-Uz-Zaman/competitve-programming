#include<cstdio>
#include<algorithm>
#include<cstring>
#define  mx 31
# define ll unsigned long long
using namespace std;
ll dp[mx][mx];
void make()
{
    for(int i=0;i<mx;i++) dp[i][0]=1;
    for(int i=0;i<mx;i++) dp[i][i]=1;

    for(int i=2;i<mx;i++)
    {
        for(int j=1;j<i;j++) dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
    }
}
int main()
{
    make();
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        ll n,k;
        scanf("%llu %llu",&n,&k);
        if(k>n) {printf("Case %d: 0\n",cas);continue;}
        ll ans=dp[n][k];
        ll npr=1;
        ll x=(ll)n;
        for(int j=1;j<=k;j++) npr*=x,x--;
        ans*=npr;
        printf("Case %d: %llu\n",cas,ans);

    }

    return 0;
}
