Sabotage
Chef is participating in a programming competition. Currently, he has a score of 
X
X.

There are 
N
N participants other than Chef.
The 
i
i-th of these participants has a score of 
A
i
A 
i
​
 .

Chef's rank in the contest is determined as follows:

Count the number of indices 
i
i (
1
≤
i
≤
N
1≤i≤N) such that 
A
i
>
X
A 
i
​
 >X.
Let this count be 
R
R.
Chef's rank is then equal to 
R
+
1
R+1.
Chef would like to improve his rank, so he decides to sabotage his opponents.
A sabotage operation is defined as follows:

Choose an index 
i
i (
1
≤
i
≤
N
1≤i≤N), and do both of the following:
Set 
A
i
A 
i
​
  to 
0
0.
Add 
100
100 to 
X
X, that is, increase Chef's score by 
100
100.
Since there's not much time remaining, Chef can perform the sabotage operation at most 
K
K times.
Find the minimum possible rank Chef can achieve at the end.

Input Format
The first line of input will contain a single integer 
T
T, denoting the number of test cases.
Each test case consists of two lines of input.
The first line of each test case contains three space-separated integers 
N
,
X
,
N,X, and 
K
K — the number of other participants, Chef's initial score, and the number of times the sabotage operation can be performed, respectively.
The second line contains 
N
N space-separated integers 
A
1
,
…
,
A
N
A 
1
​
 ,…,A 
N
​
  — the scores of the other participants.
Output Format
For each test case, output on a new line one integer: the minimum possible rank Chef can achieve.

Constraints
1
≤
T
≤
500
1≤T≤500
1
≤
N
≤
500
1≤N≤500
0
≤
K
≤
N
0≤K≤N
1
≤
X
,
A
i
≤
10000
1≤X,A 
i
​
 ≤10000
Sample 1:
Input
Output
4
4 150 1
250 375 509 12
4 150 2
250 375 509 12
5 415 3
5325 123 2523 6320 789
3 128 0
256 768 512
2
1
2
4
Explanation:
Test case 
1
1: 
K
=
1
K=1, so at most one person can be sabotaged.
One optimal solution is to choose 
i
=
2
i=2. This will set 
A
2
=
0
A 
2
​
 =0 and increase 
X
X by 
100
100.
As a result of this, the scores will be 
A
=
[
250
,
0
,
509
,
12
]
A=[250,0,509,12], and 
X
=
150
+
100
=
250
X=150+100=250.

Chef's rank here is 
2
2, since there's exactly one person with a strictly score (that being 
A
3
=
509
A 
3
​
 =509).
It can be shown that obtaining a rank of 
<
2
<2 is impossible.

Test case 
2
2: The same set of scores, but 
K
=
2
K=2 now.
One optimal solution is to choose 
i
=
2
i=2 and 
i
=
3
i=3.
As a result of this, the scores will be 
A
=
[
250
,
0
,
0
,
12
]
A=[250,0,0,12], and 
X
=
150
+
100
+
100
=
350
X=150+100+100=350.

Chef's rank here is 
1
1, since there's nobody with a higher score than him.

Test case 
4
4: 
K
=
0
K=0, so no sabotage can be performed.
All three other participants have a higher score than Chef, so Chef's rank is 
3
+
1
=
4
3+1=4.#include <bits/stdc++.h>
using namespace std;

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);

    int t;
    cin >> t;
    while(t--)
    {
        int n,x,k;
        cin >> n >> x >> k;

        vector<int> a(n);
        for(int i=0; i<n; i++)
        {
            cin >> a[i];
        }

        sort(a.rbegin(), a.rend());

        for(int i=0; i<k; i++)
        {
            a[i] = 0;
            x += 100;
        }

        int max = 0;
        for(int s : a)
        {
            if(s > x)
                max++;
        }
        cout << max+1 << '\n';
    }
    return 0;
}
