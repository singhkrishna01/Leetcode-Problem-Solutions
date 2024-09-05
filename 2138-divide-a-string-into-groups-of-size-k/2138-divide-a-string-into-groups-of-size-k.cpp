class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        
    }
};aclass Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>ans;
        string ki;
        int c=0;

        for(int i=0;i<s.length();i++)
        {
            if(c<k)
            {   ki.push_back(s[i]);
                c++;
            }
            else
            {
               
                c=0;
                ans.push_back(ki);
                 ki.clear();
                 i-=1;
            }

        }

            ki.push_back(fill);
        }
        ans.push_back(ki);

        return ans;
        
    }
};