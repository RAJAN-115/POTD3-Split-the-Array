#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int countGroups(vector<int>& arr) {
        int res = 0;
        for (auto& num : arr) {
            res ^= num; // Calculate total XOR
        }
        
        // If total XOR is not 0, return 0
        if (res != 0) return 0;

        // If total XOR is 0, return the size of the array
        return arr.size(); // Return the number of elements in the array
    }
};

int main() {
    string ts;
    getline(cin, ts); // Read the number of test cases
    int t = stoi(ts);
    
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the input line
        
        stringstream ss(input); // Use stringstream to read numbers
        int number;
        while (ss >> number) {
            arr.push_back(number); // Add each number to the array
        }

        Solution obj; // Create an instance of Solution
        int ans = obj.countGroups(arr); // Call the function
        cout << ans << endl; // Print the result
    }
    
    return 0;
}
