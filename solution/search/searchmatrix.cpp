#include<iostream>
#include<vector>
using namespace std;

bool searchmatrix(vector<vector<int>>& nums,int target){
    int m=nums.size();
    int n=nums[0].size();
    int left=0,right=m-1;

    while(left<=right){
        int mid=(left+right)/2;
        if(nums[mid][0]<target){
            left=mid+1;
        }else if(nums[mid][0]>target){
            right=mid-1;
        }else if(nums[mid][0]==target){
            return true;
        }
    }
    int row=left-1;
    if(row<0) return false;
    left=0;
    right=n-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(nums[row][mid]<target){
            left=mid+1;
        }else if(nums[row][mid]>target){
            right=mid-1;
        }else if(nums[row][mid]==target){
            return true;
        }
    }
    return false;

}

int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>> nums;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>nums[i][j];
        }
    }

    int target;
    cin>>target;
    
    bool flag=searchmatrix(nums,target);
}