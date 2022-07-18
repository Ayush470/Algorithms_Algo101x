#include <bits/stdc++.h>
#include<cstring>
using namespace std;

int lps(string s) {
	int dp[s.length()];
	dp[0]=0;
	int i = 1;
	int len = 0;
	while (i < s.length()) {
		if (s[i] == s[len]) {
			len++;
			dp[i] = len;
			i++;
		}
		else{
			if (len > 0)
				len = dp[len - 1];
			else{
				dp[i] = 0;
				i++;
			}
		}
	}
	return dp[s.length()-1];
}
int main(){
	string s;
	cin>>s;
	int ans=lps(s);
	for(int i=0;i<ans;i++){
		cout<<s[i];
	}
}

// Longest Happy Prefix