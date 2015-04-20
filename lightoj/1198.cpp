#include<bits/stdc++.h>
#define pb push_back
#define mx 1005
#define ll long long
#define mod 1000000007
using namespace std;
int karate(int a[],int b[],int n)
{
    sort(a,a+n);
    sort(b,b+n);
    int ans=0;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<n;j++)
        {
            if(a[j]!=0 && a[j]>b[i])
            {
                ans+=2;
                a[j]=0;
                b[i]=0;
                break;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i]!=0 && a[i]==b[j])
            {
                ans++;
                a[i]=0;b[j]=0;
            }
        }
    }
    return ans;

}
int main()
{

    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        int n;int a[55],b[55];
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d",&a[i]);

        for(int i=0;i<n;i++)scanf("%d",&b[i]);
        printf("Case %d: %d\n",cas,karate(a,b,n));



    }

}
