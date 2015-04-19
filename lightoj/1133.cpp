#include<iostream>
#include<cstdio>


using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int n,m;
        char c[5];
        int a[105];
        int ra[105];
        scanf("%d %d",&n,&m);
        for(int j=0;j<n;j++) scanf("%d",&a[j]);
        for(int j=1;j<=m;j++)
        {
            scanf("%s",c);

            if(c[0]=='R')
            {
                int p=0;
                for(int k=n-1;k>=0;k--) ra[p++]=a[k];
                for(int k=0;k<n;k++) a[k]=ra[k];
            }
            else if(c[0]=='S')
            {
                int d;
                scanf("%d",&d);
                for(int k=0;k<n;k++) a[k]+=d;
            }
            else if(c[0]=='M')
            {
                 int d;
                scanf("%d",&d);
                for(int k=0;k<n;k++) a[k]*=d;

            }
            else  if(c[0]=='D')
            {
                 int d;
                scanf("%d",&d);
                for(int k=0;k<n;k++) a[k]/=d;

            }
            else
            {
                int y,z;
                scanf("%d %d",&y,&z);
                int temp=a[y];
                a[y]=a[z];
                a[z]=temp;
            }
        }

        printf("Case %d:\n",i);
        for(int j=0;j<n-1;j++) printf("%d ",a[j]);
         printf("%d\n",a[n-1]);

    }

    return 0;
}
