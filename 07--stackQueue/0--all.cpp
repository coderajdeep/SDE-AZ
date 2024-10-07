// [1-6] Basic implementation problem
// [3-4] need to know, otherwise hard to come up with solution

// TODO
// Need to implement circular queue ***
// Validate a prefix, infix or postfix expression ***
// Implement calculator

// 1
// Initially topIndex = -1
// Implement stack class -- coding ninjas

// 2
// Initially frontIndex = rearIndex = 0
// We enqueue in rearIndex and dequeue from frontIndex
// Implement queue class -- coding ninjas

// 3 **
// Approach 2 is easy to remember and intutive
// Approach 1 push(X) : insert X into Q2, insert all elements from Q1 to Q2 one by one (initially single entered element will be on top), 
// Then swap Q1 and Q2
// Approach 2 push(x) : Insert into Q, then insert size - 1 element pop and push to the queue
// Implement stack using queue -- leetcode 225

// 4 **
// Approach 1 push(x) : Insert from S1 to S2 one by one, then insert X into S1, then again insert from S2 to S1 one by one
// Approach 2 is very easy and optimize also **
// Implement queue using stack -- leetcode 232

// 5
// Need to maintain top as head of linkedlist
// Implement stack class using Linkedlist -- coding ninjas

// 6
// Need to maintain front as head and rear as tail of linked list
// Implement queue using linkedlist -- coding ninjas

// 7 **
// Stack based solution 
// https://www.geeksforgeeks.org/check-for-balanced-parentheses-in-an-expression/
// Constant space solution, but the string will be modified
// Checked for balanced paranthesis -- leetcode 20

// 8 ***
// Very very important problem
// O(n) solution is tricky ***
// In Push(val) : if val is less than minElement then (2*val-minElement) need to insert
// In getTop() : if top is less than minElement then need to return the minElement as a top element 
// In pop() : if top value is less than minElement then minElement = 2*minElement-topElement
// Implement Minimum stack -- leetcode 155

// Very Very important
// https://leetcode.com/problems/basic-calculator/solutions/414898/infix-to-postfix-a-general-approach-to-similar-questions/
// 9
// Infix to postfix expression  -- coding ninjas

// 10
// Prefix to infix expression -- coding ninjas

// 11
// Prefix to postfix -- coding ninjas

// 12
// Postfix to prefix -- coding ninjas

// 13
// Postfix to Infix -- coding ninjas

// 14 ***
// Tricky 
// reverse and exhange ( with ) and vice versa
// convert infixToPostfix
// again reverse and exhange ( with ) and vice versa
// Infix to Prefix -- coding ninjas

// 15
// Next greater element -- leetcode 496

// 16
// Have better method
// Next greater element II -- leetcode 503

// 17
// Next smalletr element  -- InterviewBit

// 18 ***
// Tricky 
// Need to use merge sort concept
// Similar to inversion count
// Number of NGE -- Coding Ninjas

// 19 ***
// Constant space solution is tricky ***
// Tapping Rainwater -- leetcode 42

// 20 ******
// Very very important
// *** 
// If an array has x+1+y element and x index (o based indexing) is val
// then there will be (x+1) * (y+1) subarray which will contain val
// subarray starting index [0 x] and ending index [x x+y]
// ***
// For handling duplicate case
// We are calculating what is the next smaller element in the left side
// And what is the next smaller or equal element in right side
// If we don't do this then for duplicate element, we will count double 
// [5 3 1 4 1 2] : for index 2 prev smaller index and next smaller index -1
// for index 4 prev smaller index and next smaller index -1
// So we are calculation 2 times when there is duplicate in array
// Sum of subarray minimum -- leetcode 907

// 21
// Asteroid Collision -- leetcode 735

// 22
// Sum of subarray ranges -- leetcode 2104

// 23
// Remove K digits -- leetcode 402

// 19
// Need to do this in one pass
// Largest Rectangle in histogram -- leetcode 84
