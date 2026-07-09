class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    vis[i][j] =2;
                    q.push({{i,j},0});
                }
            }
        }
        int time = 0;
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            time = q.front().second;
            q.pop();
            for(int delrow=-1;delrow<=1;delrow++){
                for(int delcol=-1;delcol<=1;delcol++){
                    int nrow = delrow + row;
                    int ncol = delcol + col;
                    if(abs(delrow)+abs(delcol)==1){
                        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
                        grid[nrow][ncol]==1 && vis[nrow][ncol]!=2){
                            vis[nrow][ncol]=2;
                            q.push({{nrow,ncol},time+1});
                        }
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]!=2){
                    return -1;
                }
            }
        }
        return time;
    }
};