/** 
 * Filename: project3_Barras_jab0217.cpp
 *
 * Name: James Barras (jab0217)
 *
 * Compiler: compiled using AU server's compiler (g++ function)(c++11 maybe?)
 *
 * External Resources:
 *
 *  I used this website to understand vectors in c++ and their various functions: https://www.geeksforgeeks.org/vector-in-cpp-stl/#:~:text=size()%20%E2%80%93%20Returns%20the%20number,it%20contains%20'n'%20elements.
 *
 */

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;



//////
bool check_file(string file) {
ifstream stream;

stream.open(file.c_str());
if (stream.fail()) {
return false;
}

stream.close();

return true;
}


/////
vector<int> read_file(string file) {
ifstream instream;
vector<int> v;
vector<int> returnV;
int i;
string line;

instream.open(file.c_str());
while (instream.good()) {

getline(instream, line);
stringstream(line) >> i;
v.push_back(i);

}

for (int n = 0; n < v.size() - 1; n++) {
returnV.push_back(v[n]);
}


//
//cout << "\n\n";
//for (int j = 0; j < returnV.size(); j++) {
//cout << "\n" << returnV[j];
//}
//cout <<  "\n\n";


instream.close();

return returnV;
}


/////
void write_file(string file, vector<int> v) {
ofstream outFile;
outFile.open(file.c_str());

for (int i = 0; i < v.size(); i++) {
//outFile << i << "\n";
outFile << v[i] << "\n";
}

outFile.close();

}


/////
vector<int> merge(vector<int> v1, vector<int> v2) {
vector<int> combinedV;

int i = 0;
int j = 0;
while ((i < v1.size()) && (j < v2.size())) {

 if (v1[i] > v2[j]) {
 combinedV.push_back(v2[j]);
 j++;
 } else {
 combinedV.push_back(v1[i]);
 i++;
 }

}

 if (i < v1.size()) {
  for (i; i < v1.size(); i++) {
  combinedV.push_back(v1[i]);
  }
 
 }
 if (j < v2.size()) {
  for (j; j < v2.size(); j++) { 
  combinedV.push_back(v2[j]);
  }
 }

return combinedV;
}


/////
void to_string(string file, vector<int> v) {
int length = v.size();

cout << "The list of " << length << " numbers in the file " 
     << file << " is:" << endl;
//
//cout << v[1];
//cout << v[2];
//cout << v[3];
//

for (int i = 0; i < v.size(); i++) {
//cout << "\n" << i << "\n";
//unsigned short j = v[i];
cout << v[i] << "\n";
}

}



/////////
/////////
int main() {
string filename;
vector<int> v1;
vector<int> v2;
vector<int> combinedV;

cout << "*** Welcome to James's sorting program ***\n";

do {
cout << "Enter the first input file name: "; 
cin >> filename;
} while (cin.fail() || !check_file(filename));
v1 = read_file(filename);
to_string(filename, v1);


do {
cout << "\nEnter the second input file name: ";
cin >> filename;
} while (cin.fail() || !check_file(filename));
v2 = read_file(filename);
to_string(filename, v2);




combinedV = merge(v1, v2);
int combSize = combinedV.size();
cout << "\nThe sorted list of " << combSize << " numbers is: ";
for (int k = 0; k < combSize; k++) {
cout << " " << combinedV[k];
}

do {
cout << "\nEnter the output file name: ";
cin >> filename;
} while (cin.fail());
write_file(filename, combinedV);

cout << "*** Please check the new file - " << filename << " ***"
     << "\n*** Goodbye. ***\n\n";

return 1;
}
