#include<bits/stdc++.h>
#define mx 30005
using namespace std;


int  make(int n,int s,int a[],int srt[])
{
    int j=0;
    for(int i=0;i<n;i++)
    {
        if(i==j*s)
        {
            srt[j]=a[i];j++;
        }
        else
        {
            srt[j-1]=min(srt[j-1],a[i]);
        }
    }
    return j-1;


}
int forser(int i,int n,int s,int final,int a[],int srt[])
{
    if(i==n-1)return 1;
    int cursec, mn=a[i];
    if(i%s==0)cursec=i/s;
    else
    {
        cursec=(i/s)+1;
        for(int j=i+1;j<n && j<cursec*s;j++)
        {
            if(a[j]<a[i])return j-i;
        }
    }
    int j;
    for( j=cursec;j<=final;j++)
    {
        if(srt[j]<a[i])break;
    }
    if(j==final+1)return n-i;
    else
    {
        for(int k=j*s;k<n;k++)
        {
            if(a[k]<a[i])return k-i;
        }
    }

}
int main()
{
    int a[mx];
    int b[mx];
    int srt[mx];
    int srt1[mx];
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        int n;
        scanf("%d",&n);
        for(int i=0,j=n-1;i<n;i++,j--){scanf("%d",&a[i]);b[j]=a[i];}
        int s=sqrt(n);
        int section=make(n,s,a,srt);
        int section1=make(n,s,b,srt1);
        int ans=-1;
        for(int i=0;i<n;i++)
        {
            int x=forser(i,n,s,section,a,srt);
            int y=forser(n-1-i,n,s,section1,b,srt1);
            ans=max(ans,(x+y-1)*a[i]);

        }
        printf("Case %d: %d\n",cas,ans);


    }

}
