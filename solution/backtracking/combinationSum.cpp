#include<iostream>
#include<vector>
using namespace std;

vector<int> path;
vector<vector<int>> ans;
void backtracking(vector<int>& nums,int index,int target){
    if(target==0){
        int n=path.size();
        for(int i=0;i<n;i++){
            cout<<path[i];
        }
        cout<<endl;
        ans.push_back(path);
        return;
    }

    if(target<0){
        return;
    }

    for(int i=index;i<nums.size();i++){
        path.push_back(nums[i]);
        backtracking(nums, i, target-nums[i]);
        path.pop_back();
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    int sum=0;
    for(int i=0;i<n;i++){
        sum+=nums[i];
    }

    int target;
    cin>>target;
    backtracking(nums, 0,target);


}