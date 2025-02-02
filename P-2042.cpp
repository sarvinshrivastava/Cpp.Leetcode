class Solution {
public:
    bool areNumbersAscending(string s) {
        istringstream sstream(s);
        vector<string> tokens;
        string word;

        while (getline(sstream, word, ' '))
            tokens.push_back(word);

        int prevNum = -1;
        for (auto t : tokens)
            if (t[0] >= '0' && t[0] <= '9') {
                int curNum = stoi(t);
                if (curNum <= prevNum)
                    return false;
                prevNum = curNum;
            }

        return true;
    }
};
