# include<cstdio>
# include<cmath>
#define ll long long int
# define absl(x) x>0?x:-x
#define min(x,y) x>y?y:x
using namespace std;
ll GCD(ll a,ll b)
{
    if(a%b==0) return b;
    else GCD(b,a%b);
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t; scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        ll x1,x2,y1,y2;
        scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
        ll a,b,ans;
        a=y2-y1;b=x1-x2;
        //printf("%lld %lld\n",a,b);
        if(x1==x2 && y1==y2) printf("Case %d: 1\n",i);
        else if(b==0){
            ans=absl(a);
            printf("Case %d: %lld\n",i,ans+1);
        }
        else if(a==0)
        {
            ans=absl(b);
            printf("Case %d: %lld\n",i,ans+1);
        }
        else {
            ll temp=GCD(a,b);


         ans=absl(temp);
        printf("Case %d: %lld\n",i,ans+1);}

    }
    return 0;
}
