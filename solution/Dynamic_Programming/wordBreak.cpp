#include<iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool wordBreak(string s,vector<string>& dict){
    int n=s.size();
    vector<bool> dp(n+1,0);
    unordered_set<string> set(dict.begin(),dict.end());
    dp[0]=1;
    
    for(int i=0;i<=s.size();i++){
        for(int j=0;j<i;j++){
            string substr=s.substr(j,i-j);
            if(set.count(substr) && dp[j]){
                dp[i]=true;
            }
        }
    }

    cout<<dp[n];
    return dp[n];   
}

int main(){
    int n;
    cin>>n;
    vector<string> dict(n);
    for(int i=0;i<n;i++){
        cin>>dict[i];
    }

    string s;
    cin>>s;
    wordBreak(s, dict);
}