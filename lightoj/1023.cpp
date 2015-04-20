#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
char a[26];
bool taken[26];
int n;
int p;
int count;

void permute(vector<char> result )
{
    if(count==p) return ;
    if(result.size()==n)
    {
        for(int i=0;i<n;i++) printf("%c",result[i]);
        printf("\n");
        count++;

    }
    else
    {
        for(int i=0;i<n;i++)
        {
            if(taken[i]==0) {taken[i]=1;result.push_back(i+65);
            permute(result);
            taken[i]=0;
            result.pop_back();}
        }

    }

}
int main()
{
    for(int i=0;i<26;i++) a[i]=i+65;
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        vector<char> result;
        memset(taken,0,sizeof(taken));
        count=0;

        scanf("%d %d",&n,&p);
        printf("Case %d:\n",i);
        permute(result);
    }
    return 0;
}
