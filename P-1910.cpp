class Solution {
public:
    string removeOccurrences(string s, string part) {
        int len = part.size();

        while (s.find(part) != string::npos) {
            int pos = s.find(part);
            s.erase(pos, len);
        }

        return s;
    }
};
