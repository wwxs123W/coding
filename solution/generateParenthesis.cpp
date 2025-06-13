#include<iostream>
#include<vector>
using namespace std;

string path;
vector<string> ans;

void backtracking(int n,int leftsize,int rightsize){

    if(leftsize>n){
        return;
    }
    if(rightsize>leftsize) return;

    if(path.size()==2*n){
        cout<<path<<endl;
        ans.push_back(path);
    }

    path.push_back('(');
    leftsize++;
    backtracking(n, leftsize, rightsize);
    leftsize--;
    path.pop_back();

    path.push_back(')');
    rightsize++;
    backtracking(n,leftsize,rightsize);
    rightsize--;
    path.pop_back();

}

int main(){
    int n;
    cin>>n;
    backtracking(n, 0, 0);
    
}