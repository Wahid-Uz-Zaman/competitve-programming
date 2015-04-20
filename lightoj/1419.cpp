#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define LL long long
#define i64 long long
#define MOD 1000000007

long long divisors[100] , remainders [100], tot;

//extended gcd


void gcdd(LL a,LL b,LL &d,LL &x,LL &y)//ax+by=d=gcd(a,b)
{

    if(!b){d=a;x=1;y=0;}
    else{gcdd(b,a%b,d,y,x);y-=x*(a/b);}
}

i64 gcd (i64 a, i64 b, i64 &x, i64 &y) {//eta invrse mod e deya jay na , karon -ve x dei she
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	i64 x1, y1;
	i64 d = gcd (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

//amar mod function
ll mod_pow (ll b , ll e, ll m)//b^e % m, m is prime
{
    if (e==0)   return 1;
    ll ret=  mod_pow ( b ,  e/2,  m);
    if (e&1)
    {

            ret = (ret * ret)% m;
            ret = (ret*b ) %m;
            return ret;
    }
    else {
            ret = (ret * ret)% m;

            return ret;

    }
}


ll inverse_mod (ll a, ll m )//ax % m=1
{
    ll x,y,d;
    //d=gcd(a,m,x,y);
    d=gcd(a,m,x,y);
    //cout<<"dekhi a x m y d a*x+m*y "<< a<<" "<<x<<" "<<m<<" "<<y<<" "<<d<<" "<<a*x+m*y<<" tai? 1?\n";
    if (d==1)   return x%m;
    else return 0;
}

ll inverse_modd (ll a, ll m )//ax % m=1
{
    mod_pow (a, m-2, m);
}


ll burnside(ll n, ll k)
{
    ll sum=0, i, d,x,y;
    for (i=1; i<=n; i++)
    {
        //d=gcd(n,i, x,y);
        d=gcd(n,i, x,y);
        //cout<<i<<" " <<k<<" i k d "<<d<<" "<<mod_pow( k, d, MOD)<<endl;
        sum= ( sum+ mod_pow( k, d, MOD) )%MOD;
    }
    //cout<<sum<<" ager sum \n";
    //cout<<inverse_mod (n, MOD)<<" agr invrse mod  \n";
    sum= sum * inverse_mod (n, MOD);
    sum%=MOD;
    //cout<<sum<<" =sum before ret sum is \n";
    //cout<<(sum+MOD) %MOD<<" =RETUREND \n";
    return (sum+MOD) %MOD;
}

int main()
{

    //freopen("in2.txt","r",stdin);
    ll cs,csno=1,tot,N, K,i,ans;
    //cout<<(10 * inverse_mod (10, MOD) ) % MOD<<endl;
    //cout<< inverse_mod (10, MOD) ;while(1);
    cin>>tot;
    for (i=1; i<=tot; i++)
    {
        scanf("%lld%lld", &N, &K);
        ans=burnside(N,K);
        printf("Case %lld: %lld\n",csno++, ans);
    }
    return 0;
}
