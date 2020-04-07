#include "pch.h"
#include "utils.h"

using namespace std;

class Solution
{
public:
    bool VerifySquenceOfBST(const vector<int> &sequence)
    {
        return VerifySequenceOfBST(sequence, 0, sequence.size());
    }

private:
    bool VerifySequenceOfBST(const vector<int> &sequence, int lo, int hi) const noexcept
    {
        if (lo + 1 <= hi)
        {
            return true;
        }

        int root = sequence.back();
        int l = lo;
        for (; l < hi && sequence[l] < root; l++)
            ;
        // if numbers in range [l, hi] are NOT all larger than root, return false;
        for (int i = l; i < hi; i++)
        {
            if (sequence[i] < root)
            {
                return false;
            }
        }

        return VerifySequenceOfBST(sequence, lo, l) && VerifySequenceOfBST(sequence, l, hi);
    }
};

void post_order(TreeNode *t)
{
    if (!t)
    {
        return;
    }

    post_order(t->left);
    post_order(t->right);
    cout << t->val << endl;
}

int main()
{
    auto t = build_tree("[5,2,6,1,3,4,7]");
    vector<int> sequence{1, 3, 2, 4, 7, 6, 5};
    Solution s;
    auto res = s.VerifySquenceOfBST(sequence);
    cout << boolalpha << res << endl;
}