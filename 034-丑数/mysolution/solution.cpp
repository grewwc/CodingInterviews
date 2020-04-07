#include "pch.h"
using namespace std;


class Solution
{
public:
    int GetUglyNumber_Solution(int N)
    {
        vector<int> ugly_numbers(N);
        ugly_numbers[0] = 1;
        int i2=0, i3=0, i5=0;
        for(int i=1; i<N; i++)
        {
            int val = min(ugly_numbers[i5]*5, 
                min(ugly_numbers[i2]*2, ugly_numbers[i3]*3));
            if(val == ugly_numbers[i2]*2)
            {
                i2++;
            }
            if(val == ugly_numbers[i3]*3)
            {
                i3++;
            }
            if(val == ugly_numbers[i5]*5)
            {
                i5++;
            }
            ugly_numbers[i] = val;
        }
        return ugly_numbers.back();
    }
};


int main()
{
    Solution s;
    auto res = s.GetUglyNumber_Solution(10);
    cout << res << endl;
}