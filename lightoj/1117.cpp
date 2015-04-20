#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#define ll long long int
using namespace std;
ll Gcd(ll a,ll b)
{
    if(b==0) return a;
    else return Gcd(b,a%b);
}
ll n;
struct num
{
    ll no;
    ll lcm;

    num(ll x,ll tlcm)
    {
        no=x;
        lcm=tlcm;
    }
};
vector<num>num_lcm;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out1.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {

        int m;
        scanf("%lld %d",&n,&m);
        ll a[20];
         vector<int>b;
        for(int j=1;j<=m;j++)
        {
            scanf("%lld",&a[j]);
        }
        //printf("hel0");/*
        for(int j=1;j<=m;j++)
        {
            int k;
            for( k=0;k<b.size();k++)
            {
                if(a[j]==b[k]) break;
            }
            if(k==b.size()) b.push_back(a[j]);
        }
        for(int j=0;j<b.size();j++) a[j]=b[j];
        for(int j=0;j<b.size();j++)
        {
            int v=num_lcm.size();

            for(int k=0;k<v;k++)
            {
                  ll tgcd=Gcd(num_lcm[k].lcm,a[j]);
                  ll  x=(num_lcm[k].lcm/tgcd)*a[j];
                  //printf("%lld %lld %lld %lld\n",a[j],num_lcm[k].totmul,tgcd,x);
                  if(x<=n){

                      //printf("%lld\n",x);
                      num_lcm.push_back(num(num_lcm[k].no+1,x));
                  }
         }
           num_lcm.push_back(num(1,a[j]));
        }
        ll ans=n;
        int v=num_lcm.size();
        //printf("%d\n",v);
        for(int j=0;j<v;j++)
        {
            //printf("%d\n",n/num_lcm[j].lcm);
            if(num_lcm[j].no%2) ans-=(n/num_lcm[j].lcm);
            else ans+=(n/num_lcm[j].lcm);
        }
        printf("Case %d: %lld\n",i,ans);
        num_lcm.clear();
    }
    return 0;
}
