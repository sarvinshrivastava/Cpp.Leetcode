class Solution {
public:
    void choose(unordered_map<char, int>& freq, int length, string& current, int& count) {
        if (current.length() == length) {
            count++;
            return;
        }

        for (auto& [ch, f] : freq) {
            if (f > 0) {
                freq[ch]--;
                current.push_back(ch);

                choose(freq, length, current, count);

                freq[ch]++;
                current.pop_back();
            }
        }
    }

    int compute(unordered_map<char, int>& freq, int length) {
        int count = 0;
        string current;
        choose(freq, length, current, count);
        return count;
    }

    int numTilePossibilities(string tiles) {
        unordered_map<char, int> freq;

        for (char t : tiles)
            freq[t]++;

        int sum = 0;

        for (int len = 1; len <= tiles.size(); ++len) {
            sum += compute(freq, len);
        }

        return sum;
    }
};
