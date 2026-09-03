class Solution {
public:
    int solve(int i, int j, const string &s, const string &t, vector<vector<int>>& dp) {
        int n = s.length(), m = t.length();
        // base case
        if(j == m) return 1;
        if(i == n) return 0;

        int &ans = dp[i][j];
        if(ans != -1) return ans;

        ans = solve(i + 1, j, s, t, dp);
        if(s[i] == t[j]) ans += solve(i + 1, j + 1, s, t, dp);

        return ans;  
    }

    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(0, 0, s, t, dp);
    }
};
