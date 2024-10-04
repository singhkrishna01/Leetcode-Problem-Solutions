class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int ans=0,cnt=0;
        int n=grid.size();
        vector<vector<int>>v(n,vector<int>(n,0));
        
     for(int i=0;i<grid.size();i++){
        
        for(int j=0;j<grid.size();j++){
         v[j][i]=grid[i][j];
        } 
        
     }
    for(int i=0;i<grid.size();i++){
      for(int j=0;j<grid.size();j++) {
              ans++;
          }
      }
        
    }
        return ans;
    }
};