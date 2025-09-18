Drawing Chances
Alice and Bob are playing a tournament which consists of 
N
N matches.

Right now, they have completed 
M
M (
1
≤
M
≤
N
1≤M≤N) matches already, and you have the results from those matches. You are given a binary string 
S
S of length 
M
M, where 
S
i
=
1
S 
i
​
 =1 means that Alice won the 
i
i-th match and 
S
i
=
0
S 
i
​
 =0 if Bob won the 
i
i-th match.

At the end, whoever has won more matches wins the tournament. However, if both of them win equal number of matches, the tournament ends in a tie instead.

Given the matches that have already been played, is it still possible for the tournament to end in a tie? Print 
Yes
Yes if it is possible, and 
No
No otherwise.

Input Format
The first line of input will contain a single integer 
T
T, denoting the number of test cases.
Each test case consists of multiple lines of input.
The first line of each test case contains 
2
2 integers - 
N
N and 
M
M, the number of total matches to play, and the matches already played.
The second line contains a binary string 
S
S.
Output Format
For each test case, output on a new line 
Yes
Yes if is it possible to still have a draw and 
No
No otherwise.

Constraints
1
≤
T
≤
100
1≤T≤100
1
≤
M
≤
N
≤
100
1≤M≤N≤100
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
5
2 2
10
4 3
111
3 2
10
6 5
00100
6 4
0001
Yes
No
No
No
Yes
Explanation:
Test Case 1 : The tournament has already completed all the matches, and it was a 
1
−
1
1−1 tie.

Test Case 2 : Alice has won 
3
3 matches, there is no way for Bob to tie now.

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector < int > ;

void s()
{
    int n, m;
    cin >> n >> m;
    string str;
    cin >> str;
    if (n % 2 != 0)
    {
        cout << "No" << endl;
        return;
    }
    int a_s = accumulate(str.begin(), str.end(), 0, [](int sum, char c) {
        return sum + (c - '0');
    });

    int rem = n - m;
    int target = n / 2;
    if (a_s <= target && target <= a_s + rem)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        s();
}
