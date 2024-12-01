class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> ans;

        for (int i = 1; i < n; ++i) {
            int temp_i = i, temp_n = n - i;

            auto containsZero = [](int num) {
                while (num > 0) {
                    if (num % 10 == 0) return true;
                    num /= 10;
                }
                return false;
            };

            if (!containsZero(temp_i) && !containsZero(temp_n)) {
                ans.push_back(temp_i);
                ans.push_back(temp_n);
                break;
            }
        }

        return ans;
    }
};
