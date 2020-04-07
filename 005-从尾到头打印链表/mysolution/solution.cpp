#include <iostream>
#include "utils.h"
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> printListFromTailToHead(struct ListNode *head)
    {
        vector<int> res;
        auto curr = head;
        while (curr)
        {
            res.push_back(curr->val);
            curr = curr->next;
        }

        reverse(res.begin(), res.end());
        return res;
    };
};

int main()
{
    auto root = build_LinkedList("[1,2,3,4,5]");
    Solution s;
    auto res = s.printListFromTailToHead(root);
    print_vec(res);
}