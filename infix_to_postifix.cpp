#include <iostream>
#include <stack>
#include <string>
using namespace std;
int precedence(char op) 
{
    if (op == '^') return 3;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}
string infixToPostfix(string infix) 
{
    stack<char> s;
    string postfix;
    for (char &c : infix) 
    {
        if (isalnum(c)) 
        {
            postfix += c;
        }
        else if (c == '(') 
        {
            s.push(c);
        } 
        else if (c == ')') 
        {
            while (!s.empty() && s.top() != '(') 
            {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        } 
        else 
        {
            while (!s.empty() && precedence(s.top()) >= precedence(c)) 
            {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    while (!s.empty()) 
    {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}
int main() 
{
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;
    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;
    return 0;
}