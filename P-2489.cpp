class Solution {
public:
    bool isSet(int x, int bit) { return x & (1 << bit); }

    void setBit(int &x, int bit) { x |= (1 << bit); }

    void unsetBit(int &x, int bit) { x &= ~(1 << bit); }

    int minimizeXor(int num1, int num2) {
        int res = num1;

        int tgt = __builtin_popcount(num2);
        int set = __builtin_popcount(res);

        int cur = 0;

        while (set < tgt) {
            if (!isSet(res, cur)) {
                setBit(res, cur);
                set++;
            }
            cur++;
        }

        while (set > tgt) {
            if (isSet(res, cur)) {
                unsetBit(res, cur);
                set--;
            }
            cur++;
        }

        return res;
    }
};
