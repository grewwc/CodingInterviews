#include <iostream>
#include <vector>
#include <unordered_map>

#include "utils.h"

using namespace std;

class Solution
{
public:
    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> in)
    {
        for (int i = 0; i < in.size(); i++)
        {
            m[in[i]] = i;
        }
        return reConstructBinaryTree(pre, in, 0, 0, pre.size());
    };

private:
    TreeNode *reConstructBinaryTree(const vector<int> &pre, const vector<int> &in,
                                    int preStart, int inStart, int length)
    {
        if (length <= 0)
        {
            return nullptr;
        }

        TreeNode *root = new TreeNode(pre[preStart]);
        if (length == 1)
        {
            return root;
        }
        // print("here", root->val, length);
        int idx = m[root->val];
        int leftLength = idx - inStart;
        int rightLength = length - leftLength - 1;
        TreeNode *left = reConstructBinaryTree(pre, in, preStart + 1, inStart, leftLength);
        TreeNode *right = reConstructBinaryTree(pre, in, preStart + 1 + leftLength, idx + 1, rightLength);
        root->left = left;
        root->right = right;
        return root;
    }

    unordered_map<int, int> m;
};



int main()
{
    Solution s;
    vector<int> preOrder{1, 2, 4, 7, 3, 5, 6, 8};
    vector<int> midOrder{4, 7, 2, 1, 5, 3, 8, 6};
    auto res = s.reConstructBinaryTree(preOrder, midOrder);
    pre_order(res);
    print();
    in_order(res);
}