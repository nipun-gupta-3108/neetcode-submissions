class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), n1 = t.size();

        vector<int> freq1(128, 0), freq2(128, 0);
        for(char c : t) freq1[c]++;

        int start = 0, m = n + 1;
        int l = 0, cnt = 0;
        for(int r = 0; r < n; r++) {
            freq2[s[r]]++;
            if(freq2[s[r]] <= freq1[s[r]]) cnt++;

            while(cnt == n1) {
                int len = r - l + 1;
                if(len < m) {
                    start = l;
                    m = len;
                }

                freq2[s[l]]--;
                if(freq2[s[l]] < freq1[s[l]]) cnt--;

                l++;
            }
        }

        return m == n + 1 ? "" : s.substr(start, m);
    }
};
