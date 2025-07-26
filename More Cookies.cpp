More Cookies
Alice, along with 
N
N of her friends, visited a bakery.
There, Alice initially bought 
C
C cookies, and the 
i
i-th friend bought 
A
i
A 
i
​
  cookies.

Alice is quite competitive, so she'll only be happy if:

At least one friend has strictly less cookies than her; and
No other friend has equal cookies to her.
What's the minimum number of extra cookies Alice must buy, to ensure that she's happy?

Input Format
The first line of input will contain a single integer 
T
T, denoting the number of test cases.
Each test case consists of two lines of input.
The first line of each test case contains two space-separated integers 
N
N and 
C
C — the number of friends, and the number of cookies Alice bought initially.
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
  — the counts of the cookies bought by Alice's friends.
Output Format
For each test case, output on a new line the answer: the minimum number of extra cookies Alice must buy.

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
C
≤
100
1≤C≤100
1
≤
A
i
≤
100
1≤A 
i
​
 ≤100
Sample 1:
Input
Output
4
3 5
10 5 3
4 6
6 8 7 6
4 6
5 7 8 9
5 3
10 9 8 7 6
1
3
0
8
Explanation:
Test case 
1
1: Alice can buy one more cookie, to have a total of 
C
+
1
=
5
+
1
=
6
C+1=5+1=6 cookies.
No friend has 
6
6 cookies, and the second friend has 
5
5 cookies which is less than 
6
6.

Test case 
2
2: Alice has 
C
=
6
C=6 cookies initially. She must buy 
3
3 cookies to reach a total of 
9
9, which no other friend has.

Test case 
3
3: Alice doesn't need to buy any more cookies: nobody else has 
C
=
6
C=6 cookies, and the first friend has less than 
6
6 cookies.
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
int t;
cin>>t;
while(t--){
    int n,c;
    cin>>n>>c;
    int e=c;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int mini=*(min_element(v.begin(),v.end()));
    int d=*(lower_bound(v.begin(),v.end(),c));
    if(c>mini && d!=c){
        cout<<c-e<<"\n";
    }
    else if(c>mini &&d==c){
        c+=1;
       while(*(lower_bound(v.begin(),v.end(),c))==c){
           c++;
       }
       cout<<c-e<<"\n";
    }
    else if(c<=mini && d!=c){
        c=mini+1;
while(*(lower_bound(v.begin(),v.end(),c))==c){
           c++;
       }
       cout<<c-e<<"\n";
    }
    else if(c<=mini && d==c){
        c=mini+1;
        while(*(lower_bound(v.begin(),v.end(),c))==c){
           c++;
       }
       cout<<c-e<<"\n";
    }
    
}
}
