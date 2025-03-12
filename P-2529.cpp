class Solution {
    public:
        pair<bool, int> bsf(vector<int>& nums, int key) {
            int l = 0, r = nums.size() - 1; 
    
            while (l <= r) {
                int m = l + (r - l) / 2;
                
                if (nums[m] >= key)
                    r = m - 1;
                else
                    l = m + 1;
            }
    
            if (l < nums.size() && nums[l] == key)
                return {true, l};
            else
                return {false, l};
        }
    
        int bsl(vector<int>& nums, int key) {
            int l = 0, r = nums.size() - 1; 
    
            while (l <= r) {
                int m = l + (r - l) / 2;
    
                if (nums[m] <= key)
                    l = m + 1;
                else
                    r = m - 1;
            }
    
            return l;
        }
    
        int maximumCount(vector<int>& nums) {
            auto [flag, idx] = bsf(nums, 0);
    
            if (flag) {
                int len = bsl(nums, 0) - idx;
                return max((int)(nums.size() - idx - len), idx); 
            }
            else
                return max((int)nums.size() - idx, idx); 
        }
    };
    