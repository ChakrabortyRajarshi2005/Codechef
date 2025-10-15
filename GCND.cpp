GCND
The greatest common non-divisor of two positive integers 
X
X and 
Y
Y satisfying 
X
≥
5
X≥5 and 
Y
≥
5
Y≥5, denoted 
gcnd
(
X
,
Y
)
gcnd(X,Y), is defined to be the largest positive integer 
Z
Z satisfying the following conditions:

Z
≤
X
Z≤X or 
Z
≤
Y
Z≤Y, and
X
X is not a multiple of 
Z
Z and 
Y
Y is not a multiple of 
Z
Z.
It can be proved that as long as 
X
X and 
Y
Y are both 
≥
5
≥5, 
gcnd
(
X
,
Y
)
gcnd(X,Y) always exists.

You are given an array 
A
A of length 
N
N, such that 
5
≤
A
i
≤
10
7
5≤A 
i
​
 ≤10 
7
  for each 
1
≤
i
≤
N
1≤i≤N. Your task is to compute the maximum 
gcnd
gcnd of some two elements of the array.
That is, across all pairs of indices 
(
i
,
j
)
(i,j) satisfying 
1
≤
i
<
j
≤
N
1≤i<j≤N, compute the maximum possible value of 
gcnd
(
A
i
,
A
j
)
gcnd(A 
i
​
 ,A 
j
​
 ).

Input Format
The first line of input will contain a single integer 
T
T, denoting the number of test cases.
Each test case consists of two lines of input.
The first line of each test case contains a single integer 
N
N — the length of the array.
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
  — the elements of the array.
Output Format
For each test case, output on a new line the answer: the maximum possible value of 
gcnd
(
A
i
,
A
j
)
gcnd(A 
i
​
 ,A 
j
​
 ) across all 
1
≤
i
<
j
≤
N
1≤i<j≤N.

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
 
5
≤
A
i
≤
10
7
5≤A 
i
​
 ≤10 
7
 
The sum of 
N
N over all test cases won't exceed 
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
2
8 5
3
6 6 6
4
8 9 8 8
7
5
7
Explanation:
Test case 
1
1: The only choice is to compute 
gcnd
(
8
,
5
)
gcnd(8,5), since there are only two elements in the array.
It can be verified that 
gcnd
(
8
,
5
)
=
7
gcnd(8,5)=7, because 
7
7 divides neither 
5
5 nor 
8
8, and no larger integer has this property.

Test case 
2
2: All the elements are equal to 
6
6, so the answer is 
gcnd
(
6
,
6
)
gcnd(6,6), which can be verified to be 
5
5.

Test case 
3
3: One optimal choice is to choose 
i
=
1
i=1 and 
j
=
4
j=4, to obtain 
gcnd
(
A
1
,
A
4
)
=
gcnd
(
8
,
8
)
=
7
gcnd(A 
1
​
 ,A 
4
​
 )=gcnd(8,8)=7.
It can be proved that no other pair of elements in the array has a larger 
gcnd
gcnd valu#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int T;cin>>T;
    while(T--)
    {
        int n;cin>>n;
        vector<long long>v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        sort(v.begin(),v.end());
        long long a,b;a=v[0];b=v[n-1];
        // cout<<a<<" "<<b<<endl;
        int k = max(a,b);
        while(k>0)
        {
            if (a%k != 0 && b%k!=0)
                break;
            k--;
        }
        cout<<k<<endl;
    }
}
