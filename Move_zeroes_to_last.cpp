#include <bits/stdc++.h>
using namespace std;
 

void reorder(int A[], int n)
{
    // `k` stores the index of the next available position
    int k = 0;
 
    // do for each element
    for (int i = 0; i < n; i++)
    {
        // if the current element is non-zero, put the element at the
        // next free position in the array
        if (A[i] != 0) {
            A[k++] = A[i];
        }
    }
 
    // move all 0's to the end of the array (remaining indices)
    for (int i = k; i < n; i++) {
        A[i] = 0;
    }
}
 
int main(void)
{
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    
    reorder(A, n);
 
    for (int i = 0; i < n; i++) {
        cout<<A[i];
    }
    return 0;
}