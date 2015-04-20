#include<cstdio>
#define max 10005
using namespace std;
long long int x[max];
long long int y[max];
long long int  GCD(long long int  a,long long int  b)
{
    if(a%b==0) return b;
    else GCD(b,a%b);
}
int main()
{
    //freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int n,j;
        scanf("%d",&n);
        for( j=0;j<n;j++) scanf("%lld %lld",&x[j],&y[j]);
        x[j]=x[0];
        y[j]=y[0];
        long long int sum=0,sum1=0,dou_area;
        for(int j=0;j<n;j++)
        {
            sum+=(x[j]*y[j+1]);
        }

        for(int j=0;j<n;j++) sum1+=(y[j]*x[j+1]);
        dou_area=sum-sum1;
        long long int boundary=0;

        for(j=0;j<n;j++)
        {
            long long int temp=y[j+1]-y[j],ans;
            long long int temp1=x[j]-x[j+1];
            //printf("%lld  %lld ",temp,temp1);
            if(temp==0) {ans=temp1;if(ans<0) ans=-ans;}
            else if(temp1==0) {ans=temp;if(ans<0) ans=-ans;}
            else {ans=GCD(temp,temp1);if(ans<0) ans=-ans;}
            //printf("%d\n ",ans);
            boundary+=(ans+1);
        }
        //printf("\n%d\n ",boundary);

        boundary=boundary-n;

        if(dou_area<0) dou_area=-dou_area;
        //printf("%lld %lld\n",dou_area,boundary);
        printf("Case %d: %lld\n",i,(dou_area+2-boundary)/2);



    }
        return 0;
}
