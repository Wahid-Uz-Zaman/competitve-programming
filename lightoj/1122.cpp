#include<bits/stdc++.h>
using namespace std;
int dp[15][15];
int a[15];
int main()
{
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        int n,m;
        scanf("%d %d",&m,&n);
        for(int i=0;i<m;i++)scanf("%d",&a[i]);
        memset(dp,0,sizeof dp);
        //for(int i=0;i<15;i++)for(int j=0;j<15;j++)printf("%d ",dp[i][j]);
        for(int i=0;i<m;i++)dp[0][a[i]]=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(dp[i-1][a[j]]!=0)
                {
                    for(int k=0;k<m;k++)
                    {
                        int x=a[k]-a[j];
                        if(abs(x)<=2)
                        {
                            dp[i][a[k]]+=dp[i-1][a[j]];
                            //printf("%d %d %d %d %d %d\n",i,a[k],i-1,a[j],dp[i][a[k]],dp[i-1][a[j]]);
                        }
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<m;i++)
        {
            //printf("%d ",dp[n-1][a[i]]);
            ans+=dp[n-1][a[i]];
        }
        printf("Case %d: %d\n",cas,ans);


    }

    return 0;
}
