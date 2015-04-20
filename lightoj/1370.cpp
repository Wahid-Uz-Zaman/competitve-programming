#include<cstdio>
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
#define MAX 1000100
#define LMT 1009
#define ll long long
int k=0,p=-1;
int ar [1000064/64], prime[100000], ind [100];

#define  ifchk( n)   ( ar[n>>6] &(1<<( (n>>1) &31) ) )
#define  set( n)   ( ar[n>>6]|= (1<<( (n>>1)&31) ) )
void seive()
{
    int i,j,ad;
    prime[++k]=1;//just kidding for binary search, 1 on 1st index
    prime[++k]=2;
    for (i=3;i<=LMT;i+=2)   if (!ifchk( i)) for (j=i*i,ad=i+i; j<=MAX; j+=ad)  set( j);
    for (i=3;i<=MAX;i+=2)   if (!ifchk( i) )    {prime[++k]=i;
    //if (prime[k]<100)`ind[ prime[k] ]=++p;
    }//cout<<i<<endl;}

     //cout<<"k= "<<k<<"prime is: "<<prime[k]<<endl;
}
/*
int nod (ll num)
{
    int root,ret,i,pow,ans=1;
    for (i=0;i<=k && prime[i]<=sqrt(num); i++)
    {
        pow=0;
        while (num%prime[i]==0)
        {
            //cout<<"now num= "<<num<<endl;
            num/=prime[i];
            pow++;
        }
        //cout<<"now num= "<<num<<" with factor "<<prime[i]<< " power "<<pow<<endl;;
        ans*=(pow+1) ;
    }
    //cout<<"ans= !"<<ans<<endl;;
    if (num>1)//still prime factor >10^3
        {   //cout<<"ans was = "<<ans<<endl;;
            ans<<=1;//doubles
        //cout<<"ans is= "<<ans<<endl;;
        }

    --ans;
    return ans;
}
*/

int findnextprime(int n)
{
    if (n==1)   return 2;
    int lo=2,hi=k,mid;
    mid=(hi+lo)/2;
    while(lo<hi)
    {
       // cout<<"mid prime: "<<prime[mid]<<endl;
        if (prime[mid]<=n&&prime[mid+1]>=n)
            {if (prime[mid]==n)   return prime[mid+1];
               if (prime[mid+1]==n)   return prime[mid+2];
                else return prime[mid+1];
            }

        if (prime[mid]>=n&&prime[mid-1]<=n)
            {if (prime[mid-1]==n)   return prime[mid];
                if (prime[mid]==n)   return prime[mid+1];
                else return prime[mid];
            }

        if (prime[mid]<=n&&prime[mid+1]<=n)
            lo=mid+1;
         if (prime[mid]>=n&&prime[mid+1]>=n)
            hi=mid-1;
        mid=(hi+lo)/2;
    }
    return -1;

}
int main()
{
  // int p=10000*100003;
   //cout<<p<<endl;
   // cout<<"k= "<<k<<"prime is: "<<prime[k]<<endl;
   //freopen("test.txt","r",stdin);
    seive();
    int cs,csno=0,total,i;
    long long int ans;
    int num;
    scanf("%d",&cs);
    while(cs--)
    {
        ans=0;
        scanf("%d",&total);
        for (i=1;i<=total;i++)
            {scanf("%d",&num);
            //cout<<num<<" -_-  "<<findnextprime(num);
            ans+=findnextprime(num);
            }


            printf("Case %d: %lld Xukha\n",++csno,ans);
    }


    return 0;
}
