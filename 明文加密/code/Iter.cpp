#ifndef ITER
#define ITER

#include <iostream>
#include <vector>
#include "Feistel.cpp" 

using namespace std;

class Iter {
	public:
	string iteration(string s, string k) {
		string l = s.substr(0, 32);
		string r = s.substr(32, 32);
		Feisteal func;
		vector<string> childkey = func.getChildKey(k);
		for (int i = 0; i < 16; i ++) {
			string temp;
			temp = l;
			l = r;
			r = XOR(temp, func.feistel(r, childkey[i]));
		}
		string temp = r + l;
		return temp;
	}
	
	string iteration2(string s, string k) {
		string l = s.substr(0, 32);
		string r = s.substr(32, 32);
		Feisteal func;
		vector<string> childkey = func.getChildKey(k);
		for (int i = 0; i < 16; i ++) {
			string temp;
			temp = l;
			l = r;
			r = XOR(temp, func.feistel(r, childkey[15-i]));
		}
		string temp = r + l;
		return temp;
	}
	
	string XOR(string a, string b) {
		string temp(32, '0');
		for (int i = 0; i < 32; i ++) {
			if (a[i] == b[i]) temp[i] = '0';
			else temp[i] = '1';
		}
		return temp;
	}
};

#endif
