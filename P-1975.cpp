class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int len = matrix.size(), cnt = 0, smallestAbsVal = INT_MAX;
        long long sum = 0;

        for (int i = 0; i < len; i++)
            for (int j = 0; j < len; j++)
                if (matrix[i][j] < 0)
                    cnt++;

        for (int i = 0; i < len; i++)
            for (int j = 0; j < len; j++) {
                int temp = abs(matrix[i][j]);
                sum += temp;
                if (smallestAbsVal > temp)
                    smallestAbsVal = temp;
            }

        if (cnt % 2 != 0)
            return sum - 2 * smallestAbsVal;
        else
            return sum;
    }
};
