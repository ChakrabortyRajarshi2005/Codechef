Min-Max Deque
This is the hard version of the problem. Here, there are updates to the array, and the constraints on 
Q
Q are 
1
≤
Q
≤
2
⋅
10
5
1≤Q≤2⋅10 
5
 .

Consider an array 
A
A of length 
N
N. 
N
N is odd.
Alice and Bob will play the following game on it:

Let 
B
B be an initially empty array.
Alice and Bob take turns playing, with Alice going first.
On the 
i
i-th turn, the current player will choose element 
A
i
A 
i
​
 , and insert it to either the beginning or the end of 
B
B.
So, Alice will place 
A
1
A 
1
​
 , then Bob will place 
A
2
A 
2
​
 , then Alice will place 
A
3
A 
3
​
 , and so on.
This continues till all 
N
N elements have been placed in 
B
B.
Once the game has finished, Alice's score is defined to be 
min
⁡
(
B
1
,
B
N
)
min(B 
1
​
 ,B 
N
​
 ).

Alice's objective is to maximize her score, while Bob's objective is to minimize Alice's score.
Define 
f
(
A
)
f(A) to be the final score if both players play optimally, for the starting array 
A
A.

You are given an array 
A
A of length 
N
N, where 
N
N is odd.
There are 
Q
Q point updates to the array. Each update gives you two integers 
p
p and 
X
X, and you are required to set 
A
p
=
X
A 
p
​
 =X.

Report the value of 
f
(
A
)
f(A) before any updates are performed, and also after each update.
Updates to 
A
A are permanent.

Input Format
The first line of input will contain a single integer 
T
T, denoting the number of test cases.
Each test case consists of multiple lines of input.
The first line of each test case contains two space-separated integers 
N
N and 
Q
Q — the length of 
A
A and the number of updates, respectively.
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
The next 
Q
Q lines describe the updates. Each of them contains two space-separated integers 
p
p and 
X
X, denoting a point update requiring you to set 
A
p
:
=
X
A 
p
​
 :=X.
Output Format
For each test case, output one line containing 
Q
+
1
Q+1 space-separated integers: the first integer should be the value of 
f
(
A
)
f(A) before any updates, and the 
i
i-th of the next 
Q
Q integers should be the value of 
f
(
A
)
f(A) after the first 
i
i updates.

Constraints
1
≤
T
≤
10
4
1≤T≤10 
4
 
3
≤
N
≤
2
⋅
10
5
−
1
3≤N≤2⋅10 
5
 −1
N
N is odd.
1
≤
Q
≤
2
⋅
10
5
1≤Q≤2⋅10 
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
1
≤
p
,
X
≤
N
1≤p,X≤N
The sum of 
N
N and the sum of 
Q
Q across all tests each won't exceed 
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
2
3 2
1 2 3
3 2
2 1
5 6
3 4 1 5 3
3 3
3 2
5 1
5 5
4 4
4 1
2 2 1 
3 3 3 1 5 4 2 
Explanation:
Test case 
1
1: The process is as follows.

Initially, we have 
A
=
[
1
,
2
,
3
]
A=[1,2,3], and we want to know 
f
(
A
)
f(A).
Alice starts, and must place the 
1
1 in 
B
B. Since 
B
B is empty, it becomes 
[
1
]
[1] no matter what.
Bob then must place the 
2
2 either at the start or at the end. 
B
B becomes either 
[
1
,
2
]
[1,2] or 
[
2
,
1
]
[2,1] depending on his choice.
Alice must place the 
3
3. If 
B
=
[
1
,
2
]
B=[1,2] she can make it 
[
3
,
1
,
2
]
[3,1,2], and if 
B
=
[
2
,
1
]
B=[2,1] she can make it 
[
2
,
1
,
3
]
[2,1,3]. In either case, 
min
⁡
(
B
1
,
B
3
)
=
2
min(B 
1
​
 ,B 
3
​
 )=2, and this is the best Alice can do. So, the answer is 
2
2.
The first update sets 
A
3
A 
3
​
  to 
2
2, so now 
A
=
[
1
,
2
,
2
]
A=[1,2,2].
Once again, it can be seen that 
f
(
A
)
=
2
f(A)=2: Alice can follow the same strategy as above to ensure that both 
2
2's are at the ends, so that 
min
⁡
(
B
1
,
B
3
)
=
2
min(B 
1
​
 ,B 
3
​
 )=2 for sure.
The second update sets 
A
2
A 
2
​
  to 
1
1.
Now, Alice cannot avoid having a 
1
1 at an endpoint no matter what she does, so 
f
(
A
)
=
1
f(A)=1.

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int x,y;
};
struct Seg{
    int n;
    vector<Node> t;
    static inline Node comb(const Node& L,const Node& R){
        Node u;
        u.x = max(R.x, min(R.y, L.x));
        u.y = min(L.y, R.y);
        return u;
    }
    Seg(int n=0):n(n){ t.assign(4*max(1,n), {0, (int)1e9}); }
    void build(const vector<int>& a){
        if(n==0) return;
        build(1,0,n-1,a);
    }
    void build(int v,int l,int r,const vector<int>& a){
        if(l==r){
            int i = 2 + 2*l;
            t[v] = {a[i+1], a[i]};
            return;
        }
        int m=(l+r)>>1;
        build(v<<1,l,m,a);
        build(v<<1|1,m+1,r,a);
        t[v]=comb(t[v<<1], t[v<<1|1]);
    }
    void upd(int pos,int nx,int ny){
        if(n==0) return;
        upd(1,0,n-1,pos,nx,ny);
    }
    void upd(int v,int l,int r,int pos,int nx,int ny){
        if(l==r){ t[v]={nx,ny}; return; }
        int m=(l+r)>>1;
        if(pos<=m) upd(v<<1,l,m,pos,nx,ny);
        else upd(v<<1|1,m+1,r,pos,nx,ny);
        t[v]=comb(t[v<<1], t[v<<1|1]);
    }
    Node all() const{
        if(n==0) return {0,(int)1e9};
        return t[1];
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; 
    if(!(cin>>T)) return 0;
    while(T--){
        int n,q; cin>>n>>q;
        vector<int>a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        int K=(n-2)/2;
        Seg st(K);
        st.build(a);
        auto eval = [&](const vector<int>& a,const Seg& st)->int{
            int h0 = max(a[0], a[1]);
            Node r = st.all();
            int h = max(r.x, min(r.y, h0));
            return min(a[n-1], h);
        };
        cout<<eval(a,st);
        while(q--){
            int p,x; cin>>p>>x; --p;
            a[p]=x;
            if(p>=2 && p<=n-2){
                if((p%2)==0){
                    int k=(p-2)/2;
                    st.upd(k, a[p+1], a[p]);
                }else{
                    int k=(p-1-2)/2;
                    st.upd(k, a[p], a[p-1]);
                }
            }
            cout<<" "<<eval(a,st);
        }
        cout<<"\n";
    }
    return 0;
}
