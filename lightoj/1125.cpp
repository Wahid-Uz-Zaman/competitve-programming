#include<bits/stdc++.h>
#define mx 201
#define pb push_back
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        int n,q,x;
        scanf("%d %d",&n,&q);
        vector<int>a;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            a.pb(x);
        }

            printf("Case %d:\n",cas);
        for(int i=1;i<=q;i++)
        {

            int d,m;
            scanf("%d %d",&d,&m);
            long long dp[203][12][21];
            memset(dp,0,sizeof dp);
            for(int i=0;i<=n;i++)dp[i][0][0]=1;
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=m;j++)
                {
                    for(int k=0;k<d;k++)
                    {
                        dp[i][j][k]+=dp[i-1][j][k];
                        for(int p=0;p<d;p++)
                        {
                            int x=p;
                            x=(x+a[i-1])%d;
                            x=(x+d)%d;
                            if(k==x)dp[i][j][k]+=dp[i-1][j-1][p];
                        }
                         //printf("%d %d %d %lld\n",i,j,k,dp[i][j][k]);

                    }

                }
            }

            //
            printf("%lld\n",dp[n][m][0]);

        }

    }

    return 0;

}
