# Split the Array 🔗

## Problem Overview 📝

**Goal**: Count the number of ways to split an array into two groups such that the XOR of the numbers in both groups is the same.

---

## Key Concepts 💡

### XOR Basics
- **XOR (Exclusive OR)**: Compares two bits. If they differ, it results in `1`; if they are the same, it results in `0`.

  **Example**:
  \[
  ( 1 , \text{(binary: 01)} )
  \]
  \[
  ( 2 , \text{(binary: 10)} )
  \]
  \[
  ( 1 , \text{XOR} , 2 = 3 , \text{(binary: 11)} )
  \]

### Important Property
- XOR cancels out identical numbers:
  - \( x \, \text{XOR} \, x = 0 \)

---

## Examples 📊

### Example 1: Input Array `[1, 2, 3]`

1. **Calculate Total XOR**:
   \[
   ( 1 , \text{(binary: 01)} ) \, \text{XOR} \, ( 2 , \text{(binary: 10)} ) \, \text{XOR} \, ( 3 , \text{(binary: 11)} )
   \]
   - Step-by-step calculation:
     - \[
     ( 1 , \text{(binary: 01)} ) \, \text{XOR} \, ( 2 , \text{(binary: 10)} ) = 3 \, \text{(binary: 11)}
     \]
     - \[
     ( 3 , \text{(binary: 11)} ) \, \text{XOR} \, ( 3 , \text{(binary: 11)} ) = 0 \, \text{(binary: 00)}
     \]
   - **Final XOR Result**: `0`

2. **Interpret the Result**:
   - Total XOR is `0`, so we can split the array.

3. **Find Possible Splits**:
   - Valid groupings:
     - Group 1: `{1}`, Group 2: `{2, 3}`
     - Group 1: `{2}`, Group 2: `{1, 3}`
     - Group 1: `{3}`, Group 2: `{1, 2}`
   - **Total Ways**: `3 ways`

---

### Example 2: Input Array `[5, 2, 3, 2]`

1. **Calculate Total XOR**:
   \[
   ( 5 , \text{(binary: 101)} ) \, \text{XOR} \, ( 2 , \text{(binary: 010)} ) \, \text{XOR} \, ( 3 , \text{(binary: 011)} ) \, \text{XOR} \, ( 2 , \text{(binary: 010)} )
   \]
   - Step-by-step calculation:
     - \[
     ( 5 , \text{(binary: 101)} ) \, \text{XOR} \, ( 2 , \text{(binary: 010)} ) = 7 \, \text{(binary: 111)}
     \]
     - \[
     ( 7 , \text{(binary: 111)} ) \, \text{XOR} \, ( 3 , \text{(binary: 011)} ) = 4 \, \text{(binary: 100)}
     \]
     - \[
     ( 4 , \text{(binary: 100)} ) \, \text{XOR} \, ( 2 , \text{(binary: 010)} ) = 6 \, \text{(binary: 110)}
     \]
   - **Final XOR Result**: `6`

2. **Interpret the Result**:
   - Total XOR is `6` (not `0`), so we **cannot** split the array.
   - **Total Ways**: `0 ways`

---

## Summary 📈

- **For `arr = [1, 2, 3]`**: `3` valid splits (XOR = `0`).
- **For `arr = [5, 2, 3, 2]`**: `0` valid splits (XOR ≠ `0`).

---

## Conclusion 🎯

### To Solve This Problem:
1. Calculate the XOR of all elements.
2. If the result is `0`, count the valid ways to split.
3. If the result is not `0`, return `0`.

---

## YouTube Tutorial 📺
For a detailed explanation, check out this video: [Counting Ways to Split an Array](https://youtu.be/r2XB6qWcizw?si=6_oHzJkZuEAArztl)

---

## Implementation 💻

Here’s a sample implementation in C++:

```cpp
#include <iostream>
#include <vector>
using namespace std;

int countWaysToSplit(vector<int>& arr) {
    int totalXor = 0;
    for (int num : arr) {
        totalXor ^= num;
    }

    // If total XOR is not 0, return 0
    if (totalXor != 0) return 0;

    // Count the ways to split the array
    return (1 << (arr.size() - 1)) % 1000000007;
}

int main() {
    vector<int> arr = {1, 2, 3};
    cout << "Ways to split: " << countWaysToSplit(arr) << endl;
    return 0;
}
