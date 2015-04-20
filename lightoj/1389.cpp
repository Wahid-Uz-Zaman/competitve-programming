#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        char a[105];
        int n,ans=0;
        scanf("%d",&n);
        scanf("%s",a);
        for(int j=0;j<n;j++)
        {
            if(a[j]=='.') {j+=2;ans++;}
        }
        printf("Case %d: %d\n",i,ans);
    }
    return 0;
}
