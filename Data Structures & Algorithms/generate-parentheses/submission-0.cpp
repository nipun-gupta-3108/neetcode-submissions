class Solution {
public:
    bool isValid(const string& s) {
        int open = 0;
        for(char c : s) {
            open += (c == '(' ? 1 : -1);
            if(open < 0) return false;
        }

        return open == 0;
    }

    void solve(string s, int n, vector<string>& ans) {
        if(s.length() == 2 * n) {
            if(isValid(s)) ans.push_back(s);
            return;
        }

        solve(s + '(', n, ans);
        solve(s + ')', n, ans);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        solve("", n, ans);
        return ans;
    }
};
