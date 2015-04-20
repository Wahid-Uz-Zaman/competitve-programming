#include<cstdio>
#include<cstring>
#define mx 1000000
using namespace std;
int chnge=0;
int less=0;
bool all_9(char a[])
{
    int i;
    for(i=0;a[i]!=0;i++)
    {
        if(a[i]!='9') break;
    }
    if(a[i]==0) return true;
    return false;
}
void change(char a[])
{
    int len=strlen(a);
    for(int i=0,j=len-1;i<len/2;i++,j--)
    {
        if(a[i]<a[j]) {chnge=1;less=1;}
        else if(a[i]>a[j]){less=0;chnge=1;}

    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        char a[mx];
        scanf("%s",a);
        printf("Case %d: ",i);
        int len=strlen(a);
        if(len==1 && a[0]<'9') printf("%c\n",a[0]+1);
        else if(len==1) printf("11\n");
        else if(all_9(a))
        {
            printf("1");
            for(int j=1;j<len;j++)printf("0");
            printf("1\n");
        }
        else if(len%2)
        {
            chnge=less=0;
                change(a);
            if(a[len/2]<'9')
            {

                if(chnge==0 || less ==1) a[len/2]++;
                for(int j=0;j<=len/2;j++)printf("%c",a[j]);
                for(int j=len/2-1;j>=0;j--) printf("%c",a[j]);
                printf("\n");
            }
            else
            {
                if(chnge==1 && less==0)
                {
                    for(int j=0;j<=len/2;j++)printf("%c",a[j]);
                    for(int j=len/2-1;j>=0;j--) printf("%c",a[j]);
                    printf("\n");
                }
                else
                {
                    for(int j=len/2-1,k=len/2+1;j>=0;j--,k++)
                    {

                         if(a[j]==a[k]&& a[j]=='9') a[j]='0';
                         else if(a[j]<=a[k]){a[j]++;break;}
                    }
                    for(int j=0;j<len/2;j++)printf("%c",a[j]);
                    printf("0");
                    for(int j=len/2-1;j>=0;j--) printf("%c",a[j]);
                    printf("\n");
                }
            }
        }
        else
        {
            chnge=less=0;
            change(a);
            //printf("%d %d\n",chnge,less);
            if(chnge==1 && less==0)
            {
                for(int j=0;j<len/2;j++)printf("%c",a[j]);
                for(int j=len/2-1;j>=0;j--) printf("%c",a[j]);
                printf("\n");
            }
            else
            {
                for(int j=len/2-1,k=len/2;j>=0;j--,k++)
                {

                     if(a[j]=='9'&& a[k]=='9') a[j]='0';
                     else if(a[j]<=a[k]){a[j]++;break;}
                }
                for(int j=0;j<len/2;j++)printf("%c",a[j]);
                for(int j=len/2-1;j>=0;j--) printf("%c",a[j]);
                printf("\n");
            }
        }


    }
    return 0;
}

