#include<bits/stdc++.h>
#define mx 5
#define ll  unsigned long long
using namespace std;
ll mod;
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
 sqmatrix matrix_product(sqmatrix A,sqmatrix B)
 {
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
                 temp.m[i][j]=(temp.m[i][j]+((A.m[i][k]*B.m[k][j])%mod))%mod;
             }

         }

     }
     return temp;


 }
sqmatrix matrix_expo(sqmatrix A,int p)
{
    if(p==1)return A;
    else
    {
        sqmatrix tp=matrix_expo(A,p/2);
        if(p%2)return matrix_product(matrix_product(tp,tp),A);
        else return matrix_product(tp,tp);

    }


}
int main()
{
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        ll a,b,n,c;
        scanf("%llu %llu %llu %llu",&n,&a,&b,&c);
        ll n0=0,n1=0,n2=0;

        mod=10007;
        //printf("%llu %llu %llu %llu %",a,b,n,m);
        if(n<=2){printf("Case %d: %llu\n",cas,0);continue;}
        sqmatrix A;A.sz=4;
        A.m[0][0]=a;A.m[0][1]=0;A.m[0][2]=b;A.m[0][3]=c;
        A.m[1][0]=1;A.m[1][1]=0;A.m[1][2]=0;A.m[1][3]=0;
        A.m[2][0]=0;A.m[2][1]=1;A.m[2][2]=0;A.m[2][3]=0;
        A.m[3][0]=0;A.m[3][1]=0;A.m[3][2]=0;A.m[3][3]=1;
        sqmatrix tp=matrix_expo(A,n-2);
        printf("Case %d: %llu\n",cas,(tp.m[0][3])%mod);


    }


}
