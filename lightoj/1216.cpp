#include<cstdio>
#include<cmath>
#define pi acos(-1.)
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        double r1,r2,h,p,x,r3,ans;
        scanf("%lf %lf %lf %lf",&r2,&r1,&h,&p);
        x=h*r1/(r2-r1);
        //printf("%lf\n",x);
        r3=((p+x)/(x+h))*r2;
        //printf("%lf\n",r3);
        ans=(1./3)*pi*(r3*r3*(p+x)-r1*r1*x);
        printf("Case %d: %.10lf\n",i,ans);
    }
    return 0;

}
