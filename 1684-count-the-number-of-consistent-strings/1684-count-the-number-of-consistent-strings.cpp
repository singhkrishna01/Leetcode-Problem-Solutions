class Solution {
public:
    int countConsistentStrings(string all, vector<string>& w) 
    {
        int n = w.size();
        int cnt = 0;

        for(int i = 0; i < n; i++)
        {
            set<char> st(w[i].begin(), w[i].end());

            bool flag = true; 

            for(auto x : st)
            {
                auto it = find(all.begin(), all.end(), x);
                if(it == all.end()) 
                {
                    flag = false;
                    break;
                }
            }

            if(flag) cnt++;
        }

        return cnt;
    }
};