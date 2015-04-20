#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define LL long long

long long divisors[100] , remainders [100], tot;

//extended gcd
void gcd(LL a,LL b,LL &d,LL &x,LL &y)//ax+by=d=gcd(a,b)
{
    if(!b){d=a;x=1;y=0;}
    else{gcd(b,a%b,d,y,x);y-=x*(a/b);}
}






ll  chinese_remainder_theorem_for_primes()// sloving x%divisors[i]=remainders[i],
            //for all i upto tot(total)
{
    ll prod=1, i, m, d, x,y, ans=0;
    for (i=0;i<tot;i++)
    {
     prod*=divisors[i];
    }
     for (i=0;i<tot;i++)
     {
         m=prod/divisors[i];
        gcd(divisors[i], m,d, x, y);
        ans= (ans + remainders[i]*y*m) %prod;


     }
     return (ans%prod+prod) %prod;

}

int main() {

    //freopen("in.txt","r",stdin);

    long long cs,csno=1, i,div, rem, ans;



    cin>>cs;
    while(cs--)
    {



            scanf("%lld", &tot);
            for (i=0; i<tot; i++)
            {
                scanf("%lld%lld", &divisors[i], &remainders[i]);

            }
            ans = chinese_remainder_theorem_for_primes();


             printf("Case %lld: %lld\n", csno++, ans);

    }



    return 0;
}

