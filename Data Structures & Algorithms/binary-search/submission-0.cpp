class Solution {
public:
    int search(vector<int>& a, int tar) {
        int n = a.size();

        int lo = 0, hi = n - 1;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if(a[mid] == tar) return mid;
            if(a[mid] < tar) lo = mid + 1;
            else hi = mid - 1;
        }

        return -1;
    }
};
