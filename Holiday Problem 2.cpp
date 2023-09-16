// Your best friend from America is coming to visit you in Melbourne, Australia. "I hope the weather is nice," he says unaware of what Melbourne has in store for him.
// Your friend has indentified n consecutive days over which he could be in Melbourne but has not yet decided how long to stay.
// You have looked up the weather report for those n days and noted the temperature for each one. Your friend would like to experience all of the different temperatures of Melbourne.
// Determine the minimum number of consecutive days your friend must stay in order to experience every temperature.
// That is, what is the smallest value of t such that no matter which of the first n-t+1 day your friend arrives,
// they will experience every different temperature at some point during their t day trip?

// Input Format

// The first line contains an integer n (1

// Constraints

// NULL

// Output Format

// display the minimum number of consecutive days your friend must stay

// Sample Input 0

// 6
// 40 40 10 10 50 50 
// Sample Output 0

// 4

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std; // Added this line

long long minConsecutiveDays(long long n, vector<long long>& temperatures) {
    set<long long> uniqueTemperatures(temperatures.begin(), temperatures.end());
    long long numUniqueTemperatures = uniqueTemperatures.size();

    unordered_map<long long, long long> frequency;
    long long left = 0;
    long long minDays = n;

    for (long long right = 0; right < n; ++right) {
        long long temp = temperatures[right];
        frequency[temp]++;

        while (frequency.size() == static_cast<size_t>(numUniqueTemperatures)) {
            minDays = min(minDays, right - left + 1);
            frequency[temperatures[left]]--;

            if (frequency[temperatures[left]] == 0) {
                frequency.erase(temperatures[left]);
            }

            left++;
        }
    }

    return minDays;
}

int main() {
    long long n;
    cin >> n;
    vector<long long> temperatures(n);

    for (long long i = 0; i < n; ++i) {
        cin >> temperatures[i];
    }

    long long result = minConsecutiveDays(n, temperatures);
    cout << result << endl;

    return 0;
}
