class Solution {
public:
    struct sorter {
        bool operator() (string& a,string& b) { return (a.size()<b.size()); }
    } mysorter;
    
    string longestCommonPrefix(vector<string>& strs) {
        sort (strs.begin(), strs.end(), mysorter);

        string prefix = strs[0];

        for (auto s : strs) {
            int i;

            for (i = prefix.size(); i >= 1; --i) {
                if (prefix.compare(s.substr(0, i)) == 0)
                    break;
                
                prefix.pop_back();
            }

            if (i == 0) return "";
        }

        return prefix;
    }
};