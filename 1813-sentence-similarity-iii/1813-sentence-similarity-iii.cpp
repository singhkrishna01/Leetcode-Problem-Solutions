class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {  
        vector<string> wordS1 = splitInWords(sentence1);
        vector<string> wordS2 = splitInWords(sentence2);
        vector<string> min, max;
        if (wordS1.size() > wordS2.size()) {
            min = wordS2; max = wordS1;
        } else {
            min = wordS1; max = wordS2;
        }
        bool normal = checkSimilarity(min, max);
        reverse(min.begin(), min.end());
        reverse(max.begin(), max.end());
        bool bothReverse = checkSimilarity(min, max);
        
        return normal || bothReverse;
    }
    bool checkSimilarity(vector<string>& min, vector<string>& max) {
        bool miss = false;
        int j = 0;
        for(int i = 0; i < min.size(); i++) {
            if (j < max.size() && min[i] == max[j]) {        
                j++;
                continue;
            }
            if (miss)
                return false;
            
            miss = true;
            while(j < max.size() && min[i] != max[j])
                j++;
            if (j >= max.size()) 
                return false;
            if (j < max.size() && min[i] == max[j])
                j++;
            
        }
        return j == max.size() || !miss;
    }
    vector<string> splitInWords(string s) {
        vector<string> result;
        string current = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                result.push_back(current);
                current = "";
                continue;
            } else {
                current.push_back(s[i]);
            }
        }
        result.push_back(current);
        return result;
    }
};