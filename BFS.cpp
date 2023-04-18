#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class BFS{
    private:
        int n, m;
        vector<vector<int>> adj;
        vector<int> dist;
        queue<int> q;
    public:
        BFS(int n, int m){
            this->n = n;
            this->m = m;
            adj.resize(n);
            dist.resize(n, -1);
        }
        void addEdge(int u, int v){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        void BFSPath(int s){
            q.push(s);
            dist[s] = 0;
            while (!q.empty()){
                int v = q.front();
                q.pop();
                for (int u : adj[v]){
                    if (dist[u] == -1){
                        dist[u] = dist[v] + 1;
                        q.push(u);
                    }
                }
            }
        }
        void printPath(){
            for (int i = 0; i < n; i++){
                cout << dist[i] << " ";
            }
        }
};
int main(){
    int n, m, u, v, s;
    cin >> n >> m;
    BFS bfs(n, m);
    for (int i = 0; i < m; i++){
        cin >> u >> v;
        bfs.addEdge(u, v);
    }
    cin >> s;
    bfs.BFSPath(s);
    bfs.printPath();
    return 0;
}