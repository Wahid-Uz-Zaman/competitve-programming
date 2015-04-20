#include<bits/stdc++.h>
#define mx 53//olper jonno berber stack overflow khacche
#define ll  unsigned int
using namespace std;
ll ncr[mx][mx];
void makedp()
{
    ncr[0][0]=1;
    for(int i=1;i<mx;i++)ncr[i][0]=1,ncr[i][i]=1,ncr[i][1]=i;
    for(int i=3;i<mx;i++)
    {
        for(int j=2;j<i;j++)ncr[i][j]=ncr[i-1][j]+ncr[i-1][j-1];
    }


}
struct sqmatrix
{
    int sz;
    ll m[mx][mx];
   // sqmatrix(int x){sz=x;}
    void print()
    {
        for(int i=0;i<sz;i++)
        {
            for(int j=0;j<sz;j++)printf("%d ",m[i][j]);
            printf("\n");
        }

    }

};
int c=0;
 sqmatrix matrix_product(sqmatrix A,sqmatrix B)
 {
     c++;
     int sz=A.sz;
     sqmatrix temp;
     temp.sz=sz;
     for(int i=0;i<sz;i++)
     {
         for(int j=0;j<sz;j++)
         {
             temp.m[i][j]=0;
             for(int k=0;k<sz;k++)
             {
                 temp.m[i][j]=temp.m[i][j]+(A.m[i][k]*B.m[k][j]);
             }

         }

     }
     return temp;


 }
sqmatrix I;
void makeidentity(int k)
{
    I.sz=k+2;
    int sz=k+2;
    for(int i=0;i<sz;i++)for(int j=0;j<sz;j++)I.m[i][j]=0;
    for(int i=0;i<sz;i++)I.m[i][i]=1;

}
sqmatrix matrix_expo(sqmatrix A, long long int p)
{

    sqmatrix ans=I;
    while(p)
    {
        if(p%2)ans=matrix_product(A,ans);
        p=p/2;
        A=matrix_product(A,A);

    }
    return ans;


}
sqmatrix makeinitial(int k)
{
    sqmatrix t;
    t.sz=k+2;
    int  sz=k+2;
    t.m[0][0]=1;
    for(int i=1;i<sz;i++)t.m[0][i]=ncr[k][i-1];
    for(int i=1;i<sz;i++)
    {
        for(int j=0;j<i;j++)t.m[i][j]=0;
        for(int j=i,p=0;j<sz;j++,p++)t.m[i][j]=ncr[k][p];
        k--;
        //printf("%d\n",i);
    }
    return t;

}
int mmm(long long p)
{
    printf("%lld\n",p);
    if(p==1)return 0;
    mmm(p/2);
}
int main()
{
    makedp();

    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        long long int  n;
        int k;
        scanf("%lld %d",&n,&k);
        //printf("%lld ")


        if(n==1){printf("Case %d: 1\n",cas);continue;}
        makeidentity(k);
        sqmatrix A=makeinitial(k);

        sqmatrix tp=matrix_expo(A,n-1);
        //printf("infgre");
        ll ans=0;
        for(int i=0;i<tp.sz;i++)ans+=tp.m[0][i];
        printf("Case %d: %u\n",cas,ans);


    }


}
