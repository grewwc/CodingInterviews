#include "pch.h"

using namespace std;

class Solution
{
public:
    double Power(double base, int exponent)
    {
        if (exponent == 0)
        {
            return 0;
        }

        if (exponent == 1)
        {
            return base;
        }

        bool negative = exponent < 0 ? true : false;
        exponent = abs(exponent);
        int res = 1;
        while (exponent != 0)
        {
            if ((exponent & 1) == 1)
            {
                res *= base;
            }
            base *= base;
            exponent >>= 1;
        }

        return negative ? 1.0 / res : res;
    }
};

int main()
{
    Solution s;
    
}