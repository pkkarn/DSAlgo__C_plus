#include <iostream>
using namespace std;


void bubbleSort(int arr[], int N) {

   for(int  i = 0; i<N - 1; i++) {
    //  start j at 0 and at each iteration 1 item from last will get sorted. So 
    // you can keep length in j after each iteration of i [i<n-i-1]
       for(int j = 0; j < N - i - 1; j++) {
            cout<< i << "-" << j+1 << endl;
           if(arr[j] > arr[j+1]) {
            
                
               swap(arr[j], arr[j+1]);
           }
       }
   }
}

void printArray(int arr[], int N) {
    for(int i=0; i<N; i++) {
        cout<<arr[i] << endl;
    }
} 



int main() {
    int arr[] {1,3,2,34,34,345345,332,2};
    
    int N = sizeof(arr) / sizeof(arr[0]); // To calculate size;
    
    bubbleSort(arr, N);
    printArray(arr, N);
}
