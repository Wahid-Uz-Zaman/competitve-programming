#include<bits/stdc++.h>
#define mx 114

using namespace std;
int a[mx];
int dp[mx][mx][mx];
int main()
{
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        int n;
        scanf("%d",&n);
        a[0]=0,a[1]=INT_MAX;
        for(int i=2;i<=n+1;i++)scanf("%d",&a[i]);
        //for(int i=0;i<n;i++)dp[i][i]=1;
        memset(dp,-1,sizeof dp);
        //for(int i=2;i<=n+1;i++){
        dp[0][0][1]=0;
        dp[1][0][1]=0;
        dp[2][2][1]=1;
        dp[2][0][2]=1;
        int ans=1;
        for(int i=2;i<=n+1;i++)
        {
            for(int j=0;j<i;j++)
            {

                for(int k=0;k<=n+1;k++)
                {
                    if(j!=k && i!=j && i!=k && a[i]>=a[j] && a[i]<=a[k])
                    {
                        int x=max(dp[j][j][k],dp[k][j][k]);
                        //printf("%d %d %d\n",i,j,k);
                        if(x!=-1){
                        dp[i][i][k]=max(dp[i][i][k],x+1);
                        //printf("i i k %d %d %d %d\n",i,i,k,dp[i][i][k]);
                        ans=max(ans,dp[i][i][k]);
                        dp[i][j][i]=max(dp[i][j][i],x+1);

                        //printf("i j i %d %d %d %d\n",i,j,i,dp[i][j][i]);
                        ans=max(ans,dp[i][j][i]);

                        //printf("%d %d %d %d %d %d\n",i,j,k,dp[i][i][k],dp[i][j][i],dp[j][j][k]);
                        }
                    }
                }
            }
        }
       // printf("%d\n",dp[5][2][3]);
        printf("Case %d: %d\n",cas,ans);


    }
    return 0;
}
