#include <algorithm>
#include <climits>
#include<iostream>
#include<vector>
using namespace std;

int numsquares(int n){
    vector<int> dp(n+1,INT_MAX);
    dp[0]=0;

    for(int i=1;i*i<=n;i++){
        for(int j=i*i;j<=n;j++){
            dp[j]=min(dp[j],dp[j-i*i]+1);
        }
    }
    cout<<dp[n];
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    numsquares(n);
}