class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pres) {
        vector<vector<int>> adj(n);
        vector<int> indeg(n, 0);

        for(auto &p : pres) {
            int a = p[0], b = p[1];

            indeg[a]++;
            adj[b].push_back(a);
        }

        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(indeg[i] == 0) q.push(i);
        }

        int cnt = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();

            cnt++;

            for(int nei : adj[node]) {
                indeg[nei]--;
                if(indeg[nei] == 0) q.push(nei);
            }
        }

        return cnt == n;
    }
};
