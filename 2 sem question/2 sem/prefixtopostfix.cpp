#include <iostream>
#include <stack>
using namespace std;

int checkPrecedence(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '^')
        return 3;
    else if (ch == '(')
        return 4;
    else
        return -1;
}

bool isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return true;
    else
        return false;
}

void infixToPostfix(string q, string &p)
{
    stack<char> st;
    st.push('(');
    q += ')';

    for (int i = 0; i < q.length(); i++)
    {
        char ch = q[i];

        if (isOperator(ch))
        {
            while (!st.empty() && st.top() != '(' && checkPrecedence(st.top()) >= checkPrecedence(ch))
            {
                // if(checkPrecedence(st.top()) >= checkPrecedence(ch)){
                p += st.top();

                st.pop();
            }
            st.push(ch);
        }

        else if (ch == '(')
        {
            st.push(ch);
        }

        else if (ch == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                p += st.top();
                st.pop();
            }
            st.pop();
        }

        else
        {
            p += ch;
        }
    }

    while (!st.empty())
    {
        p += st.top();
        st.pop();
    }
}

int main()
{
    string q = "(c-d)*(e*f+g)+(h)";
    string p = "";
    infixToPostfix(q, p);
    cout << p;
}