class Solution {
public:
    bool checkPowersOfThree(int n) {
        int temp = n, sum = 0;
        long p = 1;

        while (temp) {
            int d = temp % 3;

            if (d == 2)
                return false;

            sum += d * p;
            p = p * 3L;
            temp /= 3;
        }

        return (sum == n);
    }
};
