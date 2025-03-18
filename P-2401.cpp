#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <climits>

using namespace std;
using namespace std::chrono;

int longestNiceSubarray (vector<int>& nums) {
    int cnt = 0, max = 0, combined = 0;

    combined = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] & combined == 0) {
            cnt++;
            combined |= nums[i];
        }
        else {
            max = (max < cnt) ? cnt : max;
            cnt = 0;
            combined = nums[i];
        }
    }

    // for (auto x : setBitCnt)
    //     cout << x << " ";
    cout << endl << "---------------------------------" << endl;
    max = (max < cnt) ? cnt : max;
    return max;
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