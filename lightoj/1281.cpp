#include<bits/stdc++.h>
#define pb push_back
using namespace std;
struct node
{
  int n;
  int k;
  node(int x,int y)
  {
      n=x,k=y;
  }
};

typedef pair< int, node > pin;
typedef pair< int, int > pii;


/*
Set MAX according to the number of nodes in the graph. Remember,
nodes are numbered from 1 to N. Set INF according to what is the
maximum possible shortest path length going to be in the graph.
This value should match with the default values for d[] array.
*/
const int MAX = 10005;
const int INF = 1000000000;

/*
pair object for graph is assumed to be (node, weight). d[] array
holds the shortest path from the source. It contains INF if not
reachable from the source.
*/
vector< pii > G[MAX][2];
int d[MAX][25];

/*
The dijkstra routine. You can send a target node too along with
the start node.
*/

struct comp {
    bool operator() (const pin &a, const pin &b) {
        return a.first > b.first;
    }
};
void dijkstra(int start,int n,int md) {
    int u, v, i, c, w,k;

    /*
    Instead of a custom comparator struct or class, we can use
    the default comparator class greater<T> defined in quque.h
    */
    priority_queue< pin, vector< pin >, comp > Q;

    /*
    Reset the distance array and set INF as initial value. The
    source node will have weight 0. We push (0, start) in the
    priority queue as well that denotes start node has 0 weight.
    */
    //memset(d, INF, sizeof d);
    for(int i=0;i<n;i++)for(int j=0;j<=md;j++)d[i][j]=INF;

    Q.push(pin(0,node(start,0)));
    d[start][0] = 0;

    /*
    As long as queue is not empty, check each adjacent node of u
    */
    while(!Q.empty()) {

       node ux= Q.top().second; // node
        c = Q.top().first; // node cost so far
        Q.pop(); // remove the top item.
        u=ux.n;
        k=ux.k;
        /*
        We have discarded the visit array as we do not need it.
        If d[u] has already a better value than the currently
        popped node from queue, discard the operation on this node.
        */
        if(d[u][k]< c) continue;

        /*
        In case you have a target node, check if u == target node.
        If yes you can early return d[u] at this point.
        */

        /*
        Traverse the adjacent nodes of u. Remember, for the graph,,
        the pair is assumed to be (node, weight). Can be done as
        you like of course.
        */
        for(i = 0; i < G[u][0].size(); i++) {
            v = G[u][0][i].first; // node
            w = G[u][0][i].second; // edge weight

            /*
            Relax only if it improves the already computed shortest
            path weight.
            */
            if(d[v][k] > d[u][k] + w) {
                d[v][k] = d[u][k] + w;
                Q.push(pin(d[v][k], node(v,k)));
            }
        }
        //
        for(i = 0; i < G[u][1].size(); i++) {
            v = G[u][1][i].first; // node
            w = G[u][1][i].second; // edge weight

            /*
            Relax only if it improves the already computed shortest
            path weight.
            */
            if(k<md){
            if(d[v][k+1] > d[u][k] + w) {
                d[v][k+1] = d[u][k] + w;
                Q.push(pin(d[v][k+1], node(v,k+1)));
            }
            }
        }
        //
    }
}

int main() {

    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {

        int n,m,k,md;
        scanf("%d %d %d %d",&n,&m,&k,&md);
        for(int i=0;i<n;i++)G[i][0].clear(),G[i][1].clear();
        for(int i=0;i<m;i++)
        {
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            G[u][0].pb(pii(v,w));

        }
        for(int i=0;i<k;i++)
        {
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            G[u][1].pb(pii(v,w));

        }
        dijkstra(0,n,md);
        int mn=INF;
        for(int i=0;i<=md;i++)
        {
            if(d[n-1][i]!=INF)mn=min(mn,d[n-1][i]);
        }
        printf("Case %d: ",cas);
        if(mn==INF)printf("Impossible\n");
        else printf("%d\n",mn);


    }
    return 0;
}
