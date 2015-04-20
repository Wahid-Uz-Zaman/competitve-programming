#include<iostream>
using namespace std;
#include<string>
#include<stdio.h>
#include<cstring>
#include<math.h>




int mod( long long int n, long long int k)
{


if( k==1) return n%1000;
int x= mod(n,k/2);
int ans=x*x%1000;
if( k%2==1) ans=ans*n%1000;

return ans;

}

int g( long long int n, long long int k)
{

double temp;
double power=k*log10(double(n));
temp=pow(10.0, power-int(power) );
// 1<temp<10
temp*=100;

return (int)temp;

}



int main()
{

int t;
scanf("%d",&t);

for( int i=1; i<=t; i++)
{

        long long int n,k;
        scanf("%lld%lld",&n,&k);


        printf("Case %d: %d ",i,g(n,k));
        int temp=mod(n,k);
        if( temp>=100) printf("%d\n",temp);
        else if( temp>=10) printf("0%d\n",temp);
        else printf("00%d\n",temp);


}
return 0;
}
