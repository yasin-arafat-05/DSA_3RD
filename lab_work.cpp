
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#define yasin {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
using namespace std;



int precidence(string op){
        if(op=="+" || op=="-"){
            return 1;
        }else if(op=="*" || op=="/"){
            return 2;
        }else if(op=="^"){
            return 3;
        }
    return 0;
}

// Function to check if a given string is an operator
bool isOperator(const string &token) {
    return token == "+" || token == "-" || token == "*" || token == "/" || token == "^";
}

//--------------------------------------------- Prefix To Infix -------------------------------
void prefixToInfix(queue<string> input) {
    stack<string> st;
    stack<string> reversedInput;

    // Reverse the input
    while (!input.empty()) {
        reversedInput.push(input.front());
        input.pop();
    }

    // Process reversed prefix expression
    while (!reversedInput.empty()) {
        string token = reversedInput.top();
        reversedInput.pop();

        if (isOperator(token)) {
            if (st.size() < 2) {
                cout << "Error: Invalid prefix expression." << endl;
                return;
            }
            string operand1 = st.top(); st.pop();
            string operand2 = st.top(); st.pop();
            string exp = "(" + operand1 + token + operand2 + ")";
            st.push(exp);
        } else {
            st.push(token);
        }
    }

    // Output the resulting infix expression
    if (st.size() == 1) {
        cout << st.top() << endl;
    } else {
        cout << "Error: Invalid prefix expression." << endl;
    }
}


//--------------------------------------------- Post To Infix -------------------------------
void postfixToInfix(queue<string> input){
    stack<string> st;
    
    while(!input.empty()){
    string token = input.front();
    input.pop();
        if(token=="+" || token=="-" || token=="*" || token=="/"){
            string operator2  = st.top();
            st.pop();
            string operator1 = st.top();
            st.pop();
            string exp = "(" + operator1 + token + operator2 + ")";
            st.push(exp);
        }else{
            st.push(token);
        }
    }
    cout<<st.top()<<endl;
}


//--------------------------------------------- Infix To PostFix -------------------------------
void infixToPostFix(queue<string> input){
    string ans="";
    stack<string> st;
    st.push("(");
    input.push(")");
    while(!input.empty()){
        string token = input.front();
        input.pop();
        if(token=="+" || token=="-" || token=="*" || token=="/" || token=="^" ){
            while(!st.empty() && precidence(st.top())>= precidence(token)){
                ans += st.top() + " ";
                st.pop();
            }
            st.push(token);
        }else if(token==")"){
            while(!st.empty()){
                if (st.top()=="(") break;
                ans += st.top()+" ";
                st.pop();
            }
        }else if(token=="("){
            st.push(token);
        }else{
            ans += token + " ";
        }
    }
    cout<<ans<<endl;
}

int main() {

    // author of the code: 
    yasin

    //----------------- Infix To PostFix ---------------------
    queue<string> inputPostFix({"A","+","(","B","*","C","-","(","D","/","E","^","F",")","*","G",")","*","H"});
    infixToPostFix(inputPostFix);

    //------------------- PostFix To Infix -------------------
    queue<string> input_list({"5","6","2","+","*","12","4","/","-"});
    postfixToInfix(input_list);

   //------------------- Prefix To Infix -------------------
    queue<string> inputPrefix({"-", "*", "+", "5", "6", "2", "/", "12", "4"});
    prefixToInfix(inputPrefix);

    return 0;
}

