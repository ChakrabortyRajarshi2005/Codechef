Grid MEX
You are given an integer 
N
N.

Construct an 
N
×
N
N×N grid (i.e. 
N
N rows and 
N
N columns) filled with 
N
2
N 
2
  integers. Let 
A
i
,
j
A 
i,j
​
  represent the element in 
i
i-th row and 
j
j-th column.

Define 
V
i
,
j
V 
i,j
​
  be the set of all elements 
A
x
,
y
A 
x,y
​
  such that exactly one of 
x
=
i
x=i and 
y
=
j
y=j holds. In other words, 
V
i
,
j
V 
i,j
​
  is the set of all elements in the same row or column, excluding 
(
i
,
j
)
(i,j) itself.

The grid must satisfy the following conditions:

0
≤
A
i
,
j
≤
N
2
0≤A 
i,j
​
 ≤N 
2
 
A
i
,
j
=
M
E
X
(
V
i
,
j
)
†
A 
i,j
​
 =MEX(V 
i,j
​
 ) 
†
 
It can be proven that a valid grid always exists. Find any valid grid.

†
†
  
M
E
X
(
S
)
MEX(S) is defined as the smallest non-negative integer not present in 
S
S. The mex of an empty set is defined to be 
0
0.

Input Format
The first line of input will contain a single integer 
T
T, denoting the number of test cases.
The first and only line of input contains a single integer 
N
N.
Output Format
For each test case, output 
N
N lines each with 
N
N integers. The 
j
j-th integer on the 
i
i-th line should be 
A
i
,
j
A 
i,j
​
 . You are allowed to print any valid grid.

Constraints
1
≤
T
≤
30
1≤T≤30
1
≤
N
≤
30
1≤N≤30
Sample 1:
Input
Output
2
1
2
0
1 0
0 1
Explanation:
Test Case 1 : 
V
1
,
1
V 
1,1
​
  is empty, and hence 
M
E
X
(
V
1
,
1
)
MEX(V 
1,1
​
 ) will always be 
0
0. Thus, we must have 
A
1
,
1
=
0
A 
1,1
​
 =0.

Test Case 2 : We can verify that the given grid follows all conditions. For example, 
V
1
,
1
=
{
0
,
0
}
V 
1,1
​
 ={0,0} which has a 
M
E
X
MEX of 
1
=
A
1
,
1
1=A 
1,1
​
 .


import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-- > 0){
		    long n = sc.nextLong();
		    for(long i = 0; i < n; i++){
		        for (long j = 0; j < n; j++){
		            System.out.print((i+j)%n + " ");
		        }
		        System.out.println();
		    }
		}

	}
}
