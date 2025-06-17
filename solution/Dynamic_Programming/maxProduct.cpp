#include<iostream>
#include <vector>
#include <climits>
using namespace std;

int maxproduct(vector<long>& nums){
    int n=nums.size();
    vector<long> maxnum(nums.begin(),nums.end());
    vector<long> minnum(nums.begin(),nums.end());

    for(int i=1;i<n;i++){
        maxnum[i]=max(minnum[i-1]*nums[i],max(nums[i],maxnum[i-1]*nums[i]));
        minnum[i]=min(minnum[i-1]*nums[i],min(nums[i],maxnum[i-1]*nums[i]));
    }

    int result=0;
    for(int i=0;i<n;i++){
        result=max(maxnum[i],(long)result);
    }

    cout<<result;
    return result;

}

int main(){
    int n;
    cin>>n;
    vector<long> nums(n);
    
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    maxproduct(nums);
}