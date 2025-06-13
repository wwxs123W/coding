#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> zuobiao{
    {-1,0},
    {1,0},
    {0,-1},
    {0,1}
};
bool backtracking(vector<vector<char>>& words,string str,int x,int y,int index){

    if(words[x][y]!=str[index]){
        return false;
    }

    if(index>=str.size()-1){
        return true;
    }

    int m=words.size();
    int n=words[0].size();
    char c=words[x][y];
    words[x][y]='.';
    for(int i=0;i<4;i++){
        int index_x=zuobiao[i][0];
        int index_y=zuobiao[i][1];
        if(index_x+x<0 || index_y+y<0 || index_x+x>m-1 || index_y+y>n-1){
            continue;
        }
        if(backtracking(words,str,x+index_x,y+index_y,index+1)) return true;
    }

    words[x][y]=c;
    return false;

}

int main(){
    int m,n;
    cin>>m;
    cin>>n;
    vector<vector<char>> input(m,vector<char>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>input[i][j];
        }
    }
    string str;
    cin>>str;

    bool flag=false;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(backtracking(input, str, i, j, 0)){
                flag=true;
            }
        }
    }
    cout<<flag<<endl;


}