#include<cstdio>
#include<cstring>
#include<queue>
#define max 205
using namespace std;
int xx[]={0,0,1,-1};
int yy[]={1,-1,0,0};
struct place
{
    int x,y;
    place(int m,int n)
    {
        x=m;y=n;
    }
};

char a[max][max];
int time[max][max];
bool  taken[max][max];
int cost[max][max];
int row;
int col;

void make_time(int x,int y)
{

    memset(taken,0,sizeof(taken));
    time[x][y]=0;
    taken[x][y]=1;
    queue<place>q;
    q.push(place(x,y));
    while(!q.empty())
    {
        place tp=q.front();
        int x=tp.x;
        int y=tp.y;
        for(int i=0;i<4;i++)
        {
            int x_=x+yy[i];
            int y_=y+xx[i];
            if( x_>=0 && x_<row && y_>=0 && y_<col && a[x_][y_]=='.' && taken[x_][y_]==0)
            {
                if((time[x_][y_]>time[x][y]+1)||(time[x_][y_]==-1))
                    {time[x_][y_]=time[x][y]+1;
                taken[x_][y_]=1;
                q.push(place(x_,y_));}
            }
        }
        q.pop();
    }



}
int answer_bfs(int x,int y)
{
    memset(taken,0,sizeof(taken));

    int ans=3000;
    queue<place>q;
    q.push(place(x,y));
    taken[x][y]=1;
    cost[x][y]=0;
    while(!q.empty())
    {
        place tp=q.front();
        int x=tp.x;
        int y=tp.y;
        if(x==0 || x==row-1|| y==0 || y==col-1)
        {
            if(ans>cost[x][y]) ans=cost[x][y];
        }
        for(int i=0;i<4;i++)
        {
            int x_=x+yy[i];
            int y_=y+xx[i];
            if( x_>=0 && x_<row && y_>=0 && y_<col &&a[x_][y_]=='.' && taken[x_][y_]==0 && time[x_][y_]>cost[x][y]+1)
            {
                taken[x_][y_]=1;
                cost[x_][y_]=cost[x][y]+1;
                q.push(place(x_,y_));
            }
        }
        q.pop();
    }
    if(ans==3000) return -1;
    return ans+1;
}

int main()
{
    //freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d %d",&row,&col);
        for(int j=0;j<row;j++) scanf("%s",a[j]);
        int fx,fy,jx,jy;
       // for(int j=0;j<row;j++) printf("%s\n",a[j]);
       memset(time,-1,sizeof(time));
        for(int j=0;j<row;j++)
        {
            for(int k=0;k<col;k++)
            {
                if(a[j][k]=='J') {jx=j,jy=k;};
                if(a[j][k]=='F'){fx=j;fy=k;make_time(fx,fy);};
                //if(c==2) break;

            }
            //if(c==2) break;
        }
        //make_time(fx,fy);
        for(int j=0;j<row;j++)
        {
            for(int k=0;k<col;k++)
            {
                if(time[j][k]==-1) time[j][k]=1000000;
            }
        }
        int ans=answer_bfs(jx,jy);
        if(ans==-1)
        printf("Case %d: IMPOSSIBLE\n",i);
        else printf("Case %d: %d\n",i,ans);



    }
    return 0;
}

