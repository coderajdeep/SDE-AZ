// Geeks training

// Memoization -- top down approach
// Time complexity O(n*12)
// Space complexity O(n*4) + O(n) : Recursion stack space
class Solution {
  public:
    int solve(int index, int lastTask, vector<vector<int>> &points, vector<vector<int>> &dp) {
        if(index==0) {
            int maxPoints = INT_MIN;
            for(int i=0; i<3; ++i) {
                if(i!=lastTask) {
                    maxPoints = max(maxPoints, points[0][i]);
                }
            }
            return maxPoints;
        }
        
        if(dp[index][lastTask]!=-1) return dp[index][lastTask];
        
        int maxPoints = INT_MIN;
        for(int i=0; i<3; ++i) {
            if(i!=lastTask) {
                maxPoints = max(maxPoints, points[index][i] + solve(index-1, i, points, dp));
            }
        }
        return dp[index][lastTask] = maxPoints;
    }
    int maximumPoints(vector<vector<int>>& points, int n) {
        vector<vector<int>> dp(n, vector<int>(4, -1));
        int ans =  solve(n-1, 3, points, dp);
        return ans;
    }
};

// Tabulation -- Bottom Up approach
// Time complexity O(n*4*3) ~ O(n*12) ~ O(n)
// Space complexity O(n*4) ~ O(n)
int maximumPoints(vector<vector<int>>& points, int n) {
	vector<vector<int>> dp(n, vector<int>(4));
	for(int i=0; i<4; ++i) {
		int maxPoint = INT_MIN;
		for(int j=0; j<3; ++j) {
			if(i!=j) {
				maxPoint = max(maxPoint, points[0][j]);
			}
		}
		dp[0][i] = maxPoint;
	}
	for(int index=1; index<n; ++index) {
		for(int i=0; i<4; ++i) {
			int maxCost = INT_MIN;
			for(int j=0; j<3; ++j) {
				if(i!=j) {
					maxCost = max(maxCost, points[index][j] + dp[index-1][j]);
				}
			}
			dp[index][i] = maxCost;
		}
	}
	return dp[n-1][3];
}


// Space optimized Tabulation -- Bottom Up approach
// Time complexity O(n*4*3) ~ O(n*12) ~ O(n)
// Space complexity O(2*4) ~ constant space
int maximumPoints(vector<vector<int>>& points, int n) {
	vector<int> curr(4), prev(4);
	for(int i=0; i<4; ++i) {
		int maxPoint = INT_MIN;
		for(int j=0; j<3; ++j) {
			if(i!=j) {
				maxPoint = max(maxPoint, points[0][j]);
			}
		}
		prev[i] = maxPoint;
	}
	// if we avoid this condition, then at the end we can return curr[3]
	// This will perfectly work
	if(n==1) return prev[3];
	for(int index=1; index<n; ++index) {
		for(int i=0; i<4; ++i) {
			int maxCost = INT_MIN;
			for(int j=0; j<3; ++j) {
				if(i!=j) {
					maxCost = max(maxCost, points[index][j] + prev[j]);
				}
			}
			curr[i] = maxCost;
		}
		for(int i=0; i<4; ++i) prev[i] = curr[i];
	}
	return curr[3];
}


// Coding Ninjas
// Ninja's training ***
// Space optimized
// Best solution
// Time complexity O(n * 12) ~ O(n)
// Space complexity O(8) ~ constant
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> prev(4, 0), curr(4);
	for(int i=0; i<n; ++i) {
		for(int j=0; j<4; ++j) {
			int val = INT_MIN;
			for(int k=0; k<3; ++k) {
				if(j != k) {
					int point = points[i][k] + prev[k];
					val = max(val, point);
				}
			}
			curr[j] = val;
		}
		for(int index=0; index<4; ++index) {
			prev[index] = curr[index];
		}
	}
	return prev[3];
}

// Top down approach
// Memoization
// Time complexity O(n * 12) ~ O(n)
// Space complexity O(n)
// Recursion stack space O(n)
int ninjaUtils(int index, int nextDayIndex, vector<vector<int>> &points, vector<vector<int>> &dp) {
	// we can calculate index == 0 as a base condition
	// In that case, we need to add more line
	// index<0 is the best base condition
	if(index < 0) return 0;
	if(dp[index][nextDayIndex] != -1) return dp[index][nextDayIndex];
	int val = INT_MIN;
	for(int i=0; i<3; ++i) {
		if(i!=nextDayIndex) {
			int pointCollected = points[index][i] + ninjaUtils(index-1, i, points, dp);
			val = max(val, pointCollected);
		}
	}
	return dp[index][nextDayIndex] = val;
}

int ninjaTraining(int n, vector<vector<int>> &points) {
	vector<vector<int>> dp(n, vector<int>(4, -1));
    return ninjaUtils(n-1, 3, points, dp);
}

// Bottom up approach
// Tabulation
// Time complexity O(n * 12) ~ O(n)
// Space complexity O(n * 12) ~ O(n)
int ninjaTraining(int n, vector<vector<int>> &points)
{
	vector<vector<int>> dp(n+1, vector<int>(4, 0));
    for(int i=1; i<=n; ++i) {
		// next day task
		for(int j=0; j<4; ++j) {
			int val = INT_MIN;
			// current day task
			for(int k=0; k<3; ++k) {
				// we can not do same task in two consecutive day
				if(j != k) {
					int pointsCollected = points[i-1][k] + dp[i-1][k];
					val = max(val, pointsCollected);
				}
			}
			dp[i][j] = val;
		}
	}
	return dp[n][3];
}