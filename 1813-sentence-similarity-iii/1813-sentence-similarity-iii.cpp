class Solution {
public:
    bool areSentencesSimilar(string sen1, string sen2) {
        
        if(sen2.size()>sen1.size()) swap(sen1 , sen2);
        
         vector<string> s1;
         vector<string> s2;
        stringstream mystream2(sen2);
        string word;
        while(mystream1 >> word)
        {
           s1.push_back(word);
        }
        while(mystream2 >> word)
        {
         s2.push_back(word);
        }
         int i = 0;
         int j = s2.size()-1;
         for(int k = 0 ; k<s1.size() ; k++)
         {
            if(i<s2.size() && s1[k] == s2[i]) i++;
            else break;
         }
         for(int k = s1.size()-1 ; k>=0 ; k--)
         {
            if(j>=0 && s1[k] == s2[j]) j--;
            else break;
         }
        return i>j;
    }
};