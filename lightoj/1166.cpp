#include<cstdio>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int a[105];
        int n,ans=0;
        scanf("%d",&n);
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&a[j]);
        }
        for(int j=1;j<=n-1;j++)
        {
            if(j==a[j]) continue;
            else{
                for(int k=j+1;k<=n;k++)
                {
                    if(j==a[k])
                    {
                        int temp=a[j];
                        a[j]=j;
                        a[k]=temp;
                        ans++;
                        break;
                    }
                }
            }
        }
        printf("Case %d: %d\n",i,ans);




    }
    return 0;
}
