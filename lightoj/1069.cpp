#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
    int t;
    scanf("%d ",&t);
    for(int i=1;i<=t;i++)
    {
        int n,l;
        scanf("%d %d",&n,&l);
        int ans=n-l;
        if(ans<0) ans=-ans;
        ans=ans*4+(n*4)+19;
        printf("Case %d: %d\n",i,ans);
    }
    return 0;
}
