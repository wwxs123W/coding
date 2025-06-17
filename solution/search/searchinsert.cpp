#include<iostream>
#include<vector>
using namespace std;

int searchinsert(vector<int>& nums,int target){
    int left=0,right=nums.size()-1;

    while(left<=right){
        int mid=(left+right)/2;
        if(nums[mid]<target){
            left=mid+1;
        }else if(nums[mid]>target){
            right=mid-1;
        }else if(nums[mid]==target){
            return mid;
        }
    }

    return left;
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

    int ans=searchinsert(nums,target);
    cout<<ans<<endl;

}