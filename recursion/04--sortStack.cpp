// Geeks
// Time complexity O(n*n)
// Space complexity O(n)
void insert(stack<int> &stk, int temp) {
    if(stk.empty() || stk.top()<temp) {
        stk.push(temp);
        return;
    }
    int val = stk.top();
    stk.pop();
    insert(stk, temp);
    stk.push(val);
}
void SortedStack :: sort()
{
   if(s.empty() || s.size()==1) {
       return;
   }
   int temp = s.top();
   s.pop();
   sort();
   insert(s, temp);
}

// https://leetcode.com/discuss/interview-question/algorithms/125398/Given-a-stack-sort-it-in-non-decreasing-order/1207410
// https://ide.geeksforgeeks.org/online-cpp14-compiler/ea73ea7b-c61e-4fd3-8964-df98437ed7b4
#include <bits/stdc++.h>
using namespace std;

void stackInsertDec(stack<int> &stk, int temp) {
    if(stk.empty() || stk.top()<=temp) {
        stk.push(temp);
        return;
    }
    int val = stk.top();
    stk.pop();
    stackInsertDec(stk, temp);
    stk.push(val);
}

void stackSortDec(stack<int> &stk) {
    if(stk.empty() || stk.size()==1) {
        return;
    }
    int temp = stk.top();
    stk.pop();
    stackSortDec(stk);
    stackInsertDec(stk, temp);
}

void stackInsertInc(stack<int> &stk, int temp) {
    if(stk.empty() || stk.top()>=temp) {
        stk.push(temp);
        return;
    }
    int val = stk.top();
    stk.pop();
    stackInsertInc(stk, temp);
    stk.push(val);
}

void stackSortInc(stack<int> &stk) {
    if(stk.empty() || stk.size()==1) {
        return;
    }
    int temp = stk.top();
    stk.pop();
    stackSortInc(stk);
    stackInsertInc(stk, temp);
}

void printStack(stack<int> &stk) {
    while(!stk.empty()) {
        cout<<stk.top()<<" ";
        stk.pop();
    }
    cout<<endl;
} 

int main() {
	stack<int> stk;
	stk.push(7);
	stk.push(2);
	stk.push(5);
	stk.push(1);
	stk.push(6);
	stk.push(3);
	stk.push(3);
	stack<int> stk2 = stk;
	stackSortDec(stk);
	stackSortInc(stk2);
	printStack(stk);
	printStack(stk2);
	return 0;
}