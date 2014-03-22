#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void reverseword(string &s, int start, int end){
	while(start<=end){
		swap(s[start++],s[end--]);
	}
}

void reverseline(string &s){
	int i=0;
	while(s[i]!='\0'){
		while(s[i]==' ') i++;
		int start=i;
		while(s[i]!=' ' && s[i]!='\0') i++;
		int end=i-1;
		reverseword(s,start,end);
	}
	reverseword(s,0,s.size()-1);
}

int main(int argc, char* argv[]){
	if(argc!=3){
		cout<<"Usage: "<< argv[0] <<" <input_filename> <output_filename>\n";
		return 0;
	}
	ifstream infile(argv[1]);
	ofstream outfile(argv[2]);
	if(infile.is_open()){
		string line;
		getline(infile,line);
		int n=atoi(line.c_str());
		int i=1;
		while(i<=n){
			getline(infile,line);
			reverseline(line);
			outfile<<"Case #"<<i<<": "<<line<<endl;
			i++;
		}
	}
	infile.close();
	outfile.close();
}
