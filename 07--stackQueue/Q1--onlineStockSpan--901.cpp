// Online stock span -- leetcode 901
// Question asked in OYO Rooms
// Given list of temperatures
// Find the number of previous consicutive day when temperature was less than or equal to the current day
// Interview Question
// [100, 60, 70, 65, 20, 80, 105] - Sample input
// [  1,  1,  2,  1,  1,  5,   7] - Sample output
// Time complexity O(1) for each function call
// Space complexity O(n)

class StockSpanner {
private:
    stack<pair<int, int>> stk;
    int index;
public:
    StockSpanner() {
        index = 0;
        while(!stk.empty()) {
            stk.pop();
        }
    }
    
    int next(int price) {
        while(!stk.empty() && stk.top().first <= price) {
            stk.pop();
        }
        int ans;
        if(stk.empty()) {
            ans = index+1;
        }
        else {
            ans = index - stk.top().second;
        }
        stk.push({price, index++});
        return ans;
    }
};