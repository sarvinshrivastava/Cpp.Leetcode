class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int cnt = 0, preSum = 0, sPreSum = 0;

        for (int i = 0; i < n; i++) {
            preSum += arr[i];
            sPreSum += i;

            if (preSum == sPreSum) {
                cnt++;
            }
        }
        return cnt;
    }
};
