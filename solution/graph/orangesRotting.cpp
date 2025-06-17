#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int>> zuobiao{
    {-1,0},
    {1,0},
    {0,1},
    {0,-1},
};

int orangerotting(vector<vector<int>>& grid){
    int m=grid.size();
    int n=grid[0].size();

    queue<pair<int,int>> q;
    int num_2=0,num_1=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==2){
                q.push({i,j});
                num_2++;
            }else if(grid[i][j]==1){
            
                num_1++;
            }
        }
    }
    if(q.empty() && num_1!=0){
        return -1;
    }

    int ans=0;

    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            pair<int,int> p=q.front();
            int x=p.first;
            int y=p.second;
            q.pop();
            for(int j=0;j<4;j++){
                int dx=zuobiao[j][0];
                int dy=zuobiao[j][1];
                if(x+dx<0 || x+dx>=m || y+dy<0||y+dy>=n) continue;
                if(grid[x+dx][y+dy]==1){
                    q.push({x+dx,y+dy});
                    num_1--;
                    grid[x+dx][y+dy]=2;
                }
            
            }
        }
        if(!q.empty()){
            ans++;
        }
    }

    if(num_1) return -1;
    cout<<ans<<endl;
    return ans;


}

int main(){
    int m,n;
    cin>>m>>n;

    vector<vector<int>> grid(m,vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }

    orangerotting(grid);
}