// A C++ program to find articulation points in a given undirected graph
#include<iostream>
#include <list>
#define NIL -1
#include<cstdio>
using namespace std;

// A class that represents an undirected graph
class Graph
{
    int V;
    bool *visited;
    int *disc;
    int *low;
    bool *ap;
    int *parent;
    list<int> *adj;    // A dynamic array of adjacency lists
    void APUtil(int v);
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // function to add an edge to graph
    void AP();    // prints articulation points
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V+5];
    visited=new bool[V+5];
    ap=new bool[V+5];
    disc=new int [V+5];
    low=new int [V+5];
    parent=new int[V+5];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);  // Note: the graph is undirected
}

// A recursive function that find articulation points using DFS traversal
// u --> The vertex to be visited next
// visited[] --> keeps tract of visited vertices
// disc[] --> Stores discovery times of visited vertices
// parent[] --> Stores parent vertices in DFS tree
// ap[] --> Store articulation points
void Graph::APUtil(int u)
{
    // A static variable is used for simplicity, we can avoid use of static
    // variable by passing a pointer.
    static int time = 0;

    // Count of children in DFS Tree
    int children = 0;

    // Mark the current node as visited
    visited[u] = true;

    // Initialize discovery time and low value
    disc[u] = low[u] = ++time;

    // Go through all vertices aadjacent to this
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
    {
        int v = *i;  // v is current adjacent of u

        // If v is not visited yet, then make it a child of u
        // in DFS tree and recur for it
        if (!visited[v])
        {
            children++;
            parent[v] = u;
            APUtil(v);

            // Check if the subtree rooted with v has a connection to
            // one of the ancestors of u
            low[u]  = min(low[u], low[v]);

            // u is an articulation point in following cases

            // (1) u is root of DFS tree and has two or more chilren.
            if (parent[u] == NIL && children > 1)
               ap[u] = true;

            // (2) If u is not root and low value of one of its child is more
            // than discovery value of u.
            if (parent[u] != NIL && low[v] >= disc[u])
               ap[u] = true;
        }

        // Update low value of u for parent function calls.
        else if (v != parent[u])
            low[u]  = min(low[u], disc[v]);
    }
}

// The function to do DFS traversal. It uses recursive function APUtil()
void Graph::AP()
{

    // Initialize parent and visited, and ap(articulation point) arrays
    for (int i = 1; i <= V; i++)
    {
        parent[i] = NIL;
        visited[i] = false;
        ap[i] = false;
    }

    // Call the recursive helper function to find articulation points
    // in DFS tree rooted with vertex 'i'
    for (int i = 1; i <= V; i++)
        if (visited[i] == false)
            APUtil(i);
    int cnt=0;
    // Now ap[] contains articulation points, print them
    for (int i = 1; i <= V; i++){
        //printf("%d %d %d\n",i,disc[i],low[i]);
        if (ap[i] == true) cnt++;

    }
    printf(" %d\n",cnt);
}

// Driver program to test above function
int main()
{
    //freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        Graph g(n);
        for(int j=1;j<=m;j++)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            g.addEdge(u,v);
        }
        printf("Case %d:",i);
        g.AP();
    }
    return 0;
}
