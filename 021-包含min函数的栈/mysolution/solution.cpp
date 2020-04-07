#include "pch.h"

using namespace std;


class Solution
{
public:
    void push(int val)
    {
        m_Stack.push(val);
        if(m_Min.empty() || val < m_Min.top())
        {
            m_Min.push(val);
        }
        else
        {
            m_Min.push(m_Min.top());
        }
    }
    
    void pop()
    {
        m_Min.pop();
        m_Stack.pop();
    }
    
    int top()
    {
        return m_Stack.top();
    }
    
    int min()
    {
        return m_Min.top();
    }
    
private:
    stack<int> m_Stack;
    stack<int> m_Min;
};


int main()
{
    Solution s;
    s.push(2);
    cout << s.min() << endl;
    
    s.push(1);
    cout << s.min() << endl;
    
    s.push(3);
    cout << s.min() << endl;
}