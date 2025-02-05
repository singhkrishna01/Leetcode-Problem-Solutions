class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int noneql=0;
        string p=s1;
        string q=s2;
        sort(p.begin(),p.end());
        sort(q.begin(),q.end());
        if(p!=q)return 0;
        
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                noneql++;

            }

        } 
        return noneql==0||noneql==2?1:0;
        
    }
};