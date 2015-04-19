
#include<cstdio>

#include<cmath>
#define pi acos(-1.0)
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        double R,n;
        scanf("%lf %lf",&R,&n);
        double x=sqrt(2/(1-(cos(2*pi/n))))+1;
        printf("Case %d: %.9lf\n",i,R/x);


    }
    return 0;
}
