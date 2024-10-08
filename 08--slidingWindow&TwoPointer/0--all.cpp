// Generally Sliding window problem does not work with negative numbers

// 1 ***
// If curr is not in hash or hash[curr] < low : then maxlen = max(maxLen, high-low+1)
// Else update low : low = hash[curr] + 1
// At the end update curr in hash and increase high
// Longest substring without repeating character -- leetcode 3

// 2 •••
// If curr == 0 || count<k then find maxLen and increase high
// Else : arr[low] == 0 then decrease count after that increase low
// For consecutive one II has k = 1
// Max consecutive one III -- leetcode 1004

// 3 **
// Similar to longest subarray having K distinct element
// Here K = 2
// Fruit into basket

// 4 ***
// WindowLength - maxFrequency <= K then the window is valid
// Longest Repeating character replacement -- leetcode 424

// 5 ***
// Constant space solution is tricky
// This constant space solution will not work if arr[i]<0
// Similar with number of subarray with given sum
// Binary subarray with given sum -- leetcode 930

// 6 ***
// Just assume odd numbers are 1 and even numbers are zero
// Similar with number of subarray with given sum
// Count number of nice subarray -- leetcode 1248

// 7 ***
// Need to store the recent occerance of character
// If all character exist, then count += (min(a, b, c) + 1)
// Number of substring containing all three characters -- leetcode 1358

// 8 **
// First calculate lsum
// then remove (k-1-i) indexed value from lsum and add (n-1-i) indexed value in rsum
// Max point you can obtain from cards -- leetcode 1423

// 9
// Longest substring with at most K distinct character -- leetcode 340

// 10
// Total Subarray with K different Integers -- leetcode 992

// 11
// Minimum window substring -- leetcode 76

// 12
// Minimum window subsequence -- leetcode 727

// Q1
// Similar binary subarray with given sum -- leetcode 930
// Count subarray with score less than K

// Q2
// Similar binary subarray with given sum -- leetcode 930
// Count subarray with product less than K