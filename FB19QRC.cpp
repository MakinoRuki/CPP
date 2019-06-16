#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
int t, n;
char solve(char a, char c, char b) {
	if (c == '|') {
		if (a == '1' || b == '1') return '1';
		if (a == '0') return b;
		if (b == '0') return a;
		if (a == 'x' && b == 'x') return 'x';
		if (a == 'X' && b == 'X') return 'X';
		return '1';
	} else if (c == '&') {
		if (a == '0' || b == '0') return '0';
		if (a == '1') return b;
		if (b == '1') return a;
		if (a == 'x' && b == 'x') return 'x';
		if (a == 'X' && b == 'X') return 'X';
		return '0';
	} else if (c == '^') {
		if (a == '0') return b;
		if (b == '0') return a;
		if (a == 'x' && b == 'x') return '0';
		if (a == 'X' && b == 'X') return '0';
		if (a == 'X' && b == 'x') return '1';
		if (a == 'x' && b == 'X') return '1';
		if (a != '1') swap(a, b);
		if (b == '1') return '0';
		if (b == '0') return '1';
		if (b == 'x') return 'X';
		if (b == 'X') return 'x';
	}
	return '0';
}
int main() {
	freopen("mr_x.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>t;
	for (int cas = 1; cas <= t; ++cas) {
		string s;
		cin>>s;
		n = s.size();
		if (n == 1) {
			if (s[0] == '1' || s[0] == '0') {
				cout<<"Case #"<<cas<<": "<<0<<endl;
			} else {
				cout<<"Case #"<<cas<<": "<<1<<endl;
			}
		} else {
			vector<char> stk;
			stk.clear();
			for (int i = 0; i < n; ++i) {
				if (s[i] != ')')  stk.push_back(s[i]);
				else {
					char a, b, c;
					a = stk.back();
					stk.pop_back();
					c = stk.back();
					stk.pop_back();
					b = stk.back();
					stk.pop_back();
					stk.pop_back();
					char d = solve(a, c, b);
					stk.push_back(d);
				}
			}
			if (stk.back() == '1' || stk.back() == '0') {
				cout<<"Case #"<<cas<<": "<<0<<endl;
			} else {
				cout<<"Case #"<<cas<<": "<<1<<endl;
			}
		}
	}
	return 0;
}
