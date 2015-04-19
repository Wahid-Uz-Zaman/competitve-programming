#include<cstdio>
#include<cmath>
#define max 1000005
#define sq 1001
typedef long long int llu;

bool primes[max];
int a[78499];
using namespace std;
llu gcd (llu a,llu b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}
llu lcm(llu a,llu b)
{
    return a*b/gcd(a,b);
}
void sieve()
{
    int count=0,i;
    for(i=2;i<sq;i++)
    {
        if(primes[i]==0)
        {
            a[count++]=i;
            int k=i;
            int j=i*k;
            while(j<max)
            {
                primes[j]=1;
                j=i*(++k);
            }
        }
    }
    for(;i<max;i++)
    {
        if(primes[i]==0) a[count++]=i;
    }
    //printf("%d\n",a[count-1]);
}
llu power(llu a,llu b)
{
    llu ans=1;
    for(int i=1;i<=b;i++) ans*=a;
    return ans;
}

int main()
{
    sieve();
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        llu d,b,l,c=1,temp;
        scanf("%lld %lld %lld",&d,&b,&l);
        temp=lcm(d,b);
        int s=0;
        for(int j=0;j<78499;j++)
        {
            int count=0;
            while(!(temp%a[j]))
            {
                count++;
                temp/=a[j];
            }
            int ncount=0;
            while(!(l%a[j]))
            {
                ncount++;
                l/=a[j];
            }
            if(ncount<count) {s=1;printf("Case %d: impossible\n",i);break;}
            else if(ncount>count) c*=power(a[j],ncount);
            else c*=1;
            if(temp==1) break;
        }
        if(s!=1)
        {
            if(l!=1) c*=l;
            printf("Case %d: %lld\n",i,c);
        }

    }
    return 0;
}
