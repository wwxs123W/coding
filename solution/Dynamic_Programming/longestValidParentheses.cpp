#include<iostream>
#include <vector>
#include<stack>
using namespace std;

int longestvalid(string s){
    int n=s.size();
    stack<int> stk;
    stk.push(-1);
    int ans=0;

    for(int i=0;i<n;i++){
        if(s[i]=='('){
            stk.push(i);
        }else{
            stk.pop();
            if(stk.empty()){
                stk.push(i);
            }else{
                ans=max(ans,i-stk.top());
            }
        }
    }

    cout<<ans;
    return ans;
}

int main(){
    string s;
    cin>>s;
    longestvalid(s);
}