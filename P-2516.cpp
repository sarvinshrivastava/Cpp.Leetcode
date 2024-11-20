class Solution {
public:
    int takeCharacters(string s, int k) {
        int len = s.size(), freq[3] = {0};

        int l = 0;
        while (l < len && (freq[0] < k || freq[1] < k || freq[2] < k)) {
            freq[s[l] - 'a']++;
            l++;
        }

        if (freq[0] < k || freq[1] < k || freq[2] < k) return -1;

        int min_len = l, r = len - 1;
        l--;

        while (l >= 0) {
            freq[s[l] - 'a']--;
            l--;

            while (r > l && (freq[0] < k || freq[1] < k || freq[2] < k)) {
                freq[s[r] - 'a']++;
                r--;
            }

            int temp_len = len - 1 - r + l + 1;
            min_len = std::min(min_len, temp_len);
        }

        return min_len;
    }
};
