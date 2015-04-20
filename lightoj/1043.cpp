#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        double ab,ac,bc,x,ans;
        scanf("%lf %lf %lf %lf",&ab,&ac,&bc,&x);
        ans=sqrt(x/(1+x))*ab;
        printf("Case %d: %.8lf\n",i,ans);
    }
    return 0;
}
