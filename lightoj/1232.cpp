#include<cstdio>//1 1 5,5 1 1 diff ans for 7
#define mx 10001
#include<algorithm>
#define ll long long
#define mod  100000007
using namespace std;
int dp[101][mx];
//int a[]={1,5,10,25,50};
int main()
{


    int a[101];
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++ )
    {
        int c,n;
        scanf("%d %d",&c,&n);
        for(int j=0;j<c;j++) scanf("%d",&a[j]);
        //sort(a,a+c);
        for(int i=1;i<=n;i++) dp[0][i]=0;
        for(int i=0;i<=c;i++) dp[i][0]=1;
        dp[0][0]=1;

        for(int i=1;i<=c;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(j-a[i-1]>=0)
                {
                    dp[i][j]=(dp[i-1][j]+dp[i][j-a[i-1]])%mod;
                    //printf("%d %d %d\n",i,j,dp[i][j]);
                }
                else dp[i][j]=dp[i-1][j];
            }
        }
        printf("Case %d: %d\n",cas,dp[c][n]);

    }
    return 0;
}
