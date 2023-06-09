#include <iostream>
#include <map>
#include <queue>
#include <list>
using namespace std;
template <typename T>
class BFS
{
    map<T, list<T>> ver;

public:
    void addEdge(int x, int y)
    {
        ver[x].push_back(y);
        ver[y].push_back(x);
    }
    void Bfs(T src)
    {
        queue<T> q;
        map<T, int> visite;
        //un waited graph
        q.push(src);
        visite[src] = true;
        while (!q.empty())
        {
            T node = q.front();
            cout << node << " ";
            q.pop();
            for (auto nbr : ver[node])
            {
                if (!visite[nbr])
                {
                    q.push(nbr);
                    visite[nbr] = true;//mark as visited
                }
            }
        }
    }
};
int main()
{
    BFS<int> g;
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
            cout<<"edge vertices srpreade by space : ";
            cin >> x >> y;
            g.addEdge(x, y);
            break;
        case 2:
            int z;
           cout<<" enter the source node : ";
           cin>>z;
            g.Bfs(z);
            cout<<endl;
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