class Solution {
public:
    vector<int> lexicalOrder(int n) {
        set<string> stt;
        vector<int> ans;
        for(int i=1;i<=n;i++){
            stt.insert(to_string(i));
        }

        for(auto it=stt.begin();it!=stt.end();it++){
            ans.push_back(stoi);
        }
        return ans;
    }
};