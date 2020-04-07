#include "pch.h"

using namespace std;

class Solution
{
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV)
    {
        if (pushV.empty())
        {
            return true;
        }

        stack<int> st;
        int push = 0, pop = 0;
        for (; push < pushV.size() && pop < popV.size();)
        {
            while (!st.empty() && st.top() == popV[pop])
            {
                st.pop();
                pop++;
            }
            st.push(pushV[push++]);
        }

        while (!st.empty() && st.top() == popV[pop])
        {
            st.pop();
            pop++;
        }

        return st.empty();
    }
};

int main()
{
    Solution s;
    vector<int> pushV{1, 2, 3, 4, 5};
    vector<int> popV{4, 5, 3, 2, 1};
    popV = {4,3,5,1,2};
    cout << boolalpha << s.IsPopOrder(pushV, popV) << endl;
}