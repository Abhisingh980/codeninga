#include <iostream>
#include <map>
using namespace std;
map<int, int> parent;
void make(int node)
{
    parent[node] = node;
}
int find(int node)
{
    if (parent[node] == node)
        return node;
     return parent[node];
}
void union1(int u, int v)
{

if(parent[u]==u&&parent[v]==v){
parent[u]=v;
parent[v]=1;
}
else if(parent[u]==u&&parent[v]==1){
    parent[u]=parent[v];
    parent[v] = 1;
}
else if(parent[v]==v&&parent[u]==1){
    parent[u]=parent[v];
    parent[v] = 1;
}
else{
    parent[u]=parent[v];
    parent[v] = 1;
}
    // int a = find(u);
    // int b = find(v);
    // if (a != b)
    // {
    //     parent[a] = b;
    // }
}
int main()
{
    int n;
    cout << "enter the number of vertices : ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        make(i);
    }
    int m;
    cout << "enter the number of edges : ";
    cin >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        union1(u, v);
    }
    for(auto p:parent){
        cout<<p.first<<" "<<p.second<<endl;
    }
    // count no of different components
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (parent[i] != i&&parent[i]!=1)
        {
            count++;
        }
    }
    cout << "no of different components : " << count << endl;
    return 0;
}