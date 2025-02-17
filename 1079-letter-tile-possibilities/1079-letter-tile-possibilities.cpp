class Solution {
public:
    void rec(int level,int& cnt,unordered_map<char,int>& mpp,int n){
        cnt++;
        if(level==n){
            return;
        }
        for(auto v : mpp){
            if(v.second!=0){ 
                mpp[v.first]--;
                rec(level+1,cnt,mpp,n);
                mpp[v.first]++;
            }
            
        }
    }
    int numTilePossibilities(string tiles) {
        int cnt = 0;
        unordered_map<char,int> mpp;
        int n = tiles.size();
        
        for(int i=0;i<n;i++) mpp[tiles[i]]++;

        rec(0,cnt,mpp,n);
        
        return cnt-1;
        
    }
};