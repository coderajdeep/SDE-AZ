// Asteroid Collision -- leetcode 735

// Time complexity O(n)
// Space complexity O(n)
vector<int> asteroidCollision(vector<int>& asteroids) {
    int n = asteroids.size();
    stack<int> stk;
    for(int i=0; i<n; ++i) {
        // need to insert if stack is empty or element is positive
        if(stk.empty() || asteroids[i] > 0) {
            stk.push(asteroids[i]);
        }
        else {
            // asteroids[i] is negative
            // destroy all of the astroid which have lower value than the current astroid
            while(!stk.empty() && stk.top()>0 && stk.top() < abs(asteroids[i])) {
                stk.pop();
            }
            // if stk top and current astroid is equal then both will destroy
            if(!stk.empty() && stk.top()>0 && stk.top() == abs(asteroids[i])) {
                stk.pop();
            }
            // if all of the astroid has been destroid or astroid is moving to oposite direction
            else if(stk.empty() || stk.top() < 0) {
                stk.push(asteroids[i]);
            }
            // ***
            // if asteroids[i] is negative and stk.top() > abs(asteroids[i])
            // this asteroids[i] will be destroyed and will not inserted into the stack
        }
    }
    int size = stk.size();
    vector<int> ans(size);
    for(int i=size-1; i>=0; --i) {
        ans[i] = stk.top();
        stk.pop();
    }
    return ans;
}