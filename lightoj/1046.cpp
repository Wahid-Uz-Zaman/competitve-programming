#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
#define r 15
#define c 15
using namespace std;
int rn;
int cn;
int vcount;
int jump[110];
int taken[r][c];
int dis[r*c+7][r][c];
int x[]={1,1,2,2,-1,-1,-2,-2};
int y[]={2,-2,1,-1,2,-2,1,-1};
struct loc
{
    int j,k;
    loc(int x_,int y_)
    {
        j=x_,k=y_;
    }
};
void func(int j,int k)
{
    queue<loc>q;
    q.push(loc(j,k));
    taken[j][k]=1;
    while(!q.empty())
    {
        loc temp=q.front();
        j=temp.j;
        k=temp.k;
        for(int i=0;i<8;i++)
        {
           int jy=j+y[i];
           int  kx=k+x[i];
           if(kx>=0 && kx<cn && jy>=0 && jy<rn && taken[jy][kx]==0)
           {
              dis[vcount][jy][kx]=dis[vcount][j][k]+1;
              taken[jy][kx]=1;
              q.push(loc(jy,kx));
           }
        }
        q.pop();

    }

}
int main()
{
    //freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d %d",&rn,&cn);
       char a[r][c];
       for(int j=0;j<rn;j++) {scanf("%s\n",a[j]);}
        memset(dis,-1,sizeof(dis));
        vcount=0;

       for(int j=0;j<rn;j++)
       {
           for(int k=0;k<cn;k++)
           {

               if(a[j][k]>='1' && a[j][k]<='9')
               {

                   vcount++;
                   jump[vcount]=a[j][k]-'0';
                   dis[vcount][j][k]=0;
                   memset(taken,0,sizeof(taken));
                   func(j,k);

               }
           }
       }

       int ans=10000;
       for(int j=0;j<rn;j++)
       {
           for(int k=0;k<cn;k++)
           {
               int tmp=0,v;
               for(v=1;v<=vcount;v++)
               {

                   if(dis[v][j][k]==0) continue;
                   if(dis[v][j][k]==-1) break;
                   else
                   { if(dis[v][j][k]%jump[v]==0) tmp+=(dis[v][j][k]/jump[v]);
                      else  tmp+=(dis[v][j][k]/jump[v]+1);
                    }
               }

               if(v>vcount) {if(tmp<ans) ans=tmp;}
           }
       }

       if(ans==10000) printf("Case %d: -1\n",i);
       else   printf("Case %d: %d\n",i,ans);




    }


    return 0;
}
