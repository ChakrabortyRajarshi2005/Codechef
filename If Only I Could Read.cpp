If Only I Could Read
The median of an array 
B
B of length 
2
M
2M is defined as follows:

Sort 
B
B in non-decreasing order.
The median of 
B
B is then defined to be the element 
B
M
B 
M
​
 , after sorting.
That is, the median of 
B
B is obtained by sorting it in non-decreasing order and then taking the left of the two middle elements.
For example, if 
B
=
[
2
,
5
,
1
,
2
,
4
,
3
]
B=[2,5,1,2,4,3], the sorted array is 
[
1
,
2
,
2
,
3
,
4
,
5
]
[1,2,2,3,4,5] and the median is 
2
2.

Today, Chef learned about the definition of median - but he wasn't paying attention and missed the fact that the array must be sorted first!
So, Chef thinks that the median of an array 
B
B of length 
2
M
2M, is simply the element 
B
M
B 
M
​
  (without sorting it).

You would like to help Chef realize his mistake by providing him with an example.

You have with you an array 
A
A of length 
N
N.
Find any non-empty contiguous subarray
†
†
  of 
A
A of even length, such that Chef's definition of median and the true definition of median give different results when applied to this subarray.

It is possible that no valid subarray exists, in which case you must output 
−
1
−1.

†
†
  A contiguous subarray of 
A
A is obtained by deleting some (possibly none) elements both from the front and the back of 
A
A.
For example, if 
A
=
[
1
,
4
,
3
,
3
,
5
]
A=[1,4,3,3,5], some examples of its contiguous subarrays are 
[
1
,
4
,
3
,
3
,
5
]
,
[
4
,
3
]
,
[
5
]
,
[
1
,
4
,
3
,
3
]
[1,4,3,3,5],[4,3],[5],[1,4,3,3].
On the other hand 
[
1
,
3
,
5
]
[1,3,5] and 
[
4
,
1
]
[4,1] are not subarrays of 
A
A.

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
For each test case, on a new line:

If there does not exist any even-length subarray for which Chef's definition of median is different from the true definition of median, output the single integer 
−
1
−1.
Otherwise, output two space-separated integers 
L
L and 
R
R, denoting the bounds of the subarray you found.
The subarray in question is 
[
A
L
,
A
L
+
1
,
…
,
A
R
]
[A 
L
​
 ,A 
L+1
​
 ,…,A 
R
​
 ].
Note that this must be an even-length subarray, i.e. 
(
R
−
L
+
1
)
(R−L+1) must be even.
If there are multiple possible solutions, any of them will be accepted.

Constraints
1
≤
T
≤
500
1≤T≤500
2
≤
N
≤
500
2≤N≤500
1
≤
A
i
≤
500
1≤A 
i
​
 ≤500
Sample 1:
Input
Output
3
4
2 3 1 2
4
3 3 5 9
5
5 4 5 4 5
1 4
-1
2 5
Explanation:
Test case 
1
1: Consider the entire array, which corresponds to 
L
=
1
L=1 and 
R
=
4
R=4.

Chef's definition is to simply choose 
A
2
=
3
A 
2
​
 =3.
The true median is obtained by sorting the array to obtain 
[
1
,
2
,
2
,
3
]
[1,2,2,3] and then choosing 
A
2
A 
2
​
 , giving 
2
2.
So, the two definitions do differ.
Test case 
2
2: On every even-length subarray, Chef's median coincides with the true median.

Test case 
3
3: Consider 
L
=
2
,
R
=
5
L=2,R=5, resulting in the subarray 
[
4
,
5
,
4
,
5
]
[4,5,4,5].
The true median of this subarray is 
4
4, while Chef's definition will give 
5
5.

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define fr(i,a,b) for(int i = a; i < b; i++)
#define sum(v) accumulate((v).begin(), (v).end(), 0LL)
#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef vector<int> vi;
#define in(v,n) vi v(n); fr(i,0,n) cin>>v[i];

// ==================== Utility Functions ====================

// freq_vec - count frequency of elements in vector
unordered_map<int, int> freq_vec(const vi &v) {
    unordered_map<int, int> freq;
    for (int x : v) freq[x]++;
    return freq;
}

// freq_str - count frequency of characters in string
unordered_map<char, int> freq_str(const string &s) {
    unordered_map<char, int> freq;
    for (char c : s) freq[c]++;
    return freq;
}

// isPrime - checks if a number is prime
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

// sieve - generates prime markings up to n
vi sieve(int n) {
    vi is_prime(n+1, 1);
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i*i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i*i; j <= n; j += i)
                is_prime[j] = 0;
        }
    }
    return is_prime;
}

// gcd and lcm
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

// binary_search_custom - returns index or -1
int binary_search_custom(const vi &a, int target) {
    int l = 0, r = a.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] == target) return mid;
        else if (a[mid] < target) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

//XOR of n numbers
int xor_upto(int n) {
  if (n % 4 == 0) return n;
  if (n % 4 == 1) return 1;
  if (n % 4 == 2) return n + 1;
  return 0;
}

// ==================== Solve Function ====================
void solve(){
    int t; cin >> t;
    while(t--){
        int n;cin>>n;
        in(a,n);
        if(is_sorted(all(a))){
            cout<<-1<<endl;
            continue;
        }
         fr(i,1,n){
            if(a[i-1]>a[i]) {
                cout<<i<<" "<<i+1<<endl;
                break;
            }
         } 
        }
    }

int32_t main() {
    fast;
    solve();
    return 0;
}
