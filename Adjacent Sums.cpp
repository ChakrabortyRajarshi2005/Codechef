
Adjacent Sums
An array 
A
A of size 
N
(
N
≥
2
)
N(N≥2), containing non-negative integers, is called good if all of the following conditions hold:

A
1
=
A
2
A 
1
​
 =A 
2
​
 , or 
A
1
=
0
A 
1
​
 =0
A
N
=
A
N
−
1
A 
N
​
 =A 
N−1
​
 , or 
A
N
=
0
A 
N
​
 =0
A
i
=
A
i
−
1
+
A
i
+
1
A 
i
​
 =A 
i−1
​
 +A 
i+1
​
 , or 
A
i
=
0
A 
i
​
 =0 for all 
1
<
i
<
N
1<i<N.
Less formally, we need all non-zero 
A
i
A 
i
​
  equal to the sum of it's adjacent elements.

You are given an array 
A
A of size 
N
N, consisting of non-negative integers.

In one operation, you can add 
1
1 or subtract 
1
1 from some element in 
A
A. It is not allowed to make the elements in 
A
A negative at any point.

Find the minimum operations to make the array 
A
A good. It can be proven that it is always possible.

Input Format
The first line of input will contain a single integer 
T
T, denoting the number of test cases.
Each test case consists of multiple lines of input.
The first line of each test case contains 
N
N - the size of the array 
A
A.
The second line contains 
N
N integers - 
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
Output Format
For each test case, output on a new line the minimum number of operations to make 
A
A good.

Constraints
1
≤
T
≤
10
4
1≤T≤10 
4
 
2
≤
N
≤
2
⋅
10
5
2≤N≤2⋅10 
5
 
0
≤
A
i
≤
10
9
0≤A 
i
​
 ≤10 
9
 
The sum of 
N
N over all test cases does not exceed 
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
6
2
0 5
2
3 4
3
0 0 0
3
2 2 1
5
6 7 2 1 2
9
1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000
5
1
0
1
4
3000000000
Explanation:
Test Case 1 : We can reduce 
A
2
A 
2
​
  by 
5
5 to get 
[
0
,
0
]
[0,0] which is good. We could also have increased 
A
1
A 
1
​
  by 
5
5 to get 
[
5
,
5
]
[5,5] which is also good.

Test Case 2 : We can reduce 
A
2
A 
2
​
  by 
1
1 to get 
[
3
,
3
]
[3,3] which is good.#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        vector<int> dp(n);
        dp[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            // if i choose to make this equal  to arr[i-1]
            int curr = abs(arr[i] - arr[i - 1]);
            // i will also need to  make arr[i-2] as 0
            if (i - 2 >= 0)
                curr += arr[i - 2];
            // cost till i - 3
            if (i - 3 >= 0)
                curr += dp[i - 3];
            // if i choose to make this i as 0
            int curr2 = arr[i];
            if (i - 1 >= 0)
                curr2 += dp[i - 1]; // best cost till i - 1
            dp[i] = min(curr, curr2);
        }
        cout << dp[n - 1] << endl;
    }
}
