struct Compare {
    bool operator()(const string& a, const string& b) {
        int len_a = a.size();
        int len_b = b.size();

        return len_a < len_b;
    }
} compare;

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        sort(words.begin(), words.end(), compare);
        int len = words.size();

        vector <string> res;
        for (int i = 0; i < len; ++i) {
            string st = words[i];
            
            for (int j = len - 1; j > i; --j)
                if (words[j].find(st) != string::npos) {
                    res.push_back(st);
                    break;
                }
        }

        return res;
    }
};