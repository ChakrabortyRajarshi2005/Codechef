Marble Collector
There are a total of 
M
M possible types of marbles that you want to collect. They are numbered 
1
,
2
,
…
,
M
1,2,…,M.

You currently have 
N
N marbles with you, with types 
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
 . Note that you may have the same type of marble twice or more.

Find number of types of marbles that you still have not collected.

Input Format
The first line of input will contain a single integer 
T
T, denoting the number of test cases.
Each test case consists of multiple lines of input.
The first line of each test case contains 
N
N and 
M
M - the number of marbles you have, and the total possible types of marbles.
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
Output Format
For each test case, output on a new line the number of types of marbles you have not collected yet.

Constraints
1
≤
T
≤
100
1≤T≤100
1
≤
N
,
M
≤
100
1≤N,M≤100
1
≤
A
i
≤
M
1≤A 
i
​
 ≤M
Sample 1:
Input
Output
3
3 3
1 1 2
1 100
42
3 1
1 1 1
1
99
0
Explanation:
Test Case 1 : You have not collected the type 
3
3 marble only.

Test Case 2 : You have not collected types 
1
,
2
,
…
,
41
,
43
,
…
,
100
1,2,…,41,43,…,100.

Test Case 3 : There is only one type and you have collected it (thrice).

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    unordered_map<int,int> mp;
	    cin>>n>>m;
	    for(int i=0;i<n;i++){
	        int a;
	        cin>>a;
	        mp[a]++;
	    }
	    int cnt=0;
	  for(auto i:mp){
	      cnt++;
	  }
	  cout<<m-cnt<<endl;
	}

}
