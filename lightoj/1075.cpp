#include<cstdio>
#include<map>
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#define max 500
using namespace std;
int n;
int pr[max];
int child[max];
int main()
{
  //freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
       scanf("%d",&n);
       map<string,int>a;
       map<int,string>b;
       int k=1;
       memset(pr,-1,sizeof(pr));
       for(int j=1;j<n;j++)
       {
           char x[60],y[60];
           scanf("%s %s",x,y);
           pair<map<string,int>::iterator,bool>ret;
           ret=a.insert(pair<string,int>(x,k));
           if(ret.second==true)
           {

               b.insert(pair<int,string>(k,x));

               k++;
           }
           ret=a.insert(pair<string,int>(y,k));
            if(ret.second==true)
            {
                b.insert(pair<int,string>(k,y));
               k++;
            }
            int u=a[x];
            int v=a[y];
            pr[v]=u;
            child[u]=v;
       }
       int root;
       for(int j=1;j<=n;j++)
       {
           if(pr[j]==-1) {root=j;break;}
       }
       int ans[500];
       ans[1]=root;
       int u=root;
       for(int j=2;j<=n;j++)
       {
          ans[j]=child[u];
          u= child[u];
       }
       printf("Case %d:\n",i);
       for(int j=1;j<=n;j++)
       {
           cout<<b[ans[j]]<<endl;
       }
       printf("\n");

    }
    return 0;
}
