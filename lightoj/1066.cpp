#include<cstdio>
#include<queue>
#include<cstring>

using namespace std;
char a[11][11];
int cost[11][11];
int n;
struct place
{
    int x,y;
    place(int m,int n)
    {
        x=m,y=n;
    }
};
int xa[]={0,0,1,-1};
int ya[]={1,-1,0,0};
bool taken[11][11];
int ans;

place search(int x,int y,int j)
{

    memset(taken,0,sizeof(taken));
    memset(cost,0,sizeof(cost));
    queue<place> q;
    q.push(place(x,y));
    taken[x][y]=1;
    cost[x][y]=0;
//printf("\n");

    while(!q.empty())
    {
        place tp=q.front();
        int x_=tp.x;
        int y_=tp.y;
        //printf("%d %d %d s\n",x_,y_,j);
        for(int i=0;i<4;i++)
        {
            int x__=x_+ya[i];
            int y__=y_+xa[i];

           //if(x_==1 && y_==1) printf("%d  %d   %d   %d  %d %c %c\n",x_,y_,x__,y__,taken[x__][y__],a[x__][y__],65+j);

            if(x__>=0 && x__<n && y__>=0 && y__<n && taken[x__][y__]==0 &&( a[x__][y__]=='.' || (a[x__][y__]<=(65+j) && a[x__][y__]!='#') ))
            {
                //printf("%d %d \n",x__,y__);
                if(a[x__][y__]==(65+j))
                {

                    cost[x__][y__]=cost[x_][y_]+1;
                    ans+=cost[x__][y__];
                   // printf("%d %d %d",cost[x__][y__],x__,y__);

                    return place(x__,y__);
                }
                taken[x__][y__]=1;
                q.push(place(x__,y__));
                cost[x__][y__]=cost[x_][y_]+1;

            }
        }
        q.pop();
    }
    return place(-1,-1);


}
int main()
{
    //freopen("in.txt","r",stdin);
    int t; scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        ans=0;
        scanf("%d",&n);
        for(int j=0;j<n;j++) scanf("%s",a[j]);
        int sx,sy,c=0;
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                if(a[j][k]=='A') {sx=j,sy=k;}
                if(a[j][k]!='.' && a[j][k]!='#') c++;
            }
        }
        if(c==1) {printf("Case %d: %d\n",i,0);continue;}
        for(int j=1;j<c;j++)
        {
            //printf("%d %d %d\n",sx,sy,j);
            place x=search(sx,sy,j);

            if(x.x==-1) {ans=-1;break;}
            sx=x.x;
            sy=x.y;

        }
        if(ans==-1) printf("Case %d: Impossible\n",i);
        else printf("Case %d: %d\n",i,ans);

    }
    return 0;
}

