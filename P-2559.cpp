class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    bool wanted(const string& str) {
        return isVowel(str.front()) && isVowel(str.back());
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int len = words.size();
        vector<int> prefixSum(len + 1, 0);

        for (int i = 0; i < len; ++i) {
            prefixSum[i + 1] = prefixSum[i] + (wanted(words[i]) ? 1 : 0);
        }

        vector<int> res;
        for (const auto& query : queries) {
            int start = query[0], end = query[1];
            res.push_back(prefixSum[end + 1] - prefixSum[start]);
        }

        return res;
    }
};
