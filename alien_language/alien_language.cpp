#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;


int main(int argc, char *argv[])
{
	if(argc!=3){
		cout<<"Usage: "<<argv[0]<<" <input_filename> <output_filename>\n";
		return -1;
	}
	ifstream infile(argv[1]);
	ofstream outfile(argv[2]);
	string line;
	getline(infile,line);
	istringstream first(line);
	int L,D,N;
	first>>L;
	first>>D;
	first>>N;
	
	vector<string> dict;
	int d=1;
	while(d<=D){
		getline(infile,line);
		dict.push_back(line);
		d++;
	}

	bool posword[L][26];
	int k=1;
	while(k<=N){
		getline(infile,line);
		for(int i=0;i<L;i++)
			for(int j=0;j<26;j++)
				posword[i][j]=false;
		int pos=0;
		bool afterpar=false;
		for(int i=0;i<line.size();i++){
			if(line[i]=='(') afterpar=true;
			else if(line[i]==')'){
				afterpar=false;
				pos++;
			}
			else{
				posword[pos][line[i]-'a']=true;
				if(!afterpar) pos++;
			}
		}

		int count=0;
		int j=0;
		for(int d=0;d<D;d++){
			for(j=0;j<L;j++){
				if(!posword[j][dict[d][j]-'a'])
					break;
			}
			if(j==L) count++;
		}
		
		outfile<<"Case #"<<k<<": "<<count<<endl;
		k++;
	}

	infile.close();
	outfile.close();
}
