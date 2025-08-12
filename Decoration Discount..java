Decoration Discount
Chef wants to decorate his house a bit, so he decides to buy exactly two flower vases.

The shop he visits has 
N
N flower vases, all arranged in a line.
The price of the 
i
i-th vase is 
A
i
A 
i
​
 . It's guaranteed that all 
A
i
A 
i
​
  are even.

If Chef buys vase number 
i
i, the price of vase number 
i
+
1
i+1 will be halved.
No other discounts are available.

Find the minimum cost of buying two different vases.

Input Format
The first line of input will contain a single integer 
T
T, denoting the number of test cases.
Each test case consists of two lines of input.
The first line of each test case contains a single integer 
N
N — the number of vases in the store.
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
  — the prices of the vases.
Output Format
For each test case, output on a new line the answer: the minimum cost of buying two different vases.

Constraints
1
≤
T
≤
100
1≤T≤100
2
≤
N
≤
100
2≤N≤100
2
≤
A
i
≤
100
2≤A 
i
​
 ≤100
Each 
A
i
A 
i
​
  is even.
Sample 1:
Input
Output
3
4
10 14 18 8
4
10 18 14 8
5
12 18 2 28 16
17
18
14
Explanation:
Test case 
1
1: Chef should buy the first and second vases.
Buying vase 
1
1 halves the price of vase 
2
2, so the overall cost is 
10
+
14
2
=
10
+
7
=
17
10+ 
2
14
​
 =10+7=17.

Test case 
2
2: Chef should buy the first and fourth vases.
Buying the first vase halves the price of vase 
2
2, making it 
18
2
=
9
2
18
​
 =9 — but it's still cheaper to buy the fourth vase with a cost of 
8
8 instead.

Test case 
3
3: Chef should buy the first and third vases, for a cost of 
12
+
2
=
14
12+2=14.

import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		Scanner sc = new Scanner(System.in);
        for (int T = sc.nextInt(); T-- > 0; ) {
            int N = sc.nextInt(), A[] = new int[N], min = Integer.MAX_VALUE;
            for (int i = 0; i < N; A[i++] = sc.nextInt());
            for (int i = 0; i < N; i++)
                for (int j = i + 1; j < N; j++) {
                    int c1 = A[i] + (i + 1 == j ? A[j] / 2 : A[j]);
                    int c2 = A[j] + (j + 1 == i ? A[i] / 2 : A[i]);
                    min = Math.min(min, Math.min(c1, c2));
                }
            System.out.println(min);
        }
        sc.close();

	}
}
