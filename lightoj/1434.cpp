#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#define r 33
#define c 33
using namespace std;
int rn;
int cn;
char s[18];
char dir_map[][4]={"*","U","D","R","L","UL","UR","DL","DR"};
int len;
int x[]={0,0,0,1,-1,-1,1,-1,1};
int y[]={0,-1,1,0,0,-1,-1,1,1};
vector<int>ans;
int tlen;
char a[r][c];
bool wrong[17][r][c];
void  func(int j,int k)
{
   for(int i=0;i<9;i++)
   {
       if(tlen==len) return;
       int jy=y[i]+j;
       int kx=x[i]+k;
        if(!(jy>=0 && jy<rn &&kx>=0 && kx<cn)) continue;
       if(a[jy][kx]==s[tlen]&& wrong[tlen+1][jy][kx]==0)
       {
           ans.push_back(i);
           //printf("%c %s\n",a[jy][kx],dir_map[i]);
           tlen++;

           if(tlen==len) return ;
           func(jy,kx);


       }
   }
   if(tlen==len) return ;
   wrong[tlen][j][k]=1;
   int q=ans.size();
   if(q>0) {ans.pop_back();
   tlen--;}

}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out3.txt","w",stdout);
    int t;
    scanf("%d",&t);

    for(int i=1;i<=t;i++)
    {
        scanf("%d %d",&rn,&cn);

        for(int j=0;j<rn;j++) {scanf("%s",a[j]);}
        int n;
        scanf("%d",&n);
        printf("Case %d:\n",i);
        for(int j=1;j<=n;j++)
        {

            scanf("%s",s);
            memset(wrong,0,sizeof(wrong));
            ans.clear();
            len=strlen(s);
            int tmp=0;
            for(int rx=0;rx<rn;rx++)
            {
                for(int cx=0;cx<cn;cx++)
                {
                    if(a[rx][cx]==s[0] )
                    {
                        tlen=1;
                        //printf("\n\n\n%c %d %d\n",a[rx][cx],rx+1,cx+1);
                        func(rx,cx);
                        if(tlen==len)
                        {
                            printf("%s found: (%d,%d)",s,rx+1,cx+1);
                            for(int m=0;m<ans.size();m++)
                            {
                                printf(", %s",dir_map[ans[m]]);
                            }
                            printf("\n");
                            tmp=1;
                            break;
                        }

                    }
                }
                if(tmp==1) break;
            }
            if(tmp==0) printf("%s not found\n",s);
        }
    }

    return 0;
}
