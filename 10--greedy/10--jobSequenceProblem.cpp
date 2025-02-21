// Time complexity O(nlogn + n*maxDeadline)
// Space complexity O(4*n)

class Solution {
private:
    struct Job {
        int id;
        int deadline;
        int profit;
        Job(int id, int deadline, int profit) {
            Job::id = id;
            Job::deadline = deadline;
            Job::profit = profit;
        }
        Job() {}
    };
    static bool compJob(Job& job1, Job& job2) {
        if (job1.profit == job2.profit) {
            return job1.deadline > job2.deadline;
        }
        return job1.profit > job2.profit;
    }
public:
    vector<int> JobSequencing(vector<int> &ids, vector<int> &deadlines, vector<int> &profits) {
        int n = ids.size();
        vector<Job> arr(n);
        int maxDeadline = 0;
        for (int i = 0; i < n; ++i) {
            arr[i] = { ids[i], deadlines[i], profits[i] };
            maxDeadline = max(maxDeadline, deadlines[i]);
        }
        vector<int> hash(maxDeadline+1, -1);
        sort(arr.begin(), arr.end(), compJob);
        int profit = 0, count = 0;
        for (int i = 0; i < n; ++i) {
            // This inner loop can be optimized using Disjoint Set Data Structure
            for(int j = arr[i].deadline; j>=1; --j) {
                if(hash[j] == -1) {
                    profit += arr[i].profit;
                    hash[j] = arr[i].id;
                    ++count;
                    break;
                }
            }
        }
        return vector<int> {count, profit};
    }
};