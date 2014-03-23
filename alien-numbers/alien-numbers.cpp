#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<map>
#include<algorithm>
using namespace std;

int main(int argc, char *argv[]){
	if(argc!=3){
		cout<<"Usage: "<<argv[0]<<" <input_filename> <output_filename>"<<endl;
		return 0;
	}
	ifstream infile(argv[1]);
	ofstream outfile(argv[2]);
	string line;
	int N, n=1;
	getline(infile,line);
	istringstream is(line);
	is>>N;
	while(n<=N){
		string alien, src, target;
		getline(infile,line);
		stringstream is1(line);
		is1>>alien>>src>>target;
        map<char, int> m;
        for(int i=0;i<src.size();i++){
            m[src[i]]=i;
        }
        long long dec=0;
        for(int i=0;i<alien.size();i++){
            dec*=src.size();
            dec+=m[alien[i]];
        }
        string ans;
        while(dec>0){
            ans.append(1,target[dec%target.size()]);
            dec/=target.size();
        }
        reverse(ans.begin(),ans.end());
        outfile<<"Case #"<<n<<": "<<ans<<endl;
		n++;
	}
	infile.close();
	outfile.close();
}
