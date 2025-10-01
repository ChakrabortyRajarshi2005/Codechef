
Reflection Disorder
Suppose 
B
B is an array of length 
M
M. We define the reflection of 
B
B as follows:

For each 
i
i such that 
1
≤
i
<
M
+
1
−
i
1≤i<M+1−i, swap the 
i
i-th largest and 
(
M
+
1
−
i
)
(M+1−i)-th largest elements of 
B
B.
That is, the reflection of 
B
B is obtained by swapping its largest element with its smallest element, its second largest element with its second smallest, and so on.
For example, if 
B
=
[
3
,
5
,
8
,
6
,
2
,
9
]
B=[3,5,8,6,2,9], its reflection is 
[
8
,
6
,
3
,
5
,
9
,
2
]
[8,6,3,5,9,2].

Alice has an array 
A
A of length 
N
N, that contains distinct integers (
1
≤
A
i
≤
N
1≤A 
i
​
 ≤N).
She would like to sort 
A
A in ascending order, i.e. end up with 
A
1
<
A
2
<
…
<
A
N
A 
1
​
 <A 
2
​
 <…<A 
N
​
 .
To achieve this, she will do the following exactly once:

First, choose two indices 
i
i and 
j
j, and swap the values at those indices, i.e. 
swap
(
A
i
,
A
j
)
swap(A 
i
​
 ,A 
j
​
 ).
Note that choosing 
i
=
j
i=j is allowed, which effectively doesn't change the array.
Then, choose a subsequence (not necessarily contiguous) of 
A
A, and replace it by its reflection.
In particular, it is allowed to choose the empty subsequence, in which case 
A
A doesn't change.
Note that Alice will perform both operations exactly once each, and specifically in the given order - i.e. the swap before the subsequence reflection.

Is it possible for Alice to sort the array?

Input Format
The first line of input will contain a single integer 
T
T, denoting the number of test cases.
Each test case consists of two lines of input.
The first line of each test case contains a single integer 
N
N — the length of the array.
The second line contains 
N
N space-separated integers 
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
For each test case, on a new line, output the answer: Yes if Alice can sort 
A
A in ascending order, and No otherwise.

Each character of the output may be printed in either uppercase or lowercase, i.e. the strings NO, No, nO, and no will all be treated as equivalent.

Constraints
1
≤
T
≤
10
5
1≤T≤10 
5
 
1
≤
N
≤
2
⋅
10
5
1≤N≤2⋅10 
5
 
1
≤
A
i
≤
N
1≤A 
i
​
 ≤N
A
i
≠
A
j
A 
i
​
 =A 
j
​
  for 
i
≠
j
i=j
The sum of 
N
N over all test cases won't exceed 
2
⋅
10
5
2⋅10 
5
 .
Sample 1:
Input
Output
4
3
3 2 1
4
2 3 4 1
4
2 4 1 3
5
1 4 3 5 2
Yes
Yes
No
Yes
Explanation:
Test case 
1
1: 
A
=
[
3
,
2
,
1
]
A=[3,2,1]. Alice can swap the first and third elements to obtain 
A
=
[
1
,
2
,
3
]
A=[1,2,3], and then perform the reflection operation with the empty subsequence so the array doesn't change.

Test case 
2
2: One solution is as follows:

Swap the first and third elements. The array becomes 
[
4
,
3
,
2
,
1
]
[4,3,2,1].
Perform the reflection operation with the entire array. This results in it being sorted.
Test case 
3
3: No swap followed by a subsequence reversal can sort 
A
A.

Test case 
4
4: One solution is as follows:

Swap the second and fourth elements, to obtain 
A
=
[
1
,
5
,
3
,
4
,
2
]
A=[1,5,3,4,2].
Perform the subsequence reflection on the subsequence 
[
5
,
2
]
[5,2], which converts the array to 
[
1
,
2
,
3
,
4
,
5
]
[1,2,3,4,5] as required.#include<bits/stdc++.h>
#define INF LONG_LONG_MAX
#define inf INT_MAX
#define bctz __builtin_ctz
#define bclz __builtin_clz
#define bpt __builtin_popcount
#define pb push_back
#define x first
#define y second

