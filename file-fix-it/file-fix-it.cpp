#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<set>
using namespace std;

set<string> parseline(string s){
    set<string> ans;
    if(s.empty()) return ans;
    for(int i=1;s[i]!='\0';i++)
        if(s[i]=='/') ans.insert(s.substr(0,i));
    ans.insert(s);
    return ans;
}

int main(int argc, char *argv[]){
	if(argc!=3){
		cout<<"Usage: "<<argv[0]<<" <input_filename> <output_filename>"<<endl;
		return -1;
	}
	ifstream infile(argv[1]);
	ofstream outfile(argv[2]);
	string line;
	getline(infile,line);
	int T,t=1;
	istringstream is(line);
	is>>T;

	while(t<=T){
		getline(infile,line);
		int N, M, n=0, m=0;
		istringstream is1(line);
		is1>>N>>M;
        set<string> existing;
        long long count=0;
		while(n<N){
            getline(infile,line);
            existing.insert(line);
            n++;
        }
        while(m<M){
            getline(infile,line);
            set<string> required=parseline(line);
            set<string>::iterator it=required.begin();
            count+=required.size();
            for(;it!=required.end();it++){
                if(existing.find(*it)!=existing.end())
                    count--;
                else
                    existing.insert(*it);
            }
            m++;
        }
        outfile<<"Case #"<<t<<": "<<count<<endl;
		t++;
	}
	infile.close();
	outfile.close();

}
