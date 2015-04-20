#include <cstdio>
#include <cstring>
#include <algorithm>
#define max 100010
#define mn(a,b) a<b?a:b
#define mx(a,b) a>b?a:b
#define ll long long int
using namespace std;

ll M[4*max],valadd[4*max];

ll query(int  start,int end,int  low,int  high,int  node)
{
     if(low>end || start>high) return 0;
     if(start>=low && end<=high) return M[node];
     ll ans=mn(end,high);
     ans-= mx(start,low);
     ans++;
     ans*=valadd[node];

     //printf("%lld %lld %lld %lld\n",valadd[node],min(end,high),mx(start,low),ans);
     int  mid=(start+end)>>1;
     return ans+query(start,mid,low,high,2*node)+query(mid+1,end,low,high,2*node+1);
}

ll update(int  start,int end,int low,int high,int  node,int value)
{
    //printf("%lld %lld %lld\n",start,end,low);
    if(low>end || start>high) return 0;
    if(start>=low && end<=high)
    {
        ll change=(end-start+1)*value;
        M[node]+=change;
        valadd[node]+=value;
        return change;
    }
    int  mid=(start+end)/2;
    ll x=update(start,mid,low,high,2*node,value);
    ll y=update(mid+1,end,low,high,2*node+1,value);
    M[node]+=(x+y);
    return (x+y);
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int N,p,q,v;
    int op,C,TC;

    scanf("%d",&TC);
    int j=1;
    //printf("fg");
    while(TC--){
        scanf("%d %d",&N,&C);

        memset(M,0,sizeof M);
        memset(valadd,0,sizeof valadd);
        printf("Case %d:\n",j);
        j++;

        for(int i = 0;i < C;++i){
            scanf("%d",&op);

            if(op == 0){
                scanf("%d %d %d",&p,&q,&v);
               // printf("C");
                ll x=update(0,N-1,p,q,1,v);
                //printf("%d\n",x);
            }else{
                scanf("%d %d",&p,&q);

                printf("%lld\n",query(0,N-1,p,q,1));
            }
        }
    }

    return 0;
}
