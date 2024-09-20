class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int n = size(arr);
        int j = 0;
	   
	   int i = 0;
	   while(i<n and j<n){
	       
	       if(arr[j]!=0){
	           swap(arr[i++],arr[j++]);
	       }
	       else{
	           j++;
	       }
	   }
    }
};