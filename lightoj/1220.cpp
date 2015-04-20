#include<cstdio>
#include<cmath>
#define max 2147483647
using namespace std;

bool primes[46350];
int a[4793];

int GCD(int m,int n)
{
    if(n==0) return m;
    else if(!(m%n)  ) return n;
    else return GCD(n,m%n);
}
void gen_primes()
 {
   int i,j,k=0;
   for(i=2;i<=(int)sqrt(46350);i++){
     if (!primes[i]){a[k++]=i;
       for(j=i;j*i<46350;j++) primes[i*j] = 1;}
   }
   for(;i<46350;i++)
   {
       if(!primes[i]) a[k++]=i;
   }
   //printf("%d %d %d\n",k,a[0],a[4792]);
 }

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    gen_primes();
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int n,j,l=0;
        scanf("%d",&n);
        if(n<0) l=1;

        int gcd=0;


        for( j=0;j<4793;j++)
        {
            int count=0,temp=0;
            while(!(n%a[j]))
            {
                n/=a[j];
                count++;
                temp=1;
            }
            if(temp)

            {//printf("%d %d\n",count,gcd);
                gcd=GCD(count,gcd);
            //printf("%d\n",gcd);
            }
        }
        if(n==1 ||n==-1)
        {
            if(l==1)
            {
                if(gcd%2) printf("Case %d: %d\n",i,gcd);
                else
                {
                    while(!(gcd%2)) gcd/=2;
                    printf("Case %d: %d\n",i,gcd);
                }
            }
            else printf("Case %d: %d\n",i,gcd);

        }
        else  printf("Case %d: 1\n",i);

    }
    return 0;
}
