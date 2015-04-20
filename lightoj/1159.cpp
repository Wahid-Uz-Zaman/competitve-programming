#include<cstdio>
#include<cstring>
#include<algorithm>
#define mx 55
using namespace std;
int lcs[mx][mx][mx];
int lcs_of_3(char a[],char b[],char c[])
{
    int s1=strlen(a);
    int s2=strlen(b);
    int s3=strlen(c);
    for(int i=0;i<=s1;i++)
    {
        for(int j=0;j<=s2;j++) lcs[i][j][0]=0;
    }
    for(int i=0;i<=s2;i++)
    {
        for(int j=0;j<=s3;j++) lcs[0][i][j]=0;
    }
    for(int i=0;i<=s1;i++)
    {
        for(int j=0;j<=s3;j++) lcs[i][0][j]=0;
    }

    //

    for(int i=1;i<=s1;i++)
    {
        for(int j=1;j<=s2;j++)
        {
            for(int k=1;k<=s3;k++)
            {
                if(a[i-1]==b[j-1] && a[i-1]==c[k-1])
                {
                    lcs[i][j][k]=lcs[i-1][j-1][k-1]+1;
                }
                else
                {
                    lcs[i][j][k]=max(lcs[i-1][j][k],lcs[i][j-1][k]);
                    lcs[i][j][k]=max(lcs[i][j][k],lcs[i][j][k-1]);
                }
            }
        }
    }
    return lcs[s1][s2][s3];
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        char a[mx],b[mx],c[mx];
        scanf("%s %s %s",a,b,c);
        printf("Case %d: %d\n",cas,lcs_of_3(a,b,c));
    }
    return 0;
}

