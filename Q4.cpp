#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct Graph{
    int V,E;
    vector<Edge> edges;

    Graph(int V,int E) : V(V), E(E) {}
};

void addEdge(Graph& graph,int scr, int dest,int cost)
{
    Edge edge= {scr, dest,cost};
    graph.edges.push_back(edge);
}

struct Compare{
    bool operator()(const Edge& e1,const Edge& e2)
    {
        return e1.cost>e2.cost;
    }
};
void findMST(Graph& graph)
{
    int V= graph.V;
    vector<int> parent(V,-1);
    vector<int> key(V, INT_MAX);
    vector<bool> inMST(V,false);

    priority_queue<Edge, vector<Edge>, compare> pq;

    int scr=0;
    kry[src]=0;
    pq.push({src,src,0});

    while(!pq.empty())
    {
        int u=pq.top().dest;
        pq.pop();

        inMST[u]=true;

        for(const Edge& edge : graph.edges){
            int v=edge.dest;
            int cost=edge.cost;

            if(!inMST[v] && cost<key[v]){
                key[v]=cost;
                parent[v]=u;
                pq.push({u,v,cost})
            }
            }

    }
    cout<<"MST"<<endl;
    for(int i=1;i<V;i++)
    {
        cout<<"Edge: "<<parent[i]<<"-"<<i<<endl;
    }
}
int main()
{
    int V=4;
    int E=5;
    Graph graph(V,E);
    
    addEdge(graph,0,1,10);
    addEdge(graph,0,2,6);
    addEdge(graph,0,3,5);
    addEdge(graph,1,3,15);
    addEdge(graph,2,1,4);

    findMST(graph);
    return 0;
}