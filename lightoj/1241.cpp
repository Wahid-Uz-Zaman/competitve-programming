#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[15];
int main()
{
    int t;
    scanf("%d ",&t);
    for(int i=1;i<=t;i++)
    {
        int n,ans=0,j;
        memset(a,0,sizeof(a));
        scanf("%d",&n);
        for(j=0;j<n;j++) scanf("%d",&a[j]);
        for( j=0;j<n-1;j++)
        {
            if(a[j+1]>a[j])
            {
                int x=a[j+1]-a[j];
                if(x%5==0)ans+=(x/5);
                else ans+=((x/5)+1);
            }
        }
        if(a[0]>2)
        {
            int x=a[0]-2;
                if(x%5==0)ans+=(x/5);
                else ans+=((x/5)+1);
        }


        printf("Case %d: %d\n",i,ans);
    }
    return 0;
}
