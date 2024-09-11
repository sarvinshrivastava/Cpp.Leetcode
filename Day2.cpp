// Solution for 2220

class Solution {
public:
    int minBitFlips(int start, int goal) {
       int op = start ^ goal, counter = 0;

       while (op) {
        counter = (op % 2 == 1) ? counter + 1 : counter + 0;
        op /= 2;
       }

       return counter;
    }
};
