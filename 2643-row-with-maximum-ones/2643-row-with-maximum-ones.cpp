class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int maxcount=0;
        int index=0;
        for(int i=0;i<mat.size();i++){
            int countone=0;
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1){
                    countone++;
                }
        }
             if(countone>maxcount){
                 maxcount=countone;
                index=i;
             }
        }
        return{index,maxcount};
    }
};