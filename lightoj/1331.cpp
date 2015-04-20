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
        double r1,r2,r3;
        scanf("%lf %lf %lf",&r1,&r2,&r3);
        double a,b,c;
        a=r1+r2;
        b=r2+r3;
        c=r1+r3;
        double A,B,C;
        A=acos((b*b+c*c-a*a)/(2*b*c));
        B=acos((a*a+c*c-b*b)/(2*a*c));
        C=acos((a*a+b*b-c*c)/(2*a*b));
        double ans;
        ans=a*b*sin(C)-(r2*r2*C+r1*r1*B+r3*r3*A);
        printf("Case %d: %.10lf\n",i,.5*ans);
    }
    return 0;
}
