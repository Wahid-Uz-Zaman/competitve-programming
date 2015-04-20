#include<cstdio>
#include<cstring>
using namespace std;
char a[26];
char b[26];
int main()
{
    //freopen("in.txt","r",stdin);
    int t;
    scanf("%d\n",&t);
    for(int i=1;i<=t;i++)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        char u[102],v[102];
        gets(u);
        gets(v);
       // printf("%s %s\n",u,v);
        int c=0;
        for(int j=0;u[j]!=0;j++)
        {
            if(u[j]!=' ')
            {
                if(u[j]>90) u[j]=u[j]-32;
                a[u[j]-65]++;
                c++;
            }
        }
        for(int j=0;v[j]!=0;j++)
        {
            if(v[j]!=' ')
            {
                if(v[j]>90) v[j]=v[j]-32;
                b[v[j]-65]++;
                c--;
            }
        }
        if(c!=0) printf("Case %d: No\n",i);
        else
        {
            int j;
            for( j=0;j<26;j++)
            {
                if(a[j]!=b[j]) break;
            }
            if(j==26) printf("Case %d: Yes\n",i);
            else printf("Case %d: No\n",i);
        }


    }
}
