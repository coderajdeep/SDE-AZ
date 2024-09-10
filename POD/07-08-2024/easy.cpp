int getSum(int num) {
	int sum = 1;
	for(int i=2; i*i<=num; ++i) {
		sum += (num%i==0) ? i + (num/i) : 0;
	}
	return sum;
}
bool amicablePair(int x, int y) {
	if(x==0 && y==0) return true;
	if(x==0 || y==0) return false;
	int sum1 = getSum(x);
	int sum2 = getSum(y);
	return (sum1==y && sum2==x);
}