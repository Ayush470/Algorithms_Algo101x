#include <bits/stdc++.h>
#include<cstring>
#define ll long long int 
using namespace std;
ll hasgen(string s){
	ll mod = 1000000007;
	int p = 31;
	ll pow = 1;
	ll hv = 0;
	for (int i = 0; i < s.length(); i++) {
		hv = (hv + ((s[i] - 'a' + 1) * (pow%mod)) % mod) % mod;
		pow = (pow * p) % mod;

	}
	return hv;
}
int main(){
	string s;
	cin>>s;
	ll ans=hasgen(s);
	cout<<ans;
}