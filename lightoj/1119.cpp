#include<cstdio>
#include<cstring>
#include<algorithm>
#define mx 16
using namespace std;
int a[mx][mx];
int dp[1<<14+5];

//boolean method
bool check(int n,int i)
{
    return n & (1<<i);
}
int set(int n,int i)
{
    return n | ( 1<<i);
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++) scanf("%d",&a[i][j]);
        }
        memset(dp,-1,sizeof dp);
 base:  for(int i=0;i<n;i++) dp[1<<i]=a[i][i];
 int s=(1<<n);
        for(int m=1;m<s;m++)
        {
            for(int i=0;i<n;i++)
            {
                if(check(m,i)==0)
                {
                    int ans=a[i][i];
                    for(int j=0;j<n;j++)
                    {
                        if(i!=j && check(m,j)) ans+=a[i][j];
                    }
                    int x=set(m,i);
                    if(dp[x]==-1) dp[x]=dp[m]+ans;
                    else

                    dp[x]=min(dp[x],dp[m]+ans);
                }

            }

        }
        printf("Case %d: %d\n",cas,dp[(1<<n)-1]);

    }




    return 0;

}
