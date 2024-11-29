// TODO
// 36 Will do bit manipulation way 

// 1
// Largest element in an array

// 2
// Leetcode 414 : 3rd largest element
// Find 2nd largest and 2nd smallest element

// 3 ***
// Check if and array is sorted or not - coding ninjas (We can't check if an array is sorted or not in logN complexity)
// *** Check if and array is sorted and rotated -- leetcode 1752

// 4 ***
// size will track the total unique elements in array (initially size = 1)
// need to traverse i=1 to i=n-1 and check if (arr[i-1]<arr[i]) then arr[size++] = arr[i]
// *** Remove duplicate from sorted array -- leetcode 26

// 5
// Left Rotation or Anti clockwise rotation of an array by one -- Coding Ninjas

// 6 
// Right Rotation or Clockwise Rotation by K -- leetcode 189

// 7 ***
// Move All Zeroes to the end of the array -- leetcode 283
// Track non zero element index
// If the element != 0 then swap(arr[i], arr[index++])
// ***One traversal solution is important

// 8
// Linear Search -- Coding Ninjas

// 9 ***
// while inserting into ans array, just need to check ans.empty() || ans.back()!=arr[i]
// *** Union of array -- Coding Ninjas / Geeks

// 10 *
// Constant space solution is using XOR
// Missing Number in an array -- leetcode 268

// 11 ***
// Initially cnt = 0 , maxCnt = 0
// if element == 1 then ++cnt and maxCnt = max(cnt, maxCnt)
// else cnt = 0
// at the end maxCnt is the answer
// *** Maximum Consecutive one  -- leetcode 485
// leetcode 1004
// Maximum consecutive one III
// leetcode 487
// https://leetcode.ca/all/487.html
// Maximum consecutive one II
// Here k = 1

// 12 *
// Constant space solution is using XOR
// Find only single element in array  -- leetcode 136
// Find single element in sorted array -- leetcode 540
// mid is odd
// 0 1 2 3 4 5 6 -> index
// 1 1 2 3 3 4 4
// 1 1 2 2 3 4 4
// mid is even
// 0 1 2 3 4 5 6 7 8 -> index
// 1 1 2 3 3 4 4 5 5
// 1 1 2 2 3 3 4 5 5

// 13 ***
// Very very important
// *** Find the largest subarray with given sum when array elements are non negative -- coding ninjas

// 14
// Very very important
// *** Find the largest subarray with given sum when array elements can be negative

// 15
// 2sum Problem -- leetcode 1

// 16 ***
// [0 - (low-1)] : 0
// [low - (mid-1)] : 1
// [mid - (high-1)] : 0/1/2
// [high - (n-1)] : 2
// Duch national flag algo
// Time complexity O(n)
// Space complexity O(1)
// *** Sort 0 1 2 - sort colors -- leetcode 75

// 17 ***
// We can also solve this using unordered_map or unordered_multiset
// If any element's frequency is greater than (n/2) then its a majorith element
// Moore's voting algorithm
// If it's not guaranteed that majority element will exist
// Then we need to check the count of the element we get from moore's voting algorithm 
// *** Majority Element -- leetcode 169

// 18 ***
// Maximum subarray sum - Kadane's Algorithm -- leetcode 53

// 20 **
// We Need to also tell what is the buy and sell day
// Best Time to buy and sell stock -- leetcode 121

// 21
// *** Rearrange when even and odd nums are not equal
// Rearrange array in alternative way -- leetcode 2149

// 22 ***
// Need to traverse from right to left and check arr[i]<arr[i+1] : pivot = i
// If pivot is -1 the reverse the array, modified array is the answer
// Otherwise traverse again from n-1 to i>pivot and if arr[i]>arr[pivot] then swap arr[i] and arr[pivot]
// Now reverse arr.begin() + pivot + 1 to arr.end()
// Next Permutation -- leetcode 31

// 23
// Leaders in an array -- Coding Ninjas

// 24 ***
// Need to insert all of the elements in unordered_set
// if curr-1 is not exist in unordered_set then curr is the starting point for a new sequence
// If we use sorting then need to think about the case : array acn have duplicate element
// Longest Consecutive Sequence -- leetcode 128

// 25 ***
// In place solution is tricky while filling the zero
// for first col, we need to track another variable because for matrix[0][0], row and column will be overlap
// Set Matrix Zero -- leetcode 73

// 26 ***
// if the matrix is a rectangular matrix, then in place rotation is tough
// 90 degree : (i, j) --> (j, n-1-i)
// 180 degree : (i, j) --> (n-1-i, n-1-j)
// 270 degree : (i, j) --> (n-1-j, i)
// 360 degree : (i, j) --> (j, j)
// Rotate a matrix by clockwise 90 degree -- leetcode 48

// 27 ***
// Print matrix in spiral order  -- leetcode 54

// 28 ***
// Need to think about this test case 
// Arr : [1]
// K = 0
// Answer should be 0
// Count Subarray with given sum -- leetcode 560

// 29 **
// Pascal Triangle 1 -- leetcode 118

// 30 *** 
// Uisng constant space is tricky
// Initially e1 = e2 = INT_MIN and c1 = c2 = 0
// if e1==e or e2==e then increase counter of that element
// if above condition not true then assign e to e1/e2 if the counter is zero and make counter 1
// otherwise decrease both counter
// After the iteration, need to do majority check. This is mandatory
// Majority Element II  -- leetcode 229

// 31 ***
// 3sum problem
// Hashing approach will give TLE
// Array can have duplicates
// Need to handle duplicate tuplets
// Need to use Two pointer approach

// 32 ***
// 4sum problem
// Similar to 3sum
// Array can have duplicates
// Two pointer approach
// Addition to 3sum, here we need to use another extra loop

// 33 ***
// Count number of subarray with given sum target
// This is same as question 27

// 34 ***
// CodingNinjas & InterviewBit
// Count number of subarray with given xor target
// Same as question 27 and 33

// 35 ***
// Need to sort the intervals based on starting time
// So starting point will be in the sorted order
// endValue < intervals[i].start => distinct intervals
// otherwise overlap interval endValue = max(endValue, intervals[i][1])
// Merge Intervals

// 36 ***
// Merge two sorted array without extra space -- leetcode 88
// We need to swap element based on arr1[i--]>arr2[j++]
// This will make sure all elements in arr1 is less than arr2
// The sort arr1 and arr2 seperately

// 37 ***
// Missing and repeating number -- Geeks
// Hasing approach and mathematical approach are simple
// In mathematical approach, we need to use static_cast<type> ***
// Bit manipulation approach is difficult

// 38 ***
// In merge sort need to do start<end, if we put equal sign then this will goes to infinite loop
// Need to get count while merging two sorted array
// Inversion count -- leetcode 

// 39 ***
// Reverse Pairs -- leetcode 493
// Difference between this with Inversion count is in merge two sorted array case
// Because for this question, we need to check arr[i] > 2*arr[j]
// So in else part, we can't say arr[i] < arr[j], so we can merge this
// So we need to getCount and merge two sorted array in seperate function

// 40 ***
// Subarray with maximum product -- leetcode 152

// Q1
// Determine Whether Matrix Can Be Obtained By Rotation -- 1886

// Q2
// Spiral Matrix II -- leetcode 59

// Q3
// Pascal Triangle II -- leetcode 119

// Q4 ***
// Similar to Overlap intervals
// Days without meeting -- leetcode 3169 (weekly 400)