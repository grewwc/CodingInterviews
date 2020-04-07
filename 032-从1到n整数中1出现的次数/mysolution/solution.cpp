#include "pch.h"
#include "utils.h"

using namespace std;

class Solution
{
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        array<size_t, 33> a;
        a[1] = 1;
        for (int i = 2; i <= 32; i++)
        {
            a[i] = 9 * a[i - 1] + pow(10, i - 1);
        }

        int rank = get_rank(n);
        int res = 0;
        for (int i = 1; i < rank; i++)
        {
            res += a[i];
        }

        int right_most_digit = n / pow(10, rank - 1);
        res += (right_most_digit - 1) * a[rank - 1];
        // 在考虑 right_most_digit == 1
        if (right_most_digit == 1)
        {
            res += n - right_most_digit * pow(10, rank - 1) + 1;
        }
        else
        {
            res += pow(10, rank - 1);
        }
        return res;
    }

public:
    int get_rank(int n) const noexcept
    {
        int res = 0;
        while (n > 0)
        {
            res++;
            n /= 10;
        }
        return res;
    }
    
};



int main()
{
    Solution s;
    auto res = s.NumberOf1Between1AndN_Solution(1010);
    cout << res << endl;
}