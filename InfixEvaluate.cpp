#include <iostream>
#include <vector>
#include <map>
#include <bits/stdc++.h>
using namespace std;
int prec(string x)
{
    if (x == "^")
    {
        return 3;
    }
    else if (x == "*" || x == "/")
    {
        return 2;
    }
    else if (x == "+" || x == "-")
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
class MyStack
{
    int lenOstack; //current max_length of stack
    int count;     //count-1 of elements in stack..kind of current index
    string *Stack; //array representing stack

public:
    MyStack()
    {
        Stack = new string[1];
        count = -1;
        lenOstack = 1;
    }
    void push(string item)
    {
        if (count + 1 == lenOstack)
        {
            lenOstack *= 2;
            string *new_arr = new string[lenOstack];
            for (int i = 0; i < count + 1; i++)
            {
                new_arr[i] = Stack[i];
            }
            delete[] Stack;
            Stack = new_arr;
        }
        count++;
        Stack[count] = item;
        //cout<<"count:: "<<count+1<<'\n';
    }
    void pop()
    {
        count--;
        //cout<<"count:: "<<count+1<<'\n';
    }
    string peek()
    {
        if (count == -1)
        {
            cout << "!!! STACK UNDERFLOW !!!" << '\n';
            return "";
        }
        else
        {
            return Stack[count];
        }
    }
    bool empty()
    {
        if (count == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};
vector<string> convert_to_postFix(vector<string> &v)
{
    MyStack st;
    vector<string> postfix;
    string temp;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] != "^" && v[i] != "*" && v[i] != "/" && v[i] != "+" && v[i] != "-" && v[i] != "(" && v[i] != ")")
        {
            postfix.push_back(v[i]);
        }
        else if (v[i] == "(")
        {
            st.push("(");
        }
        else if (v[i] == ")")
        {
            while (!st.empty() && st.peek() != "(")
            {
                postfix.push_back(st.peek());
                st.pop();
            }
            if (st.peek() == "(")
            {
                st.pop();
            }
        }
        else
        {
            while (!st.empty() && prec(v[i]) <= prec(st.peek()) && (st.peek() != "(" || st.peek() != ")"))
            {
                postfix.push_back(st.peek());
                st.pop();
            }
            st.push(v[i]);
        }
    }
    while (!st.empty())
    {
        postfix.push_back(st.peek());
        st.pop();
    }
    return postfix;
}

int evaluate(vector<string> &postfix)
{
    MyStack st;
    int temp;
    int CurrOp;
    for (int i = 0; i < postfix.size(); i++)
    {
        if (postfix[i] == "+" or postfix[i] == "-" or postfix[i] == "*" or postfix[i] == "^" or postfix[i] == "/" or postfix[i] == "%")
        {
            temp = stoi(st.peek());
            st.pop();
            if (postfix[i] == "+")
            {
                CurrOp = stoi(st.peek()) + temp;
            }
            else if (postfix[i] == "-")
            {
                CurrOp = stoi(st.peek()) - temp;
            }
            else if (postfix[i] == "*")
            {
                CurrOp = stoi(st.peek()) * temp;
            }
            else if (postfix[i] == "^")
            {
                CurrOp = pow(stoi(st.peek()), temp);
            }
            else if (postfix[i] == "/")
            {
                if (temp != 0)
                {
                    CurrOp = stoi(st.peek()) / temp;
                }
                else
                {
                    cout << "!!! ZERO DIVISION ERROR !!!" << '\n';
                    return -1;
                }
            }
            else if (postfix[i] == "%")
            {
                if (temp - int(temp) != 0)
                {
                    if (temp != 0)
                    {
                        CurrOp = stoi(st.peek()) % int(temp);
                    }
                    else
                    {
                        cout << "!!! ZERO DIVISION ERROR !!!" << '\n';
                        return -1;
                    }
                }
                else
                {
                    cout << "!!! error: invalid operands of types ‘int’ and ‘double’ to binary ‘operator%’ !!!" << '\n';
                }
            }
            st.pop();
            st.push(to_string(CurrOp));
        }
        else
        {
            st.push(postfix[i]);
        }
    }
    return stoi(st.peek());
}

int main()
{
    map<string, int> prec;
    prec.insert(pair<string, int>("*", 3));
    prec.insert(pair<string, int>("/", 3));
    prec.insert(pair<string, int>("%", 3));
    prec.insert(pair<string, int>("+", 2));
    prec.insert(pair<string, int>("-", 2));
    prec.insert(pair<string, int>("&", 1));
    prec.insert(pair<string, int>("^", 4));
    string input, temp = "";
    vector<string> v;
    cout << "ENTER THE EXPRESSION" << '\n';
    cin >> input;

    for (int i = 0; i < input.length(); i++)
    {
        if (isdigit(input[i]) == true)
        {
            temp += string(1, input[i]);
            //cout << temp << '\n';
        }
        else
        {
            if (temp != "")
                v.push_back(temp);
            v.push_back(string(1, input[i]));
            //cout<<string(1,input[i])<<'\n';
            temp = "";
        }
        //cout<<temp<<"here"<<'\n';
    }
    if (temp.length() != 0)
    {
        v.push_back(temp);
    }
    vector<string> tempo;
    tempo = convert_to_postFix(v);
    cout << "HERE IS THE EASY ANSWER !" << '\n';
    cout << evaluate(tempo) << '\n';
}
