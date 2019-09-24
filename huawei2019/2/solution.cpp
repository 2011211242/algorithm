#include <iostream>
#include <string>
using namespace std;

char add(const char & ch1, const char & ch2, char & pending) {
	char tmp = pending;
	pending = (pending - '0' + ch1 - '0' + ch2 - '0') / 7  + '0';
	return (tmp - '0' + ch1 - '0' + ch2 - '0') % 7  + '0';
}

string add(const string & s1, const string & s2) {
	string ret;
	char pending = '0';
	
	for(int i = 0; i < s1.size() && i < s2.size(); i ++) {
		ret = add(s1[s1.size() - i - 1], s2[s2.size() - i - 1], pending) + ret;
	}

	if (s1.size() > s2.size()) {
		for(int i = s1.size() - s2.size() - 1; i >= 0; i--) {
			ret = add(s1[i], '0', pending) + ret;
		}
	}
	else if (s2.size() > s1.size()) {
		for(int i = s2.size() - s1.size() - 1; i >= 0; i--) {
			ret = add(s2[i], '0', pending) + ret;
		}
	}

	if (pending > '0') ret = pending + ret;
	return ret;
}

string mul(const string & s1, const char ch) {
	string ret; 
	char pending = '0';

	for(int i = s1.size() - 1; i >= 0; i--) {
		int ml = (s1[i] - '0') * (ch - '0') + (pending - '0');
		pending =  ml / 7 + '0';
		ret = char(ml % 7 + '0') + ret;
	}

	if (pending > '0') {
		ret = pending + ret;
	}

	return ret;
}

string mul(const string &s1, const string &s2) {
	string ret = "0";
	string tail(s1.size(), '0');

	for(int i = s1.size() - 1; i >= 0; i--) {
		string mul1 = mul(s2, s1[i]); 
		mul1 = mul1 + tail.substr(0, s1.size() - 1 - i);
		ret = add(mul1, ret);
	}
	return ret;
}

int main()
{
	cout << mul("123123123", "123123123") << endl;
}
