#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int a[50005],n;
            int m,p,w,ans=0;
            scanf("%d %d",&n,&w);
            for(int j=0;j<n;j++)
            {
                scanf("%d %d",&m,&p);
                a[j]=p;
            }
            sort(a,a+n);
            int max=a[0]+w;
            ans=1;
            for(int j=0;j<n;j++)
            {

                if(a[j]>max)
                {
                    max=a[j]+w;
                    ans++;
                }

            }

            printf("Case %d: %d\n",i,ans);


        }
        return 0;

}
