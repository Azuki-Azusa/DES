#ifndef IPCPP
#define IPCPP

#include <string>

using namespace std;

class IP{
	public:
		string S2B(string a) {
			string bi;
			for (int i = 0; i < 8; i ++) {
				bi.append(W2B(a, i));
			}
			return bi;
		}
		
		string W2B(string s, int idx) {
			string byte(8, '0');
			char c = s[idx];
			unsigned char k = 0x80;
			for (int i = 0; i < 8; i ++, k >>= 1){
				if (c & k) {
					byte[i] = '1';
				}
				else {
					byte[i] = '0';
				}
			}
			return byte;
		}
		
		string B2S(string a) {
			string s;
			for (int i = 0; i < 8; i ++) {
				string temp = a.substr(i * 8, 8);
				s.append(B2W(temp));
			}
			return s;
		}
		
		string B2W(string a) {
			char k = 0x00;
			for (int i = 0; i < 8; i ++) {
				k <<= 1;
				if (a[i] == '1') {
					k = k | 1;
				}
				else {
					k = k | 0;
				}
			}
			string word(1, k);
			return word;
		}
		
		string IPTran(string a) {
			string temp(64,'0');
			for (int i = 0; i < 64; i ++) {
				temp[i] = a[ip[i]-1];
			}
			return temp;
		}
		
		string IPTran2(string a) {
			string temp(64,'0');
			for (int i = 0; i < 64; i ++) {
				temp[i] = a[ip2[i]-1];
			}
			return temp;
		}
		
		IP() {
			int IP[64] = {
				58 , 50 , 42 , 34 , 26 , 18 , 10 ,  2 ,
		    	60 , 52 , 44 , 36 , 28 , 20 , 12 ,  4 ,
			    62 , 54 , 46 , 38 , 30 , 22 , 14 ,  6 ,
			    64 , 56 , 48 , 40 , 32 , 24 , 16 ,  8 ,
			    57 , 49 , 41 , 33 , 25 , 17 ,  9 ,  1 ,
			    59 , 51 , 43 , 35 , 27 , 19 , 11 ,  3 ,
			    61 , 53 , 45 , 37 , 29 , 21 , 13 ,  5 ,
			    63 , 55 , 47 , 39 , 31 , 23 , 15 ,  7
			};
			
			int IP2[64] = {
			    40 ,  8 , 48 , 16 , 56 , 24 , 64 , 32 ,
			    39 ,  7 , 47 , 15 , 55 , 23 , 63 , 31 ,
			    38 ,  6 , 46 , 14 , 54 , 22 , 62 , 30 ,
			    37 ,  5 , 45 , 13 , 53 , 21 , 61 , 29 ,
			    36 ,  4 , 44 , 12 , 52 , 20 , 60 , 28 ,
			    35 ,  3 , 43 , 11 , 51 , 19 , 59 , 27 ,
			    34 ,  2 , 42 , 10 , 50 , 18 , 58 , 26 ,
			    33 ,  1 , 41 ,  9 , 49 , 17 , 57 , 25
			};
			
			for (int i = 0; i < 64; i ++) {
				ip[i] = IP[i];
				ip2[i] = IP2[i];
			}
		}
		
		int ip[64];
		int ip2[64];
};

#endif
