#include<iostream>
#include <type_traits>
#include<vector>
using namespace std;

bool isvalid(vector<string> board,int x,int y){
    //lie
    int n=board.size();
    for(int i=0;i<x;i++){
        if(board[i][y]=='Q'){
            return false;
        }
    }

    //zuoshang
    for(int i=x,j=y;i>=0 && j>=0;i--,j--){
        if(board[i][j]=='Q'){
            return false;
        }
    }

    //you
    for(int i=x,j=y;i>=0 && j<n;i--,j++){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    return true;
}

void backtracking(vector<string>& board,int row){
    int n=board.size();
    if(row==board.size()){
        for(int i=0;i<n;i++){
            cout<<board[i]<<endl;
        }
        cout<<endl;
        return;
    }

    for(int i=0;i<n;i++){
        if(!isvalid(board,row,i)) continue;
        board[row][i]='Q';
        backtracking(board,row+1);
        board[row][i]='.';
    }
}

int main(){
    int n;
    cin>>n;
    vector<string> board(n,"....");

    backtracking(board, 0);


}