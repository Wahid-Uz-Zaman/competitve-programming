#include<cmath>
# include<cstdio>


#define max 1000
#define MAX_NUM 5000005
//bitwise sieve lagbe
typedef unsigned long long llu;
using namespace std;

llu  primes[MAX_NUM];



void gen_sieve_primes()

{
    llu p,i=0;
    primes[0]= 0;
    primes[1]= 0;

    for (p=2; p<MAX_NUM; p++)
    {

        if(primes[p] == 0)
        {

            primes[p]=(p-1);


        llu c=2;
        llu mul = p * c;
        for(; mul < MAX_NUM;)
        {
            if(primes[mul]==0) primes[mul] = (mul/p)*(p-1);

            else primes[mul] = (primes[mul]/p)*(p-1);
            c++;
            mul = p*c;
        }
    }
    }
    for(int i=2;i<MAX_NUM;i++)
    {
        primes[i]=primes[i]*primes[i]+primes[i-1];
    }

    //return 0;
}




int main()

{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    gen_sieve_primes();
    int t,i;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
      int p,q,j;
      llu sum=0;
      scanf("%d %d",&p,&q);
      //for( j=p;j<=q;j++) sum=sum+primes[j]*primes[j];
      printf("Case %d: %llu\n",i,primes[q]-primes[p-1]);
    }
        return 0;

}
