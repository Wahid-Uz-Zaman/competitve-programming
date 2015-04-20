#include<cstdio>
using namespace std;


int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int n;
        double sum=1;
        scanf("%d",&n);
        for(int j=2;j<=n;j++)
        {
            sum+=((n*1.)/(n-j+1));
        }
        printf("Case %d: %.10lf\n",i,sum);
    }
    return 0;
}
