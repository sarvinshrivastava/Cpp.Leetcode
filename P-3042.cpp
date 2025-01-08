class Solution {
public:
    bool isPrefixAndSuffix(string a, string b) {
        int alen = a.size(), blen = b.size();
        if (alen > blen) return false;

        if (b.compare(0, alen, a) != 0) return false;

        if (alen != blen)
            if (b.compare(blen - alen, alen, a) != 0)
                return false;

        return true;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int cnt = 0, len = words.size();

        for (int i = 0; i < len; ++i)
            for (int j = i + 1; j < len; ++j)
                if (isPrefixAndSuffix(words[i], words[j]) == true)
                    ++cnt;

        return cnt;
    }
};
