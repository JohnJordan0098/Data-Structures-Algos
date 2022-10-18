#include <iostream>
using namespace std;

int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr)/sizeof(int);
    int m = n;
    
    
    for (int i = 0; i <= n-1;i++,n-- ){

        int temp = arr[i];
         arr[i]=arr[n-1];
         arr[n-1]=temp;


    }
       
        for (int i = 0; i < m; i++)
        {
            cout<<arr[i]<<" ";
        }
    return 0;
}