// Task Scheduler -- leetcode 621
// Time complexity O(NlogN)
// Space complexity O(3*D) --> D : total distinct task
int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char, int> umap;
    for(char task : tasks) {
        umap[task]++;
    }
    priority_queue<int> maxHeap;
    for(pair<int, int> p : umap) {
        maxHeap.push(p.second);
    }
    queue<pair<int, int>> cooldownTask;
    int time = 0;
    while(!maxHeap.empty() || !cooldownTask.empty()) {
        ++time;
        // as CPU can only process one task at a time
        // there will be max one task which is about to enter 
        // task queue from cooldown queue
        if(!cooldownTask.empty() && cooldownTask.front().second <= time) {
            maxHeap.push(cooldownTask.front().first);
            cooldownTask.pop();
        }
        if(!maxHeap.empty()) {
            int remainingTime = maxHeap.top() - 1;
            maxHeap.pop();
            if(remainingTime > 0) {
                cooldownTask.push(make_pair(remainingTime, time + n + 1));
            }
        }
    }
    return time;
}