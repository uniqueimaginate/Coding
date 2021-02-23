// BFS
class Solution {
public:
    int ret = 0;
    
    int fx[4] = {0,0,1,-1};
    int fy[4] = {-1,1,0,0};
    
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        int nc = grid[0].size();
        
        int numIslands = 0;
        for(int r=0; r<nr; ++r){
            for(int c=0; c<nc; ++c){
                if(grid[r][c] == '1'){
                    ++numIslands;
                    grid[r][c] = '0';
                    queue<pair<int, int>> q;
                    q.push({r,c});
                    
                    while(!q.empty()){
                        int rr = q.front().first;
                        int cc = q.front().second;
                        q.pop();
                        
                        for(int t=0; t<4; ++t){
                            int newR = rr + fx[t];
                            int newC = cc + fy[t];
                            if((0 <= newR && newR < nr) && (0 <= newC && newC < nc) && (grid[newR][newC] == '1')){
                                q.push({newR, newC});
                                grid[newR][newC] = '0';
                            }
                        }
                    }
                }
                
            }
        }
        
    
        return numIslands;
    }
    
};


// DFS
class Solution {
public:
    int fr[4] = {0,0,1,-1};
    int fc[4] = {1,-1, 0,0};
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        int nc = grid[0].size();
        int numIslands = 0;
        for(int r = 0; r < nr; ++r){
            for(int c = 0; c < nc; ++c){
                if(grid[r][c] == '1'){
                    ++numIslands;
                    dfs(r, c, grid);
                }
                
            }
        }
        
        return numIslands;
    }
    
    void dfs(int rr, int cc, vector<vector<char>> &grid){
        int nr = grid.size();
        int nc = grid[0].size();
        if(grid[rr][cc] == '0') return;
        
        grid[rr][cc] = '0';
        for(int t=0; t<4; ++t){
            int newR = rr + fr[t];
            int newC = cc + fc[t];
            
            if(0 <= newR && newR < nr && 0 <= newC && newC < nc && grid[newR][newC] == '1'){
                dfs(newR, newC, grid);
            }
        }
    }
    
};