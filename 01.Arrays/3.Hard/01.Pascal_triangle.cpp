/*
**Question:**

Given an integer `rowIndex`, return the `rowIndex`th (0-indexed) row of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: `rowIndex = 3`

Output: `[1, 3, 3, 1]`
*/

/*
**APPROACH:**
To generate the `rowIndex`th row of Pascal's triangle, we can use the property that each number is the sum of the two numbers directly above it. We start with the base case of the first row, which is `[1]`. Then, for each subsequent row, we calculate the elements using the formula `C(n, k) = C(n-1, k-1) * (n-k+1) / k`, where `C(n, k)` represents the binomial coefficient.

**CODE:**
*/

vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for (int i = 0; i < numRows; i++) {
            vector<int> row(i + 1, 1);
            for (int j = 1; j < i; j++) {
                row[j] = result[i - 1][j - 1] + result[i - 1][j];
            }
            result.push_back(row);
        }
        return result;
    }

/*
**COMPLEXITY ANALYSIS:**
- Time Complexity: O(rowIndex)
  - We iterate over each element in the row and calculate its value using the binomial coefficient formula.
- Space Complexity: O(rowIndex)
  - We use additional space to store the row of Pascal's triangle.

Overall, the algorithm has a linear time complexity and linear space complexity.
*/
