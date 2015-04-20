#include<bits/stdc++.h>
#define pb push_back
#define large 1000000000000LL
#define ll long long
using namespace std;
vector<ll>a;

void makelist()
{
    //a.pb(0);
    vector<ll>t;t.pb(0);
    for(int i=1;i<=12;i++)
    {
        int sz=t.size();
        vector<ll>tt;
        for(int j=0;j<sz;j++)
        {
            a.pb(t[j]*10+4);
            tt.pb(t[j]*10+4);

            tt.pb(t[j]*10+7);
            a.pb(t[j]*10+7);
        }
        t.clear();
        for(int j=0;j<tt.size();j++)t.pb(tt[j]);
    }
   // printf("%d\n",a.size());
   sort(a.begin(),a.end());
    //for(int i=0;i<100;i++)printf("%d\n ",a[i]);
}
/*vector<ll>pro;

void prolist()
{
    pro.pb(1);
    set<ll>s;
    set<ll>::iterator it;
    for(int i=0;i<a.size();i++)
    {
        //sort(pro.begin(),pro.end());
        int sz=pro.size();
        for(int j=0;j<sz;j++)
        {
            ll x=a[i]*a[j];
            if(x<=large)
            {pro.pb(x);
            s.insert(x);}
        }
    }
    printf("%d\n",s.size());
    pro.clear();
    //for(it=s.begin();it!=s.end();i++)
}*/
set<ll>pro;
vector<ll>lst;
void prolist()
{
    pro.insert(1);
    //set<ll>s;
    set<ll>::iterator it;
    for(int i=0;i<a.size();i++)
    {
        //sort(pro.begin(),pro.end());
        int sz=pro.size();
        vector<ll>t;
        for(it=pro.begin();it!=pro.end();it++)
        {
            ll x=a[i]*(*it);
            if(x<=large)
            {pro.insert(x);
            //s.insert(x);
            }
            else break;
        }
        for(int ii=0;ii<t.size();ii++)pro.insert(t[ii]);
    }
    //printf("%d\n",pro.size());
    //pro.clear();
    //int x=100;
    //lst.pb(0);
    pro.erase(1);
    for(it=pro.begin();it!=pro.end();it++)
    {
        lst.pb(*it);
        //1if(x-- && x>=0)printf("%lld\n",*it);
    }
    //lst.pb(large);
    //lst.pb(large+1);
}
int binser(ll k)
{
    int st=0,ed=lst.size()-1;
    //printf
    while(st<=ed)
    {
        //printf("st%d ed%d\n",st,ed);
        int mid=(st+ed)>>1;
        //printf("mid %lld\n",lst[mid]);
        if(mid!=0){
        if(lst[mid]>=k && lst[mid-1]<k)return mid;
        else if(lst[mid]>k && lst[mid-1]>k )
        {
            ed=mid-1;
            //printf("bak\n");
        }
        else st=mid+1;
        }
        else if(mid==0)
        {
            if(lst[mid]>=k)return mid;
            //else if(a[mid]>k && a[mid+1]>k && a[mid-1]>k )ed=mid-1;
            else st=mid+1;
        }
    }

}
int main()
{
    makelist();
    prolist();
    while(1)
    {
        break;
        ll x;
        scanf("%lld",&x);
        printf("%d\n",binser(x));
    }
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        ll a,b;
        scanf("%lld %lld",&a,&b);
        int ans = upper_bound(lst.begin(),lst.end(),b)-lower_bound(lst.begin(),lst.end(),a);
        printf("Case %d: %d\n",cas,ans);
        //int x=binser(a);
        //printf("%d\n",x);
        //if(x==0)x++;
        //int y=binser(b);
       // printf("%d\n",y);
        //if(lst[y]>b)y--;
        //printf("Case %d: %d\n",cas,y-x+1);
    }
}
