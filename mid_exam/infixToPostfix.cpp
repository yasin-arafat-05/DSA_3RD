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

void postfix(queue<string> input){
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
    queue<string> input({"A","+","(","B","*","C","-","(","D","/","E","^","F",")","*","G",")","*","H"});
    postfix(input);
    return 0;
}
