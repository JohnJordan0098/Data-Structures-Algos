/* You are given a string SS of length NN, consisting of the digits 0-9 and the characters '+' and '-'. SS represents a valid mathematical expression.

Rearrange the characters of SS to form a valid mathematical expression such that the result obtained upon evaluating it is maximum.

If there are multiple possible answers, you may print any of them. */

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string str;
        cin >> str;
        int p = 0;
        int m = 0;
        vector<char> num;

        for (int i = 0; i < n; i++)
        {
            if (str[i] == '+')
            {
                p++;
            }
            else if (str[i] == '-')
            {
                m++;
            }
            else
            {
                num.push_back(str[i]);
            }
        }

        sort(num.begin(), num.end());

        string a = "";

        for (int j = 0; j < num.size(); j++)
        {
            if (m != 0)
            {
                a = a + num[j];
                a = a + '-';
                m--;
            }
            else if (p != 0)
            {
                a = a + num[j];
                a = a + '+';
                p--;
            }

            else
            {
                a = a + num[j];
            }
        }
        reverse(a.begin(), a.end());

        cout << a << endl;
    }

    return 0;
}
