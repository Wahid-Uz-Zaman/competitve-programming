#include<bits/stdc++.h>
#define mx 10
#define ll  unsigned long long int
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
sqmatrix makeinitial(ll a1,ll b1,ll c1,ll a2,ll b2,ll c2)
{
    sqmatrix t;
    t.sz=6;
    t.m[0][0]=a1;t.m[0][1]=b1;t.m[0][2]=0;t.m[0][3]=0;t.m[0][4]=0;t.m[0][5]=c1;
    t.m[1][0]=1;t.m[1][1]=0;t.m[1][2]=0;t.m[1][3]=0;t.m[1][4]=0;t.m[1][5]=0;
    t.m[2][0]=0;t.m[2][1]=1;t.m[2][2]=0;t.m[2][3]=0;t.m[2][4]=0;t.m[2][5]=0;
    t.m[3][0]=0;t.m[3][1]=0;t.m[3][2]=c2;t.m[3][3]=a2;t.m[3][4]=b2;t.m[3][5]=0;
    t.m[4][0]=0;t.m[4][1]=0;t.m[4][2]=0;t.m[4][3]=1;t.m[4][4]=0;t.m[4][5]=0;
    t.m[5][0]=0;t.m[5][1]=0;t.m[5][2]=0;t.m[5][3]=0;t.m[5][4]=1;t.m[5][5]=0;
    return t;

}

int main()
{
    makeidentity(6);

    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        ll f[3],g[3];
        ll a1,b1,c1,a2,b2,c2,f0,f1,f2,g0,g1,g2,m;
        scanf("%llu%llu%llu%llu%llu%llu%llu%llu%llu%llu%llu%llu%llu",&a1,&b1,&c1,&a2,&b2,&c2,&f0,&f1,&f2,&g0,&g1,&g2,&m);
        mod=m;
        f[0]=f0,f[1]=f1,f[2]=f2;g[0]=g0,g[1]=g1,g[2]=g2;
        //printf("%lld ")




        sqmatrix A=makeinitial(a1,b1,c1,a2,b2,c2);
        int q;
        scanf("%d",&q);
        printf("Case %d:\n",cas);
        for(int i=1;i<=q;i++)
        {
            ll n;
            scanf("%llu",&n);
             if(n<=2){printf("%llu %llu\n",f[n]%mod,g[n]%mod);continue;}
            sqmatrix tp=matrix_expo(A,n-2);
        //printf("infgre");
            //tp.print();
            ll fans=(tp.m[0][0]*f[2]+tp.m[0][1]*f[1]+tp.m[0][2]*f[0]+tp.m[0][3]*g[2]+tp.m[0][4]*g[1]+tp.m[0][5]*g[0])%m;
            ll gans=(tp.m[3][0]*f[2]+tp.m[3][1]*f[1]+tp.m[3][2]*f[0]+tp.m[3][3]*g[2]+tp.m[3][4]*g[1]+tp.m[3][5]*g[0])%m;
            printf("%llu %llu\n",fans,gans);
        }


    }


}
