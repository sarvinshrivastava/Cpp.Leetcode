#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <climits>

using namespace std;
using namespace std::chrono;

int longestNiceSubarray(vector<int>& nums) {
    int usedBits = 0, windowStart = 0, maxLength = 0;

    for (int windowEnd = 0; windowEnd < nums.size(); ++windowEnd) {
        while ((usedBits & nums[windowEnd]) != 0) {
            usedBits ^=
                nums[windowStart];
            windowStart++;
        }

        usedBits |= nums[windowEnd];

        maxLength = max(maxLength, windowEnd - windowStart + 1);
    }

    return maxLength;
}

int main () {
    string st;
    cin >> st;
    
    string temp;
    vector<int> nums;
    for (auto ch : st) {
        if (ch == ',') {
            nums.push_back(stoi(temp));
            temp = "";
        }
        else if (ch  >= '0' && ch <= '9')
            temp += ch;
    }

    nums.push_back(stoi(temp));
    
    auto start = high_resolution_clock::now();
    
    int res = longestNiceSubarray(nums);
    
    auto end = high_resolution_clock::now();
    duration<double> elapsed = end - start;

    cout << "Result: " << res << endl;
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;

    return 0;
}