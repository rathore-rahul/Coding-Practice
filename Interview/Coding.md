#### Length of proper prefix which is also a proper suffix
> Use KMP prefix array creation method

#### Count BST subtree that lie in a given range
> Do DFS return backup whether below subtree is in range or not. If both subtree
> are in range and so did the root return true as backup and increase count.

#### Find missing number in array from 1 to N
> 1. put number at their index in 1 run and check in other
> 2. Do sum of the array and decrease it from N*(N+1)/2
> 3. Take xor of whole array and 1 to N number also, result is missing number

#### Binary search in rotated and sorted array
```cpp
int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        while(low <= high){
            int mid = (low+ high)/2;
            if(nums[mid] == target)  return mid;
            else if(nums[mid] < nums[high]){
                if(target < nums[mid] || target > nums[high])
                    high = mid-1;
                else
                    low = mid+1;
            }
            else{
                if(target < nums[low] || target > nums[mid])
                    low = mid+1;
                else
                    high = mid-1;
            }

        }
        return -1;
    }
```

#### Given two binary tree find whether one is subtree of another
```cpp
bool isEqual(TreeNode* s, TreeNode* t){
    if(s == NULL && t == NULL)  return true;
    if(s == NULL || t == NULL)  return false;
    return (s->val == t->val && isEqual(s->left,t->left) && isEqual(s->right,t->right));
}
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s == NULL)
            return false;
        bool flag = false;
        if(s->val == t->val){
            flag = isEqual(s,t);
        }
        flag = (flag || isSubtree(s->left,t) || isSubtree(s->right,t));
        return flag;
    }
};
```
#### Add two numbers represented by linked list
> ### LSD as head
> very easy just create dummy head and use carry flow forward
> ### MSD as head

```cpp
class Solution {
public:
    int recurse(ListNode*l1, ListNode*l2, int dist,ListNode ** head){
        int val = 0,carry = 0;
        if(dist > 0){
            carry = recurse(l1->next,l2,dist-1,head);
            val = carry + l1->val;
        }
        else if(dist < 0){
            carry = recurse(l1,l2->next,dist+1,head);
            val = carry + l2->val;
        }        
        else if(l1->next == NULL && l2 -> next == NULL){
            val = l1->val + l2->val;
        }
        else{
            carry = recurse(l1->next,l2->next,dist,head);
            val = l1->val + l2->val + carry;
        }
        carry = val/10;
        val = val%10;
        ListNode * temp = new ListNode(val);
        temp->next = *head;
        *head = temp;
        return carry;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1, * t2 = l2;
        int len1 = 0, len2 = 0;
        while(t1 != NULL){
            len1++; t1 = t1->next;
        }
        while(t2 != NULL){
            len2++;t2 = t2->next;
        }
        ListNode * head = NULL;
        int carry = recurse(l1,l2,len1-len2,&head);
        if(carry){
            ListNode * temp = new ListNode(1);
            temp->next = head;
            head = temp;
        }
        return head;
    }
};
```

#### Reverse Linked List in group of K
```cpp
struct Node* reverse (struct Node* head, int k)
{
    struct Node* current = head;
    struct Node* next = NULL;
    struct Node* prev = NULL;
    int count = 0;   

    while (current != NULL && count < k)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    // next is now a pointer to (k+1)th node
    //   Recursively call for the list starting from current.
    //   And make rest of the list as next of first node
    if (next !=  NULL)
       head->next = reverse(next, k);

    // prev is new head of the input list
    return prev;
}
```

#### Reverse Integer with overflow check
```cpp
int reverse(int x) {
        int ans = 0;
        while (x) {
            int temp = ans * 10 + x % 10;
            if (temp / 10 != ans)
                return 0;
            ans = temp;
            x /= 10;
        }
        return ans;
    }
```

#### Maximum Area using two lines
> Two  pointer approach. one at start and other at end take current area then move the pointer pointing to least height forward

```cpp
int maxArea(int h[],int n){
  int area = 0;
  int l = 0, r = n-1;
  while(l < r){
    area = max(area,(r-l)*min(h[l],h[r]));
    if(h[l] < h[r])
      l++;
    else
      r++;
  }
  return area;
}
```
#### Longest Common prefix -- Leetcode
> 1. Brute Force.
> 2. Divide and conquer.
> 3. Binary Serarch.
> 4. Trie (Not clear).

#### Find Maximum Difference A[j] - A[i] such that j > i
> Keep minimum from left side and for every element greater than min calculate diff  <strong> O(n) time O(1) space</strong>. Works beacuse at any index i if i is not the current_min than you are better off with taking current min in place of i.

> Take difference of consecutive element the problem is reduced into Maximum sum subarray(use kadane). <strong> O(n) time O(1) space.


#### find maximum Difference j- i such that A[j] > A[i]
> <strong> Observations:- </strong> if there is a element smaller thatn A[i] in left of i than we don't need to consider i similarly if there is a element greater than A[j] right of j we don't need to consider j.

Create two array Lmin[i] = min from (0..i) , Rmax[i] = max(i..n). Lmin and Rmin both will be decreasing array. Start traversing both array from left to right.
* case 1- Lmin[i] > Rmin[j] then we need to move ahead in Lmin to decrease the left value.
* case 2- Otherwise move ahead in Rmax for greater j-i value.

