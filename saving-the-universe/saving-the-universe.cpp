#include<iostream>
#include<fstream>
#include<sstream>
#include<set>
#include<string>
using namespace std;

int main(int argc, char *argv[]){
	if(argc!=3) return 0;
	ifstream infile(argv[1]);
	ofstream outfile(argv[2]);
	string line;
	getline(infile,line);
	istringstream is(line);
	int N, n=1;
	is>>N;

	while(n<=N){
		getline(infile,line);
		int S,s=0;
		istringstream is1(line);
		is1>>S;
		while(s<S){ getline(infile,line); s++;}
		getline(infile,line);
		int Q;
		istringstream is2(line);
		is2>>Q;
		set<string> st;
		long long count=0;
		while(Q>0){
			getline(infile,line);
			if(st.find(line)==st.end()){
				if(st.size()==S-1){
					st.clear();
					count++;
				}
				st.insert(line);
			}
			Q--;
		}
		outfile<<"Case #"<<n<<": "<<count<<endl;
		n++;
	}
	infile.close();
	outfile.close();
}
