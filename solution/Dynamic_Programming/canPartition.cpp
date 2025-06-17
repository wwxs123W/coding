#include<iostream>
#include <vector>
using namespace std;

bool canPartition(vector<int>& nums){
    int n=nums.size();
    int sum=0;

    for(int i=0;i<n;i++){
        sum+=nums[i];
    }
    int target=sum/2;
    vector<int> dp(target,0);
    if(sum%2==1) return 0;

    for(int i=0;i<n;i++){
        for(int j=target;j>=nums[i];j--){
            dp[j]=max(dp[j],dp[j-nums[i]]+nums[i]);
        }
    }

    return dp[target]==target;
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    bool flag =canPartition(nums);
    cout<<flag;
}