class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int> m;
        int max=INT_MIN;
        for(int i=0;i<wall.size();i++)
        {
            int curr=0;
            for(int j=0;j<wall[i].size()-1;j++)
            {
                curr=curr+wall[i][j];
                if(m.find(curr)==m.end())
                    m[curr]=1;
                else
                    m[curr]++;
                if(max<m[curr])
                    max=m[curr];
            }
        }
       
        if(max==INT_MIN)
            return wall.size();
        return wall.size()-max;
    }
};
