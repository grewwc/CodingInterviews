#include "pch.h"
#include "utils.h"

#define DEBUG 1 

#include "wwc_numerics.h"

using namespace std;

class Solution
{
public:
    bool HasSubtree(TreeNode *parent, TreeNode *child)
    {
        if(!parent)
        {
            return false;
        }
        
        if(!child)
        {
            return true;
        }
        if (equals(parent, child))
        {
            return true;
        }

        return HasSubtree(parent->left, child) ||
               HasSubtree(parent->right, child);
    }

public:
    bool equals(TreeNode *t1, TreeNode *t2) const noexcept
    {
        
        if (!t1)
        {
            return t2 == nullptr;
        }
        if (!t2)
        {
            return t1 == nullptr;
        }

        if (t1->val != t2->val)
        {
            return false;
        }

        return equals(t1->left, t2->left) && equals(t1->right, t2->right);
    }
};

int main()
{
    auto t1 = build_tree("[3,2,4,1,0]");
    auto t2 = build_tree("[4]");
    Solution s;
    auto res = s.HasSubtree(t1, t2);
    cout << boolalpha << res << endl;
}