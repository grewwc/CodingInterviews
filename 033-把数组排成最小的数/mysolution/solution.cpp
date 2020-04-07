#include "pch.h"

using namespace std;

class Solution
{
public:
    string PrintMinNumber(vector<int> numbers)
    {
        string res;
        auto get_rank = [](int n) {
            int res = 0;
            while (n > 0)
            {
                res++;
                n /= 10;
            }
            return res;
        };

        sort(numbers.begin(), numbers.end(), [&get_rank](int a, int b) {
            int r1 = get_rank(a);
            int r2 = get_rank(b);
            long long concat1 = r1 * pow(10, r2 - 1) + r2;
            long long concat2 = r2 * pow(10, r1 - 1) + r1;
            return concat1 < concat2;
        });

        for (const int i : numbers)
        {
            res += to_string(i);
        }

        return res;
    }
};

int main()
{
    Solution s;
    vector<int> vec{3, 32, 321};
    auto res = s.PrintMinNumber(vec);
    cout << res << endl;
}