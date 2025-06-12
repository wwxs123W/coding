#include<iostream>
#include<vector>

using namespace std;

vector<int> path;
vector<vector<int>> ans;
void backtracking(int n,vector<int>& used){
    if(path.size()==n){
        ans.push_back(path);
        for(int j=0;j<n;j++){
            cout<<path[j]<<" ";
        }
        cout<<endl;
        return;
    }

    for(int i=1;i<=n;i++){
        if(used[i]==1) continue;
        used[i]=1;
        path.push_back(i);
        backtracking(n, used);
        used[i]=0;
        path.pop_back();
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> used(n+1,0);
    backtracking(n, used);

}