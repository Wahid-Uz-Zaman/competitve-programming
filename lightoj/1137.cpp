#include<cstdio>
#include<cmath>
#define pi acos(-1.0)
using namespace std;
int main()
{
    int t;scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        double L,n,c,temp;
        scanf("%lf %lf %lf",&L,&n,&c);
        if(n==0.0) printf("Case %d: 0\n",i);
        else{
            temp=(1+n*c)*L/2.0;
            double low=0,high=pi/2.0,mid;
            while(high-low>=10e-14)
            {
                mid=(low+high)/2.0;
                if((L*mid/(2*sin(mid)))>temp)
                {
                    high=mid-10e-14;
                }
                else low=mid+10e-14;
            }
            double ans;
            ans=(L/(2*sin(mid)))*(1-(cos(mid)));
            printf("Case %d: %.10lf\n",i,ans);
        }
    }
    return 0;
}
