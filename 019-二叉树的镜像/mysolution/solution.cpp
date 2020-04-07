#include "utils.h"
#include "pch.h"


using namespace std;

class Solution
{
public:
    void Mirror(TreeNode *pRoot)
    {
        if(!pRoot)
        {
            return;
        }
        
        swap(pRoot->left, pRoot->right);
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
    
    void MirrorPre(TreeNode* pRoot)
    {
        if(!pRoot)
        {
            return;
        }
        
        stack<TreeNode*> st;
        TreeNode* cur = pRoot;
        while(cur || !st.empty())
        {
            while(cur)
            {
                swap(cur->left, cur->right);
                st.push(cur);
                cur = cur->left;
            }
            
            if(!st.empty())
            {
                cur = st.top()->right;
                st.pop();
            }
        }
    }
};

int main()
{
    Solution s;
    auto t = build_tree("[8,6,10,5,7,9,11]");
    s.MirrorPre(t);
    cout << tree_to_string(t) << endl;
}