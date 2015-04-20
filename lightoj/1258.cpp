#include<cstdio>
#include<cstring>
#define mx 1000009

using namespace std;
void compute_prefix_function(char pat[],int prefix[])
{
    int m=strlen(pat);
    prefix[0]=0;
    int k=0;
    for(int q=1;q<m;q++)
    {

        while(k>0 && pat[k]!=pat[q]) k=prefix[k-1];
        if(pat[k]==pat[q]) k++;
        prefix[q]=k;
        //printf("%d %d\n",k,q);
    }
}
int  KMP_matcher(char txt[],char pat[])
{
    int count=0;
    int n=strlen(txt);
    int m=strlen(pat);
    int *prefix=new int [m];
    int *txtpost=new int[n];
    compute_prefix_function(pat,prefix);
    //for(int i=0;i<m;i++) printf("prefix[%d] is %d\n",i,prefix[i]);
    int q=0;
    for(int i=0;i<n;i++)
    {
        while(q>0 && pat[q]!=txt[i]) q=prefix[q-1];
        if(pat[q]==txt[i]) {q++;txtpost[i]=q;}
        if(q==m)
        {
            count++;
            //printf("pattern at %d\n",i-m+1);
            q=prefix[q-1];
        }
    }
    delete[]prefix;
    int ans=txtpost[n-1];
    delete[]txtpost;
    //return count;
    return ans;
}

int main()
{
   //freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        char txt[mx];
        scanf("%s",txt);
        int n=strlen(txt);
        char pat[mx];
        int k=0;
        for(int j=n-1;j>=0;j--) pat[k++]=txt[j];
        pat[k]=0;
        int x=KMP_matcher(txt,pat);
        int ans=x+(n-x)*2;
        printf("Case %d: %d\n",i,ans);
    }
    return 0;

}
