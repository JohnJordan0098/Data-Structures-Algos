#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void push_zeros_to_end(std::vector<int> &arr)
{
    stable_partition(arr.begin(), arr.end(), [](int n)
                     { return n != 0; });
}

int main()
{
    vector<int> arr{1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9};

    push_zeros_to_end(arr);

    for (const auto &i : arr)
        cout << i << ' ';

    cout << "\n";

    return 0;
}
