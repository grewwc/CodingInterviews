#include "pch.h"

#define DEBUG 1

#include "wwc_numerics.h"

using namespace std;


class Solution
{
public:
    void reOrderArray(vector<int> &array)
    {
        int i = 0, j = array.size() - 1;
        while (i < j)
        {
            if (array[i] % 2 == 1)
            {
                i++;
            }
            else if (array[j] % 2 == 0)
            {
                j--;
            }
            else
            {
                swap(array[i++], array[j--]);
            }
        }
    }
};

int main()
{
    Solution s;
    vector<int> array{1, 2, 3, 4, 5, 6, 7};
    s.reOrderArray(array);
    print(array);
}