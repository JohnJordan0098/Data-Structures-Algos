class Solution
{
public:

    #include <bits/stdc++.h>
    
    int minimizeArrayValue(vector<int> &nums)
    {
        long long int min = nums[0];
        long long int c = 0;
        long long int n = nums.size();
        for (int i = 1; i < n; i++)
        {

            if (min >= nums[i])
            {
                c += (min - nums[i]);
            }

            else if ((long)nums[i] - min <= c)
            {
                c -= ((long)nums[i] - min);
            }

            else
            {
                long long int val11 = ((long)nums[i] - min) - c;
                c = 0;
                long long int cnt = i + 1;
                min = min + val11 / cnt;
                long long int gg = val11 % cnt;
                if (gg > 0)
                {
                    min++;
                    c += ((long)cnt - gg);
                }
            }
        }
        return (int)min;
    }
};