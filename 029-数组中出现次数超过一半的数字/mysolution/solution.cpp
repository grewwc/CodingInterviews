#include "pch.h"

using namespace std;

class Solution
{
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        if (numbers.empty())
        {
            return 0;
        }
        int count = 1;
        int val = numbers[0];
        for (int i = 1; i < numbers.size(); i++)
        {
            if (val == numbers[i])
            {
                count++;
            }
            else
            {
                count--;
            }

            if (count <= 0)
            {
                val = numbers[i];
                count = 1;
            }
        }

        return val;
    }
};

int main()
{
    Solution s;
    vector<int> vec{1, 2, 2, 3, 3, 3, 2, 3, 3};
    // vec = {5, 5, 2, 2, 3, 3, 5, 5, 5};
    auto res = s.MoreThanHalfNum_Solution(vec);
    cout << res << endl;
}