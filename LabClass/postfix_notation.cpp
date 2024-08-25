#include<iostream>
#include <stack>
#include <queue>

using namespace std;

//_____________________________ Postfix to infix_____________________________

string solvePostfix_1(queue<string> input_list) {
    stack<string> st;
    while (!input_list.empty()) {
        string token = input_list.front();
        input_list.pop();
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            string operand2 = st.top();
            st.pop();
            string operand1 = st.top();
            st.pop();
            if (token == "+") {
                st.push(to_string(stoi(operand1) + stoi(operand2)));
            } else if (token == "-") {
                st.push(to_string(stoi(operand1) - stoi(operand2)));
            } else if (token == "*") {
                st.push(to_string(stoi(operand1) * stoi(operand2)));
            } else if (token == "/") {
                st.push(to_string(stoi(operand1) / stoi(operand2)));
            }
        } else {
            st.push(token);
        }
    }
    return st.top();
}

//_____________________________ Infix to Postfix _____________________________

int precendenceReturn(string str) {
    switch (str.at(0))
    {
    case '+':
        return 1;
        break;
    case '-':
        return 1;
        break;
    case '*':
        return 2;
        break;
    case '/':
        return 2;
        break;
    case '^':
        return 3;
        break;
    default:
        return 0;
        break;
    }
}

string toPostfix(queue<string> input_list) {
    stack<string> st;
    string postfix = "";
    input_list.push(")");
    while (!input_list.empty()) {
        string token = input_list.front();
        input_list.pop();
        if (token == "+" || token == "-" || token == "*" || token == "/" || token == "^") {
            if (!st.empty() && precendenceReturn(st.top()) > precendenceReturn(token)) {
                postfix += st.top();
                st.pop();
            }
            st.push(token);
        } else if (token == "(") {
            st.push(token);
        } else if (token == ")") {
            while (!st.empty()) {
                if (st.top() == "(") {st.pop(); break;}
                postfix += st.top();
                st.pop();
            }
        } else {
            postfix += token;
        }
    }
    return postfix;
}

//______________________________ Main Function ______________________________

int main() {

    // postfix to infix:
    queue<string> input_list({"5","6","2","+","*","12","4","/","-"});
    cout << solvePostfix_1(input_list) << "\n";

    // infix to postfix:
    queue<string> input({"A","+","(","B","*","C","-","(","D","/","E","^","F",")","*","G",")","*","H"});
    cout << toPostfix(input) << "\n";
    return 0;
}    

