#include<bits/stdc++.h>
#define mx 2
#define ll  unsigned long long
using namespace std;
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
                 temp.m[i][j]+=(A.m[i][k]*B.m[k][j]);
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
        ll a,b,n;
        scanf("%llu %llu %llu",&a,&b,&n);
        ll n0=2,n1=a;
        if(n<2){printf("Case %d: %llu\n",cas,n==0?n0:n1);continue;}
        sqmatrix A;A.sz=2;
        A.m[0][0]=a;A.m[0][1]=-b;A.m[1][0]=1;A.m[1][1]=0;
        sqmatrix tp=matrix_expo(A,n-1);
        printf("Case %d: %llu\n",cas,tp.m[0][0]*n1+tp.m[0][1]*n0);


    }


}
