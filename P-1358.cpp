#include <iostream>
#include <vector>
#include <string>
#include <chrono>
using namespace std;
using namespace std::chrono;

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int n = s.size(), result = 0;
        vector<int> count(3, 0);

        int left = 0;

        for (int right = 0; right < n; right++)
        {
            count[s[right] - 'a']++;

            while (count[0] > 0 && count[1] > 0 && count[2] > 0)
            {
                result += n - right;

                count[s[left] - 'a']--;
                left++;
            }
        }

        return result;
    }
};

int main()
{
    Solution obj;
    string inp;
    cin >> inp;

    auto start = high_resolution_clock::now();
    int result = obj.numberOfSubstrings(inp);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Result: " << result << endl;
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;

    return 0;
}