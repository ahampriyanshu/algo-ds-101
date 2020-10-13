class Solution
{
public:
    int leastBricks(vector<vector<int>> &wall)
    {
        unordered_map<int, int> m;
        //Maintain a sort of prefix array with counts for each sum
        int max_surpass = 0;
        int res = wall.size();
        int sum;
        for (int i = 0; i < wall.size(); i++)
        {
            sum = 0;
            for (int j = 0; j < wall[i].size() - 1; j++)
            {
                sum += wall[i][j];
                m[sum] += 1;
                max_surpass = max(max_surpass, m[sum]);
            }
        }
        return wall.size() - max_surpass;
    }
};