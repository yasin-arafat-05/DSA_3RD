

#include<iostream>
#include<queue>
#include<stack>
#define yasin {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
using namespace std;

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


int main(){
    queue<string> input_list({"5","6","2","+","*","12","4","/","-"});
    postfixToInfix(input_list);
}
