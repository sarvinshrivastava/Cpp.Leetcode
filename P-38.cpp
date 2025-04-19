class Solution
{
public:
    struct st
    {
        int num, freq;
    };

    vector<st> map(string str)
    {
        vector<st> res;

        for (auto c : str)
        {
            if (res.empty() || res.rbegin()->num != c - '0')
                res.push_back({c - '0', 1});
            else
                res.rbegin()->freq++;
        }

        return res;
    }

    string combine(string inp)
    {
        auto res = map(inp);
        string str;

        for (auto [x, y] : res)
            str += to_string(y) + to_string(x);

        // cout << str;
        return str;
    }

    string countAndSay(int n)
    {
        string s = "1";

        for (int i = 1; i < n; ++i)
            s = combine(s);

        return s;
    }
};