Leave no Witnesses
Let 
B
B be a binary string of length 
N
N.
The integer 
X
X is said to be a witness for 
B
B if the following condition holds:

Consider two arrays 
S
1
S 
1
​
  and 
S
2
S 
2
​
 , initially both empty.
For each index 
i
i (
1
≤
i
≤
N
1≤i≤N),
If 
B
i
=
0
B 
i
​
 =0, append 
(
X
 
&
 
i
)
(X & i) to 
S
1
S 
1
​
 .
Here, 
&
& represents the bitwise AND operation.
If 
B
i
=
1
B 
i
​
 =1, append 
(
X
∣
i
)
(X∣i) to 
S
2
S 
2
​
 .
Here, 
∣
∣ represents the bitwise OR operation.
In the end, if 
S
1
∩
S
2
=
∅
S 
1
​
 ∩S 
2
​
 =∅ holds, i.e. 
S
1
S 
1
​
  and 
S
2
S 
2
​
  have no common elements, then 
X
X is said to be a witness for 
B
B.
For example, consider 
B
=
010
B=010.

X
=
1
X=1 is a witness for this string, because 
S
1
=
[
1
 
&
 
1
,
1
 
&
 
3
]
=
[
1
,
1
]
S 
1
​
 =[1 & 1,1 & 3]=[1,1], and 
S
2
=
[
1
∣
2
]
=
[
3
]
S 
2
​
 =[1∣2]=[3] are disjoint.
X
=
2
X=2 is not a witness for this string, because 
S
1
=
[
2
 
&
 
1
,
2
 
&
 
3
]
=
[
0
,
2
]
S 
1
​
 =[2 & 1,2 & 3]=[0,2], and 
S
2
=
[
2
∣
2
]
=
[
2
]
S 
2
​
 =[2∣2]=[2] are not disjoint (they both contain the element 
2
2).
You are given a binary string 
A
A of length 
N
N.
In one operation, you can choose an index 
i
i (
1
≤
i
≤
N
1≤i≤N), and flip the character at index 
i
i, i.e. convert it from 
0
0 to 
1
1 or vice versa.

Find the minimum number of operations needed to convert 
A
A into a binary string such that no integer from 
1
1 to 
N
N is a witness to it.
Note that we do not care whether integers larger than 
N
N are witnesses or not - just that no integer between 
1
1 and 
N
N is a witness.

If it's impossible to convert 
A
A to such a binary string no matter what, print 
−
1
−1 instead.

Input Format
The first line of input will contain a single integer 
T
T, denoting the number of test cases.
Each test case consists of two lines of input.
The first line of each test case contains a single integer 
N
N, the length of the binary string.
The second line contains the binary string 
A
A of length 
N
N.
Output Format
For each test case, print the answer on a new line: the minimum number of changes needed to obtain a binary string that admits no witnesses in 
[
1
,
N
]
[1,N], or 
−
1
−1 if it's impossible.

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
2
⋅
10
5
1≤N≤2⋅10 
5
 
A
i
∈
{
0
,
1
}
A 
i
​
 ∈{0,1}
The sum of 
N
N across all tests won't exceed 
2
⋅
10
5
2⋅10 
5
 .
Sample 1:
Input
Output
3
3
010
4
0100
5
01011
1
-1
2
Explanation:
Test case 
1
1: For 
A
=
010
A=010, 
X
=
1
X=1 is a witness: we obtain 
S
1
=
[
1
,
1
]
S 
1
​
 =[1,1] and 
S
2
=
[
3
]
S 
2
​
 =[3], which are disjoint.
We can use an operation on 
i
=
1
i=1 to change 
A
1
A 
1
​
  to 
1
1, obtaining 
A
=
110
A=110.
It can be verified that 
A
A now has no witnesses in 
[
1
,
3
]
[1,3].

For 
X
=
1
X=1, the arrays are 
S
1
=
[
1
]
S 
1
​
 =[1] and 
S
2
=
[
1
,
3
]
S 
2
​
 =[1,3], which are not disjoint.
For 
X
=
2
X=2, the arrays are 
S
1
=
[
2
]
S 
1
​
 =[2] and 
S
2
=
[
3
,
2
]
S 
2
​
 =[3,2], which are not disjoint.
For 
X
=
3
X=3, the arrays are 
S
1
=
[
3
]
S 
1
​
 =[3] and 
S
2
=
[
3
,
3
]
S 
2
​
 =[3,3], which are not disjoint.
Test case 
2
2: It can be proved that every binary string of length 
4
4 has at least one integer in 
[
1
,
4
]
[1,4] be a witness, so no solution exists.

Test case 
3
3: One optimal solution is to turn the string into 
A
=
11010
A=11010 by operating on indices 
1
1 and 
5
5.

import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
	      Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T-- > 0) {
            processTestCase(sc);
        }
    }

    private static void processTestCase(Scanner sc) {
        int n = sc.nextInt();
        String A = sc.next();

        if (isPowerOfTwo(n)) {
            System.out.println(-1);
            return;
        }

        long flips = 0;
        int bitLength = calculateBitLength(n);

        // Minimal masks (powers of two) → must be 1
        for (int p = 1; p <= n; p <<= 1) {
            if (A.charAt(p - 1) == '0') {
                flips++;
            }
        }

        // Maximal masks → no superset → must be 0
        for (int i = 1; i <= n; i++) {
            if (!hasValidSuperset(i, n, bitLength)) {
                if (A.charAt(i - 1) == '1') {
                    flips++;
                }
            }
        }

        System.out.println(flips);
    }

    private static boolean isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }

    private static int calculateBitLength(int n) {
        return n > 0 ? (int)(Math.floor(Math.log(n) / Math.log(2))) + 1 : 0;
    }

    private static boolean hasValidSuperset(int i, int n, int bitLength) {
        for (int b = 0; b < bitLength; b++) {
            if (((i >> b) & 1) == 0) {
                int j = i | (1 << b);
                if (j <= n) {
                    return true;
                }
            }
        }
        return false;
    }
}
