#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
using namespace std;
int x[]={0,0,1,-1};
int y[]={1,-1,0,0};
int ans,r,c,comp;
char a[505][505];
bool taken[505][505];
int compo[505][505];
vector<int>com;
int dfs(int R,int C)
{
    taken[R][C]=1;
    if(a[R][C]=='.') compo[R][C]=comp;
    if(a[R][C]=='C') ans++;
    for(int i=0;i<4;i++)
    {
        int py=R+y[i];
        int px=C+x[i];
        if(py>=0 && py<r && px>=0 && px<c && !taken[py][px] && a[py][px]!='#')
        dfs(py,px);


    }
    return ans;
}
int main()
{
    //freopen("in.txt","r",stdin);

    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int q;
        memset(a,0,sizeof(a));
        memset(compo,-1,sizeof(compo));
        memset(taken,0,sizeof(taken));
        com.clear();
        comp=0;

        scanf("%d %d %d",&r,&c,&q);
        printf("Case %d:\n",i);
        for(int j=0;j<r;j++) scanf("%s",a[j]);


        for(int j=1;j<=q;j++)
        {

            int px,py;
            scanf("%d %d",&py,&px);
            py--,px--;
            if(compo[py][px]!=-1) printf("%d\n",com[compo[py][px]]);
            else
            {
                ans=0;
                com.push_back(dfs(py,px));
                printf("%d\n",com[compo[py][px]]);
                comp++;
            }
        }

    }
    return 0;
}
