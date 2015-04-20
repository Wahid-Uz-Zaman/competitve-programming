#include<cmath>
# include<cstdio>
#define llu unsigned long long
using namespace std;
llu a[20];

llu fact(int n)
{
    if(n==2) a[n]=2;
    else
    {
        a[n]= n*fact(n-1);
       // return a[n];

    }
    return a[n];
}
int fact_search(llu x,int end)
{
    int start=0,mid=(start+end)/2;
    while(start<end)
    {
        if(a[mid]==x) return mid;
        else if(a[mid]>x)
        {
            end=mid-1;
            mid=(start+end)/2;
        }
        else
        {   start=mid+1;
            mid=(start+end)/2;
        }
    }
    if(a[start]<=x) return start;
    else return start-1;

}
int main()
{
    a[0]=a[1]=1;
    fact(19);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        llu n;
        scanf("%llu",&n);
        int temp[20];
        int end=19,j=0;
        while(end!=0)
        {
            end=fact_search(n,end);
            //printf("%d\n",end);
            temp[j++]=end;
            n=n-a[end];
            if(n==0) break;
            end--;
        }
        if(n==0)
        {
            printf("Case %d: ",i);
            for(int k=j-1;k>0;k--) printf("%d!+",temp[k]);
            printf("%d!\n",temp[0]);
        }
        else if((n- a[0])==0)
        {
            printf("Case %d: 0!",i);
            for(int k=j-1;k>=0;k--) printf("+%d!",temp[k]);
            printf("\n");
        }
        else printf("Case %d: impossible\n",i);


    }


    return 0;
}
