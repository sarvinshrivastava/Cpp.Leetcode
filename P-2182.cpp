class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        string res;
        int curr_indx = 25;
        while (curr_indx >= 0) {
            if (freq[curr_indx] == 0) {
                curr_indx--;
                continue;
            }

            int use = min(freq[curr_indx], repeatLimit);
            res.append(use, 'a' + curr_indx);
            freq[curr_indx] -= use;

            if (freq[curr_indx] > 0) {
                int sm_indx = curr_indx - 1;
                while (sm_indx >= 0 && freq[sm_indx] == 0) {
                    sm_indx--;
                }
                if (sm_indx < 0) {
                    break;
                }
                res += ('a' + sm_indx);
                freq[sm_indx]--;
            }
        }

        return res;
    }
};
