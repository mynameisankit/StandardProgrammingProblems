#include<bits/stdc++.h>

using namespace std;
typedef long long int INT;

class Graph {
    public:
    vector<vector<INT>> adj_list;

    Graph(INT n) {
        adj_list = vector<vector<INT>>(n + 1);
    }

    void addEdge(INT u, INT v, bool bidirectional = false) {
        adj_list[u].push_back(v);

        if(bidirectional) adj_list[v].push_back(u);
    }
};

void preprocess(INT parent, INT src, Graph &g, vector<INT> &subtree_size, vector<INT> &subtree_sum) {
    //Go to all the children
    for(INT i = 0; i < g.adj_list[src].size(); i++) {
        INT children = g.adj_list[src][i];
        
        if(parent == children) continue;
        preprocess(src, children, g, subtree_size, subtree_sum);
        subtree_size[src] += subtree_size[children];
        subtree_sum[src] += subtree_size[children] + subtree_sum[children];
    }

    subtree_size[src] += 1;

    return;
}

void solve(Graph &g, vector<INT> &subtree_sum, vector<INT> &subtree_size, vector<INT> &ans) {
    queue<INT> frontier;
    frontier.push(1);
    ans[1] = subtree_sum[1];

    vector<INT> visited(subtree_sum.size(), false);

    while(!frontier.empty()) {
        INT parent = frontier.front();
        frontier.pop();
        visited[parent] = true;

        //Traverse all the children
        for(INT i =  0; i < g.adj_list[parent].size(); i++) {
            INT children = g.adj_list[parent][i];
            
            if(visited[children]) continue;
            
            frontier.push(children);
            visited[children] = true;
            ans[children] = subtree_sum[children] + (ans[parent] - (subtree_sum[children] + subtree_size[children])) + (subtree_size[1] - subtree_size[children]);
            // cout << children << " : " << subtree_sum[children] << " + (" << ans[parent] << " - ( " << subtree_sum[children] << " + " << subtree_size[children] << " )) + " << " ( " << subtree_size[1] << " - " << subtree_size[children] <<  " ) " << " = " << ans[children] << "\n";
        }
    }

    return;
}

int main() {
    INT n;
    cin >> n;

    Graph g(n);
    
    INT u, v;
    for(INT i = 1; i < n; i++) {
        cin >> u >> v;
        g.addEdge(u, v, true);
    }

    vector<INT> subtree_size(n + 1, 0);
    vector<INT> subtree_sum(n + 1, 0);
    preprocess(-1, 1, g, subtree_size, subtree_sum);

    vector<INT> ans(n + 1, 0);
    solve(g, subtree_sum, subtree_size, ans);
    for(INT i = 1; i < n + 1; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}