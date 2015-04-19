#include<cstdio>
#include<cmath>

using namespace std;
int main()
{
    int t;

    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        double x1,y1,r1,x2,y2,r2,ans=0.0,theta;
        scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&r1,&x2,&y2,&r2);
        double x=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);

        theta=acos((r2*r2 +x- r1*r1)/(2*r2*sqrt(x)));
        printf("%lf\n",theta);
        printf("Case %d: %.10lf\n",i,.5*r2*r2*( 2*theta-sin(2*theta)));
    }
    return 0;
}
