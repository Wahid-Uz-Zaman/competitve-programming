//bitmask dp

#include<cstdio>
#include<cstring>
#include<algorithm>
#define mx 16
using namespace std;
int a[mx][mx];
int dp[(1<<mx)+5];

//boolean method
bool check(int n,int i)
{
    return n & (1<<i);
}
int set(int n,int i)
{
    return n | ( 1<<i);
}
int count_set(int num,int n)
{
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(num & 1<<i) ans++;
    }
    return ans;
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
 base:  for(int i=0;i<n;i++) dp[1<<i]=a[0][i];
 int s=(1<<n);
        for(int m=1;m<s;m++)
        {
            int j=count_set(m,n);
            for(int i=0;i<n;i++)
            {
                if(check(m,i)==0)
                {
                    if(dp[set(m,i)]==-1)dp[set(m,i)]=dp[m]+a[j][i];
                    else dp[set(m,i)]=max(dp[set(m,i)],dp[m]+a[j][i]);

                }

            }

        }
        printf("Case %d: %d\n",cas,dp[(1<<n)-1]);

    }




    return 0;

}
