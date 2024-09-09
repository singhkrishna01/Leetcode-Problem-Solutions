class Solution {
public:
    int kItemsWithMaximumSum(int one, int zero, int neg, int k){
        int sum=min(one,k); 
        k-=sum; 
        if(k==0) return sum;
       
        int negative=min(neg,k);
        sum-=negative; 
        if(k==0) return sum;

        return sum;
    }
};