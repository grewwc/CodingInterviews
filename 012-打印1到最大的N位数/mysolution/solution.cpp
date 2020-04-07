#include "pch.h"

using namespace std;

class Solution
{
public:
    void Print(int n)
    {
        Number number{n};
        while(number.size() <= n)
        {
            cout << number << endl;
            ++number;
        }
    }

public:
    struct Number
    {
        explicit Number(int N)
        {
            m_Number.reserve(N);
        }

        Number& operator++();

        int size() const 
        {
            return m_Number.size();
        }
        
        friend ostream &operator<<(ostream &os, const Number &num)
        {
            os << num.m_Number;
            return os;
        }
        
    
    private:
        string m_Number{"0"};
        int idx = 0;
    };
};

Solution::Number& Solution::Number::operator++()
{
    int carry = 1;
    for (int i = m_Number.size() - 1; i >= 0; i--)
    {
        char val = m_Number[i] + (char)carry;
        if (val > '9')
        {
            m_Number[i] = '0';
            carry = 1;
        }
        else
        {
            m_Number[i] = val;
            carry = 0;
            return *this;
        }
    }

    if (carry == 1)
    {
        m_Number = '1' + string(m_Number.size(), '0');
    }
    return *this;
}

int main()
{
    Solution s;
    s.Print(3);
}