#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#define mx 100005
#define mod 10000019
#define pb push_back
using namespace std;
vector<int>prime;
bool a[mx];
void make()
{
    prime.pb(2);
    for(int i=3;i<mx;i+=2)
    {
        if(a[i]==0)
        {
            prime.pb(i);
            //printf("%d\n",i);
            for(int j=2;i*j<mx;j++)a[i*j]=1;
        }

    }
}
long long int fact(int n,int b,int t)
{
    int c=0,y=b;
    for(;;)
    {
        if(n/b==0)break;
        c+=(n/b);
        b*=y;
    }
    //printf("aa %d %d\n",y,c);
    int x=c/t;
    if(x>0)
    {
           // printf("aa %d %d\n",y,c);
         long long int xx=y,yy=y;
        for(int i=2;i<=x;i++)xx=(xx*yy)%mod;
        return xx;
    }
    return -1;
}
int main()
{
    make();
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        int n,t;
        scanf("%d %d",&n,&t);
        long long int ans=1;
        for(int i=0;i<prime.size();i++)
        {
            int x=prime[i];
            if(x>n) break;

            long long int m=(long long int)fact(n,x,t);
            if(m!=-1)
            {
               // printf("%d\n",x);
                ans=ans*(m%mod)%mod;
            }
        }
        printf("Case %d: %d\n",cas,ans==1?-1:ans);

    }
    return 0;

}
