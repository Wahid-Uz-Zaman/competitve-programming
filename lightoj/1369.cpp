#include<cstdio>
#define max 100505
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        long long int a[max];
        long long int ca[max],sum_ca=0,inisum=0;
        int n,q;
        scanf("%d %d",&n,&q);
        for(int j=0;j<n;j++) scanf("%lld",&a[j]);
        inisum+=((n-1)*a[0]);
        ca[0]=a[0];
        sum_ca=ca[0];
        for(int j=1;j<n;j++)
        {
            inisum+=((n-j-1)*a[j]);
            ca[j]=ca[j-1]+a[j];
            sum_ca+=ca[j];
        }
        inisum=inisum-n*ca[n-1]+sum_ca;
        printf("Case %d:\n",i);
        for(int j=1;j<=q;j++)
        {
            int cas;
            scanf("%d",&cas);
            if(cas==1) printf("%lld\n",inisum);
            else
            {
                long long int index,change;
                scanf("%lld %lld",&index,&change);
                long long int x=change-a[index];
                inisum=inisum +(n-1)*x -2*index*x;
               // printf("%d %d\n",(n-1)*x -2*index*x,inisum);
                a[index]=change;
            }

        }



    }
    return 0;
}
