#include<iostream>
#include <utility>
#include<vector>
#include<map>
using namespace std;

vector<string> digit={
    "",
    "",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"
};

vector<string> ans;
string path;
void backtracking(string digit_num,int index){

    cout<<path<<endl;
    if(index==digit_num.size()){
        ans.push_back(path);
        return;
    }

    int num=digit_num[index]-'0';
    string s=digit[num];
    for(int i=0;i<s.size();i++){
        path.push_back(s[i]);
        backtracking(digit_num, index+1);
        path.pop_back();
    }
}

int main(){
    string str;
    cin>>str;
    backtracking(str, 0);
    
}