class Solution {
public:
    int captureForts(vector<int>& forts) 
    {
        int cnt=0;
        int mx=0;
        
        for(int i=0;i<forts.size();i++)
        {
            if(forts[i]==1)
            {
                
                    }
                    else if(forts[j]==-1)
                    {
                        mx = max(mx,cnt);
                        cnt=0;
                        break;
                    }
                    else
                    {
                        break;
                    }
                }
                
                cnt=0;
                for(int j=i+1;j<forts.size();j++)
                {
                    if(forts[j]==0)
                    {
                        cnt++;
                    }
                    else if(forts[j]==-1)
                    {
                        mx = max(mx,cnt);
                        cnt=0;
                        break;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        return mx;
    }
};