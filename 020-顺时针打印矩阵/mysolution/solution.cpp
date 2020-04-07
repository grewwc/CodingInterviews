#include "pch.h"


using namespace std;

class Solution
{
public:
    vector<int> printMatrix(vector<vector<int>> matrix)
    {
        vector<int> res;
        int m = matrix.size();
        if(m == 0)
        {
            return res;
        }
        int n = matrix[0].size();
        res.reserve(m*n);
        
        state s {state::ZERO_ROW};
        int level = 0;
        int i=0, j=0;
        for(int count=0; count<m*n; count++)
        {
            res.push_back(matrix[i][j]);
            auto next = get_next(i, j, m, n, s, level);
            i = get<0>(next), j = get<1>(next);
        }
        return res;
    }

private:
    enum class state
    {
        FULL_COL,
        FULL_ROW,
        ZERO_COL,
        ZERO_ROW
    };

    tuple<int, int> get_next(int i, int j, int m, int n, state &s, int& level) const noexcept
    {
        switch (s)
        {
        case state::ZERO_ROW:
            if (j + 1 + level < n)
            {
                return {i, j + 1};
            }
            s = state::FULL_COL;
            return {i + 1, j};

        case state::FULL_COL:
            if(i+level+1<m)
            {
                return {i+1, j};
            }
            s = state::FULL_ROW;
            return {i, j-1};
            
        case state::FULL_ROW:
            if(j > level)
            {
                return {i, j-1};
            }
            s = state::ZERO_COL;
            return {i-1, j};
        case state::ZERO_COL:
            if(i > level + 1)
            {
                return {i-1, j};
            }
            
            s = state::ZERO_ROW;
            level++;
            return {i, j+1};
        }
        return {-1, -1};
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix{
        {1,2,3,4}, 
        {5,6,7,8}, 
        {9,10,11,12},
        {13,14,15,16}
    };
    auto res = s.printMatrix(matrix);
    for_each(res.cbegin(), res.cend(), [](auto i ){cout << i << " ";});
}