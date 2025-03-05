class Solution {
public:
    long long coloredCells(int n) {
        long long sum = 1;

        while (n > 1) {
            n--;
            sum += 4 * n;
        }

        return sum;
    }
};
