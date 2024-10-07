// Determine Whether Matrix Can Be Obtained By Rotation
// Time complexity O(n*n)
// Space complexity O(1)
class Solution {
public:
    // matrix (n, m)
    // one 90 degree clockwise rotation
    // (i, j) --> (j, n-1-i)
    // two 90 / one 180 degree clockwise rotation
    // (i, j) --> (n-1-i, m-1-j)
    // three 90 / one 270 degree clockwise rotation
    // (i, j) --> (n-1-j, i)
    // four 90 / one 360 degree clockwise rotation
    // (i, j) --> (i, j)
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        bool degree90 = true, degree180 = true, degree270 = true, degree360 = true;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                if(mat[i][j]!=target[j][n-1-i]) {
                    degree90 = false;
                }
                if(mat[i][j]!=target[n-1-i][n-1-j]) {
                    degree180 = false;
                }
                if(mat[i][j]!=target[n-1-j][i]) {
                    degree270 = false;
                }
                if(mat[i][j]!=target[i][j]) {
                    degree360 = false;
                }
                if (!degree90 && !degree180 && !degree270 && !degree360) {
                    return false;
                }
            }
        }
        
        return (degree90 || degree180 || degree270 || degree360);
    }
};