using namespace std;

typedef long long INT;
typedef pair<int,int> pii;
typedef pair<int,pii> pi3;
typedef vector<int> VI;

template<class T,class U>inline void smax(T&a,U b){if(a<b)a=b;}
template<class T,class U>inline void smin(T&a,U b){if(a>b)a=b;}

const int NN = 4e5 + 10;
const int mod = 998244353;

int A[NN], B[NN], flag[NN];
vector<int> vec, tmp, re;
vector< pii > vv;
int ok(){
	sort(vec.begin(), vec.end());
	int sz = vec.size();
	for(int i = 0; i < sz; i ++){
		int x = vec[i], y = vec[sz - i - 1];
		if(B[x] != y) return 0;
	}
	return 1;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	while(T--){
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i ++) scanf("%d", A + i);
		tmp.clear(), re.clear();	
		for(int i = 1; i <= n; i ++) flag[i] = 0;
		
		int ans = 1;
		
		for(int i = 1; i <= n; i ++){
			if(flag[i]) continue;
			if(A[i] == i) continue;
			if(A[A[i]] == i){
				tmp.pb(i);
				tmp.pb(A[i]);
				flag[i] = 1;
				flag[A[i]] = 1;
				continue;
			}
			
			int id = i;
			if(!re.empty()){
				ans = 0;
				break;
			}
			while(1){
				flag[id] = 1;
				re.pb(id);
				id = A[id];
				if(id == i) break;
			}
			if((int)re.size() > 4){
				ans = 0;
				break;
			}
		}
		
		if(ans == 0){
			puts("NO");
			continue;
		}
		if(re.size() == 0){
			for(int i = 1; i <= n; i ++) B[i] = A[i];
			
			vv.clear();
			int ans = 1;
			for(int i = 1; i <= n; i ++)
				if(i < A[i]) vv.pb({i, A[i]});
			
			int sz = vv.size();
			for(int i = 1; i < sz; i ++){
				int x = vv[i - 1].y, y = vv[i].y;
				if(x < y){
					vec.clear();
					for(int j = 0; j < sz; j ++)
						if(j == i - 1) continue;
						else{
							vec.pb(vv[j].x);
							vec.pb(vv[j].y);
						}
					if(ok()){
						ans = 1;
						break;
					}
					ans = 0;
					vec.clear();
					for(int j = 0; j < sz; j ++)
						if(j == i) continue;
						else{
							vec.pb(vv[j].x);
							vec.pb(vv[j].y);
						}
					if(ok()){
						ans = 1;
						break;
					}
					ans = 0;
					break;
				}
			}
			if(ans) puts("YES");
			else puts("NO");
			continue;
		} else if(re.size() == 3){
			ans = 0;
			for(int k = 0; k < 3; k ++){
				vec.clear();
				for(int i = 1; i <= n; i ++) B[i] = A[i];
				for(int val : tmp) vec.pb(val);
				for(int j = 0; j < 3; j ++)
					if(j != k) vec.pb(re[j]);
				int x = re[k], y = re[(k + 2) % 3];
				swap(B[x], B[y]);
				if(ok()){
					ans = 1;
					break;
				}
			}
			if(ans) puts("YES");
			else puts("NO");
			continue;
		} else{
			ans = 0;
			for(int i = 0; i < 2; i ++){
				for(int j = 1; j <= n; j ++) B[j] = A[j];
				int x = re[i], y = re[i + 2];
				swap(B[x], B[y]);
				vec.clear();
				for(int val : tmp) vec.pb(val);
				for(int val : re) vec.pb(val);
				if(ok()){
					ans = 1;
					break;
				}
			}
			if(ans) puts("YES");
			else puts("NO");
			continue;
		}
		
	}
	return 0;
}
