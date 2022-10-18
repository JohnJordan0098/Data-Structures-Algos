class Solution
{
public:
    int trap(vector<int> &height)
    {
        int len = height.size();

        int temp = 0;
        int res = 0;
        int curr_max = 0;
        for (int i = 1; i < len; i++)
        {
            if (height[i] >= height[curr_max])
            {
                res += (i - curr_max - 1) * height[curr_max] - temp;
                curr_max = i;
                temp = 0;
            }
            else
            {
                temp += height[i];
            }
        }
        temp = 0;
        curr_max = len - 1;
        for (int i = len - 2; i >= 0; i--)
        {
            if (height[i] > height[curr_max])
            {
                res += (curr_max - i - 1) * height[curr_max] - temp;
                curr_max = i;
                temp = 0;
            }
            else
            {
                temp += height[i];
            }
        }

        return res;
    }
};
