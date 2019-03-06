#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "split.cpp"
#include "IP.cpp"
#include "Iter.cpp"

using namespace std;

int main() {
	ifstream Mfile("C.txt");
	stringstream bufferM;
    if (!Mfile.is_open()) 
    { 
        cout << "Failed to open file" << endl;
        return 0;
    } 
    bufferM << Mfile.rdbuf();
    string s = bufferM.str();
    
    ifstream Keyfile("key.txt");
	stringstream bufferK;
    if (!Keyfile.is_open()) 
    { 
        cout << "Failed to open file" << endl; 
        return 0;
    } 
    bufferK << Keyfile.rdbuf();
    string k = bufferK.str();
    
	Split split;
    Iter test;
    IP test2;
    
    vector<string> v;
    for (int i = 0; i < s.size(); i += 64) {
    	string result = s.substr(i, 64);
    	string s2 = test2.IPTran(result);
    	string m = test2.IPTran2(test.iteration2(s2, k));
    	string w = test2.B2S(m);
    	v.push_back(w);
	}
	
	string M = split.merge(v);
	
	ofstream fout("M.txt");
    fout << M;
    Mfile.close();
    Keyfile.close(); 
    fout.close();
    return 0;
}
