#include <iostream> 
#include <vector> 


using namespace std;


class Solution
{
public:
    bool Find(const vector<vector<int>>& array, int target)
    {
        if(array.empty())
        {
            return false;
        }    
        const int m = array.size();
        const int n = array[0].size();
        for(int i=0, j=n-1; i<n&&j>=0; )
        {
            if(array[i][j] == target)
            {
                return true;
            }
            if(array[i][j] > target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return false;
    }
};
