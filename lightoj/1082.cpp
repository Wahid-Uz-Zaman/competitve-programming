#include<cstdio>
#include<cmath>

#define max 100005
using namespace std;

int  seg;
int n;
int count;
int a[max];
int b[317];


int minimum(int m)
{
    int end=m+seg;

    int min=max;
    for(int k=m;k<end;k++)
    {
        //printf("%d ",a[k]);

        if(min>a[k]) min=a[k];
        if(k==n) break;
    }
   // printf("\n");
    b[count]=min;
    count++;
}


int RMQ(int s,int e)
{


    int m=s/seg,n=e/seg;

    int min=max;
     if(m==n)
    {
        for(int i=s;i<=e;i++)
        {
            if(min>a[i]) min=a[i];
        }
    }
    else{
    for(int i=m+1;i<n;i++)
    {
        if(min>b[i]) min=b[i];
    }
    m= seg-(s%seg),n=e%seg;
    int mr=s+m,nr=e-n+1;
    for(int i=s;i<=mr;i++)
    {
        if(min>a[i]) min=a[i];
    }
    for(int i=e;i>=nr;i--)
    {
         if(min>a[i]) min=a[i];
    }
    }
    return min;
}
int main()
{
    //freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int q;
        scanf("%d %d",&n,&q);
        for(int j=1;j<=n;j++) scanf("%d",&a[j]);
        //for(int j=1;j<=n;j++) printf("%d ",a[j]);
        seg=sqrt(n*1.);
        //printf("%d",seg);

        count=0;
        for(int j=1;j<=n;j+=seg)
        {
            minimum(j);
        }
        //for(int j=0;j<count;j++) printf("%d ",b[j]);
        printf("Case %d:\n",i);
        for(int j=1;j<=q;j++)
        {
            int s,e;
            scanf("%d %d",&s,&e);
            int ans=RMQ(s,e);
            printf("%d\n",ans);

        }







    }

    return 0;
}
