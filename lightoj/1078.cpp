# include<stdio.h>
# include<math.h>

//uva 10127 complete

int main(void)
{
    int t,j;
    scanf("%d",&t);
    for(j=1;j<=t;j++)
    {
        long long int k,d;
        scanf("%lld %lld",&k,&d);


        long long int p,s,i,n;
        i=1;
        s=p=d;
        if(s%k==0)  printf("Case %d: %d\n",j,i);

        else
        {
            for(i=2;;i++)
            {
            p*=10;
            p=p%k;
            s+=p;
            s%=k;
            if(s==0)break;
            }
            printf("Case %d: %d\n",j,i);
        }
    }

}
