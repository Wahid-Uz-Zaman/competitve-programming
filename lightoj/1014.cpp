#include<stdio.h>
#include<math.h>
long int a[1000];
long int b[1000];
int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        long  int p,l,m,n,j=0,k=0,r=0;
        scanf("%ld %ld",&p,&l);
         m=1;
        p=p-l;

        for(;m<=sqrt(p);m++)
        {
            if(!(p%m))
            {

                a[j++]=m;
                if(m*m!=p) b[r++]=p/m;
                k=1;
            }
        }

        if(k==0) printf("Case %d: impossible\n",i);
        else{
            printf("Case %d:",i);
        for(p=0; p<j ;p++)
        {
            if(a[p]>l)
            {
            printf(" %ld",a[p]);
            k=2;
            }
        }
        for(p=r-1;p>=0;p--)
        {
            if(b[p]>l)
            {
            printf(" %ld",b[p]);
            k=2;}
        }
        if(k==2)printf("\n");
        else printf(" impossible\n");
        }

    }
    return 0;

}
