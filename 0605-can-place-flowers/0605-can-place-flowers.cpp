class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) { 
        if(n==0) return true;
        int p=1;
        for(int i=0;i<f.size();i++){
            if(f[i]==0){
                p++;
            }
            else{
                p=0;
            }
            if(p==3){
                n--;
                p=1;
           
        }
        return n==0; 
    }
};