#include<cstdio>
#include<cmath>

using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int n,count=0;
        double ans=1.0;
        scanf("%d",&n);
        for(int j=n-1;j>0;j--)
        {
            ans=ans*j/n;
            if(ans>0.5) {count++;continue;}
            else break;
        }
        printf("Case %d: %d\n",i,count+1);



    }
    return 0;
}
