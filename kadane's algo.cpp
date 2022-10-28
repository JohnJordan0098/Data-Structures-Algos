// C++ program to print largest contiguous array sum
#include <bits/stdc++.h>
using namespace std;

//kadane's algorithm
int maxSubArraySum(int a[], int size)
{
	int max_sum = a[0];
  int curr_sum = a[0];

	for (int i = 0; i < size; i++) {
		curr_sum += a[i];
		if (max_sum < curr_sum)
			max_sum = curr_sum;

		if (curr_sum < 0)
			curr_sum = 0;
	}
	return max_sum;
}


int main()
{
	int a[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
	int n = sizeof(a) / sizeof(a[0]);

	// Function Call
	int max_sum = maxSubArraySum(a, n);
	cout << "Maximum contiguous sum is " << max_sum;
	return 0;
}
