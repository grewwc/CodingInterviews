#include "pch.h"
#define DEBUG 1
#include "wwc_numerics.h"

using namespace std;

class Solution
{
public:
    int NumberOf1(int n)
    {
        int count = 0;
        unsigned int bit = 1U;
        for (int i = 0; i < sizeof(n) * 8; i++)
        {
            if ((bit & n) != 0)
            {
                count++;
            }
            bit <<= 1;
        }
        return count;
    }
};

int test(int val)
{
    return bitset<32>(val).count();
}

int main()
{
    Solution s;
    vector<int> vec{3, 4, 5, 1};
    vector<int> res;
    vector<int> compare;
    transform(vec.cbegin(), vec.cend(), back_inserter(res), [&s](int val) {
        return s.NumberOf1(val);
    });
    
    transform(vec.cbegin(), vec.cend(), back_inserter(compare), [&s](int val) {
        return test(val);
    });
    
    print(res);
    print(compare);

}