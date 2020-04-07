#include "pch.h"

using namespace std;

class Solution
{
public:
    int FirstNotRepeatingChar(string str)
    {
        if (str.empty())
        {
            return -1;
        }

        unordered_map<char, pair<int, int>> m;
        for (int i = 0; i < str.size(); i++)
        {
            char ch = str[i];
            if (m.find(ch) == m.cend())
            {
                m[ch].second = i;
            }
            m[ch].first++;
        }
        int res = INT_MAX;
        for (const auto &[ch, p] : m)
        {
            if (p.first == 1)
            {
                res = min(res, p.second);
            }
        }
        return res;
    }
};

int main()
{
}