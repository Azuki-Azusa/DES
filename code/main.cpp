#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "split.cpp"
#include "IP.cpp"
#include "Iter.cpp"

void testSplit() {
	ifstream infile("M.txt");
	stringstream buffer;
    if (!infile.is_open()) 
    { 
        cout << "Failed to open file" << endl; 
    } 
    buffer << infile.rdbuf();
    string s = buffer.str();
    vector<string> v;
    string str;
    
    Split test;
    v = test.split(s);
    cout << "拆分：" << endl;
    for (int i = 0; i < v.size(); i ++) {
    	cout << v[i] << endl;
	}
	cout << endl;
	
	cout << "合并：" << endl; 
	str = test.merge(v);
	cout << str;
	cout << endl;
	cout << endl;
	
	infile.close();
}

void testIP() {
	IP test2;
	
	string t = "香锅的S8";
	string B = test2.S2B(t);
	string s = test2.B2S(B);
	string ip = test2.IPTran(B);
	
	cout << "原文：" << t << endl; 
	cout << "原文转二进制：：" << B << endl;
	cout << "二进制转原文：" << s << endl;
	cout << "IP置换后：" << ip << endl;
	
	cout << endl;
}

void testFeistel() {
	string t = "香锅的S8";
	
	ifstream infile("key.txt");
	stringstream buffer;
    if (!infile.is_open()) 
    { 
        cout << "Failed to open file" << endl; 
    } 
    buffer << infile.rdbuf();
    string k = buffer.str();
    
    Iter test;
    IP test2;
    string s = test2.IPTran(test2.S2B(t));
    string result = test2.IPTran2(test.iteration(s, k));
    string s2 = test2.IPTran(result);
    string M = test2.IPTran2(test.iteration2(s2, k));
    
    cout << "明文加密前：" << test2.S2B(t) << endl;
    cout << "加密为密文：" << result << endl;
    cout << "解密为明文：" << M << endl; 
    
    cout << endl;
    
}

void test() {
	ifstream infile("M.txt");
	stringstream buffer;
    if (!infile.is_open()) 
    { 
        cout << "Failed to open file" << endl; 
    } 
    buffer << infile.rdbuf();
    string s = buffer.str();
    
    ifstream infile2("key.txt");
	stringstream buffer2;
    if (!infile2.is_open()) 
    { 
        cout << "Failed to open file" << endl; 
    } 
    buffer2 << infile2.rdbuf();
    string k = buffer2.str();
    
    Split test;
    vector<string> v;
    v = test.split(s);
    
    IP test2;
    string str;
    Iter test3;
    string C;
    for (int i = 0; i < v.size(); i ++) {
    	string B = test2.S2B(v[i]);
		string ip = test2.IPTran(B);
		string result = test2.IPTran2(test3.iteration(ip, k));
		C.append(result);
	}
	cout << "原文：" << s << endl;
	cout << "密文：" << C << endl;
	vector<string> M;
	for (int i = 0; i < C.size(); i += 64) {
		string result = C.substr(i, 64);
		string s2 = test2.IPTran(result);
    	string m = test2.IPTran2(test3.iteration2(s2, k));
    	string w = test2.B2S(m);
    	M.push_back(w);
	}
    
    str = test.merge(M);
	cout << "解密：" << str << endl;
	cout << endl;
	cout << endl;
	
	infile.close();
}


int main() {
	testSplit();
    testIP();
    testFeistel();
    
    test();
    
    getchar();
    return 0;
}
