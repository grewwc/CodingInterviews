#include "pch.h"

#include "utils.h"

class Solution
{
public:
    // edge cases are a little bit tricky
    ListNode *FindKthToTail(ListNode *pListHead, unsigned int k)
    {
        ListNode *p = pListHead, *q = pListHead;
        // move p k steps first
        int count = 0;
        while (count < k - 1 && q)
        {
            q = q->next;
            count++;
        }

        if (count != k - 1) // pListHead don't have k nodes
        {
            return nullptr;
        }

        while (q && q->next)
        {
            cout << "what " << endl;
            p = p->next;
            q = q->next;
        }
        return q ? p : nullptr;
    }
};

int main()
{
    Solution s;
    auto l = build_LinkedList("[1,2,3,4,5]");
    cout << s.FindKthToTail(l, 6)->val << endl;
}