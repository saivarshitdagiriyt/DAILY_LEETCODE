class Solution {
public:
    void dfs(pair<int,int>node,vector<vector<char>>&board,vector<vector<int>>&vis){
        int row = node.first;
        int col = node.second;
       int n = board.size();
        int m = board[0].size();
        vis[row][col] = 1;
        for(int i = -1;i<=1;i++){
            for(int j = -1;j<=1;j++){
                if(abs(i)+abs(j)==1){
                    int nrow = row+i;
                    int ncol = col+j;
                    if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m && vis[nrow][ncol]==0 && board[nrow][ncol]=='O'){
                        pair<int,int> temp = {nrow,ncol};
                        dfs(temp,board,vis);
                    }
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                q.push({i,0});
            }
            if(board[i][m-1]=='O'){
                q.push({i,m-1});
            }
        }
        for(int i=0;i<m;i++){
            if(board[0][i]=='O'){
                q.push({0,i});
            }
            if(board[n-1][i]=='O'){
                q.push({n-1,i});
            }
        }
       
        while(!q.empty()){
         pair<int,int> start = {q.front().first,q.front().second};
         if(!vis[start.first][start.second]){
            dfs(start,board,vis);
         }
         q.pop();
    }
    for(int i=0;i<n;i++){
        for(int  j=0;j<m;j++){
            if(vis[i][j]==1){
                board[i][j]='O';
            }
            else{
                board[i][j]='X';
            }
        }
    }
    return;
}
};