#include<bits/stdc++.h>
#define pb push_back
#define mx 100005
#define ll long long
#define mod 1000000007
using namespace std;
ll a[mx];
ll s[mx];

int main()
{
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        ll k,c;
        int n,i;
        scanf("%lld %lld %d %lld",&k,&c,&n,&a[0]);
        //s[0]=a[0];
        for(int i=1;i<n;i++)a[i]=(k*a[i-1]+c)%1000007 ;
        sort(a,a+n);
        s[0]=a[0];
        for(int i=1;i<n;i++)s[i]=s[i-1]+a[i];
        ll ans=0;
        for(int i=1;i<n;i++)
        {
            ans+=(i*a[i]-s[i-1]);
        }
        printf("Case %d: %lld\n",cas,ans);
    }


}
