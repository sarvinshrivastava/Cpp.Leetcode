#include <iostream>
#include <vector>
#include <unordered_map>
#include <chrono>
#include <string>
#include <algorithm>

using namespace std;
using namespace std::chrono;


vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); ++i)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int left = i + 1, right = nums.size() - 1;
        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0)
            {
                result.push_back({nums[i], nums[left], nums[right]});
                while (left < right && nums[left] == nums[left + 1])
                    left++;
                while (left < right && nums[right] == nums[right - 1])
                    right--;
                left++;
                right--;
            }
            else if (sum < 0)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }

    return result;
}

vector<int> format(string s)
{
    vector<int> intVec;
    string temp;

    for (char ch : s)
    {
        if (ch != '[' && ch != ']' && ch != ',' && ch != ' ')
            temp += ch;
        else if (ch == ',')
        {
            intVec.push_back(stoi(temp));
            temp = "";
        }
    }
    intVec.push_back(stoi(temp));

    return intVec;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;

        vector<int> nums = format(s);

        auto start = high_resolution_clock::now();
        vector<vector<int>> result = threeSum(nums);
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);

        cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
        cout << "Result: " << endl;
        for (auto &i : result)
        {
            for (auto &j : i)
            {
                cout << j << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}