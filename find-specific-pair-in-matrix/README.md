# Find  Specific Pair in Matrix

## Problem:
Given an `n x n` matrix `matrix[n][n]` of integers, find the maximum value of 
`matrix(c,d) - matrix(a,b)` such that `c > a` and `d > b`.

## Example:
```
Input:
matrix[n][n] = {{1, 2, -1, -4, -20},
				{-8, -3, 4, 2, 1},
				{3, 8, 6, 1, 3},
				{-4, -1, 1, 7, -6},
				{0, -4, 10, -5, 1}};
Output: 18
The maximum value is 18 as 
	matrix[4][2] - matrix[1][0] = 18
has maximum difference.
```