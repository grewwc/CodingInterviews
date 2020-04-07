#include <iostream>
#include <stack> 
#include <bitset>
#include <memory>

using namespace std;

class Myqueue
{
public:
    void push(int val)
    {
        st1.push(val);
    }
    
    int pop()
    {
        while(!st1.empty())
        {
            int top = st1.top();
            st1.pop() ;
            st2.push(top);
        }
        int res = st2.top();
        st2.pop();
        return res;
    }
    
private:
    stack<int> st1, st2;
};



int main()
{
    Myqueue q;
    q.push(1), q.push(2);
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    q.push(3), q.push(4);
    cout << q.pop() << endl;
    cout << q.pop() << endl;
}