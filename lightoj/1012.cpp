#include<cstdio>
#include<queue>
#include<vector>
#include<cstdlib>
#include<bitset>
#include<iostream>
#include<cstring>

#define max(m,n) m>n?m:n
#define high 20

using namespace std;
int ans;
struct dim{
 int x,y;};
struct vertex{
    char ch;
    bool used;
    vector<struct dim >adj;
    };


void bfs(struct dim s,struct vertex v[][20])
{

    queue<struct dim> q;
    q.push(s);
    v[s.x][s.y].used=true;
    //printf("a ");
    while(!(q.empty()))
    {
        //printf("a ");
        struct dim u= q.front();
       //printf("%c  %d\n",u.ch,(u.adj).size());
        for(int i=0;i<(v[u.x][u.y].adj).size();i++)
        {
            struct dim t=v[u.x][u.y].adj[i];
            if(!(v[t.x][t.y].used))
            {
                if(v[t.x][t.y].ch=='.'){ ans++;
                v[t.x][t.y].used=true;
                q.push(t);}
            }


        }

        q.pop();

    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt")
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        ans=1;
        struct vertex v[20][20];
        int wid,hig;
        struct dim s;
        scanf("%d %d",&wid,&hig);
       //input;
        for(int j=0;j<hig;j++)
        {
            int k=0;
            while(k<wid)
            {
                char ch;
                scanf("%c",&ch);
                if((ch=='.')|| (ch=='#')||(ch=='@'))
                {

                 v[j][k].ch=ch;
                 if(ch=='@') {s.x=j;s.y=k;}
                 v[j][k].used=false;
                 struct dim a;
                 if(k+1<wid)
                 {
                     a.x=j;a.y=k+1;
                     (v[j][k].adj).push_back(a);
                 }
                 if(k-1>=0)
                 {
                     a.x=j;a.y=k-1;
                     (v[j][k].adj).push_back(a);
                 }
                 if(j-1>=0)
                 {
                     a.x=j-1;a.y=k;
                     (v[j][k].adj).push_back(a);
                 }
                 if(j+1<hig)
                 {
                     a.x=j+1;a.y=k;
                     (v[j][k].adj).push_back(a);
                 }
                 k++;
                }
            }
        }
            //input
            //bfs

            bfs(s,v);
            printf("Case %d: %d\n",i,ans);


    }


    return 0;
}
