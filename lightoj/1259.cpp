#include<cmath>
# include<cstdio>
#include<ctime>
#define llu unsigned long long
#define MAX 10000006

#define max 664583
using namespace std;

bool  primes[MAX];
int a[max];




void gen_primes()
{
       int i,j,k=0;
       //for(i=0;i<MAX;i++) primes[i] = 1;
       for(i=2;i<=(int)sqrt(MAX);i++){
         if (!primes[i]){
             a[k++]=i;
           for(j=i;j*i<MAX;j++) primes[i*j] = 1;}
       }
       for(;i<MAX;i++)
       {
           if(!primes[i]) a[k++]=i;
       }
       //printf("%d %d\n",k,a[k-1]);
}



int main()

{
    //freopen("out.txt","w",stdout);
    gen_primes();
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int  n;
        scanf("%d",&n);
        if(n==4) printf("Case %d: 1\n",i);
        else{
            int ans=0;
        for(int j=0;a[j]<=n/2;j++)
        {
            if(primes[n-a[j]]==0)
            {
                //printf("%d \n",j);
                ans++;
            }
        }
        printf("Case %d: %d\n",i,ans);
        }
    }
    return 0;
}
