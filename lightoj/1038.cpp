#include<cstdio>
#include<cmath>
#define max 100002
using namespace std;
double a[max];
void make()
{
    a[1]=0;
    a[2]=2.0;
    for(int j=3;j<max;j++)
    {
        int sr=sqrt(j*1.),k;
        double temp=0;
        int count=1;

        for( k=2;k<=sr;k++)
        {
            if(!(j%k)){
            temp=temp+2+a[j/k]+a[k];
            count+=2;}

        }
        //printf("%d",k);
        if(k!=2 && (k-1)*(k-1)==j) {temp=temp-1-a[k-1];
        count--;}
        //printf("%lf %d ",temp,count);
        a[j]=(2+temp)*1./count;
        //printf("%lf\n",a[j]);

    }

}
int main()
{
    make();
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int n;
        scanf("%d",&n);
        printf("Case %d: %.10lf\n",i,a[n]);
    }
    return 0;
}
