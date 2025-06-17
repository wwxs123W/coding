#include<iostream>
#include<vector>
using namespace std;

vector<string> path;
vector<vector<string>> ans;

bool huiwen(string s){
    int n=s.size();
    int left=0,right=n-1;
    while(left<=right){
        if(s[left]!=s[right]){
            return false;
        }
        left++;
        right--;
    }
    return true;
}


void backtracking(string s,int index){
    if(index==s.size()){
        int n=path.size();
        for(int i=0;i<n;i++){
            cout<<path[i]<<endl;
        }
        ans.push_back(path);
        return;
    }

    for(int i=index;i<s.size();i++){
        int length=i-index+1;
        string subs= s.substr(index,i-index+1);
        if(!huiwen(subs)){
            continue;
        }
        path.push_back(subs);
        backtracking(s, i+1);
        path.pop_back();

    }
}


int main(){
    string s;
    cin>>s;
    backtracking(s, 0);
}
