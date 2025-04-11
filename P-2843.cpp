class Solution
{
public:
    int countSymmetricIntegers(int low, int high)
    {
        int cnt = 0;

        for (int i = low; i <= high; ++i)
        {
            string temp = to_string(i);

            if (temp.size() & 1 == 1)
                continue;

            int n = temp.size() / 2, sumL = 0, sumR = 0;
            for (int j = 0; j < temp.size(); ++j)
            {
                if (j < n)
                    sumL += temp[j] - '0';
                else
                    sumR += temp[j] - '0';
            }

            if (sumL == sumR)
                cnt++;
        }

        return cnt;
    }
};