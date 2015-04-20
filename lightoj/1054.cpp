#include<cstdio>
#include<cmath>

#define llu unsigned long long
#define max 4792
#define MAX_NUM 46350
#define mod 1000000007
using namespace std;

char primes[MAX_NUM];
llu a[max];

llu power(llu b,llu p)
{
    if(p==0) return 1;
    if (p==1) return b%mod;
    llu temp=power(b,p/2);
    if(p%2) return ((((temp%mod)*(temp%mod))%mod)*(b%mod))%mod;
    else return ((temp%mod)*(temp%mod))%mod;
}


int  gen_sieve_primes()

{
    int  p,i=1;
    a[0]=2;

    for (p=3; p<MAX_NUM; p=p+2)
    {
        if(primes[p] == 0)
        {
            a[i++]=p;


        int  c=3;
        llu mul = p * c;
        for(; mul < MAX_NUM;)
        {
            primes[mul] = 2;
            c+=2;
            mul = p*c;
        }
        }

    }
return 0;

}

int main()

{
    gen_sieve_primes();

    int t,i;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        llu n,m,ans;

        scanf("%llu %llu",&n,&m);


        if(n==1 || m==0) printf("Case %d: 1\n",i);
        else if(n== mod) printf("Case %d: 1\n",i);

        else
        {
            llu j,ans=1;
            for(j=0;j<max && a[j]<=sqrt(n);j++)
            {
                llu count =0;
                while(!(n%a[j]))
                {
                    count++;
                    n/=a[j];

                }

                if(count>0)
                {
                    ans=(ans*(power(a[j],count*m+1)-1))%mod;

                    ans=(ans* power(a[j]-1,mod-2))%mod;

                }

            }
            if(n!=1)
            {

                ans=(ans*((power(n,m+1)-1)%mod))%mod;

                ans=(ans* (power(n-1,mod-2)))%mod;

            }
            printf("Case %d: %llu\n",i,ans);
        }
    }
        return 0;

}
