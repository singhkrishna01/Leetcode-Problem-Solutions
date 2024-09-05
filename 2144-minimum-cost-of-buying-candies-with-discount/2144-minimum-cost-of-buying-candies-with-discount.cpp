class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());

        int totalCost=0;
        for(int i=cost.size()-1;i>=0;i=i-3){
            
            }
            else if(i==1){
                totalCost = totalCost + cost[i]+cost[i-1]; // Buy 2 candy , No discount
            }
            else if(i==0){
                totalCost = totalCost + cost[i];           // buy remaining 1 candy
            }
        }
        return totalCost;
    }
};