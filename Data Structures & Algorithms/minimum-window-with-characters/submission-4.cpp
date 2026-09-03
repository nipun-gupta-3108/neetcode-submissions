class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), n1 = t.size();

        vector<int> freq1(128, 0), freq2(128, 0);
        for(char c : t) freq1[c]++;

        int start = 0, m = n + 1;
        int l = 0;
        for(int r = 0; r < n; r++) {
            freq2[s[r]]++;

            while(true) {
                // check whether current window is valid
                bool isValid = true;
                for(int i = 0; i < 128; i++) {
                    if(freq2[i] < freq1[i]) {
                        isValid = false;
                        break;
                    }
                }

                if(!isValid) break;

                // curr wind valid
                int len = r - l + 1;
                if(len < m) {
                    start = l;
                    m = len;
                }

                // shrink from left
                freq2[s[l]]--;
                l++;
            }
        }

        return m == n + 1 ? "" : s.substr(start, m);
    }
};
