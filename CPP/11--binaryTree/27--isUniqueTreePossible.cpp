// Is Unique Binary Tree Possible
// Time complexity O(1)
// 1 : preOrder
// 2 : inOrder
// 3 : postOrder
bool isPossible(int a,int b) {
    return abs(a-b)==2 || a==b ? false : true;
}