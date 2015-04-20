#include<bits/stdc++.h>
#define mx 100005
#define ll long long int
using namespace std;
int a[mx];
ll mod[mx];
int main()
{
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        memset(mod,0,sizeof mod);
        int n,k;
        scanf("%d %d",&n,&k);
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        int m=0;
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            int x=(m+a[i])%k;
            int lagbe=(x)%k;
            ans+=(mod[lagbe]);
            if(x==0)ans++;
            mod[x]++;
            m=x;
        }
        printf("Case %d: %lld\n",cas,ans);
    }
    return 0;
}
