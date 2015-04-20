#include<cmath>
# include<cstdio>
#include<ctime>
#define llu unsigned long long
#define max_point 100000
#define max_Seg 50000
int p[max_point];
int start[max_Seg];
int end[max_Seg];
int point_size,seg_size;
void input()
{
    for(int i=0;i<point_size;i++)
    {
        scanf("%d",&p[i]);
    }
    for(int i=0;i<seg_size;i++)
    {
        scanf("%d %d",&start[i],&end[i]);
    }
}





int endbinary_search(int k)
{
    int start=0,end=point_size-1,mid=(start+end)/2;
    while(start<end)
    {
        if(p[mid]==k) return mid;
        else if(p[mid]>k)
        {
            end=mid-1;
            mid=(start+end)/2;
        }
        else
        {
            start=mid+1;
             mid=(start+end)/2;
        }

    }

    if(p[start]<=k) return start;
    else return start-1;


}
int startbinary_search(int k)
{
    int start=0,end=point_size-1,mid=(start+end)/2;
    while(start<end)
    {
        if(p[mid]==k) return mid;
        else if(p[mid]>k)
        {
            end=mid-1;
            mid=(start+end)/2;
        }
        else
        {
            start=mid+1;
             mid=(start+end)/2;
        }

    }

    if(p[start]>=k) return start;
    else return start+1;


}
int main()

{

    //freopen("in.txt","r",stdin);
    //freopen("out.txt", "w", stdout);

    int t,i;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {

        scanf("%d %d",&point_size,&seg_size);
        input();
        for(int j=0;j<seg_size;j++)
        {
            int m=startbinary_search(start[j]);
            //printf("%d",m);
            int n=endbinary_search(end[j]);
            //printf("%d\n",n);

            start[j]=n-m+1;

        }
        printf("Case %d:\n",i);
        for(int j=0;j<seg_size;j++)
        {
           printf("%d\n",start[j]);
        }

    }


    return 0;
}
