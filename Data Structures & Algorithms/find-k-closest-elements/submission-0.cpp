class Solution {
public:
    vector<int> findClosestElements(vector<int>& a, int k, int x) {
        sort(a.begin(), a.end(), [x](int a, int b) {
            int d = abs(a - x) - abs(b - x);
            return d == 0 ? (a < b) : d < 0;
        });

        vector<int> res(a.begin(), a.begin() + k);
        sort(res.begin(), res.end());

        return res;
    }
};