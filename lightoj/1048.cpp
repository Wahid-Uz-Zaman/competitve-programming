#include<bits/stdc++.h>
#define mx 1005
#define pb push_back
using namespace std;
int a[mx];
bool func(int k,int m,int n)
{
    int s=0,i;
    for( i=0;i<n;i++)
    {
       // if(m>=(n-i-1))return 1;
       if(s+a[i]<=k){s=s+a[i];continue;}
       else
       {
           //printf("%d\n",s);
           s=a[i];m--;
       }
       //if(m==0)break;
    }
    //printf("m %d\n",m);
    if(s!=0)m--;
    if(m<0)return 0;
    return 1;
}
int bin(int n,int mm,int s,int m)
{
    int st=mm,ed=s,ans=s;
    while(st<=ed)
    {
        int md=(st+ed)>>1;
        if(func(md,m,n))
        {
            //printf("%d %d\n",md,ans);
            ans=min(ans,md);
            ed=md-1;
        }
        else st=md+1;
    }
    return ans;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        int n,m,mm=0,s=0;
        scanf("%d %d",&n,&m);
        for(int i=0;i<=n;i++)
        {   scanf("%d",&a[i]);s+=a[i];
            if(a[i]>mm)mm=a[i];
        }
        int ans=bin(n+1,mm,s,m+1);
        printf("Case %d: %d\n",cas,ans);
         s=0;
        m++;
        vector<int>b;
        for(int i=0;i<=n;i++)
        {

           if(s+a[i]<=ans && n-i+1>=m)
           {
               s+=a[i];
               //printf(" c%d\n",s);
           }
           else
           {
               //printf(" b%d\n",s);
               b.pb(s);
               s=a[i];
               m--;
           }
        }
        if(m!=0)b.pb(s);
        for(int i=0;i<b.size();i++)printf("%d\n",b[i]);


    }
    return 0;
}
