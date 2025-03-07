class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> prime(right + 1, true);

        prime[0] = false;
        prime[1] = false;

        int k;
        for (int i = 2; i < prime.size(); ++i) {
            k = 2;

            if (prime[i] == true)
                while (i * k <= right) {
                    prime[i * k] = false;
                    k++;
                }
        }

        int least = INT_MAX, lastPrime = -1, a = -1, b = -1;
        for (int i = left; i <= right; ++i) {
            if (prime[i] == true) {
                if (lastPrime == -1) {
                    lastPrime = i;
                    continue;
                }

                if (least > i - lastPrime) {
                    least = i - lastPrime;
                    a = lastPrime;
                    b = i;
                    if (least == 2) break;
                }

                lastPrime = i;
            }
        }

        vector<int> result = {a, b};
        return result;
    }
};
