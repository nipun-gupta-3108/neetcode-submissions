class Solution {
public:
    vector<int> findClosestElements(vector<int>& a, int k, int x) {
        int i = 0, j = a.size() - 1;
        while(j - i >= k) {
            if(abs(x - a[i]) <= abs(x - a[j])) j--;
            else i++;
        }

        return vector<int>(a.begin() + i, a.begin() + j + 1);
    }
};