class Solution
{
public:
    struct st
    {
        char ch;
        int freq;
    };

    int compress(vector<char> &chars)
    {
        vector<st> res;
        for (auto c : chars)
        {
            if (res.empty() || res.rbegin()->ch != c)
                res.push_back({c, 1});
            else
                res.rbegin()->freq++;
        }

        chars.clear();
        for (auto [x, y] : res)
        {
            chars.push_back(x);
            if (y > 1)
            {
                string s = to_string(y);
                for (char ch : s)
                    chars.push_back(ch);
            }
        }

        return chars.size();
    }
};