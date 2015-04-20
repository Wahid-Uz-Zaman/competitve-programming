#include<cstdio>
#include<cstring>
#define mx  65
using namespace std;
long long int ps[mx][mx];

long long int palindrome_subse(char a[])
{
    memset(ps,0,sizeof ps);
    int s1=strlen(a);
    for(int i=0;i<s1;i++) ps[i][i]=1;
    for(int i=0;i<s1-1;i++)
    {
        if(a[i]==a[i+1]) ps[i][i+1]=3;
        else ps[i][i+1]=2;
    }
    for(int l=3;l<=s1;l++)
    {
        for(int i=0;i<=s1-l;i++)
        {
            int end=i+l-1;
            long long int c=0;
            for(int k=i;k<end;k++)
            {
                if(a[k]==a[end])
                {
                    c+=(1+ps[k+1][end-1]);
                }
            }
            ps[i][end]=c+1+ps[i][end-1];
        }
    }
    return ps[0][s1-1];
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        char a[mx];
        scanf("%s",a);
        printf("Case %d: %lld\n",i,palindrome_subse(a));
    }
    return 0;
}
