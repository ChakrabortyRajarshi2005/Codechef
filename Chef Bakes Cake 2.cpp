Chef Bakes Cake 2
Chef is an expert baker. To make a cake, he needs 
N
N different ingredients numbered 
1
,
2
,
…
,
N
1,2,…,N. He needs 
A
i
A 
i
​
  amount of the ingredient numbered 
i
i, and he currently has 
B
i
B 
i
​
  amount of that ingredient already.

Each ingredient costs him 
1
1 coin to buy. Find the total cost of buying the excess ingredients necessary to make 
1
1 cake.

Input Format
The first line of input will contain a single integer 
T
T, denoting the number of test cases.
Each test case consists of multiple lines of input.
The first line of each test case contains a single integer 
N
N - the total number of ingredients.
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
The third line contains 
N
N integers - 
B
1
,
B
2
,
…
,
B
N
B 
1
​
 ,B 
2
​
 ,…,B 
N
​
 .
Output Format
For each test case, output on a new line the total cost of buying the necessary ingredients for 
1
1 cake.

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
≤
100
1≤N≤100
1
≤
A
i
,
B
i
≤
100
1≤A 
i
​
 ,B 
i
​
 ≤100
Sample 1:
Input
Output
4
1
5
2
2
1 2
2 1
3
3 4 5
1 1 1
1
2
5
3
1
9
0
Explanation:
Test Case 1 : The cake has only one ingredient, of which you need 
5
5 to make 
1
1 cake. Since you already have 
2
2 of that ingredient, you need to buy 
3
3 more for a cost of 
3
3.

Test Case 2 : The cake has 
2
2 ingredients. You don't need anymore quantity of the ingredient 
1
1, since you already have 
2
2 of those but need only 
1
1. However, you need 
1
1 more quantity of the ingredient 
2
2, since you have only 
1
1 but need 
2
2. Thus, you pay 
1
1 coin to buy ingredient 
2
2.

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        int A[N];
        int B[N];
        
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        for(int i=0;i<N;i++){
            cin>>B[i];
        }
        int count = 0;
        for(int i=0;i<N;i++){
            if(A[i]>B[i]){
                count += A[i] - B[i];
            }
        }
        cout<<count<<endl;
    }
    
}
