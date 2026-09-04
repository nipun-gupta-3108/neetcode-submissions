class Solution {
public:
    bool check(int k, vector<int>& piles, int h) {
        long long cnt = 0;
        for(int pile : piles) {
            cnt += (pile + k - 1) / k;
        }

        return cnt <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1, hi = *max_element(piles.begin(), piles.end());
        while(lo < hi) {
            int m = lo + (hi - lo) / 2;

            if(check(m, piles, h)) hi = m;
            else lo = m + 1;
        }

        return lo;
    }
};
