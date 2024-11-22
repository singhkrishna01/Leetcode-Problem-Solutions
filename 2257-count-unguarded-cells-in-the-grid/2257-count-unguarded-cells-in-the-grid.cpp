class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        
        int matrix[m][n];

        for(int i = 0; i < m ; i++){
            for(int j = 0; j < n ; j++){
                matrix[i][j] = 0;
            }
        }

        for(auto& i : walls){
            matrix[i[0]][i[1]] = 1;
        }

        for(auto& i : guards){
            matrix[i[0]][i[1]] = 8;
        }
        for(auto& k : guards){
            int i = k[0];
            int j = k[1];

            int ti = i+1;
            
            while(ti < m){
                if(matrix[ti][j] == 1 or matrix[ti][j] == 8){
                    break;
                }
                matrix[ti++][j] = -1;
            }

            int tj = j-1;

            while(tj >= 0){
                if(matrix[i][tj] == 1 or matrix[i][tj] == 8){
                    break;
                }
                matrix[i][tj--] = -1;
            }
            tj = j+1;

            while(tj < n){
                if(matrix[i][tj] == 1 or matrix[i][tj] == 8){
                    break;
                }
                matrix[i][tj++] = -1;
            }
            ti = i-1;

            while(ti >= 0){
                if(matrix[ti][j] == 1 or matrix[ti][j] == 8){
                    break;
                }
                matrix[ti--][j] = -1;
            }
        }


        int ans = 0;

        for(auto& i : matrix){
            for(auto& j : i){
                ans += j == 0 ? 1 : 0;
            }
        }

        return ans;


    }
};