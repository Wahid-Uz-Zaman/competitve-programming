# include<cstdio>
# define max 100000
using namespace std;
double a[max+1];
void make_harmonic()
{
    int i=0;
    for(;i<max;i++)
    {

        for(int j=i*1000,k=1;k<=1000;k++)
        {
            a[i]+=(1.0/(j+k));
        }
        a[i]+=a[i-1];
    }
}

int main()
{
    make_harmonic();
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int n;
        scanf("%d",&n);
        double ans=a[n/1000-1];
        if(n%1000==0) printf("Case %d: %.10lf\n",i,ans);
        else
        {
            int k=n%1000,j=n/1000*1000;
            for(int temp=j+1;temp<=j+k;temp++)
            {
                ans+=(1.0/temp);
            }

        printf("Case %d: %.10lf\n",i,ans);

        }
    }

}
