class Solution {
public:
    int minSwaps(string s) {
        int maxiClose=0;
        int maxi=0;
        for(int i=0;i<s.size();i++){
                maxiClose--;
            else{
                maxiClose++;
            }
            maxi=max(maxiClose,maxi);

        }
        return (maxi+1)/2;
        
    }
};