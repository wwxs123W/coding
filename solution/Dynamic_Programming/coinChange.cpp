#include <algorithm>
#include <climits>
#include<iostream>
#include<vector>
using namespace std;

int coinchange(int amout,vector<int>& nums){
    
    int n=nums.size();
    vector<int> dp(amout+1,INT_MAX);
    dp[0]=0;
    for(int i=0;i<n;i++){
        for(int j=nums[i];j<=amout;j++){
            if(dp[j-nums[i]]+1!=INT_MAX){
                dp[j]=min(dp[j],dp[j-nums[i]]+1);
            }
            
        }
    }
    if(dp[amout]==INT_MAX){
        cout<<-1;
        return -1;
    }
    cout<<dp[amout];

    return dp[amout];
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    int amout;
    cin>>amout;
    coinchange(amout,nums);
}