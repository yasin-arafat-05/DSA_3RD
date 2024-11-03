


#include<iostream>
#include<queue>
#include<stack>
#include<string>
#include<algorithm>

using namespace std;



// --------------------- quick sort -------------

int partion(int arr[],int s, int e){
    int left,right,loc;
    left = s;
    loc = s;
    right = e;
    while(true){

        // handle right part: 
        while(arr[loc]<arr[right] && right!=loc){
            right--;
        }
        if(loc==right) return loc;
        if(arr[loc] > arr[right]){
            swap(arr[loc],arr[right]);
        }
        loc = right;

        // handle left par: 
        while(arr[loc]>arr[left] && right!=loc){
            left++;
        }
        if(loc==left) return loc;
        if(arr[loc] < arr[left]){
            swap(arr[loc],arr[left]);
        }
        loc = left;

    }
}

void quickSort(int arr[],int s,int e){

    if(s>=e){
        return ;
    }

    int p = partion(arr,s,e);
    
    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);
}


//--------------------Tower of Hanoi ------------------

void Hanoi(int n,string BEG,string AUX,string END){
    if(n==1){
        cout<<BEG<<" -> "<<END<<endl;
        return ;
    }
    Hanoi(n-1,BEG,END,AUX);
    cout<<BEG<<" -> "<<END<<endl;
    Hanoi(n-1,AUX,BEG,END);
}

//----------------------- infix to postfix: ---------------

int precidence(string token ){
   if(token=="+" || token=="-"){
    return 1;
   }else if(token=="*" || token == "/"){
    return 2;
   }else if(token=="^"){
    return 3;
   }
   return 0;
}

void toPostfix(queue<string> input){
    stack<string> st;
    string ans = "";
    st.push("(");
    input.push(")");

    while(!input.empty()){
        string token = input.front();
        input.pop();
        if(token=="+" || token=="-" || token=="*" || token=="/" || token=="^"){
            if(!st.empty() && precidence(token) < precidence(st.top())){
                string k = st.top();
                st.pop();
                ans += k + " ";
            }
            st.push(token);
        }else if(token=="("){
            st.push(token);
        }else if(token==")"){
            while(!st.empty()){
                if(st.top() == "("){st.pop(); break;}
                ans +=st.top() + " ";
                st.pop();
            }
        }else{
            ans += token + " ";
        }
    }

    cout<<ans<<endl;

}


//-------------------------  postfix to infix:---------------
void solvePostfix_1(queue<string> input_list){
    stack<string> st;
    while(!input_list.empty()){
        string token = input_list.front();
        input_list.pop();

        if(token=="+" || token=="-" || token == "/" || token=="*"){
            string operand2 = st.top();
            st.pop();
            string operand1 = st.top();
            st.pop();

            if(token=="+"){
                // stoi -> string to integer: 
               int ans = stoi(operand1) + stoi(operand2);
               st.push(to_string(ans));
            }else if(token=="-"){
                int ans = stoi(operand1) - stoi(operand2);
               st.push(to_string(ans));
            }else if(token=="*"){
                int ans = stoi(operand1) * stoi(operand2);
                st.push(to_string(ans));
            }else if(token=="/"){
                int ans = stoi(operand1) / stoi(operand2);
                st.push(to_string(ans));
            }
        }else{
            st.push(token);
        }

    }
    cout<<st.top()<<endl;
}


//______________________________ Main Function ______________________________

int main() {
    
    cout<<endl;
    // postfix to infix:
    queue<string> input_list({"5","6","2","+","*","12","4","/","-"});
    solvePostfix_1(input_list);
    


    cout<<endl;
    // infix to postfix:
    queue<string> input({"A","+","(","B","*","C","-","(","D","/","E","^","F",")","*","G",")","*","H"});
    toPostfix(input);
    

    cout<<endl;
    cout<<endl;
    // quick sort:
    int arr[5] = {13,15,2,3,5};
    int size = 5;
    int s = 0,e = size-1;
    quickSort(arr,s,e);

    // print 
    for (int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    

    cout<<endl;
    cout<<endl;
    //tower of hanoi:
    Hanoi(4,"A","B","C");
} 



