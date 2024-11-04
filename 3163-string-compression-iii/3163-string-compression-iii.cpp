class Solution {
public:
    string compressedString(string word) {
        char ch = word[0];
        string s = "";
        int count = 0;
        for(int i = 0; i < word.size(); i++){
            if(ch == word[i] && count < 9){
                count++;
            }
            else{
                s.push_back(count + '0');
                s.push_back(ch);
                ch = word[i];
                count = 1;
            }
        }
        s.push_back(count + '0');
        s.push_back(ch);
        return s;
    }
};