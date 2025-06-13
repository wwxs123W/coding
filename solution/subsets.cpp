#include<iostream>
using namespace std;
#include<vector>

vector<vector<int>> path;
vector<int> ans;

void subsets(vector<int>& nums,int index){
    int m=ans.size();
    for(int j=0;j<m;j++){
        cout<<ans[j];
    }

    cout<<endl;
    if(index==nums.size()){
        return;
    }

    
    path.push_back(ans);
    for(int i=index;i<nums.size();i++){
        ans.push_back(nums[i]);
        subsets(nums, i+1);
        ans.pop_back();
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n,0);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    subsets(nums, 0);

}