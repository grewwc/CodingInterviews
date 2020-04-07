#include "pch.h"

#include "utils.h"

using namespace std;

class Solution
{
public:
    vector<vector<int>> FindPath(TreeNode *root, int expectNumber)
    {
        vector<vector<int>> res;
        vector<int> cur;
        FindPath(root, expectNumber, cur, res);
        return res;
    }

private:
    void FindPath(TreeNode *node, int expectNumber,
                  vector<int> &path, vector<vector<int>> &res) const
    {

        if (!node)
        {
            return;
        }

        path.push_back(node->val);

        if (expectNumber == node->val && node->left == nullptr && node->right == nullptr)
        {
            res.push_back(path);
            return;
        }

        FindPath(node->left, expectNumber - node->val, path, res);
        FindPath(node->right, expectNumber - node->val, path, res);
        path.pop_back();
    }
};

int main()
{
    auto t = build_tree("[5,2,6,1,3,4,7]");
    Solution s;
    auto res = s.FindPath(t, 15);
    for (auto e : res)
    {
        print_vec(e);
    }
}