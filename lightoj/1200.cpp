#include<bits/stdc++.h>
#define mx 10005
using namespace std;
int price[111];
int wei[111];
int dp[mx];
int main()
{
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        int n,w;
        scanf("%d %d",&n,&w);
        int tot=0;
        for(int i=0;i<n;i++)
        {
            int p,c,ww;
            scanf("%d %d %d",&p,&c,&ww);
            tot+=(c*ww);
            price[i]=p;
            wei[i]=ww;

        }
        if(tot<w)
        {

            w=w-tot;
            /////////////
            memset(dp,-1,sizeof dp);
            int ans=-1;
            dp[0]=0;
            for(int k=1;k<=w;k++)
            {
                for(int i=0;i<n;i++)
                {
                    if(k-wei[i]>=0 && dp[k-wei[i]]!=-1)
                    {
                        dp[k]=max(dp[k-wei[i]]+price[i],dp[k]);
                        if(ans<dp[k])ans=dp[k];
                    }
                }
            }


            printf("Case %d: %d\n",cas,ans);
            ////////////
        }
        else if(tot==w)printf("Case %d: 0\n",cas);
        else printf("Case %d: Impossible\n",cas);
    }
    return 0;
}
