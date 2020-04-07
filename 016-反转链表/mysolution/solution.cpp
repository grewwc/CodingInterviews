#include "pch.h"
#include "utils.h"

using namespace std;


class Solution
{
public:
    ListNode* ReverseList(ListNode* pHead)
    {
        ListNode* reversed_head = new ListNode(0);
        ListNode* cur_head = pHead;
        while(cur_head)
        {
            auto tmp = reversed_head->next;
            reversed_head->next = cur_head;
            auto next = cur_head->next;
            cur_head->next = tmp;
            cur_head = next;
        }
        auto res = reversed_head->next;
        delete reversed_head;
        return res;
    }
};

int main()
{
    Solution s;
    auto l = build_LinkedList("[1,2,3,4,5,6,7]");
    print_LinkedList(l);
    auto r = s.ReverseList(l);
    print_LinkedList(r);
}