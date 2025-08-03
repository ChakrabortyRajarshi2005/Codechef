Good Ranking (Triplet)
This shares part of the initial setup with Good Ranking (Pair).

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

For every triplet 
(
a
,
b
,
c
)
(a,b,c) such that 
1
≤
a
,
b
,
c
≤
N
1≤a,b,c≤N and 
a
≠
b
,
b
≠
c
,
c
≠
a
a=b,b=c,c=a, there exists at least one contest such that simultaneously, 
a
a beats 
b
b and 
b
b beats 
c
c.
Your task is to choose the number of rankings, let's say 
M
M and then print 
M
M permutations, the rankings of each of the contests. You can have at most 
40
40 contests, so ensure 
1
≤
M
≤
40
1≤M≤40.

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
40
)
M(1≤M≤40) - the number of contests, and then output 
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
