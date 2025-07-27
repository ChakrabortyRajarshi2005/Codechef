Light All
Chefland's jail has 
N
N prison cells, all arranged in a row.
Above each prison cell is a light.

Each light can be made to face either left or right (but not both).
The lights aren't very strong, and so can only light up adjacent cells. In particular,

If the light at index 
i
i is facing right, it will light up cells 
i
i and 
i
+
1
i+1 (the latter only if 
i
+
1
≤
N
i+1≤N).
If the light at index 
i
i is facing left, it will light up cells 
i
i and 
i
−
1
i−1 (the latter only if 
i
−
1
≥
1
i−1≥1).
Unfortunately, due to a lack of maintenance, not all of the lights are working.
You are given a binary string 
S
S of length 
N
N, where 
S
i
=
1
S 
i
​
 =1 means the 
i
i-th light is working, and 
S
i
=
0
S 
i
​
 =0 means it's not working.

Is it possible to choose the directions for all the working lights, so that every cell is lit up by at least one light?

Input Format
The first line of input will contain a single integer 
T
T, denoting the number of test cases.
Each test case consists of two lines of input.
The first line of each test case contains a single integer 
N
N — the number of cells.
The second line contains a binary string 
S
S of length 
N
N, denoting information about which lights work.
Output Format
For each test case, output on a new line the answer: Yes if there's a way to choose directions for the lights and light up every cell, and No otherwise.

Each character of the output may be printed in either uppercase or lowercase, i.e. the strings NO, No, nO, and no will all be treated as equivalent.

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
S
i
∈
{
0
,
1
}
S 
i
​
 ∈{0,1}
Sample 1:
Input
Output
4
5
10011
5
01010
6
110100
7
0110011
Yes
No
No
Yes
Explanation:
Test case 
1
1: The lights at positions 
1
,
4
,
5
1,4,5 are working. Consider the following configuration:

Light 
1
1 faces right. This lights up cells 
1
,
2
1,2.
Light 
4
4 faces left. This lights up cells 
3
,
4
3,4.
Light 
5
5 faces left. This lights up cells 
4
,
5
4,5.
All cells are now lit up.
Test case 
2
2: The lights at positions 
2
,
4
2,4 are active.
To light up cell 
1
1, the light at 
2
2 must face left.
To light up cell 
5
5, the light at 
4
4 must face right.
But then this leaves position 
3
3 unlit.
So, it's impossible to light up all the cells.

Test case 
3
3: There's no way to light up the last cell.

Test case 
4
4: The lights at positions 
2
,
3
,
6
,
7
2,3,6,7 are active.
One valid configuration is to make them face directions left, right, left, right, respectively.
#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    bool flag=true;
    vector<bool> taken(n,false);
    for(int i=0;i<n;i++){
        if(s[i]=='1') continue;
        //left
        if(i>0 && s[i-1]=='1' && taken[i-1]==false){
            taken[i-1]=true;
        }else if(i<n-1 && s[i+1]=='1' && taken[i+1]==false){
            taken[i+1]=true;
        }else{
            flag=false;
            break;
        }
    }
    if(flag){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}
int main() {
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
