class Solution {
public:
    bool checkStrings(string s1, string s2) {
        string x1 = "";
        string x2 = "";
        string x3 = "";
        string x4 = "";
        
        for(int i = 0; i < s1.size(); i += 2) x1 += s1[i]; //iterating through even indices of s1
        for(int i = 1; i < s1.size(); i += 2) x2 += s1[i]; //iterating through odd indices of s1
        for(int i = 0; i < s2.size(); i += 2) x3 += s2[i]; //iterating through even indices of s2
        for(int i = 1; i < s2.size(); i += 2) x4 += s2[i]; //iterating through odd indices of s2
        
        //Sorting each individual string 
        sort(x1.begin(), x1.end());
        sort(x2.begin(), x2.end());
        sort(x3.begin(), x3.end());
        sort(x4.begin(), x4.end());

        return ((x1 + x2) == (x3 + x4));
    }
};