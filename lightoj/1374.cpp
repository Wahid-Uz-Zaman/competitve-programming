#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int b[10006];
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int n,a[10006],j;
        memset(b,0,sizeof(b));
        scanf("%d",&n);
        for(j=0;j<n;j++) scanf("%d",&a[j]);
        for( j=0;j<n;j++)
        {
            if(a[j]>=n) break;
            if(b[a[j]]==0) b[a[j]]=1;
            else if(b[n-1-a[j]]==0) b[n-1-a[j]]=1;
            else break;
        }
        if(j==n) printf("Case %d: yes\n",i);
        else printf("Case %d: no\n",i);

    }
    return 0;
}
