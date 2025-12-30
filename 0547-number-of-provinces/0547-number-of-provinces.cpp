class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size(), false);
        queue<int> q;
        int connected = 0;

        for (int i = 0; i < isConnected.size(); i++)
        {
            if(!visited[i])
            {
                connected++;
                visited[i] = true;
                q.push(i);
                while(!q.empty())
                {
                    int node = q.front();
                    q.pop();

                    for (int j = 0; j < isConnected.size(); j++) {
                        if (isConnected[node][j] == 1 && !visited[j]) {
                            visited[j] = true;
                            q.push(j);
                        }
                    }
                }
            }
        }
        return connected;
    }
};