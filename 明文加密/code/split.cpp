#ifndef SPLITCPP
#define SPLITCPP

#include <string>
#include <vector>

using namespace std;

class Split {
	public:
	vector<string> split(string a) {
		vector<string> v;
		for(int i = 0; i <= a.size(); i += 8) {
			string temp;
			if (a.size() - i < 8) {
				int add = 8 - a.size() + i;
				temp.append(a.substr(i, i + 8 - add));
				for (int j = 8 - add; j < 8; j ++) {
					char n = add + 48;
					temp = temp + n;
				}
			}
			else {
				temp.append(a.substr(i, 8));
			}
			v.push_back(temp);
		}
		return v;
	} 
	string merge(vector<string> a) {
		string temp;
		if (a.size() < 1) return temp;
		for (int i = 0; i < a.size() - 1; i ++) {
			temp.append(a[i]);
		}
		string s = a[a.size() - 1];
		temp.append(s.substr(0, 8 - int(s[7] - 48)));
		return temp;
	}
};

#endif
