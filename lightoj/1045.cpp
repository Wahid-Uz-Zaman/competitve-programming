# include<stdio.h>
# include<math.h>
double a[1000000];
int main(void)
{
    long int t,i,j,n,b;
    double sum,k=1;
    a[0]=0;
    for(i=1;i<1000000;i++) a[i]=a[i-1]+log(++k);

    scanf("%ld",&t);
    for(j=1;j<=t;j++)
    {
        scanf("%ld %ld",&n,&b);
        if(n==1 || n==0) printf("Case %ld: %d\n",j,1);
        else
        {
            sum=a[n-1];
            sum/=log(b*1.0);
            i=(int)floor(sum+1);
            printf("Case %ld: %ld\n",j,i);
        }

    }
    return 0;
}
