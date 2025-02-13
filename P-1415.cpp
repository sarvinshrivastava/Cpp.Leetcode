class Solution{
public:
    void generate(string str, vector<string>& candidates, int n) {
        if(str.size() == n) {
            candidates.push_back(str);
            return;
        }

        for(char ch='a'; ch<='c'; ch++) {
            if(str.size() > 0 && str.back() == ch) continue;
            generate(str + ch, candidates, n);
        }
    }

    string getHappyString(int n, int k) {
        vector<string> candidates;
        generate("", candidates, n);

        if(k > candidates.size()) return "";
        return candidates[k-1];
    }
};
