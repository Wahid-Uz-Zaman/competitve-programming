#include<cstdio>
#include<cstring>
#include<algorithm>
#define mx 100010
using namespace std;
int LIS[mx];
int Lis(int a[],int n)//a array of original sequence,n size..0-n-1
{
    int L=0;
    int M[mx],P[mx];//LIS[n];//M[i]=index of smallest value a[k] with which lis length is i;
    //p[i]=index of a[j] where lis with last element a[i] and then a[j] second last
    //LIS[i]=length of lis for 0-i;
    for(int i=0;i<n;i++)
    {
        int lo=1,hi=L;
        while(lo<=hi)
        {
            int mid=(lo+hi)>>1;
            if(a[M[mid]]<a[i]) lo=mid+1;
            else hi=mid-1;
        }
        int newL=lo;
        LIS[i]=newL;
        P[i]=M[newL-1];
        if(newL>L)
        {
            L=newL;
            M[L]=i;
        }
        else if(a[i]<a[M[newL]]) M[newL]=i;

    }

    /*int S[L];//longest increaisng sequence array
    int k=M[L];
    for(int i=L-1;i>=0;i--)
    {
        S[i]=a[k];
        k=P[k];
    }
    for(int i=0;i<L;i++)printf("%d ",S[i]);
    printf("\n");
    return L;
    */

}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("a.txt","w",stdout);
    int n,t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d",&n);
        int a[mx],b[mx];
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        for(int i=n-1,j=0;i>=0;i--,j++) b[i]=a[j];
        Lis(a,n);
        //for(int i=0;i<n;i++)printf("%d %d\n",a[i],LIS[i]);
        for(int i=0;i<n;i++)a[i]=LIS[i];

        Lis(b,n);
        //printf("ok\n");//okk
        //for(int i=0,j=n-1;i<n;i++,j--)printf("%d %d\n",b[i],LIS[i]);
        for(int i=0,j=n-1;i<n;i++,j--)b[i]=LIS[j];
        int ans=0;
        for(int i=0;i<n;i++)
        {
            //if(a[i]==b[i])
            //{
                //printf()
                int x=min(a[i],b[i])*2-1;//crucial aspect suppose lis1 4 but lis2 3 then we can take 3
                if(x>ans) ans=x;
            //}
        }
        printf("Case %d: %d\n",cas,ans);



    }
    return 0;
}
