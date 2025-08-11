Minimize Maximum Mex
The MEX of an array of integers is defined to be the smallest non-negative integer not present in it.
For example, 
MEX
(
[
2
,
3
,
1
,
2
]
)
=
0
MEX([2,3,1,2])=0 and 
MEX
(
[
2
,
0
,
3
]
)
=
1
MEX([2,0,3])=1.

You are given two arrays 
A
A and 
B
B, both of length 
N
N.
You can perform the following operation on the arrays:

Choose an index 
i
i (
1
≤
i
≤
N
1≤i≤N), and swap 
A
i
A 
i
​
  with 
B
i
B 
i
​
 .
Find the minimum possible value of 
max
⁡
(
MEX
(
A
)
,
MEX
(
B
)
)
max(MEX(A),MEX(B)) if you are allowed to perform as many operations as you like (possibly, none).

Input Format
The first line of input will contain a single integer 
T
T, denoting the number of test cases.
Each test case consists of three lines of input.
The first line of each test case contains a single integer 
N
N — the length of the arrays.
The second line contains 
N
N space-separated integers 
A
1
,
A
2
,
…
,
A
N
A 
1
​
 ,A 
2
​
 ,…,A 
N
​
 .
The third line contains 
N
N space-separated integers 
B
1
,
B
2
,
…
,
B
N
B 
1
​
 ,B 
2
​
 ,…,B 
N
​
 .
Output Format
For each test case, output on a new line the answer: the minimum possible value of 
max
⁡
(
MEX
(
A
)
,
MEX
(
B
)
)
max(MEX(A),MEX(B)) after performing some swaps.

Constraints
1
≤
T
≤
10
5
1≤T≤10 
5
 
1
≤
N
≤
3
⋅
10
5
1≤N≤3⋅10 
5
 
0
≤
A
i
,
B
i
<
N
0≤A 
i
​
 ,B 
i
​
 <N
The sum of 
N
N over all test cases won't exceed 
3
⋅
10
5
3⋅10 
5
 .
Sample 1:
Input
Output
4
2
0 1
1 0
4
2 3 1 2
1 3 1 3
4
0 1 3 0
0 3 0 1
4
0 1 2 3
0 3 2 1
1
0
2
3
Explanation:
Test case 
1
1: Suppose we choose 
i
=
1
i=1, to swap 
A
1
A 
1
​
  and 
B
1
B 
1
​
 . This results in 
A
=
[
1
,
1
]
A=[1,1] and 
B
=
[
0
,
0
]
B=[0,0].
This gives 
MEX
(
A
)
=
0
MEX(A)=0 and 
MEX
(
B
)
=
1
MEX(B)=1, so their maximum is 
1
1. This is optimal.

Test case 
2
2: No swaps are needed: 
MEX
(
A
)
=
MEX
(
B
)
=
0
MEX(A)=MEX(B)=0 already so their maximum is 
0
0. This is optimal.

Test case 
3
3: No matter how the swaps are made, at least one of 
MEX
(
A
)
MEX(A) or 
MEX
(
B
)
MEX(B) will equal 
2
2, so the answer is 
2
2.

Test case 
4
4: One optimal solution is to swap 
A
2
A 
2
​
  and 
B
2
B 
2
​
 , to obtain 
A
=
[
0
,
3
,
2
,
3
]
A=[0,3,2,3] and 
B
=
[
0
,
1
,
2
,
1
]
B=[0,1,2,1].
This gives 
MEX
(
A
)
=
1
MEX(A)=1 and 
MEX
(
B
)
=
3
MEX(B)=3, so 
max
⁡
(
1
,
3
)
=
3
max(1,3)=3. We can't do better than this.

import java.util.*;
import java.io.*;

class Codechef {
    public static void solve(Scanner sc) {
        int n = sc.nextInt();
        int[] A = new int[n];
        int[] B = new int[n];
        for (int i = 0; i < n; i++) {
            A[i] = sc.nextInt();
        }
        for (int i = 0; i < n; i++) {
            B[i] = sc.nextInt();
        }
        
        boolean[] present = new boolean[n];
        boolean[] bad = new boolean[n];
        
        for (int i = 0; i < n; i++) {
            int a = A[i];
            int b = B[i];
            present[a] = true;
            present[b] = true;
            if (a == b) {
                bad[a] = true;
            }
        }
        
        int[] goodPrefix = new int[n];
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (present[i] && !bad[i]) {
                count++;
            }
            goodPrefix[i] = count;
        }
        
        int ans = n;
        for (int i = 0; i <= n; i++) {
            if (i == n) {
                ans = n;
                break;
            }
            if (!present[i]) {
                ans = i;
                break;
            }
            if (goodPrefix[i] >= 2) {
                ans = i;
                break;
            }
        }
        System.out.println(ans);
    }
    
    public static void main (String[] args) throws java.lang.Exception {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        
        while (T-- > 0) {
            solve(sc);
        }
        sc.close();
    }
}
