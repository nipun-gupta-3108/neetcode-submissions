class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        unordered_map<int, vector<pair<int, int>>> adj;
        for(int i = 0; i < n; i++) {
            int x1 = points[i][0], y1 = points[i][1];
            for(int j = i + 1; j < n; j++) {
                int x2 = points[j][0], y2 = points[j][1];
                int d = abs(x1 - x2) + abs(y1 - y2);

                adj[i].push_back({d, j});
                adj[j].push_back({d, i});
            }
        }

        unordered_set<int> vis;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});

        int ans = 0;
        while(!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            int u = cur.second;
            int dist = cur.first;
            
            if(vis.count(u)) continue;

            vis.insert(u);
            ans += dist;

            for(const auto &nei : adj[u]) {
                int d = nei.first;
                int v = nei.second;

                if(!vis.count(v)) {
                    pq.push({d, v});
                }
            }
        }

        return ans;
    }
};
