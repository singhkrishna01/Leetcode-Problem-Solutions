class Solution {
public:

    int slv(int i, vector<int>&arr){
      if(i >= arr.size()){
        return 0;
      }
      int ret = 0;
      if(i - 1 >= 0){
        if(arr[i] >= arr[i - 1]){
          int o = arr[i] - arr[i - 1] + 1;
          arr[i] -= o;
          ret += o;
        }
      } 

      if(i + 1 < arr.size()){
        if(arr[i] >= arr[i + 1]){
          int o = arr[i] - arr[i + 1] + 1;
          arr[i] -= o;
          ret += o;
        }
      } 
      ret += slv(i+2, arr);
      return ret;
    }

    int movesToMakeZigzag(vector<int>& arr) {
      vector<int>a = arr;
      vector<int>b = arr;

      return min(
        {slv(0, a), slv(1, b)}
      ) ;
    }
};