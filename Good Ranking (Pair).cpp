Good Ranking (Pair)
This shares part of the initial setup with Good Ranking (Triplet).

There are 
N
N contestants numbered 
1
,
2
,
…
,
N
1,2,…,N. Your task is to make them participate in some contests and then manipulate the ranking in a particular way. In each competition, the ranking of the contestants can be considered to be a permutation of the integers 
[
1
,
N
]
[1,N] (i.e. there are no ties).

A contestant 
a
a is said to beat contestant 
b
b in a particular contest if 
a
a occurs earlier than 
b
b in the permutation that denotes the contest ranking.

The following condition should hold:

For every pair 
(
a
,
b
)
(a,b) such that 
1
≤
a
,
b
≤
N
1≤a,b≤N and 
a
≠
b
a=b, there exists at least one contest such that 
a
a beats 
b
b.
Your task is to choose the number of rankings, let's say 
M
M and then print 
M
M permutations, the rankings of each of the contests. You can have at most 
10
10 contests, so ensure 
1
≤
M
≤
10
1≤M≤10.

Input Format
The only line of input contains a single integer 
N
N.
Output Format
First, output 
M
(
1
≤
M
≤
10
)
M(1≤M≤10) - the number of contests, and then output 
M
M permutations of the integers in 
[
1
,
N
]
[1,N], each on a new line.

Constraints
3
≤
N
≤
250
3≤N≤250
Sample 1:
Input
Output
3
6
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
Explanation:
We have 
6
6 contests, and print all the possible permutations of 
[
1
,
3
]
[1,3], so we are guaranteed to satisfy the constraints.

#include <bits/stdc++.h>
using namespace std;

int main() {
	
    int n;
    cin>>n;
    int a = 1;
    int k = n;
    cout<<2<<endl;
    while(n--)
    {
        cout<<a<<" ";
        a++;
    }
    cout<<endl;
    --a;
    while(k--)
    {
        cout<<a<<" ";
        a--;
    }
    cout<<endl;
    
    
}
