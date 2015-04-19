#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        char a[13];
        int j,k,size;
        scanf("%s",&a);
        for(j=0;a[j];j++);
        size=j;
        j--;
        for( k=0;k<=size/2;k++)
        {
            if(a[k]==a[j]) j--;
            else break;
        }
        if(k>size/2) printf("Case %d: Yes\n",i);
        else printf("Case %d: No\n",i);

    }
    return 0;
}
