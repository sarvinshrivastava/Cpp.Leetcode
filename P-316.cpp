class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> freq;

        for (auto ch : s)
            freq[ch]++;

        vector<bool> isPresent(26, false);
        string result;
        stack<char> mono;

        for (auto ch : s) {
            freq[ch]--;
            if (isPresent[ch - 'a'])
                continue;

            while (!mono.empty() && mono.top() > ch && freq[mono.top()] > 0) {
                isPresent[mono.top() - 'a'] = false;
                mono.pop();
            }

            mono.push(ch);
            isPresent[ch - 'a'] = true;
        }
        while (!mono.empty()) {
            result = mono.top() + result;
            mono.pop();
        }

        return result;
    }
};
