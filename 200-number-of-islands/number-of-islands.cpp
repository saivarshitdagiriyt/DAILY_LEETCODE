class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    q.push({i,j});
                }
           }
        }
        vector<vector<int>>vis(n,vector<int>(m,0));
        int lands = 0;
        while(!q.empty()){
            pair<int,int> start = {q.front().first,q.front().second};
            if(!vis[start.first][start.second]){
                lands++;
                dfs(start,vis,grid,n,m);
            }
            q.pop();
        }
        return lands;
    }
    void dfs(pair<int,int>node,vector<vector<int>>&vis,vector<vector<char>>&grid,int n,int m){
        int row = node.first;
        int col = node.second;
        vis[row][col]=1;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                if(abs(i)+abs(j)==1){
                    int nrow = row+i;
                    int ncol = col+j;
                    if(nrow>=0 && nrow<n &&  ncol>=0 && ncol<m && !vis[nrow][ncol]
                    && grid[nrow][ncol]=='1'){
                        vis[nrow][ncol]=1;
                        pair<int,int> temp = {nrow,ncol};
                        dfs(temp,vis,grid,n,m);
                    }
                }
            }
        }
    }
};