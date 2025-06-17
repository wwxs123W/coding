#include<iostream>
#include<vector>
using namespace std;

vector<int> searchRange(vector<int>& nums,int target){
    int first=-1,last=-1;
    int left=0,right=nums.size()-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(nums[mid]==target){
            first=mid;
            right=mid-1;
        }else if(nums[mid]<target){
            left=mid+1;
        }else if(nums[mid]>target){
            right=mid-1;
        }
    }

    left=0,right=nums.size()-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(nums[mid]==target){
            last=mid;
            left=mid+1;
        }else if(nums[mid]<target){
            left=mid+1;
        }else if(nums[mid]>target){
            right=mid-1;
        }
    }

    return {first,last};


}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    int target;
    cin>>target;

    vector<int> ans=searchRange(nums,target);
    cout<<ans[0]<<ans[1]<<endl;

}