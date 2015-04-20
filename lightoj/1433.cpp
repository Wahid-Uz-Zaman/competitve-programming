#include<cmath>
# include<cstdio>
#include<ctime>
#define llu unsigned long long


using namespace std;
int main()

{

    //freopen("in.txt","r",stdin);
   //freopen("out.txt", "w", stdout);

    int t,i;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        int ox,oy,ax,ay,bx,by;
        scanf("%d %d %d %d %d %d",&ox,&oy,&ax,&ay,&bx,&by);
        double rad=sqrt((ox-ax)*(ox-ax)+(oy-ay)*(oy-ay));
        if(ax+bx==2*ox && ay+by==2*oy)printf("Case %d: %lf\n",i,rad*M_PI);
       else{

          double sqr_d= (bx-ax)*(bx-ax)+(by-ay)*(by-ay);
            //printf("%lf %lf",rad,sqr_d);
            double theta= 1-(sqr_d/(2*rad*rad));
            //printf("%lf %lf",theta);
            if(rad!=0.0)
            printf("Case %d: %lf\n",i, acos(theta)*rad);
            else printf("Case %d: %lf\n",i,rad);
       }





    }

    return 0;
}
