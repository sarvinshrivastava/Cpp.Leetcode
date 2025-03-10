#include <iostream>
#include <vector>
using namespace std;

int numberOfAlternatingGroups(vector<int> &colors, int k)
{
    for (int i = 0; i < k - 1; i++)
        colors.push_back(colors[i]);

    int len = colors.size(), result = 0;
    int l = 0, r = 1;

    while (r < len)
    {
        if (colors[r] == colors[r - 1])
        {
            l = r;
            r++;
            continue;
        }

        r++;

        if (r - l < k)
            continue;

        result++;
        l++;
    }

    return result;
}

int main()
{
    vector<int> colors = {0, 1, 1, 0, 1, 0, 1, 1};
    int k = 3;
    cout << numberOfAlternatingGroups(colors, k) << endl;
    return 0;
}

/*
 c.len + 1 = 8
 r.len = 2
 8 - 2 = 6
*/