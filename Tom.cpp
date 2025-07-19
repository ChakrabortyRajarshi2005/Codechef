Tom And Jerry 1
Read problem statements in Bengali, Mandarin Chinese, Russian, and Vietnamese as well.
There is a grid of size 
10
5
×
10
5
10 
5
 ×10 
5
 , covered completely in railway tracks. Tom is riding in a train, currently in cell 
(
a
,
b
)
(a,b), and Jerry is tied up in a different cell 
(
c
,
d
)
(c,d), unable to move. The train has no brakes. It shall move exactly 
K
K steps, and then its fuel will run out and it shall stop. In one step, the train must move to one of its neighboring cells, sharing a side. Tom can’t move without the train, as the grid is covered in tracks. Can Tom reach Jerry’s cell after exactly 
K
K steps?

Note: Tom can go back to the same cell multiple times.

Input Format
The first line contains an integer 
T
T, the number of test cases. Then the test cases follow.
Each test case contains a single line of input, five integers 
a
,
b
,
c
,
d
,
K
a,b,c,d,K.
Output Format
For each testcase, output in a single line "YES" if Tom can reach Jerry's cell in exactly 
K
K moves and "NO" if not.

You may print each character of the string in uppercase or lowercase (for example, the strings "yEs", "yes", "Yes" and "YES" will all be treated as identical).

Constraints
1
≤
T
≤
10
5
1≤T≤10 
5
 
0
≤
a
,
b
,
c
,
d
≤
10
5
0≤a,b,c,d≤10 
5
 
(
a
,
b
)
≠
(
c
,
d
)
(a,b)=(c,d)
1
≤
K
≤
2
⋅
10
5
1≤K≤2⋅10 
5
 
Subtasks
Subtask #1 (100 points): original constraints

Sample 1:
Input
Output
3
1 1 2 2 2
1 1 2 3 4
1 1 1 0 3
YES
NO
YES
Explanation:
Test Case 
1
1: A possible sequence of moves is 
(
1
,
1
)
→
(
1
,
2
)
→
(
2
,
2
)
(1,1)→(1,2)→(2,2).

Test Case 
2
2: There is a possible sequence in 
3
3 moves, but not in exactly 
4
4 moves.

Test Case 
3
3: A possible sequence of moves is 
(
1
,
1
)
→
(
1
,
0
)
→
(
0
,
0
)
→
(
1
,
0
)
(1,1)→(1,0)→(0,0)→(1,0).


#include <iostream>
using namespace std;

int main() {
int t;
cin>>t;
while(t--)
{int a,b,c,d,k;
cin>>a>>b>>c>>d>>k;
int s=abs(d-b)+abs(c-a);

if(k==s)
cout<<"Yes"<<endl;
else if (k<s)cout<<"No"<<endl;
else if (k>s && (k-s)%2==0) cout<<"Yes"<<endl;
else cout<<"No"<<endl;

    
}
	return 0;
}
