#include<cstdio>
#include<deque>
#include<cstring>
#include<cstdlib>

#include<algorithm>
#define pl "pushLeft"
#define pr "pushRight"
#define popl "popLeft"
#define popr "popRight"



using namespace std;
deque<int>deq;
int n;
void func(char a[],int x)
{
    if(x==1001)
    {
        if(!strcmp(a,popl))
        {
            if(deq.size()==0) printf("The queue is empty\n");
            else
            {
                printf("Popped from left: %d\n",deq[0]);
                deq.pop_front();
            }
        }
        else
        {
            if(deq.size()==0) printf("The queue is empty\n");
            else
            {
                printf("Popped from right: %d\n",deq[deq.size()-1]);
                deq.pop_back();
            }
        }
    }
    else
    {
        if(!strcmp(a,pl))
        {
            //printf("%d %d\n",deq.size(),n);
            if(deq.size()==n) printf("The queue is full\n");
            else
            {
                deq.push_front(x);
                printf("Pushed in left: %d\n",x);
            }
        }
        else
        {
            if(deq.size()==n) printf("The queue is full\n");
            else
            {
                deq.push_back(x);
                printf("Pushed in right: %d\n",x);
            }
        }
    }
}
int main ()
{
    //freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        deq.clear();
        int m;
        scanf("%d %d",&n,&m);
        printf("Case %d:\n",i);
        for(int j=1;j<=m;j++)
        {
            char a[30];
            int p=1001;
            scanf("%s",a);
            if((!strcmp(a,pl)) ||(!strcmp(a,pr)) ) scanf("%d",&p);
            func(a,p);
        }
    }
    return 0;
}
