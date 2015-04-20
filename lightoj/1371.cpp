#include<bits/stdc++.h>
#define ll long long
#define mx 1005
#define mod 1000000007
using namespace std;
int bamboo[mx];
int panda[mx];
bool myfunction (int i,int j) { return (i>j); }
int main()
{
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d",&bamboo[i]);
        sort(bamboo,bamboo+n,myfunction);

        for(int i=0;i<n;i++)scanf("%d",&panda[i]);
        sort(panda,panda+n,myfunction);
        ll ans=1;
        ll sum=0;
        int j=0;
        for(int i=0;i<n;i++)
        {

            while(j<n)
            {
                if(panda[j]>=bamboo[i]){sum++;j++;}
                else break;
            }
            int s=sum-i;
            if(s<1){ans=0;break;}
            else ans=(ans*s)%mod;

        }

        printf("Case %d: %lld\n",cas,ans);
    }
}
