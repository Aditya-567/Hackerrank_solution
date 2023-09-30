// You are given an array of length n and an number k which represents the length of the subarray of the given original array. 
//   This subarray has maximum average value. Find the average of the numbers in the subarray.

// Input Format

// The first line of each test case contains the elements of the array separated by spaces. 
//   The next line contains a number which represents the number of elements of the subarray which are required to calculate the maximum average

// Constraints

// null

// Output Format

// The first line of each test case must print the maximum average

// Sample Input 0

// 1 12 -5 -6 50 3
// 4

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> arr;
    int num, k;
    while (cin >> num) {
        arr.push_back(num);
        if (cin.get() == '\n') {
            break;
        }
    }

    cin >> k;

    int maxSum = 0;
    for (int a = 0; a < k; ++a) {
        maxSum += arr[a];
    }

    int currentSum = maxSum;
    for (int a = k; a < static_cast<int>(arr.size()); ++a) { 
        currentSum = currentSum - arr[a - k] + arr[a];
        maxSum = max(maxSum, currentSum);
    }


    double average = static_cast<double>(maxSum) / k;

    cout << average << endl;

    return 0;
}
