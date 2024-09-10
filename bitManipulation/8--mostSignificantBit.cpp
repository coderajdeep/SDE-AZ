// Most Significant bit -- Coding Ninjas
// Given a positive integer N. We need to find the max integer which is power of 2

int findMSB(int n){
	n = (n | (n >> 1));
	n = (n | (n >> 2));
	n = (n | (n >> 4));
	n = (n | (n >> 8));
	n = (n | (n >> 16));
	// now n have all set bits from lsb to msb
	return ((n+1)>>1);
	// As n -> [1, 10^9]
	// we don't need to handle overflow condition
	// https://www.geeksforgeeks.org/find-significant-set-bit-number/
}