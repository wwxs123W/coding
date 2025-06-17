#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> zuobiao={
    {-1,0},
    {1,0},
    {0,1},
    {0,-1},
};

void dfs(vector<vector<char>>& islands,int x,int y){
    if(islands[x][y]=='0'){
        return;
    }

    int m=islands.size();
    int n=islands[0].size();
    islands[x][y]='0';
    for(int i=0;i<4;i++){
        int dx=zuobiao[i][0];
        int dy=zuobiao[i][1];
        if(dx+x<0 ||dx+x>m-1 || dy+y<0 ||dy+y>n-1) continue;
        dfs(islands,dx+x,dy+y);
    }

}

int islandnum(vector<vector<char>>& islands){
    int num=0;
    int m=islands.size();
    int n=islands[0].size();

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(islands[i][j]=='1'){
                dfs(islands,i,j);
                num++;
            }
            
        }
    }
    return num;
}

int main(){
    int m,n;
    cin>>m>>n;

    vector<vector<char>> islands(m,vector<char>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>islands[i][j];
        }
    }

    int num=islandnum(islands);
    cout<<num;
}