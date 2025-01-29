class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<bool> vis(n*n + 1,false);
        queue<int> q;
        q.push(1);
        vis[1]=true;
        int ans = 0;
        while(q.empty()==false)
        {
            int size = q.size();
            ans++;

            for(int sz=0;sz<size;sz++)
            {
                int box = q.front();
                q.pop();

                for(int k=1;k<=6;k++)
                {
                    int newbox = box + k;
                    int nr = n-1-((newbox-1)/n);
                    int nc = ((newbox-1)/n)%2==0?(newbox-1)%n:n-1-(newbox-1)%n;

                    if(board[nr][nc] != -1)
                    {
                        newbox = board[nr][nc];
                        nr = n-1-((newbox-1)/n);
                        nc = ((newbox-1)/n)%2==0?(newbox-1)%n:n-1-(newbox-1)%n;
                    }

                    if(!vis[newbox])
                    {
                        vis[newbox]=true;
                        q.push(newbox);

                        if(newbox==n*n)
                        return ans;
                    }
                }
            }
        }
        return -1;
    }
};