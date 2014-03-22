#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
using namespace std;

inline string ston(char c){
        switch(c){
                case 'a': return "2";
                case 'b': return "22";
                case 'c': return "222";
                case 'd': return "3";
                case 'e': return "33";
                case 'f': return "333";
                case 'g': return "4";
                case 'h': return "44";
                case 'i': return "444";
                case 'j': return "5";
                case 'k': return "55";
                case 'l': return "555";
                case 'm': return "6";
                case 'n': return "66";
                case 'o': return "666";
                case 'p': return "7";
                case 'q': return "77";
                case 'r': return "777";
                case 's': return "7777";
                case 't': return "8";
                case 'u': return "88";
                case 'v': return "888";
                case 'w': return "9";
                case 'x': return "99";
                case 'y': return "999";
                case 'z': return "9999";
		case ' ': return "0";
                default: return "";
        }
}

string convert(string s){
	string ss, prev;
	for(int i=0;i<s.size();i++){
		string cur=ston(s[i]);
		if(!prev.empty() && prev[0]==cur[0]) ss+=' ';
		ss+=cur;
		prev=cur;
	}
	return ss;
}


int main(int argc, char * argv[]){
	if(argc!=3){
		cout<<"Usage: "<< argv[0] << " <input_filename> <output_filename>\n";
		return 0;
	}
	
	ifstream infile(argv[1]);
	ofstream outfile(argv[2]);
	string line;
	getline(infile,line);
	int n=atoi(line.c_str());
	int i=1;
	while(i<=n){
		getline(infile,line);
		string newline;
		newline=convert(line);
		outfile<<"Case #"<<i<<": "<<newline<<endl;
		i++;
	}

	infile.close();
	outfile.close();
}
