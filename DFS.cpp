#include <iostream>
#include <map>
#include <list>
using namespace std;
template <typename T>
class DFS
{
    map<T, list<T>> ver;

public:
    void addEdge(int x, int y)
    {
        ver[x].push_back(y);
        ver[y].push_back(x);
    }
    void dfshelper(T src,map<T,bool>&visite){
         cout<<src<<" ";
         visite[src]=true;
         for(T nbr:ver[src]){
            if(!visite[nbr]){
                dfshelper(nbr,visite);
            }
         }
    }
    void Dfs(T src)
    {
        map<T, bool> visite;
        for(auto p:ver){
            T node=p.first;
            visite[node]=false;
        }
   //call functio 
   dfshelper(src,visite); 
    }
};
int main()
{
    DFS<int> g;
    while (1)
    {
        cout << "1.Enter the edge: " << endl;
        cout << "2.BFS: " << endl;
        cout << "3.Exit: " << endl;
        int ch;
        cin >> ch;
        switch (ch)
        {
        case 1:
            int x, y;
            cout << "edge vertices srpreade by space : ";
            cin >> x >> y;
            g.addEdge(x, y);
            break;
        case 2:
            int z;
            cout << " enter the source node : ";
            cin >> z;
            g.Dfs(z);
            cout << endl;
            break;
        case 3:
            exit(0);
            break;
        default:
            cout << "Enter the valid choice: " << endl;
            break;
        }
    }
    // g.addEdge(0, 1);
    // g.addEdge(1, 2);
    // g.addEdge(2, 3);
    // g.addEdge(3, 4);
    // g.addEdge(4, 5);

    // g.Bfs(0);
    // cout << endl;
    return 0;
}
