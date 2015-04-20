#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
bool primes[1005];
int a[168];
vector<int>div[1005];
int cost[1005];

void seive()
{
    int j,k=0;
    for(j=2;j<1005;j++)
    {
        if(primes[j]==0)
        {
            a[k++]=j;
            for(int s=j*2;s<1005;s+=j)
            {
                primes[s]=1;
                div[s].push_back(j);
            }
        }
    }


}

int BFS(int n,int m,int cost[])
{
    queue<int> q;
    q.push(n);
    cost[n]=0;
    while(!q.empty())
    {
        int p=q.front();
        for(int i=0;i<div[p].size();i++)
        {
            int temp=p+div[p][i];
            if(cost[temp]==-1)
        //if(cost[p]+1 <cost[temp])
            {
                cost[temp]=cost[p]+1;
                //printf("%d %d\n ",temp,cost[temp]);
                if(temp<m) q.push(temp);
            }

        }
        q.pop();
    }
    return cost[m];
}

int main()
{
    seive();
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        if(m==n) printf("Case %d: 0\n",i);
        else if(m<n || primes[n]==0) printf("Case %d: -1\n",i);
        else
        {

            memset(cost,-1,sizeof(cost));
            //int cost[1005];
            //for(int p=0;p<1005;p++) cost[p]=100000;
            int k=BFS(n,m,cost);
            if(k==-1) printf("Case %d: -1\n",i);
            else printf("Case %d: %d\n",i,k);


        }

    }
    return 0;
}
