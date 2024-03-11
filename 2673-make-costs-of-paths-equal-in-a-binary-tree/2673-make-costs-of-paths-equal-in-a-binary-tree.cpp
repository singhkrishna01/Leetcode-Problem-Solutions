class Solution {
    // this array contains every cost of path from root to leaf
    vector<int> ans;
    void rec(vector<int> &cost,int n,int node,int val){
        if(node*2>n){
            // pushing the cost of path from root to leaf (node)
            ans.push_back(val+cost[node-1]);
            return;
        }
        rec(cost,n,2*node,val+cost[node-1]);
        rec(cost,n,2*node+1,val+cost[node-1]);
    }
    
    int cnt = 0; // this is our answer to the question
    int mx = -1; // this is the final value of every path
    
    //// this function is just like merge sort /////////////////
    void half(vector<int> &arr,int l,int r,int add){
        if(l>=r)
            return;
        int mid = (l+r)>>1;
        
        ////////////////// calculating maximum /////////////////
        int b = -1;
        for(int i=l;i<=mid;i++){
            b = max(b,arr[i]+add);
        }
        /// why doing max(b,arr[i]+add)
        /// arr[i] + add. here add variable tell us the total
        /// value that we have added to the parent or ancestor
        /// that came befor our current node. so if we have
        /// increase our ancestor by value add then we must also
        /// increase its childrens the the same value add.
        ////////////////////////////////////////////////////////
        
        cnt+=(mx-b); // how much to increase in this segment l - mid
        half(arr,l,mid,add+(mx-b));
        /// add+(mx-b). here mx-b tell us how much we need to increase
        /// the common node to make the value of the max to become 
        /// mx i.e. the final equal value
        ////////////////////////////////////////////////////////

        ///////////////// calculating maximum //////////////////
        b = -1;
        for(int i = mid+1;i<=r;i++){
            b = max(b,arr[i]+add);
        }
        ////////////////////////////////////////////////////////

        cnt+=(mx-b); // how much to increase in this segment mid+1 - r
        half(arr,mid+1,r,add+(mx-b));
    }
    
public:
    int minIncrements(int n, vector<int>& cost) {
        rec(cost,n,1,0);
        /// calculating the final common value /////
        for(auto it:ans){
            mx = max(mx,it);
        }
        half(ans,0,ans.size()-1,0);  
        return cnt;
    }
};