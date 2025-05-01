class Solution
{
public:
    bool canAssign(int k, const vector<int> &tasks, const vector<int> &workers, int pills, int strength)
    {

        multiset<int> ms(workers.end() - k, workers.end());
        int pillsLeft = pills;

        for (int i = k - 1; i >= 0; --i)
        {
            int t = tasks[i];

            auto itStrong = prev(ms.end());
            if (*itStrong >= t)
                ms.erase(itStrong);
            else if (pillsLeft > 0)
            {
                auto it = ms.lower_bound(t - strength);

                if (it == ms.end())
                    return false;

                ms.erase(it);
                --pillsLeft;
            }
            else
                return false;
        }

        return true;
    }

    int maxTaskAssign(vector<int> &tasks, vector<int> &workers, int pills, int strength)
    {
        int L = 0, R = min((int)tasks.size(), (int)workers.size()), ans = 0;

        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        while (L <= R)
        {
            int mid = L + (R - L) / 2;

            if (canAssign(mid, tasks, workers, pills, strength))
            {
                ans = mid;
                L = mid + 1;
            }
            else
                R = mid - 1;
        }
        return ans;
    }
};
