// https://www.codechef.com/AUG221D/problems/AFLIP

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> ae, ao, be, bo;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if ((i + j) % 2 == 0)
                {
                    int x;
                    cin >> x;
                    ae.push_back(x);
                }
                else
                {
                    int x;
                    cin >> x;
                    ao.push_back(x);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if ((i + j) % 2 == 0)
                {
                    int x;
                    cin >> x;
                    be.push_back(x);
                }
                else
                {
                    int x;
                    cin >> x;
                    bo.push_back(x);
                }
            }
        }
        int s;
        if (m == 1 || n == 1)
        {

            if (ae == be)
            {
                if (ao == bo)
                {
                    s = 1;
                }
                else
                {
                    s = 0;
                }
            }
            else
            {
                s = 0;
            }
        }
        else
        {

            sort(ae.begin(), ae.end());
            sort(ao.begin(), ao.end());
            sort(be.begin(), be.end());
            sort(bo.begin(), bo.end());
            for (int i = 0; i < (n * m) / 2; i++)
            {
                if (ae[i] != be[i])
                {
                    s = 0;
                    break;
                }
                // 			else if (ae[i]!=be[i])
                // 			{
                // 				s=0;
                // 				break;
                // 			}
                else
                {
                    s = 1;
                }
            }
        }
        if (s == 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}