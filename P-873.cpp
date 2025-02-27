// N^2logN
class Solution {
public:
    int search(vector<int>& nums, int key, int low) {
        int i = low, j = nums.size() - 1;

        while (i <= j) {
            int m = i + (j - i) / 2;

            if (nums[m] == key)
                return m;
            else if (nums[m] > key)
                j = m - 1;
            else
                i = m + 1;
        }

        return -1;
    }

    int findLength(vector<int>& nums, int curCnt, int i, int j) {
        int idx = search(nums, nums[i] + nums[j], j + 1);

        while (idx != -1 && idx < nums.size()) {
            i = j;
            j = idx;
            curCnt++;
            idx = search(nums, nums[i] + nums[j], j + 1);
        }

        return curCnt > 2 ? curCnt : 0;
    }

    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size(), maxCnt = 0;

        for (int i = 0; i < n - 1; ++i)
            for (int j = i + 1; j < n; ++j) {
                if (arr[i] + arr[j] > arr[n - 1])
                    break;

                maxCnt = max(findLength(arr, 2, i, j), maxCnt);
            }

        return maxCnt;
    }
};
// N^2
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size(), maxLen = 0;
        unordered_map<int, int> indexMap;
        vector<vector<int>> dp(n, vector<int>(n, 2));

        for (int i = 0; i < n; i++)
            indexMap[arr[i]] = i;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int needed = arr[i] - arr[j];
                if (needed < arr[j] && indexMap.count(needed)) {
                    int k = indexMap[needed];
                    dp[j][i] = dp[k][j] + 1;
                    maxLen = max(maxLen, dp[j][i]);
                }
            }
        }

        return maxLen >= 3 ? maxLen : 0;
    }
};
