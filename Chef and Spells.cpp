Chef and Spells
Read problem statements in Mandarin, Bengali, Russian, and Vietnamese as well.
Chef has three spells. Their powers are 
A
A, 
B
B, and 
C
C respectively. Initially, Chef has 
0
0 hit points, and if he uses a spell with power 
P
P, then his number of hit points increases by 
P
P.

Before going to sleep, Chef wants to use exactly two spells out of these three. Find the maximum number of hit points Chef can have after using the spells.

Input Format
The first line of the input contains a single integer 
T
T denoting the number of test cases. The description of 
T
T test cases follows.
The first and only line of each test case contains three space-separated integers 
A
A, 
B
B, and 
C
C.
Output Format
For each test case, print a single line containing one integer — the maximum number of hit points.

Constraints
1
≤
T
≤
10
4
1≤T≤10 
4
 
1
≤
A
,
B
,
C
≤
10
8
1≤A,B,C≤10 
8
 
Subtasks
Subtask #1 (100 points): original constraints

Sample 1:
Input
Output
2
4 2 8
10 14 18
12
32
Explanation:
Example case 1: Chef has three possible options:

Use the first and second spell and have 
4
+
2
=
6
4+2=6 hitpoints.
Use the second and third spell and have 
2
+
8
=
10
2+8=10 hitpoints.
Use the first and third spell and have 
4
+
8
=
12
4+8=12 hitpoints.
Chef should choose the third option and use the spells with power 
4
4 and 
8
8 to have 
12
12 hitpoints.

Example case 2: Chef should use the spells with power 
14
14 and 
18
18
#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int a,b,c, ans=0;
	    cin>>a>>b>>c;
	    cout<<(a+b+c)-min(a,min(b,c))<<endl;
	}
	return 0;
}
