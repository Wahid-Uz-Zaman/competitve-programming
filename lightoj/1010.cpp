#include<cstdio>
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int a,b,x,ans;
        scanf("%d %d",&a,&b);
        if(a==1 || b==1) printf("Case %d: %d\n",i,a*b);
        else if(a==2 || b==2)
        {
            if(a==2) x=b;
            else x=a;
            ans=(x/4)*4;
            if(x%4<=2) ans=ans+(x%4)*2;
            else ans=ans+4;
            printf("Case %d: %d\n",i,ans);

        }
        else printf("Case %d: %d\n",i,(a*b/2)+((a*b)%2));

    }
    return 0;
}
