#include "pch.h"

#define DEBUG 1

#include "wwc_numerics.h"

using namespace std;

class Solution
{
public:
    int minNumberInRotateArray(vector<int> rotateArray)
    {
        if (rotateArray.empty())
        {
            throw logic_error("invalid input");
        }
        int lo = 0, hi = rotateArray.size();
        while (lo < hi)
        {
            // print("here", lo, hi);
            if (lo + 1 == hi)
            {
                return rotateArray[lo];
            }

            if (lo + 2 == hi)
            {
                return min(rotateArray[lo], rotateArray[lo + 1]);
            }

            int mid = (hi - lo) / 2 + lo;
            int midVal = rotateArray[mid];
            if (midVal > rotateArray[lo] && midVal < rotateArray[hi - 1])
            {
                return rotateArray[lo];
            }

            if (midVal < rotateArray[lo])
            {
                hi = mid + 1;
            }
            else
            {
                lo = mid;
            }
        }
        return -1;
    }
};

void _rotate(vector<int> &vec)
{
    srand(time(nullptr));
    int idx = rand() % vec.size();
    vector<int> temp(vec.cbegin(), vec.cbegin() + idx);
    copy(vec.cbegin() + idx, vec.cend(), vec.begin());
    copy(temp.cbegin(), temp.cend(), vec.end() - idx);
}

int main()
{
    vector<int> vec = wwc::range<int>(500);
    sort(vec.begin(), vec.end());
    _rotate(vec);

    // vec = {1, 2, 3, 4, 0};
    // print(vec);
    Solution s;
    auto res = s.minNumberInRotateArray(vec);

    print(res);
}