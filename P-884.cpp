class Solution {
public:
    map<string,int> m;

    void simple_tokenizer(string s) {
        stringstream ss(s);
        string word;

        while (ss >> word) {
            m[word] += 1;
        }
    }

    vector<string> uncommonFromSentences(string s1, string s2) {
        simple_tokenizer(s1);
        simple_tokenizer(s2);

        vector<string> res;

        for (auto& x:m) {
            if(x.second == 1) {
                res.push_back(x.first);
            }
        }

        return res;
    }
};
