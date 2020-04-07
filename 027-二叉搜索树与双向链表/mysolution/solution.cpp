#include "pch.h"
#include "utils.h"

using namespace std;

class Solution
{
public:
    TreeNode *Convert(TreeNode *pRootOfTree)
    {
        auto mid = ConvertRecurse(pRootOfTree);
        while (mid && mid->left)
        {
            mid = mid->left;
        }
        return mid;
    }

private:
    TreeNode *ConvertRecurse(TreeNode *pRootOfTree)
    {
        if (!pRootOfTree)
        {
            return nullptr;
        }

        TreeNode *pre = ConvertRecurse(pRootOfTree->left);
        TreeNode *post = ConvertRecurse(pRootOfTree->right);

        while (pre && pre->right)
        {
            pre = pre->right;
        }

        while (post && post->left)
        {
            post = post->left;
        }

        pRootOfTree->left = pre;
        pRootOfTree->right = post;

        if (pre)
        {
            pre->right = pRootOfTree;
        }

        if (post)
        {
            post->left = pRootOfTree;
        }
        
        return pRootOfTree;
    }
};

int main()
{
    auto t = build_tree("[5,2,7,1,3,6,9]");
    // t = build_tree("[5,1,6]");
    Solution s;
    auto res = s.Convert(t);
    while(res)
    {
        cout << res->val << endl;
        res = res->right;
    }
}