##### Sort array containing O, 1 and 2
> count sort.
> Partition using 2 pointers left and right to store 0 from front and 2 from backward 1 will sort automatically.

#### Shortest Word Distance
Given a list of words and two words w1 and w2 return the shortest distance between them(w1 and w2 can be same). </br>
Ex.- [practice,makes, perfect, coding ,makes]. Given w1 and w2 makes return 3.
> create a boolean variable whether both words are equal or not. if equals take turn to update else do normal ways.


#### Median of two sorted Array

#### Lower_bound function

#### Longest Valid Parenthesis
> * generate every substring and check for validity. O(N^3)
> * Dynamic Programming- dp[i] represented length of longest valid substring ending at index i. <br>
>  * if s[i] = '(' then dp[i] = 0
>  * if s[i] = ')' and s[i-1] = '(' then string looks like ....()
>    * dp[i] = dp[i-2] + 2;
>  * if s[i] = ')' and s[i-1] = ')' then string looks like ....))
>    * if s[i-1 - dp[i-1]] = ')' then dp[i] = 0
>    * else dp[i] = dp[i-1] + dp[i- dp[i-1] - 2] + 2
> * stack- Instead of finding every possible string and checking its validity, we can make use of stack while scanning the given string to check if the string scanned so far is valid, and also the length of the longest valid string. In order to do so, we start by pushing −1 onto the stack.For every '(' encountered, we push its index onto the stack.for every ')' encountered, we pop the topmost element and subtract the current element's index from the top element of the stack, which gives the length of the currently encountered valid string of parentheses. If while popping the element, the stack becomes empty, we push the current element's index onto the stack. In this way, we keep on calculating the lengths of the valid substrings, and return the length of the longest valid string at the end.
> * Linear Scan - In this approach, we make use of two counters left and right. First, we start traversing the string from the left towards the right and for every '(' encountered, we increment the left counter and for every ')' encountered, we increment the right counter. Whenever left becomes equal to right, we calculate the length of the current valid string and keep track of maximum length substring found so far. If right becomes greater than left we reset left and right to 0.Next, we start traversing the string from right to left and similar procedure is applied.

#### Maximum Rectangle of 0's and 1's
Given a 2D binary matrix filled with 0’s and 1’s, find the largest rectangle containing all ones and return its area.
> for every row i. consider the base of rectangle at this row and applied largest rectangle in histogram method. O(N^2)

#### Desgi a data structure with insert delete and get Random in O(1)

#### palindromic pairs in array of strings
> O(N*K^2) using trie. inserting every string reverse while keeping track of wheter remaining string is palindrome or not.

#### Isomorphic strings
> Define greedy mapping

#### Increasing triplet subsequence
Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.
> This problem can be converted to be finding if there is a sequence such that the_smallest_so_far < the_second_smallest_so_far < current.

#### Rotate Array by k
> 1. Create new array and copy with shift. O(n) time O(n) space
> 2. use bubble sort like step k times and bring the last element at 0 index each time. O(n*k) time O(1) space
> 3. divide array into 2 parts of n-k and k Length. reverse both part. then reverse whole aray.

#### reverse words in string
> reverse the whole string then reverse each word

#### Length of Longest AP

#### Sentence reversal
#### Maximum product subarray
#### K-diff distinct pairs in array

## <center> Heap </center>
* properties- can be build in O(n) time.
* Heap sort can be done in place with worst case O(n logn).

* Find smallest 1 million integers among 1 billion values
> divide into 1000 parts. sorts each part then build tournament tree on top of that. Keep Apeending the output into a file.

* Finding 1st and 2nd max in less than 2n comparison.
> Build tournament tree. winner will be found n operations. take all numbers which lose to the winner in tournament take maximum of those as 2nd max. these will be atmost log(n) (heigh of tree).  n + log(n) comparison

* Median of sorted arrays
> Build Heap on top of the arrays. one by one remove element untill the median comes.

* Check whether a Binary tree is heap or not
> count number of nodes using recursion. assign index = 0 to root and for any nodes i assign index 2*i + 1 and 2*i + 2 to left and right child. then check for heap property between parent and child and index of any node can not be >= num of nodes because it will violates the complete tree property

* Design a data structure to implement findmin, findmax, deletemin, deletemax, insert, delete
> create a maxheap and minheap and a multiset. set will store the pointer to the location of the element in both heaps. findmin and findmax is O(1). insert will take O(logn). to delete first find the pointer to the location of both heaps then element will be deleted from them and finally from the hashmap. O(logn)

* Kth Largest sum continuous subarray
> 1. Brute force method is to compute each subarray sum and sort them. this require O(N^2) extra space and time O(N^2 + N^2 log(N^2)).
> 2. compute the prefix sum for the array. now sum between i and j can be found using arr[j] - arr[i]. create a minheap of size k. for each possible subarray insert the sum into heap if its greater then the top and pop the top element.
time complexity O(N^2 logk) space complexity O(k)

## <center> Array </center>
* Next permutation
> start from end and check wheter an element is less than its right nbr. If no such element is found than this is already the largest permutation possible Otherwise swap this element with the smallest element greater than this on right side and reverse the right side </br>
> Ex. [3,2,9,7,6,5,4] till 2 no one is greater than its right nbr. smallest value greater than 2 is 4. Swap 2 and 4 and reverse the right part. The output will be [3,4,2,5,6,7,9]

## <center> Binary Search </center>
## <center> Two Pointer </center>
