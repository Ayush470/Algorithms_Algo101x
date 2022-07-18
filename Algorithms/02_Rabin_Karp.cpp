#include <bits/stdc++.h>
#include<cstring>
#include<vector>
using namespace std;
#define ll long long int 

void NAJPF(string s,string p){
		ll mod = 1000000007;
		ll dp[s.length()];
		ll pa[s.length()];
		int pr = 31;
		ll hv = 0;
		ll pow = 1;
		for (int i = 0; i < p.length(); i++) {
			hv = (hv + ((p[i] - 'a' + 1) * pow) % mod) % mod;
			pow = (pow * pr) % mod;

		}

		dp[0] = s[0] - 'a' + 1;
		pa[0] = 1;
		pow = pr;
		for (int i = 1; i < s.length(); i++) {
			dp[i] = (dp[i - 1] + ((s[i] - 'a' + 1) * pow) % mod) % mod;
			pa[i] = pow;
			pow = (pow * pr) % mod;
		}
		vector<int> list;
		for (int ei = p.length() - 1, si = 0; ei < s.length(); ei++, si++) {
			ll currhash = dp[ei];
			if (si > 0) {
				currhash = (currhash - dp[si - 1]+mod) % mod;
			}
			if (currhash == (hv * pa[si]) % mod) {
				list.push_back(si); 
			}

		}

		if (list.size() == 0) {
			cout<<"Not Found"<<endl;
		} else {
			cout<<list.size()<<endl;
			for (int v : list) {
				cout<<(v+1)<<" ";
			}
			cout<<endl;
		}
		cout<<endl;

}

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		string s,p;
		cin>>s>>p;
		NAJPF(s,p);
	}
}

// NAJPF SPOJ

// 1 jjjjjjjjjjjaaaaaaaaapppppppjjjjjjjj jj