// Minimum Falling Path Sum II -- leetcode 1289
// Time complexity O(n*n*n)
// Space complexity O(2*n)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n==0) return 0;
        vector<int> prev(n+1), curr(n+1);
        for(int i=0; i<=n; ++i) {
            int points = INT_MAX;
            for(int j=0; j<n; ++j) {
                if(i!=j) {
                    points = min(points, grid[0][j]);
                }
            }
            prev[i] = points;
        }
        for(int index=1; index<n; ++index) {
            for(int i=0; i<=n; ++i) {
                int points = INT_MAX;
                for(int j=0; j<n; ++j) {
                    if(i!=j) {
                        points = min(points, grid[index][j] + prev[j]);
                    }
                }
                curr[i] = points;
            }
            for(int i=0; i<=n; ++i) {
                prev[i] = curr[i];
            }
        }
        return prev[n];
    }
};


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
				// we can not do same task in two consecutive day
                if(i!=lastTask) {
                    maxPoints = max(maxPoints, points[0][i]);
                }
            }
            return maxPoints;
        }
        
        if(dp[index][lastTask]!=-1) return dp[index][lastTask];
        
        int maxPoints = INT_MIN;
        for(int i=0; i<3; ++i) {
			// we can not do same task in two consecutive day
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

// If the number of element in each row is K
// Memoization -- top down approach
// Time complexity O(n*k)
// Space complexity O(n*(k+1)) + O(n) : Recursion stack space
class Solution {
  public:
    int maximumPointsUtils(int index, int last, int k, vector<vector<int>>& arr, vector<vector<int>>& dp) {
        if(index==0) {
            int points = INT_MIN;
            for(int i=0; i<k; ++i) {
				// we can not do same task in two consecutive day
                if(i != last) {
                    points = max(points, arr[0][i]);
                }
            }
            return points;
        }
        if(dp[index][last] != -1) return dp[index][last];
        int points = INT_MIN;
        for(int i=0; i<k; ++i) {
			// we can not do same task in two consecutive day
            if(i != last) {
                int value = arr[index][i] + maximumPointsUtils(index-1, i, k, arr, dp);
                points = max(points, value);
            }
        }
        return dp[index][last] = points;
    }
    int maximumPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        int k = arr[0].size();
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        return maximumPointsUtils(n-1, k, k, arr, dp);
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
			// we can not do same task in two consecutive day
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
				// we can not do same task in two consecutive day
				if(i!=j) {
					maxCost = max(maxCost, points[index][j] + dp[index-1][j]);
				}
			}
			dp[index][i] = maxCost;
		}
	}
	return dp[n-1][3];
}

// If there are total k type of activities
// Tabulation -- Bottom Up approach
// Time complexity O(n * k * (k+1))
// Space complexity O(n*k)
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        int k = arr[0].size();
        vector<vector<int>> dp(n, vector<int>(k+1));
        for(int i=0; i<=k; ++i) {
            int points = INT_MIN;
            for(int j=0; j<k; ++j) {
				// we can not do same task in two consecutive day
                if(i != j) {
                    points = max(points, arr[0][j]);
                }
            }
            dp[0][i] = points;
        }
        for(int index=1; index<n; ++index) {
            for(int i=0; i<=k; ++i) {
                int points = INT_MIN;
                for(int j=0; j<k; ++j) {
					// we can not do same task in two consecutive day
                    if(i != j) {
                        int value = arr[index][j] + dp[index-1][j];
                        points = max(points, value);
                    }
                }
                dp[index][i] = points;
            }
        }
        return dp[n-1][k];
    }
};


// Space optimized Tabulation -- Bottom Up approach
// Time complexity O(n*4*3) ~ O(n*12) ~ O(n)
// Space complexity O(2*4) ~ constant space
int maximumPoints(vector<vector<int>>& points, int n) {
	vector<int> curr(4), prev(4);
	for(int i=0; i<4; ++i) {
		int maxPoint = INT_MIN;
		for(int j=0; j<3; ++j) {
			// we can not do same task in two consecutive day
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
				// we can not do same task in two consecutive day
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


// If there are total k type of activities
// Bottom up approach
// Tabulation
// Time complexity O(n * k * (k-1)) ~ O(n)
// Space complexity O(2*k)
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        int k = arr[0].size();
        vector<int> prev(k+1), curr(k+1);
        for(int i=0; i<=k; ++i) {
            int points = INT_MIN;
            for(int j=0; j<k; ++j) {
				// we can not do same task in two consecutive day
                if(i != j) {
                    points = max(points, arr[0][j]);
                }
            }
            prev[i] = points;
        }
        for(int index=1; index<n; ++index) {
            for(int i=0; i<=k; ++i) {
                int points = INT_MIN;
                for(int j=0; j<k; ++j) {
					// we can not do same task in two consecutive day
                    if(i != j) {
                        int value = arr[index][j] + prev[j];
                        points = max(points, value);
                    }
                }
                curr[i] = points;
            }
            for(int i=0; i<=k; ++i) {
                prev[i] = curr[i];
            }
        }
        return prev[k];
    }
};