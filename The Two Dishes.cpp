The Two Dishes
Chef prepared two dishes yesterday. Chef had assigned the 
tastiness
tastiness 
T
1
T 
1
​
  and 
T
2
T 
2
​
  to the first and to the second dish respectively. The tastiness of the dishes can be any 
integer
integer between 
0
0 and 
N
N (both inclusive).

Unfortunately, Chef has forgotten the values of 
T
1
T 
1
​
  and 
T
2
T 
2
​
  that he had assigned to the dishes. However, he remembers the sum of the tastiness of both the dishes - denoted by 
S
S.

Chef wonders, what can be the maximum possible absolute difference between the tastiness of the two dishes. Can you help the Chef in finding the maximum absolute difference?

It is guaranteed that at least one pair 
{
T
1
,
T
2
}
{T 
1
​
 ,T 
2
​
 } exist such that 
T
1
+
T
2
=
S
,
0
≤
T
1
,
T
2
≤
N
T 
1
​
 +T 
2
​
 =S,0≤T 
1
​
 ,T 
2
​
 ≤N.

Input Format
The first line of input contains a single integer 
T
T, denoting the number of testcases. The description of the 
T
T testcases follows.
The first and only line of each test case contains two space-separated integers 
N
N, 
S
S, denoting the maximum tastiness and the sum of tastiness of the two dishes, respectively.
Output Format
For each testcase, output a single line containing the maximum absolute difference between the tastiness of the two dishes.

Constraints
1
≤
T
≤
10
3
1≤T≤10 
3
 
1
≤
N
≤
10
5
1≤N≤10 
5
 
1
≤
S
≤
2
⋅
10
5
1≤S≤2⋅10 
5
 
Sample 1:
Input
Output
3
3 1
4 4
2 3
1
4
1
Explanation:
Test Case 
1
1: The possible pairs of 
{
T
1
,
T
2
}
{T 
1
​
 ,T 
2
​
 } are 
{
0
,
1
}
{0,1} and 
{
1
,
0
}
{1,0}. Difference in both the cases is 
1
1, hence the maximum possible absolute difference is 
1
1.

Test Case 
2
2: The possible pairs of 
{
T
1
,
T
2
}
{T 
1
​
 ,T 
2
​
 } are 
{
0
,
4
}
{0,4}, 
{
1
,
3
}
{1,3}, 
{
2
,
2
}
{2,2}, 
{
3
,
1
}
{3,1} and 
{
4
,
0
}
{4,0}. The maximum possible absolute difference is 
4
4.

Test Case 
3
3: The possible pairs of 
{
T
1
,
T
2
}
{T 
1
​
 ,T 
2
​
 } are 
{
1
,
2
}
{1,2} and 
{
2
,
1
}
{2,1}. Difference in both the cases is 
1
1, and hence the maximum possible absolute difference is 
1
1.

int T;
    cin >> T;
    while (T--) {
        int N, S;
        cin >> N >> S;

        // Minimum of S and (2*N - S) gives the max absolute difference
        int maxDiff = min(S, 2 * N - S);
        cout << maxDiff << endl;
    }
    return 0;
