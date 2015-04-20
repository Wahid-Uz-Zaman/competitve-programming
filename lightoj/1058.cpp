#include<cstdio>
#include<algorithm>
using namespace std;
struct point{
    int x,y;
    bool operator<(const point temp) const
    {
        return ((x<temp.x) ||(x==temp.x && y<temp.y));
    }
    bool operator==(const point temp)const
    {
        return (x==temp.x && y==temp.y);
    }
} ;
int main()
{
    //freopen("in.txt","r",stdin);
 point a[1005],mid[504510];
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {

        int n,m=0;
        scanf("%d",&n);
        for(int j=0;j<n;j++)
            scanf("%d %d",&a[j].x,&a[j].y);

        for(int j=0;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                mid[m].x=a[j].x+a[k].x;
                mid[m].y=a[j].y+a[k].y;
                m++;

            }
        }
        sort(mid,mid+m);
        int x=1,ans=0;
        for(int j=1;j<m;j++)
        {
            if(mid[j]==mid[j-1]) x++;
            else
            {
                ans+=((x*(x-1))>>1);
                x=1;
            }

        }
        printf("Case %d: %d\n",i,ans);

    }
    return 0;
}

