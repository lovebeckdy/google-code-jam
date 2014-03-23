#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<sstream>
#include<algorithm>

using namespace std;

int main(int argc, char *argv[]){
	if(argc!=3){
		cout<<"Usage: "<<argv[0]<<" <input_filename> <output_filename>"<<endl;
		return -1;
	}
	ifstream infile(argv[1]);
	ofstream outfile(argv[2]);
	string line;
	map<char,int> m;
	getline(infile,line);
    istringstream is(line);
    int T, t=1;
    is>>T;
    while(t<=T){
        getline(infile,line);
        m.clear();
        m[line[0]]=1;
        for(int i=1;i<line.size();i++){
            int size=m.size();
            if(m.find(line[i])==m.end()){
                if(size==1) m[line[i]]=0;
                else m[line[i]]=size;
            }
        }
        int base = max((int)m.size(),2);
        long long result=0;
        for(int i=0;i<line.size();i++){
            result*=base;
            result+=m[line[i]];
        }
        outfile<<"Case #"<<t<<": "<<result<<endl;
        t++;
    }

	infile.close();
	outfile.close();
}
