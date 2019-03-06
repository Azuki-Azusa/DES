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
	ifstream Mfile("M.txt");
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
    
    vector<string> v = split.split(s);
    string C;
    for (int i = 0; i < v.size(); i ++) {
    	string subM = test2.IPTran(test2.S2B(v[i]));
    	string subC = test2.IPTran2(test.iteration(subM, k));
    	C.append(subC);
	}
	ofstream fout("C.txt");
    fout << C;
    Mfile.close();
    Keyfile.close(); 
    fout.close();
    return 0;
}
