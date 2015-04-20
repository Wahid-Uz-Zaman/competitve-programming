# include <stdio.h>

long int max(long int a[][100],int n)
{
    int m=0,i;
    for(i=0;i<n;i++)
    {
        if(a[n-1][i]>m) m=a[n-1][i];
    }
    return m;
}
int main(void)
{
    int t,b;
    scanf("%d",&t);
    for(b=1;b<=t;b++)
    {
        int n,i;
        long int a[199][100];
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            int j;
            for(j=0;j<=i;j++)
            {
                scanf("%ld",&a[i][j]);
            }
        }
        int k=1;
        int j;
        for(i=n;i<2*n-1;i++)
        {
            for(j=0;j<n-k;j++)
            {
                scanf("%ld",&a[i][j]);
            }
            k++;
        }
        for(i=1;i<n;i++)
        {
            a[i][0]=a[i][0]+a[i-1][0];
            for(j=1;j<i;j++)
            {
                if(a[i-1][j]>a[i-1][j-1]) a[i][j]+=a[i-1][j];
                else a[i][j]+=a[i-1][j-1];

            }
            a[i][j]+=a[i-1][j-1];
        }
        k=n-1;
        for(i=2*n-3;i>=(n-1);i--)
        {
            a[i][0]=a[i][0]+a[i+1][0];
            for(j=1;j<n-k;j++)
            {
                if(a[i+1][j]>a[i+1][j-1]) a[i][j]+=a[i+1][j];
                else a[i][j]+=a[i+1][j-1];

            }
            a[i][j]+=a[i+1][j-1];
            k--;
        }
        printf("Case %d: %ld\n",b,max(a,n));
    }
    return 0;
}
