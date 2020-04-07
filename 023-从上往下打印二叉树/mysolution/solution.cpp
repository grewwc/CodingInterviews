#include "pch.h"
#include "utils.h"
// #include <queue>

using namespace std;


class Solution
{
public:
    vector<int> PrintFromTopToBottom(TreeNode *root)
    {
        queue<TreeNode*> q;
        vector<int> res;
        if(!root)
        {
            return res;
        }
        
        q.push(root);
        while(!q.empty())
        {
            auto cur = q.front();
            q.pop();
            res.push_back(cur->val);
            if(cur)
            {
                if(cur->left)
                {
                    q.push(cur->left);
                }
                if(cur->right)
                {
                    q.push(cur->right);
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    auto t = build_tree("[3,4,2,null,null,  1,0]");
    auto res = s.PrintFromTopToBottom(t);
    print_vec(res);
}