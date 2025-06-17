#include<iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int lengthOfLIS(vector<int>& nums){
    int n=nums.size();
    vector<int> dp(n,1);
    dp[0]=1;

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[j]<nums[i]){
                dp[i]=max(dp[j]+1,dp[i]);
            }
        }
    }

    cout<<dp[n-1];
    return dp[n-1];
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    lengthOfLIS(nums);
}