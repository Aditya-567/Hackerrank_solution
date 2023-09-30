// You are given an array of length n and an number k which represents the length of the subarray of the given original array.
//   This subarray has maximum average value. Find the average of the numbers in the subarray.

// Input Format

// The first line of each test case contains the elements of the array separated by spaces. 
// The next line contains a number which represents the number of elements of the subarray which are required to calculate the maximum average

// Constraints

// null

// Output Format

// The first line of each test case must print the maximum average

// Sample Input 0

// 1 12 -5 -6 50 3
// 4
// Sample Output 0

// 12.75

#include <iostream>
#include <vector>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    vector<int> arr;
    int num, k;
    while (cin >> num) {
        arr.push_back(num);
        if (cin.get() == '\n') {
            break;
        }
    }
    float maxavg=0;
    cin >> k;
    int n=arr.size();
    for (int i = 0; i <= n - k; i++) {
        float sum = 0;
        for (int j = i; j < i + k; j++) {
            sum += arr[j];
        }
            if(sum>maxavg){
            maxavg=sum;
        }
    }
    float ans=maxavg/k;
    cout<<ans<<endl;

    return 0;
}
