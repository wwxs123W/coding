#include<iostream>
#include <vector>
using namespace std;

int rob(vector<int>& nums){
    int n=nums.size();
    vector<int> dp(n,0);
    if(n==0) return 0;
    if(n==1) return nums[0];
    dp[0]=nums[0];
    dp[1]=max(nums[0],nums[1]);

    for(int i=2;i<n;i++){
        dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
    }

    cout<<dp[n-1]<<endl;
    return dp[n-1];
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    rob(nums);
}