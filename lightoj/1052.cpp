#include<bits/stdc++.h>
#define mx 10
#define ll  long long int
using namespace std;
ll mod=1000000007;
ll fa;
ll fb;
ll gcd(ll x,ll y)
{
    if(y==0)return x;
    else return gcd(y,x%y);
}

void eq_solver(ll aa[][3])
{
   ll det=aa[0][0]*aa[1][1]-aa[1][0]*aa[0][1];
   if(det==0) {fa=-1,fb=-1;return;}
   ll xx=aa[0][2]*aa[1][1]-aa[1][2]*aa[0][1];

   ll yy=aa[0][0]*aa[1][2]-aa[1][0]*aa[0][2];
   if(gcd(xx,det)==gcd(yy,det))
   {
       fa=xx/det;fb=yy/det;
       if(fa==0 && fb==0){fa=-1,fb=-1;return;}
       if(fa>=0 && fb>=0)return;

   }
    fa=-1;fb=-1;return;
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
                 temp.m[i][j]=(temp.m[i][j]+(A.m[i][k]*B.m[k][j])%mod)%mod;
             }

         }

     }
     return temp;


 }
sqmatrix I;
void makeidentity(int k)
{
    I.sz=k;
    int sz=k;
    for(int i=0;i<sz;i++)for(int j=0;j<sz;j++)I.m[i][j]=0;
    for(int i=0;i<sz;i++)I.m[i][i]=1;

}
sqmatrix matrix_expo(sqmatrix A, ll p)
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
sqmatrix makeinitial()
{
    sqmatrix t;
    t.sz=2;
    t.m[0][0]=0;t.m[0][1]=1;
    t.m[1][0]=1;t.m[1][1]=1;

    return t;

}

int main()
{
    makeidentity(2);
    sqmatrix A=makeinitial();

    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        ll n,x,m,y,k;
        ll X[2][3];
        scanf("%lld %lld %lld %lld %lld",&n,&x,&m,&y,&k);
        int i=0;
        if(n==1){X[i][0]=1;X[i][1]=1;}
        else
        {
            sqmatrix tp=matrix_expo(A,n-1);
            X[i][0]=tp.m[0][0]+tp.m[1][0];
            X[i][1]=tp.m[0][1]+tp.m[1][1];

        }
        X[i][2]=x;i++;
        if(m==1){X[i][0]=1;X[i][1]=1;}
        else
        {
            sqmatrix tp=matrix_expo(A,m-1);
            X[i][0]=tp.m[0][0]+tp.m[1][0];
            X[i][1]=tp.m[0][1]+tp.m[1][1];
        }
        X[i][2]=y;
        printf("Case %d: ",cas);
        eq_solver(X);
        if(fa==-1 && fb==-1)printf("Impossible\n");
        else
        {
            if(k==1)printf("%lld\n",(fa+fb)%mod);
            else
            {
                sqmatrix tp=matrix_expo(A,k-1);
                ll ans=(tp.m[0][0]+tp.m[1][0])*fa+(tp.m[0][1]+tp.m[1][1])*fb;
                ans=ans%mod;
                printf("%lld\n",ans);
            }

        }
    }

    return 0;
}
