// Solution for 1684

class Solution {
public:
    bool check(string key, string val) {
        bool f;
        for (int i = 0; i < val.size(); i++) {
            for (int j = 0; j < key.size(); j++) {
                if(key[j] != val[i])
                    f = false;
                else {
                    f = true;
                    break;
                }
            }
            if(f == false)
                return false;
        }
        return true;
    }

    int countConsistentStrings(string allowed, vector<string>& words) {
        int i = 0, count = 0;
        for (; i < words.size(); i++) {
            if(check(allowed, words[i]) == true) {
                count++;
            }
        }
        return count;
    }
};
