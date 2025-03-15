#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    bool canRobWithCapability(vector<int>& nums, int k, int capability) {
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] <= capability) {
                count++;
                i++;  // Skip the adjacent house
            }
            if (count >= k) return true;
        }
        return false;
    }

    int minCapability(vector<int>& nums, int k) {
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canRobWithCapability(nums, k, mid)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return result;
    }
};

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int k;
        string str;
        cin >> str >> k;

        vector<int> nums;
        for (auto c : str)
            if (c >= '0' && c <= '9')
                nums.push_back(c - '0');

        // Debug: Print the input vector
        cout << "Input vector: ";
        for (int num : nums)
            cout << num << " ";
        cout << endl;

        Solution sol;
        auto start = high_resolution_clock::now();
        int result = sol.minCapability(nums, k);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        cout << "Result: " << result << endl;
        cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    }

    return 0;
}