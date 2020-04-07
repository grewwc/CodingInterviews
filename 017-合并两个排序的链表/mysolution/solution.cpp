#include "pch.h"

#include "utils.h"

using namespace std;

class Solution
{
public:
    ListNode *Merge(ListNode *pLeft, ListNode *pRight)
    {
        // don't change pLeft & pRight
        ListNode dummy{0}, *p = &dummy;
        while (pLeft || pRight)
        {
            if (pLeft && pRight)
            {
                if (pLeft->val <= pRight->val)
                {
                    p->next = new ListNode(pLeft->val);
                    pLeft = pLeft->next;
                }
                else
                {
                    p->next = new ListNode(pRight->val);
                    pRight = pRight->next;
                }
            }
            else if (pLeft)
            {
                p->next = new ListNode(pLeft->val);
                pLeft = pLeft->next;
            }
            else
            {
                p->next = new ListNode(pRight->val);
                pRight = pRight->next;
            }
            p = p->next;
        }
        return dummy.next;
    }
};

int main()
{
    auto l1 = build_LinkedList("[1,3,5,7,9]");
    auto l2 = build_LinkedList("[2,4]");
    Solution s;
    auto res = s.Merge(l1, l2);
    print_LinkedList(res);
}