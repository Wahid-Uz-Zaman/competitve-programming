#include<cstdio>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int ax,ay,bx,by,cx,cy;
        scanf("%d %d %d %d %d %d",&ax,&ay,&bx,&by,&cx,&cy);
        int a=(ax-bx)*(by-cy)-(bx-cx)*(ay-by);
        if(a<0) a=-a;
        printf("Case %d: %d %d %d\n",i,ax+cx-bx,ay+cy-by,a);
    }
    return 0;
}
