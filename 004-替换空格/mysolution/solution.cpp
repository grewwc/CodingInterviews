#include <iostream>
#include <cstring> 
#include <algorithm> 
#include <string>

using namespace std;

class Solution
{
public:
    void replaceSpace(string& str)
    {
        if(str.empty())
        {
            return ;
        }
        
        int numSpace = count(str.cbegin(), str.cend(), ' ');
        int len = str.size();
        int newLen = len + numSpace*2;
        str.resize(newLen);

        for(int i=len-1, j =newLen-1; i>=0; i--)
        {
            if(str[i] == ' ')
            {
                str[j--] = '0', str[j--]='2', str[j--] = '%';
            }
            else
            {
                str[j--] = str[i];
            }
        }
    }
};


int main()
{
    Solution s;
    string str = "We Are Happy";
    s.replaceSpace(str);
    cout << str << endl;
}