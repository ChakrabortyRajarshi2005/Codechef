Chef Bakes Cake 1
Chef is an expert baker. Each cake costs him 
30
30 coins to make, and then he sells each for 
50
50 coins.

Today, Chef made a total of 
N
N cakes and was able to sell 
M
M cakes. The remaining cakes went unsold and were wasted.

Find out how much money (in coins) Chef made from these cakes. It may be possible that the answer is negative to indicate Chef lost money.

Input Format
The only line of input contains 
2
2 integers - 
N
N and 
M
M.
Output Format
For each test case, output on a new line the amount of money Chef made.

Constraints
1
≤
M
≤
N
≤
10
1≤M≤N≤10
Sample 1:
Input
Output
3 3
60
Explanation:
Chef made 
3
3 cakes and sold all 
3
3 of them. His profit on each of the cakes was 
20
20 coins, and hence he made a total of 
60
60 coins.

Sample 2:
Input
Output
3 1
-40
Explanation:
Chef had made 
3
3 cakes, costing him 
90
90 coins, but only 
1
1 of them was sold which got him back 
50
50 coins. Hence, he lost 
90
−
50
=
40
90−50=40 coins.
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int N,M;
	cin>>N>>M;
	int profit = (M*50) - (N*30);
	cout<<profit;

}
