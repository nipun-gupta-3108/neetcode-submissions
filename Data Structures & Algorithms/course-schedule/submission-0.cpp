class Solution {
public:
    bool dfs(int u, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis) {
        vis[u] = 1;
        pathVis[u] = 1;

        for(int v : adj[u]) {
            // neighbour is already in current dfs path
            if(pathVis[v]) return true;

            // not visited yet
            if(!vis[v]) {
                if(dfs(v, adj, vis, pathVis)) return true;
            }
        }

        // backtrack, remove from current dfs path
        pathVis[u] = 0;
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& pres) {
        vector<vector<int>> adj(n);
        for(auto &p : pres) {
            int a = p[0], b = p[1];

            adj[b].push_back(a);
        }

        vector<int> vis(n, 0), pathVis(n, 0);
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                if(dfs(i, adj, vis, pathVis)) return false;
            }
        }

        return true;
    }
};
