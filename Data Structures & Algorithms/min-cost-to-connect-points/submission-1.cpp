class DSU {
public:
    vector<int> par, sz;

    DSU(int n) {
        par.resize(n);
        sz.resize(n, 1);

        for(int i = 0; i < n; i++) par[i] = i;
    }

    int find(int x) {
        if(par[x] == x) return x;

        return par[x] = find(par[x]);
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if(px == py) return;

        if(sz[px] < sz[py]) swap(px, py);
        sz[px] += sz[py];
        par[py] = px;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        vector<array<int, 3>> edges;
        for(int i = 0; i < n; i++) {
            int x1 = points[i][0], y1 = points[i][1];
            for(int j = i + 1; j < n; j++) {
                int x2 = points[j][0], y2 = points[j][1];
                int d = abs(x1 - x2) + abs(y1 - y2);

                edges.push_back({d, i, j});
            }
        }

        DSU dsu(n);
        sort(edges.begin(), edges.end());

        int ans = 0;
        for(auto &it : edges) {
            int d = it[0], u = it[1], v = it[2];

            if(dsu.find(u) != dsu.find(v)) {
                ans += d;
                dsu.unite(u, v);
            } 
        }

        return ans;
    }
};
