class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();

        int buy = p[0];
        int ans = 0;
        for(int i = 1; i < n; i++) { // consider p[i] as selling price
            ans = max(ans, p[i] - buy);
            buy = min(buy, p[i]);
        }

        return ans;
    }
};
