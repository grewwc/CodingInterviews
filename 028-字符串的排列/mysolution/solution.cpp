#include "pch.h"

using namespace std;

class Solution
{
public:
    vector<string> Permutation(string str)
    {
        vector<string> res;
        Permutation(str, 0, res);
        sort(res.begin(), res.end());
        return res;
    }

private:
    void Permutation(string str, int begin, vector<string> &res)
    {
        if (str.size() == begin)
        {
            res.push_back(str);
            return;
        }

        for (int i = begin; i < str.size(); i++)
        {
            if (!hasDuplicates(str, begin, i))
            {
                swap(str[i], str[begin]);
                Permutation(str, begin + 1, res);
                swap(str[i], str[begin]);
            }
        }
    }

    bool hasDuplicates(const string &str, int begin, int end) // "end" is including
    {
        for (int i = begin + 1; i <= end; i++)
        {
            if (str[i] == str[begin])
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    string str = "aabc";
    auto res = s.Permutation(str);
    // cout << "size " << res.size() << endl;
    for (auto i : res)
    {
        cout << i << endl;
    }
}