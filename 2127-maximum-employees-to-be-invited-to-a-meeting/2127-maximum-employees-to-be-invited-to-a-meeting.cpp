class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        map<int , vector<int>>gf ;
        vector<int>inde(favorite.size(), 0 ) ;
        int n  =  favorite.size() ;
        for(int  i =0; i  < favorite.size() ; i++){
            int a =  i ;
            int  b = favorite[i] ;
            gf[a].push_back(b) ;
            inde[b]++; 
        }
        queue<int>q  ;
        for(int  i =  0 ;  i <  n ;  i++){
            if(inde[i] ==0 ){
                q.push(i) ;
            }
        }
        vector<int>dist(n , 0) ;
        while(q.size() > 0 ){
            auto it =  q.front() ;
            q.pop() ;
            int next =  favorite[it] ;
            dist[next] =  max(dist[next] , dist[it] + 1 ); 
            inde[next]--;
            if(inde[next] == 0 ){
                q.push(next) ;
            }

        } 

        int cycle2 = 0 ;
        int mx  =0 ; 
        for(int  i =0 ; i <n ;  i++){
            int a = i ;
            if(inde[a] ==0 )continue ;
            int len = 0 ;
          

            while(inde[a] != 0 ){
                inde[a] = 0 ;
                len++;
                a =  favorite[a] ;
            }

            if(len == 2 ){
                cycle2 += dist[a] +  dist[favorite[a]] +  len  ;
                mx = max(mx ,  cycle2 ) ;
            }
            else{
                mx =  max(mx , len ) ;
            }
        }
        return mx ;

        
    }
};