#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
#define mx 26
using namespace std;
bool taken[mx][mx][mx];
bool avoid[mx][mx][mx];
int dist[mx][mx][mx];
int ans;
struct state
{
  int x,y,z;
  state(int a,int b,int c)
  {
      x=a,y=b,z=c;
  }
};
int change[][3]=
{
    {1,0,0},{-1,0,0},
    {0,1,0},{0,-1,0},
    {0,0,-1},{0,0,1}

};


char out[5];
int bfs(state  ini)
{
    out[0]-=97,out[1]-=97,out[2]-=97;
    queue<state>q;
    q.push(ini);
    dist[ini.x][ini.y][ini.z]=0;
    taken[ini.x][ini.y][ini.z]=1;
    while(!q.empty())
    {
        state tmp=q.front();
        q.pop();
        if(avoid[tmp.x][tmp.y][tmp.z]==1)
        {
            if(tmp.x==out[0] && tmp.y==out[1] && tmp.z==out[2]) {ans=-1;break;}

        }
        else if(tmp.x==out[0] && tmp.y==out[1] && tmp.z==out[2]){ ans=dist[tmp.x][tmp.y][tmp.z];break;}
        else
        {
            for(int i=0;i<6;i++)
            {
                int u=(tmp.x+change[i][0])%26;
                int v=(tmp.y+change[i][1])%26;
                int z=(tmp.z+change[i][2])%26;
                if(u<0) u+=26;
                if(v<0) v+=26;
                if(z<0) z+=26;
                if(!taken[u][v][z])
                {
                     dist[u][v][z]=dist[tmp.x][tmp.y][tmp.z]+1;
                     taken[u][v][z]=1;
                     q.push(state(u,v,z));
                }
            }
        }
    }
    return ans;

}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        memset(taken,0,sizeof taken);
        memset(avoid,0,sizeof avoid);
        char input[5];
        scanf("%s %s",input,out);
        int n;
        scanf("%d",&n);
        for(int j=1;j<=n;j++)
        {
            char x[30],y[30],z[30];
            scanf("%s %s %s",x,y,z);
            int xl=strlen(x);
            int yl=strlen(y);
            int zl=strlen(z);
            for(int j=0;j<xl;j++)
            {
                for(int k=0;k<yl;k++)
                {
                    for(int l=0;l<zl;l++) avoid[x[j]-97][y[k]-97][z[l]-97]=1;
                }
            }
        }
            //int ans =
            ans=-1;
            ans= bfs(state(input[0]-97,input[1]-97,input[2]-97));
            printf("Case %d: %d\n",i,ans);



    }



    return 0;
}
