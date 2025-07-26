Cloud Watching
Chef believes he can predict the weather just by looking at clouds!

Chef saw 
A
A clouds in the morning, and 
B
B clouds in the evening.
He believes that it will rain if the number of clouds he saw in the evening is at least 
3
3 times of the number of the clouds he saw in the morning.

Given the values of 
A
A and 
B
B, what will Chef's prediction be?

Input Format
The only line of input contains two space-separated integers 
A
A and 
B
B — the number of clouds Chef saw in the morning and evening, respectively.
Output Format
Output a single line containing the answer: Rain if Chef believes it will rain, and Dry otherwise.

Each character of the output may be printed in either uppercase or lowercase, i.e. the strings dry, Dry, DrY, and dRY are all considered equivalent.

Constraints
1
≤
A
,
B
≤
20
1≤A,B≤20
Sample 1:
Input
Output
3 9
Rain
Explanation:
Chef saw 
3
3 clouds in the morning and 
9
9 in the evening.
Since 
9
≥
3
×
3
9≥3×3, Chef believes it will rain.

Sample 2:
Input
Output
4 9
Dry
Explanation:
Chef saw 
4
4 clouds in the morning and 
9
9 in the evening.
Since 
9
<
3
×
4
=
12
9<3×4=12, Chef believes it will not rain.

Sample 3:
Input
Output
15 14
Dry
Explanation:
Chef saw 
15
15 clouds in the morning and 
14
14 in the evening.
Since 
14
<
3
×
15
=
45
14<3×15=45, Chef believes it will not rain.
#include <bits/stdc++.h>
using namespace std;

int main() {
	int A,B;
	cin>>A>>B;
	if(B >= 3*A){
	    cout<<"Rain"<<endl;
	  }  else{
	        cout<<"Dry"<<endl;
	    }
	
return 0;
}
