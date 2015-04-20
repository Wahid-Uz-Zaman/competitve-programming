#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<set>
using namespace std;
int depth;
struct job
{
    int s,f;
    job(int x,int y){s=x,f=y;}
    bool operator<(const job t)const
    {
        return (s<t.s)||((s==t.s)&&(f<t.f));
    }
};
struct job1
{
    int s,f;
    int no;
    job1(int n,int x,int y){no=n;s=x,f=y;}
    bool operator<(const job1 t)const//find min end time job at top
    {
        return (f<t.f)||((f==t.f)&&(s<t.s))||((f==t.f)&&(s==t.s)&&(no<t.no));
    }
    bool operator==(const job1 t)const//find min end time job at top
    {
        return (no==t.no);
    }
};
int main()
{
    //freopen("a.in","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int n;
        scanf("%d",&n);
        vector<job>a;
        int s,f;
        for(int j=0;j<n;j++)
        {
            scanf("%d %d",&s,&f);
            a.push_back(job(s,f));
        }
        sort(a.begin(),a.end());
        depth=1;
        set<job1> q;
        q.insert(job1(0,a[0].s,a[0].f));
        for(int j=1;j<n;j++)
        {
            job1 tmp=*q.begin();
            //printf("%d %d\n",a[j].s,tmp.f);
            if(a[j].s>tmp.f)
            {

                q.erase(q.find(job1(tmp.no,tmp.s,tmp.f)));
                q.insert(job1(tmp.no,tmp.s,a[j].f));
            }
            else
            {
                depth++;
                q.insert(job1(j,a[j].s,a[j].f));
            }
        }
        printf("Case %d: %d\n",i,depth);


    }
    return 0;
}
