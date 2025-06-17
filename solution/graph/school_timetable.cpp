#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool canFinish(int num_course,vector<vector<int>>& topology){
    vector<int> indeg(num_course);
    vector<vector<int>> edge(num_course);

    int m=topology.size();

    for(int i=0;i<m;i++){
        indeg[topology[i][0]]++;
        edge[topology[i][1]].push_back(topology[i][0]);
    }

    queue<int> q;
    for(int i=0;i<num_course;i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }

    int visited=0;
    while(!q.empty()){
        int size =q.size();
        int curr=q.front();
        q.pop();
        visited++;
        for(int i=0;i<size;i++){
            int zhixiao=edge[curr].size();
            for(int j=0;j<zhixiao;j++){
                indeg[edge[curr][j]]--;
                if(indeg[edge[curr][j]]==0){
                    q.push(edge[curr][j]);
                }
            }
        }
    }

    return visited==num_course;
}

int main(){
    int m,n;
    cin>>m>>n;

    vector<vector<int>> topology(m,vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>topology[i][j];
        }
    }

    int num_course;
    cin>>num_course;

    bool flag=canFinish(num_course, topology);
    cout<<flag<<endl;

}