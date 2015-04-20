//1006 jan complete


#include<stdio.h>
long long int ar[10001];
void make()
{
    long long int i;
    for(i=0;i<=10000;i++) ar[i]=0;
}
long long int a, b, c, d, e, f;
long long int fn( long long int n )
{

    if( n == 0 ) ar[n]=a;
    else if( n == 1 ) ar[n]=b;
    else if( n == 2 ) ar[n]=c;
    else if( n == 3 ) ar[n]=d;
    else if( n == 4 ) ar[n]=e;
    else if( n == 5 ) ar[n]=f;
    else if(n>5 && ar[n]==0) ar[n]=( fn(n-1)% 10000007 + fn(n-2)% 10000007 + fn(n-3)% 10000007 + fn(n-4)% 10000007 + fn(n-5)% 10000007 + fn(n-6)% 10000007);
    return ar[n];
}
 int main()
 {
    long long int n, caseno = 0, cases;
    scanf("%lld", &cases);
    while( cases-- ) {
        scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f, &n);
        make();
        printf("Case %lld: %lld\n", ++caseno, fn(n) % 10000007);
    }
    return 0;
}
