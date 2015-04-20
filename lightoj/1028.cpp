#include<stdio.h>
#include<math.h>
#define llu unsigned long long
#define max 78498
#define MAX_NUM 1000000


llu primes[MAX_NUM];
llu a[max];


void gen_sieve_primes(void)

{
    llu p,i=0;
    for (p=2; p<MAX_NUM; p++)
    {
        if(primes[p] == 0)
        {
            a[i++]=p;

        }
        llu c=2;
        llu mul = p * c;
        for(; mul < MAX_NUM;)
        {
            primes[mul] = -1;
            c++;
            mul = p*c;
        }
    }


}




int main()

{
    gen_sieve_primes();
    int t,i;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        llu n,m,ans;
        scanf("%llu",&n);
        m=n;
        ans=1;
        if(n==1) printf("Case %d: 0\n",i);
        else
        {
            int j;
            for(j=0;j<max && a[j]<=sqrt(m);j++)
            {
                int count=0;
                while(!(m%a[j]))
                {
                    count++;
                    m/=a[j];
                }
                ans=ans*(++count);
            }
            if(m!=1) ans*=2;
            if(ans==1) printf("Case %d: 1\n",i);
            else printf("Case %d: %llu\n",i,ans-1);
        }

    }
        return 0;

}
