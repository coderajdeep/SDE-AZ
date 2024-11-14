// 1
// Binary serach on array - leetcode 704

// 2
// Implement lower bound for non decreasing array - coding ninja

// 3
// Implement upper bound for non decreasing array - coding ninja

// 4
// Search insert position - leetcode 35

// 5
// Ceil and floor in sorted array - coding ninjas

// 6
// First and last occurance in array - leetcode 34

// 7
// Number of occurance in sorted array

// 8
// Search in rotated sorted array - leetcode 33

// 9
// Search in rotated sorted array - leetcode 81

// 10
// Find minimum in rotated sorted array - leetcode 153

// 11
// Find rotation count in rotated sorted array - Coding ninjas

// 12
// Find single element in sorted array -- leetcode 540

// 13
// Find Peak element in array -- leetcode 162

// 14 ***
// Square root of a number -- coding ninjas ***

// 15 ***
// N-th rooth of M -- coding ninjas ***

// 16 ***
// Koko eating bananas -- leetcode 875

// 17
// Minimum number of days to make m bouquets -- leetcode 1482

// 18
// Find the smallest divisor -- leetcode 1283

// 19
// Capacity to ship packages within D days -- leetcode 1011

// 21
// Aggressive Cow | Magnetic Force between two balls -- leetcode 1552

// 26
// Median of two sorted array -- leetcode 4

// 28 ***
// Row with maximum 1's
// Can be solve with binary search
// But best approach has time complexity O(n+m)
// if r = 0, c = m-1
// if arr[r][c] == 1 : move left else move down
// at the end if c == m-1 then there is no 1 present and return -1
// else return c

// 29 **
// Search in a sorted matrix -- leetcode 74

// 30 ***
// Similar to 28 (Row with maximum 1's)
// Search in a sorted matrix II -- leetcode 240

// 31 ***
// Similar to pick element in 1D array
// Here we have to find the largest element in a perticular column
// And need to check if it is the peak or not
// Else we need to eleminate one half
// Find a peak element II -- leetcode 1901

// 32 ***
// Answer will be between lowest and largest element
// Need to do binary search between this two element
// Answer(Median) : mid will be the smallest possible number for which count > expectedCount
// count : number of element in the matrix which is less than equal to mid
// expectedCount + [1 or more] : atleast this amount of number should be less or equal than mid
// Median of row wise sorted matrix
