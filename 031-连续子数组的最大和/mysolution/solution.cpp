#include "pch.h"

using namespace std;

class Solution
{
public:
    int FindGreatestSumOfSubArray(vector<int> array)
    {
        int prev_max = INT_MIN;
        int res = INT_MIN;
        for (int i = 0; i < array.size(); i++)
        {
            int cur_max = max(prev_max + array[i], array[i]);
            prev_max = cur_max;
            res = max(cur_max, res);
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> array{6, -3, -2, 7, -15, 1, 2, 2};
    auto res = s.FindGreatestSumOfSubArray(array);
    cout << res << endl;
}