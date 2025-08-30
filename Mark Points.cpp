Mark Points
There are 
N
N equi-spaced points numbered 
1
,
2
,
…
,
N
1,2,…,N. Initially, all points are unmarked.

In one operation, you can choose 
X
X such that 
1
<
X
<
N
1<X<N, and then mark points 
X
−
1
,
X
,
X
+
1
X−1,X,X+1. (If any of them were already marked, they do not get affected)

Finally, you will make a binary string 
S
S, where 
S
i
=
1
S 
i
​
 =1 if and only if you marked point 
i
i, and otherwise 
S
i
=
0
S 
i
​
 =0.

Now, you forgot what operations you did. You have a binary string 
S
S with you. You want to check if it is possible to obtain 
S
S by doing some of the above operations of marking points.

Print 
Yes
Yes if it is possible to obtain 
S
S and 
No
No otherwise.

Input Format
The first line of input will contain a single integer 
T
T, denoting the number of test cases.
Each test case consists of multiple lines of input.
The first line of each test case contains 
N
N - the number of points.
The second line contains 
S
S - a binary string.
Output Format
For each test case, output on a new line 
Yes
Yes if it is possible to obtain 
S
S and 
No
No otherwise.

Constraints
1
≤
T
≤
100
1≤T≤100
3
≤
N
≤
100
3≤N≤100
S
i
∈
{
0
,
1
}
S 
i
​
 ∈{0,1}
Sample 1:
Input
Output
7
3
000
4
1111
5
00101
7
0110111
11
11101110111
4
0011
4
1100
Yes
Yes
No
No
Yes
No
No
Explanation:
Test Case 1 : You can choose to not mark anything.

Test Case 2 : First perform one operation with 
X
=
2
X=2 and then with 
X
=
3
X=3.
#include <bits/stdc++.h>

using namespace std;

void s() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t = s;
    for (int i = 1; i < n - 1; ++i) {
        if (s[i - 1] == '1' && s[i] == '1' && s[i + 1] == '1') {
            t[i - 1] = '0';
            t[i] = '0';
            t[i + 1] = '0';
        }
    }
    bool ok = true;
    for (char c : t) {
        if (c == '1') {
            ok = false;
            break;
        }
    }

    if (ok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        s();
    }
}
