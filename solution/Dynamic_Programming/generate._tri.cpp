#include <algorithm>
#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> generate(int n){
    vector<vector<int>> dp(n);
    dp[0].resize(1);
    dp[0][0]=1;
    
    for(int i=1;i<n;i++){
        dp[i].resize(i+1);
        dp[i][0]=1;
        dp[i][i]=1;
        for(int j=1;j<=i-1;j++){
            dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
        }
    }

    for(int i=0;i<n;i++){
        int m=dp[i].size();
        for(int j=0;j<m;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp;
}

int main(){
    int n;
    cin>>n;
    generate(n);

}