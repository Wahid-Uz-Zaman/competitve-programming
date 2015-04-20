#include<cstdio>
#include<cstring>
#include<algorithm>
#define mx 105
using namespace std;
//bool dp[mx*mx][mx];
//double prob[mx*mx][mx];
int makedp(int a[],double p[],int n,double P)
{
    int sum=0;
    for(int i=0;i<n;i++) sum+=a[i];
    //printf("%d\n",sum);
    bool rob[sum+1][n+1];
    double prob[sum+1][n+1];
    for(int i=0;i<=n;i++) {rob[0][i]=1;prob[0][i]=0;}
    for(int i=1;i<=sum;i++) {rob[i][0]=0;prob[i][0]=1;}
    for(int i=1;i<=sum;i++)
    {
        for (int j = 1; j <= n; j++)
        {
            rob[i][j] = rob[i][j-1];
            prob[i][j] = prob[i][j-1];
            if (i >= a[j-1])
            {
                rob[i][j]=rob[i][j] || rob[i-a[j-1]][j-1];
                //if(rob[i-a[j-1]][j-1] && rob[i][j] )
                double x=prob[i-a[j-1]][j-1];
                double y=x+(1-x)*p[j-1];
                //printf("%lf %lf\n",x,y);
                prob[i][j]=min(prob[i][j],y);


            }
       }
    }
    //for(int i=sum;i>=0;i--) printf("%d %lf\n",rob[i][n],prob[i][n]);
    for(int i=sum;i>=0;i--)
        if(rob[i][n] && prob[i][n]<P) return i;


}
int main()
{
    //freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        int n;
        double P;
        scanf("%lf %d",&P,&n);
        int a[mx];
        double p[mx];
        for(int i=0;i<n;i++) scanf("%d %lf",&a[i],&p[i]);
        int ans=makedp(a,p,n,P);
        printf("Case %d: %d\n",cas,ans);
    }
    return 0;
}
