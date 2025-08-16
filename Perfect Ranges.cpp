Perfect Ranges
A pair of arrays 
A
A and 
B
B, both of length 
N
N, are called perfect if it is possible to form an array 
C
C of length 
N
N satisfying the following conditions:

C
i
=
A
i
C 
i
​
 =A 
i
​
  or 
C
i
=
B
i
C 
i
​
 =B 
i
​
  for each 
1
≤
i
≤
N
1≤i≤N
C
i
<
C
i
+
1
C 
i
​
 <C 
i+1
​
  for each 
1
≤
i
<
N
1≤i<N
You are given 
2
2 arrays 
A
A and 
B
B of length 
N
N. It is guaranteed that each element from 
1
1 to 
2
⋅
N
2⋅N either occurs once in 
A
A or occurs once in 
B
B.

Find how many pairs 
L
L and 
R
R exist such that:

1
≤
L
≤
R
≤
N
1≤L≤R≤N
The pair of arrays 
A
[
L
,
R
]
A[L,R] and 
B
[
L
,
R
]
B[L,R] are perfect.
Here, 
A
[
L
,
R
]
A[L,R] represents the subrange 
[
A
L
,
A
L
+
1
,
…
,
A
R
]
[A 
L
​
 ,A 
L+1
​
 ,…,A 
R
​
 ] of the array 
A
A.

Input Format
The first line of input will contain a single integer 
T
T, denoting the number of test cases.
Each test case consists of multiple lines of input.
The first line of input contains a single integer 
N
N - the size of the arrays.
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
The third line contains 
N
N integers - 
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
For each test case, output on a new line the number of 
L
L and 
R
R, such that corresponding subranges in 
A
A and 
B
B are perfect.

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
 
1
≤
A
i
,
B
i
≤
2
⋅
N
1≤A 
i
​
 ,B 
i
​
 ≤2⋅N
A
i
≠
A
j
,
B
i
≠
B
j
A 
i
​
 =A 
j
​
 ,B 
i
​
 =B 
j
​
  for any 
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
≠
B
j
A 
i
​
 =B 
j
​
  for any 
1
≤
i
,
j
≤
N
1≤i,j≤N
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
3
3
2 6 4
3 1 5
3
2 5 4
3 1 6
3
5 3 1
6 4 2
5
6
3
Explanation:
Test Case 1 : All the pairs of 
L
L and 
R
R (satisfying 
1
≤
L
≤
R
≤
N
1≤L≤R≤N) are perfect except 
L
=
1
,
R
=
3
L=1,R=3. For example, for 
L
=
1
,
R
=
2
L=1,R=2, we can choose 
C
=
[
3
,
6
]
C=[3,6].

Test Case 2 : All the pairs 
L
L and 
R
R are perfect. For example, for 
L
=
1
,
R
=
3
L=1,R=3, we can choose 
C
=
[
2
,
5
,
6
]
C=[2,5,6].

#include <bits/stdc++.h>
using namespace std;
#define int long long

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

int32_t main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int test_cases = 1;
  cin >> test_cases;
  while (test_cases--)
  {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
      cin >> a[i];
    }
    vector<int> b(n);
    for(int i = 0; i < n; ++i){
      cin >> b[i];
    }
    bool ok = false;
    int ans = n;
    if(is_sorted(a.begin(), a.end()) || is_sorted(b.begin(), b.end())){
      ans += (n * (n - 1)) / 2;
      cout << ans << '\n';
      continue;
    }
    vector<int> suff_a(n, 0), suff_b(n, 0);
    suff_a[n - 1] = 0;
    suff_b[n - 1] = 0;

    for(int i = n - 2; i >= 0; --i){
      if(i + 1 < n && a[i] < a[i + 1]){
        suff_a[i] = suff_a[i + 1] + 1;
      }
      if(i + 1 < n && b[i] < b[i + 1]){
        suff_b[i] = suff_b[i + 1] + 1;
      }
      if (a[i] < b[i + 1]) {
        suff_a[i] = max(suff_a[i], suff_b[i + 1] + 1);
      }
      if (b[i] < a[i + 1]) {
        suff_b[i] = max(suff_b[i], suff_a[i + 1] + 1);
      }
      int mx = max({suff_b[i], suff_a[i]});
      ans += mx;
    }
    cout << ans << '\n';
  }
  return 0;
}
