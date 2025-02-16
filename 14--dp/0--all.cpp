// 1
// N-th Fibonacci number -- geeks

// 2 **
// Same as n-th fibonacci number
// Climbing Stairs (distinct way to reach n-th stair) -- leetcode 70

// 3 **
// Similar to Climbing Stairs -- Here we just need the min Value not the total distinct way
// Geek Jump -- Geeks
// Frog Jump -- Coding Ninjas

// 4 ***
// If n >> k then we can solve this problem using monotonic deque
// Minimum cost -- geeks
// Here constant space solution is not possible
// Frog Jump with k distance -- Coding Ninjas

// 5 **
// Maximum sum of non-adjacent elements
// House Robber -- leetcode 198

// 6 ***
// Same as previous question, here just the given array is cyclic
// So we need to find max between o to n-2 and 1 to n-1 index
// House Robber II -- leetcode 213

// 7 ********
// We can use index == 0 and index < 0 as a base case
// This question can be asked as K task
// Ninja's training ***

// 8 **
// Base condition can be (i==0 || j==0) return 1
// Another base condition can be (i==0 && j==0) return 1 && (i<0 || j<0) return 0
// In memoization approach, recursive stack space time complexity is O(n + m)
// Unique path -- leetcode 62

// 9 **
// In question 8, second base condition can be used in here and aditionally we need to check if the current pont has obstacles or not
// If yes then we need to return 0
// if(r<0 || c<0) return 0; if(obstacleGrid[r][c]==1) return 0; if(r==0 && c==0) return 1;
// Unique Path II -- leetcode 63

// 10 **
// Minimum Path Sum -- leetcode 64

// 11 ***
// Fixed starting point
// Here we will start from fixed starting point and base case will be when we will touch the last row
// Even we can start from the last row and end to the fixed starting point, but here we need to handle out of bound cell cases
// Minimum path sum in triangle -- leetcode 120

// 12 ***
// Variable starting and ending point
// Here we can start the recursion (a) from the start row and finish to the end row 
// Or (b) from the last row and finish to the first row
// Second one is more easy to implement
// Minimum falling path in rectangle -- leetcode 931 

// 13 ***
// Need to solve cherry pick up
// https://leetcode.com/problems/cherry-pickup/solutions/290654/Java-brute-force-with-explanation-and-how-to-approach-this-problem-in-real-life/
// Solved tabulation as well as space optimize tabulation
// Cherry Pickup II -- leetcode 1463

// 14 **
// Need to try if the sum is negative
// In that case we need to use unordered_map
// Subset sum equal to K -- coding ninjas

// 15 **
// Simlar to subset sub equal to target (previous question)
// lets say each partion sum = n
// 2 * eachSum = sum
// eachSum = n / 2
// eachSum is an integer
// if not then partition is not possible 
// Partition equal subset sum -- leetcode 416

// 16 ***
// Little modification on subset sum with given k problem
// But if we need to consider two subset equal, then it will be very different ***
// Partition array into two subsets with minimum absolute sum difference -- coding ninja (leetcode 2035 need to try)

// 17 VVIP ***
// Base case 
// if(k<0) return 0;
// if(index==0) {
// if(k==0 && nums[0]==0) return 2;
// else if(k==0 || nums[0]==k) return 1;
// else return 0;
// }
// Edge case [0 0 0] k = 0
// Count subset with sum K -- Geeks / Coding Ninjas

// 18 ***
// s1 + s2 = sum
// s1 - s2 = d
// s2 = sum - d
// if s2 is odd or less than zero then ans is zero
// Otherwise find number of subset of sum s2
// Count Partition with given difference -- coding ninjas

// 19 **
// Not a DP problem
// Assign Cookies -- leetcode 455

// 20 ***
// Need to check overflow cases
// Coin Change -- leetcode 322

// 21 ***
// Similar to number of subsequence having sum K
// Count Partition with given difference
// Target Sum -- leetcode 494

// 22 ***
// Can be solved single 1D array
// Coin Changes II -- leetcode 518 

// 23 ***
// Space optimized using only one 1D array
// Max Profit from trading stocks (premium question)
// 0 1 Knapsack (Unbounder Knapsack) -- Geeks

// 24 ***
// Similar to 0 1 Knapsack (Only difference is here we need to complete the Knapsack)
// Rod cutting - Geeks

// 25 ***
// Base problem
// Longest Common Subsequence -- 1143

// 26 ***
// Print all lcs -- Geeks TLE (Not optimized)
// Print LCS -- Coding Ninjas

// 27 ***
// We can solve this using recursive + memoization
// But result will not store in dp[n][m], so after memoization
// We need to go through entire 2D array for getting the max value
// Space optimized solution only required one 1D array 
// Longest Common Substring length -- Coding Ninjas

// 28 ***
// Need to reverse the given string
// Find the lcs of actual string and reversed string
// Longest Palindromic Subsequence -- leetcode 516

// 29 ***
// ans --> (n - lcs)
// Minimum Insertion required to make a string palindrom -- leetcode 1312

// 30 ***
// Minimum delete operation to convert one string to another -- leetcode 583

// 31 ***
// Length of shortest common supersequence : (n + m - lcs)
// To get the supersequence, we to take the common element as well as the uncommon element
// When i or j will be zero then we need to completely take the other string
// Shortest common supersequence -- leetcode 1092

// 32
// Distinct Subsequence -- leetcode 115

// 33
// Edit distance -- leetcode 72

// 34
// Wild Card Matching -- leetcode 44 ***

// 35
// Best time to buy and sell stocks with single transaction -- leetcode 121

// 36
// Best time to buy and sell stocks II -- leetcode 122

// 37
// Best time to buy and sell stocks III -- leetcode 123

// 38   
// Best time to buy and sell stocks IV -- leetcode 188

// 41
// Longest Increasing Subsequence -- leetcode 300

// 42
// Print Longest Increasing Subsequence -- Coding Ninjas

// 43
// Largest Divisible subset -- leetcode 368

// 44
// Longest String Chain -- leetcode 1048

// 45
// Longest Biotonic subsequence -- Coding Ninjas

// 46
// Find Number of LIS -- leetcode 673

// 47
// Matrix Chain Multiplications -- Coding Ninjas

// 48
// Minimum Cost to Cut a stick -- leetcode 1547

// 49
// Max Coins for burst balloons -- leetcode 312

// 50
// Evaluate boolean expression to true -- Coding Ninjas

// 51
// Palindrome Partitioning II -- leetcode 132