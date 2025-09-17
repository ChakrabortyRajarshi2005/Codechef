Episodes
Chef just started a new series on Netflix. This series has a total of 
N
N episodes, each of which is 
K
K minutes long.

Chef wonders what is the total time that it will take him to watch this series from start to finish. Assume that Chef does not need breaks in the middle.

You need to find the answer in terms of hours and minutes, for example, 
140
140 minutes should be 
2
2 hours and 
20
20 minutes. More specifically, the output of 
H
H hours and 
M
M minutes is considered valid only if 
0
≤
M
<
60
0≤M<60.

Input Format
The first line of input will contain a single integer 
T
T, denoting the number of test cases.
The first and only line of each test case contains 
2
2 integers - 
N
N and 
K
K.
Output Format
For each test case, output on a new line 
2
2 integers - 
H
H and 
M
M, the number of hours and minutes it will take to watch the whole series. 
0
≤
H
0≤H and 
0
≤
M
<
60
0≤M<60.

Constraints
1
≤
T
≤
1800
1≤T≤1800
1
≤
N
≤
30
1≤N≤30
1
≤
K
<
60
1≤K<60
Sample 1:
Input
Output
4
3 15
4 15
5 27
5 59
0 45
1 0
2 15
4 55
Explanation:
Test Case 1 : The total length is 
45
45 minutes, which is printed as 
0
0 hours and 
45
45 minutes.

Test Case 2 : The total length is 
60
60 minutes, which is printed as 
1
1 hour and 
0
0 minutes.

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
      int t;
      cin>>t;
      while(t--){
          int n,k;
          cin>>n>>k;
          int ti=n*k;
          int h=ti/60;
          int m=ti%60;
          cout<<h<<" "<<m<<endl;
      }
}
