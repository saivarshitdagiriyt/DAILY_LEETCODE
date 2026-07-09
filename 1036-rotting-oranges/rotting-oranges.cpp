class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>>q; 
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else{
                    vis[i][j] = 0;
                }
            }
        }
        int time = 0;
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            time = q.front().second;
            q.pop();
            for(int delrow = -1;delrow<=1;delrow++){
                for(int delcol = -1;delcol<=1;delcol++){
                    if(abs(delrow)+abs(delcol)==1){
                        int nrow = row+delrow;
                        int ncol = col+delcol;
                        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]!=2 && 
                        grid[nrow][ncol] == 1){
                            vis[nrow][ncol] = 2;
                            q.push({{nrow,ncol},t+1});
                        }
                    }
                }
            }

        }
        for(int i = 0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j] == 1 && vis[i][j]!=2){
                    return -1;
                }
            }
        } 
        return time;

     }
};