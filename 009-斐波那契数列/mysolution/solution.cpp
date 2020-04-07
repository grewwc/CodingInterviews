#include "pch.h"

using namespace std;

class Solution
{
public:
    int Fibonacci(int n)
    {
        if (n <= 1)
        {
            return n;
        }

        return power({1, 1, 1, 0}, n - 1)[0];
    }

private:
    vector<int> power(const vector<int> &val, int n)
    {
        if (n == 0)
        {
            throw invalid_argument("n must be positive");
        }

        if (n == 1)
        {
            return {1, 1, 1, 0};
        }

        vector<int> half = power(val, n / 2);
        if (n % 2 == 0)
        {
            return mat_mul(half, half);
        }

        // n % 2 == 1
        return mat_mul(mat_mul(half, half), val);
    }

    vector<int> mat_mul(const vector<int> &a, const vector<int> &b)
    {
        vector<int> res(a.size());
        res[0] = a[0] * b[0] + a[1] * b[2];
        res[1] = a[0] * b[1] + a[1] * b[3];
        res[2] = a[2] * b[0] + a[3] * b[2];
        res[3] = a[2] * b[1] + a[3] * b[3];
        return res;
    }
};

int main()
{
    Solution s;
    auto res = s.Fibonacci(8);
    cout << res << endl;
}