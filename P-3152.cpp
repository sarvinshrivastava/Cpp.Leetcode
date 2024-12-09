// class Solution {
// public:
//     bool check(vector <int> nums, int l, int r) {
//         for (int i = l; i < r; ++i) {
//             if (nums[i] % 2 == 0 && nums[i + 1] % 2 == 0) return false;
//             if (nums[i] % 2 != 0 && nums[i + 1] % 2 != 0) return false;
//         }

//         return true;
//     }

//     vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
//         int len = queries.size();

//         vector <bool> res;

//         for (int i = 0; i < len; ++i) {
//             int r = queries[i][1], l = queries[i][0];

//             if (r - l  + 1 >= 2) res.push_back(check(nums, l, r));
//             else res.push_back(true);
//         }

//         return res;
//     }
// };

class Solution {
public:
    vector <bool> isArraySpecial(vector <int>& nums, vector<vector<int>>& q) {
        int len = nums.size();
        vector <int> preArr (len, 0);

        for (int i = 1; i < len; ++i) {
            if (nums[i - 1] % 2 == nums[i] % 2) preArr[i] = preArr[i - 1] + 1;
            else preArr[i] = preArr[i - 1];
        }

        // cout << "=======================" << endl;
        // for (auto a : preArr) cout << a << " ";
        // cout << endl << "=======================" << endl;

        vector <bool> res;
        for (auto x : q) {
            int spCnt = preArr[x[1]] - (x[0] > 0 ? preArr[x[0]] : 0);
            res.push_back(spCnt == 0);
        }

        return res;
    }
};
