#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define mx 110
using namespace std;
int dp[mx][mx];
//int l[mx][mx];
int pos[mx];
int cnt[mx];
vector<int>a;
int main()
{

    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        //for(int i=0;i<mx;i++)
        //for(int j=0;j<mx;j++) l[i][j]=;
        int n,w,p;
        a.clear();
        scanf("%d%d%d",&n,&w,&p);

        for(int i=0;i<n;i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            a.push_back(y);
        }
        sort(a.begin(),a.end());
        pos[0]=a[0];
        cnt[0]=1;
        int m=0;
        for(int i=1;i<n;i++)
        {
            if(pos[m]==a[i])
            {
                cnt[m]++;
            }
            else
            {
                m++;
                pos[m]=a[i];
                cnt[m]=1;
            }
        }

        for(int i=0;i<=m;i++)
        {
            for(int j=i+1;j<=m;j++)
            {
                if(pos[j]>pos[i]+w)break;
                else cnt[i]+=cnt[j];
            }
        }
        //dp[i][j] means jth jump at i node
        //for(int i=0;i<=m;i++) printf("%d %d\n",pos[i],cnt[i]);
        for(int i=0;i<=m;i++)
        {
            dp[i][1]=cnt[i];
            for(int j=2;j<=p;j++)
            {
                int s=0;
                for(int k=0;k<i;k++)
                {
                    if(pos[i]>pos[k]+w && dp[k][j-1]+cnt[i]>s)s=dp[k][j-1]+cnt[i];


                }
                dp[i][j]=s;
            }
        }
        int ans=-1;
        for(int i=0;i<=m;i++)
        {
            for(int j=1;j<=p;j++)
             {//printf("%d %d %d\n",i,j,dp[i][j]);
             if(ans<dp[i][j]) ans=dp[i][j];}
        }
        printf("Case %d: %d\n",cas,ans);
        memset(dp,0,sizeof dp);




    }

    return 0;
}
