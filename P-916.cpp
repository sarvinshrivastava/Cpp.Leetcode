class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        int bmax[26] = {0};
        for (const auto& b : B) {
            int bCount[26] = {0};
            for (char c : b) {
                bCount[c - 'a']++;
            }
            for (int i = 0; i < 26; ++i) {
                bmax[i] = std::max(bmax[i], bCount[i]);
            }
        }

        vector<string> ans;
        for (const auto& a : A) {
            int aCount[26] = {0};
            for (char c : a) {
                aCount[c - 'a']++;
            }
            bool found = true;
            for (int i = 0; i < 26; ++i) {
                if (aCount[i] < bmax[i]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                ans.push_back(a);
            }
        }

        return ans;
    }

    int* count(const std::string& S) {
        int ans[26] = {0};
        for (char c : S) {
            ans[c - 'a']++;
        }
        return ans;
    }
};
