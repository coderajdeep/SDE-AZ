// Solution 1
// Time complexity O(9 + 2 * N/2000)
// Space complexity O(1)
vector<int> minPartition(int N) {
    vector<int> coins{1,2,5,10,20,50,100,200,500,2000};
    vector<int> ans;
    for(int i=9; i>=0; --i) {
        while(coins[i]<=N) {
            ans.push_back(coins[i]);
            N -= coins[i];
        }
    }
    return ans;
}

// Solution 2
vector<int> minPartition(int N) {
    vector<int> ans;
    while(N>0) {
        if(N>=2000) {
            int coin = (N / 2000);
            N = (N % 2000);
            for(int i=0; i<coin; ++i) {
                ans.push_back(2000);
            }
        }
        else if(N>=500) {
            int coin = (N / 500);
            N = (N % 500);
            for(int i=0; i<coin; ++i) {
                ans.push_back(500);
            }
        }
        else if(N>=200) {
            int coin = (N / 200);
            N = (N % 200);
            for(int i=0; i<coin; ++i) {
                ans.push_back(200);
            }
        }
        else if(N>=100) {
            int coin = (N / 100);
            N = (N % 100);
            for(int i=0; i<coin; ++i) {
                ans.push_back(100);
            }
        }
        else if(N>=50) {
            int coin = (N / 50);
            N = (N % 50);
            for(int i=0; i<coin; ++i) {
                ans.push_back(50);
            }
        }
        else if(N>=20) {
            int coin = (N / 20);
            N = (N % 20);
            for(int i=0; i<coin; ++i) {
                ans.push_back(20);
            }
        }
        else if(N>=10) {
            int coin = (N / 10);
            N = (N % 10);
            for(int i=0; i<coin; ++i) {
                ans.push_back(10);
            }
        }
        else if(N>=5) {
            int coin = (N / 5);
            N = (N % 5);
            for(int i=0; i<coin; ++i) {
                ans.push_back(5);
            }
        }
        else if(N>=2) {
            int coin = (N / 2);
            N = (N % 2);
            for(int i=0; i<coin; ++i) {
                ans.push_back(2);
            }
        }
        else if(N>=1) {
            int coin = N;
            N = 0;
            for(int i=0; i<coin; ++i) {
                ans.push_back(1);
            }
        }
    }
    return ans;
}