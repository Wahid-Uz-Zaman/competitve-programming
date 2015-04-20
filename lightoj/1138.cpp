#include<cstdio>
#include<cmath>
#include<ctime>
#include<cstdlib>
#define llu unsigned long long

# define num 80000004*5
using namespace std;


int func(int n)
{
    int ans=0,i=1;
    while((n/((int)pow(5,i)))!=0)
    {
        ans+=(n/((int)pow(5,i)));
        i++;

    }
    return ans;
}
int binary_search(int n)
{
    int start=1,end=num,mid=(start+end)/2;
    while(start<=end)
    {
        if(func(mid)==n)
        {


            while(func(mid)==n) mid--;


            return mid+1;}
        else if(func(mid)>n)
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
    return -1;


}
int main()

{


    int t,i;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        int n,j;
        scanf("%d",&n);
        j=binary_search(n);
        if(j==-1) printf("Case %d: impossible\n",i);
        else printf("Case %d: %d\n",i,j);
    }




    return 0;
}
