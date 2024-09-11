// 00
// Basic heap implementation

// 1
// Implement Priority Queue POP Method (similar to extract min or max value)

// 2
// Implement Min Heap

// 3 **
// All the leaf node follows heap property (n/2 to n-1 indexed element)
// Need to check internal nodes if they are following heap property (0 to n/2 - 1 indexed element)
// Check if an array is Max Heap or not

// 4 *
// Use build heap method (Time O(n))
// Min Heap to max Heap

// 5 **
// For largest, use min heap
// K'th largest element -- leetcode 215

// 6 **
// For smallest, use max heap
// K'th smallest element -- geeks

// 7 ***
// Use min heap (node structure --> nodeValue, positionInTheMatrix, positionInTheArray)
// Heap will be based on nodeValue
// Sort K sorted array -- geeks

// 8 ***
// Similar to above problem 7
// Merge M sorted List -- 23

// 9 **
// https://youtu.be/179XocEJcLY
// Uisng Min Heap
// push {element, index} into the min heap
// pop one by one and fill the rank array
// handle duplicate elements
// Rank Transform of an array -- leetcode 1331

// 10
// Task Scheduler -- leetcode 621

// 14
// K-Largest element in integer stream -- leetcode 703

// 15 ***
// Maximum sum combination -- Geeks

// 16
// Median in data stream -- leetcode 295