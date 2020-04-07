#include "pch.h"
#include "utils.h"

#define DEBUG 1
#include "wwc_numerics.h"
using namespace std;

class Solution
{
public:
    vector<int> GetLeastNumbers_Solution(vector<int> numbers, int k)
    {
        vector<int> res;
        res.reserve(k);
        GetLeastNumbers_Solution(numbers, k, 0, numbers.size() - 1);
        copy(numbers.cbegin(), numbers.cbegin() + k, back_inserter(res));
        return res;
    }

    int partition(vector<int> &numbers, int begin, int end) // end is included
    {
        const int pivot = numbers[end];
        int i=begin-1, j = begin;
        while(j <= end)
        {
            if(numbers[j]<pivot)
            {
                swap(numbers[++i], numbers[j++]);
            }
            else
            {
                j++;
            }
        }
        swap(numbers[i+1], numbers[end]);
        return i + 1;
    }

    void GetLeastNumbers_Solution(vector<int> &numbers, int k,
                                  int begin, int end)
    {
        int idx = partition(numbers, begin, end);
        int smaller_num = idx - begin + 1;
        if(smaller_num == k)
        {
            return;
        }
        
        if(smaller_num > k)
        {
            GetLeastNumbers_Solution(numbers, k, begin, idx-1);
        }
        else
        {
            GetLeastNumbers_Solution(numbers, k-smaller_num, idx+1, end);
        }
    }
};

int main()
{
    Solution s;
    constexpr int N = 10;
    auto vec = wwc::rand_vec<int>(N, 0, 100, time(NULL));
    auto vec_copy = vec;
    sort(vec_copy.begin(), vec_copy.end());

    srand(time(NULL));
    int k = rand() % N;
    auto res = s.GetLeastNumbers_Solution(vec, k);

    print_vec(res);
    print_vec(vec_copy);

}