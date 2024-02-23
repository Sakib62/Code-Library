/**	  	 بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 *       Author  :   Sakib62
 *       Created :   Fri__23-Feb-2024__17:46:48
 *       File    :   FurthestNode.cpp
**/

//From a source node, find the furthest node and it's distance.

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
typedef long long ll;

pair <int, int> furthestNode(vector <int> adj[], int nodes, int src) {
    vector <int> dist(nodes+1, 0);
    vector <bool> visited(nodes+1, false);

    stack <int> nodeList;//DFS traversal
    nodeList.push(src);

    while(!nodeList.empty()) {
        int parent = nodeList.top();
        nodeList.pop();
        visited[parent] = true;

        for(auto child : adj[parent]) {
            if(visited[child]) continue;
            dist[child] = dist[parent] + 1;
            nodeList.push(child);
        }
    }
    vector <pair <int, int> > maxDist; // {node, distance}
    for(int i = 1; i <= nodes; i++) {
        maxDist.push_back({i, dist[i]});
    }

    sort(maxDist.begin(), maxDist.end(), [](auto a, auto b) {
        return a.second > b.second;
    });
    return maxDist[0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int nodes, edges;
    cin >> nodes >> edges;
    vector <int> adj[nodes+1];

    for(int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto ans = furthestNode(adj, nodes, 1);//furthest node from node 1
    cout << "Furthest Node : " << ans.first << "\nDistance : " << ans.second << "\n";
}