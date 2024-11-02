#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int inf = 1e5;


int main() {
    int nodes, edges;
    cout << "Enter the number of nodes and edges: ";
    cin >> nodes >> edges;

    // Create adjacency list for the graph
    // n+1, 1st node ke 1 diye detect korbo.
    vector<vector<pair<int, int>>> graph(nodes + 1);
    vector<int> dist(nodes + 1, inf);

    // Take edge input in (u, v, w) format
    cout << "Enter the edges (u v w):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); // Since it's an undirected graph
    }

    // Set the source node and initialize its distance to 0
    int source;
    cout << "Enter the source node: ";
    cin >> source;
    dist[source] = 0;

    // Using a set to track nodes with their current shortest distance
    set<pair<int, int>> st; // {distance, node}
    st.insert({0, source});

    // Dijkstra's algorithm
    while (!st.empty()) {
        // Get the node with the smallest distance
        auto top = *(st.begin());
        int nodeDistance = top.first;
        int nodeValue = top.second;
        st.erase(st.begin());

        // Traverse through all neighbors of the current node
        for (auto neighbour : graph[nodeValue]) {
            int adjNode = neighbour.first;
            int edgeWeight = neighbour.second;

            // Relaxation step
            if (nodeDistance + edgeWeight < dist[adjNode]) {

                // If there's a shorter path to adjNode, update the distance
                // Remove old pair if it exists
                if (dist[adjNode] != inf) {
                    st.erase({dist[adjNode], adjNode});
                }
                // update distance:
                dist[adjNode] = nodeDistance + edgeWeight;

                // add new pair
                st.insert({dist[adjNode], adjNode});
            }
        }
    }

    // Output the shortest distances from source to each node
    cout << "Shortest distances from source " << source << ":" << endl;
    for (int i = 0; i < nodes; i++) {
         cout<<dist[i]<<" ";
    }

    return 0;
}



/*

4 5

0 1 5
0 2 8
1 2 9
1 3 2
3 2 6

0

*/