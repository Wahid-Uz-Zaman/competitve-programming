#include<math.h>
# include<stdio.h>
#include<math.h>
#include<time.h>
#define llu unsigned long long
#define max 664579
#define MAX_NUM 10000000
//bitwise sieve lagbe

char primes[MAX_NUM];
llu  a[max];


void gen_sieve_primes(void)

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
        if(n==1 || n==2) printf("Case %d: 0\n",i);
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
                if(a[j]!=2) ans=ans*(++count);
            }
            if(m!=1) ans*=2;
            printf("Case %d: %llu\n",i,ans-1);
        }

    }

        return 0 ;
}
