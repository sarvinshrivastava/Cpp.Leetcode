class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int len = arr.size();

        for (int i = 0; i < len; ++i)
            for (int j = i + 1; j < len; ++j) {
                if (arr[i] == arr[j] * 2) return true;
                else if (arr[j] == arr[i] * 2) return true;
            }

        return false;
    }
};
