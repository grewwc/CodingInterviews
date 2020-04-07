#include "pch.h"

using namespace std;

struct RandomListNode
{
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x)
        : label(x), next(NULL), random(NULL)
    {
    }
};


class Solution
{
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        unordered_map<RandomListNode*, RandomListNode*> m;
        RandomListNode* newHead = nullptr, *preNode = nullptr;
        RandomListNode* p = pHead;
        while(p)
        {
            if(newHead == nullptr)
            {
                newHead = new RandomListNode(p->label);
                preNode = newHead;
            }
            else
            {
                auto newNode = new RandomListNode(p->label);
                preNode->next = newNode;
                preNode = newNode;
            }
            
            m[preNode] = p->random;
            p = p->next;
        }
        
        p = newHead;
        while(p)
        {
            if(m.find(p) != m.cend())
            {
                p->random = new RandomListNode(m[p]->random->label);
            }
            p = p->next;
        }
        return newHead;
    }
};

int main()
{
    
}