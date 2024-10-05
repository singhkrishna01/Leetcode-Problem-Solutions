class Solution {
public:
    string removeStars(string s) {
        stack<char>str;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!='*')
            {
                str.push(s[i]);
            }
            else
            {
                str.pop();
            }
        }
        string res="";
        while(!str.empty())
        {
            res+=str.top();
            str.pop();
        }
        reverse(res.begin(),res());
        return res;
    }
};