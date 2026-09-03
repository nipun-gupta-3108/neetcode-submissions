class Solution {
public:
    vector<int> findClosestElements(vector<int>& a, int k, int x) {
        int n = a.size();

        int idx = lower_bound(a.begin(), a.end(), x) - a.begin();

        int i = idx - 1, j = idx;
        vector<int> ans;
        while(j - i - 1 < k) {
            if(i < 0) ans.push_back(a[j++]);
            else if(j >= n) ans.push_back(a[i--]);
            else if(x - a[i] <= a[j] - x) ans.push_back(a[i--]);
            else ans.push_back(a[j++]);
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};