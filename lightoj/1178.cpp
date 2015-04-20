#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        double a,b,c,d,x,te,ans;
        scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
        te=a-c;
        x=(te*te-d*d+b*b)/(2*te);
        ans=.5*(a+c)*sqrt(b*b-x*x);
        printf("Case %d: %.10lf\n",i,ans);
    }
    return 0;
}
