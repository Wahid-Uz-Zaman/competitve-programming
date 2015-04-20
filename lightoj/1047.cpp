#include<cstdio>
#include<iostream>

#define max 20

using namespace std;
int  min(int temp[])
{
    int min=temp[0];
    for(int i=1;i<3;i++)
    {
        if(min>temp[i]) min=temp[i];
    }
    return min;

}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int cost[max][3],house;

        scanf("\n%d",&house);
        for(int j=0;j<house;j++)
        {
            for(int k=0;k<3;k++) scanf("%d",&cost[j][k]);

        }
        //start
        for(int i=1;i<house;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(j==0)
                {
                    if(cost[i-1][1]<cost[i-1][2]) cost[i][j]+=cost[i-1][1];
                    else cost[i][j]+=cost[i-1][2];
                }
                if(j==1)
                {
                    if(cost[i-1][0]<cost[i-1][2]) cost[i][j]+=cost[i-1][0];
                    else cost[i][j]+=cost[i-1][2];
                }
                if(j==2)
                {
                    if(cost[i-1][0]<cost[i-1][1]) cost[i][j]+=cost[i-1][0];
                    else cost[i][j]+=cost[i-1][1];
                }
            }
        }

        printf("Case %d: %d\n",i,min( cost[house-1]));
    }
    return 0;

}

