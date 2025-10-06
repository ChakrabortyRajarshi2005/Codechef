Prime Sum
Chef has an integer array 
A
A of length 
N
N such that 
1
≤
A
i
≤
3
1≤A 
i
​
 ≤3.

Chef is wondering how many pairs exist in his array, which have a prime sum. Formally, find the number of pairs 
(
i
,
j
)
(i,j) such that

1
≤
i
<
j
≤
N
1≤i<j≤N
A
i
+
A
j
A 
i
​
 +A 
j
​
  is prime.
X
X is a prime integer if it is not 
1
1, and has no other divisor except 
1
1 and 
X
X. For example, 
2
2, 
13
13 and 
97
97 are prime integers, while 
1
1 and 
4
4 are not.

Input Format
The first line of input will contain a single integer 
T
T, denoting the number of test cases.
Each test case consists of multiple lines of input.
The first line of each test case contains a single integer 
N
N.
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
For each test case, output on a new line the number of pairs with prime sums.

Constraints
1
≤
T
≤
100
1≤T≤100
1
≤
N
≤
100
1≤N≤100
1
≤
A
i
≤
3
1≤A 
i
​
 ≤3
Sample 1:
Input
Output
2
2
1 1
3
2 1 3
1
2
Explanation:
Test Case 1 : The only pair is 
(
1
,
2
)
(1,2) which has a sum of 
2
2.

Test Case 2 : The valid pairs are 
(
1
,
2
)
(1,2) and 
(
1
,
3
)
(1,3), having sums of 
3
3 and 
5
5 respectively.
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;

void s()
{
    int n;
    cin >> n;
    ll c1 = 0, c2 = 0, c3 = 0;
    for (int i = 0; i < n; ++i)
    {
        int v;
        cin >> v;
        if (v == 1)
        {
            c1++;
        }
        else if (v == 2)
        {
            c2++;
        }
        else
        {
            c3++;
        }
    }

    ll ans = 0;
    ans += (c1 * (c1 - 1)) / 2;
    ans += c1 * c2;
    ans += c2 * c3;
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
        s();
}
