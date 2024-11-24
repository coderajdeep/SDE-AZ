// Time complexity O(n)
// Space complexity O(1)

bool lemonadeChange(vector<int>& bills) {
    int five = 0, ten = 0;
    for(int bill : bills) {
        if(bill==5) {
            five += 1;
        }
        else if(bill==10) {
            if(five>=1) {
                ten += 1;
                five -= 1;
            }
            else {
                return false;
            }
        }
        else {
            if((five>=1 && ten>=1) || (five>=3)) {
                if(ten>0) {
                    ten -= 1;
                    five -= 1;
                }
                else {
                    five -= 3;
                }
            }
            else {
                return false;
            }
        }
    }
    return true;
}