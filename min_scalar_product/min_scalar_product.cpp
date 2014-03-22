#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(int argc, char * argv[]){
	if(argc!=3){
		cout<<"Usage: "<< argv[0] << " <input_filename> <output_filename>\n";
		return -1;
	}
	ifstream infile(argv[1]);
	ofstream outfile(argv[2]);
	string line;
	getline(infile,line);
	int n=atoi(line.c_str());
	int i=1;
	while(i<=n){
		getline(infile,line);
		int k=atoi(line.c_str());
		
		long long A[k], B[k];
		getline(infile,line);
		long long temp;
		int j=0;
		istringstream i1(line);
		while(i1>>temp)
			A[j++]=temp;
		sort(A,A+k);
		j=0;
		getline(infile,line);
                istringstream i2(line);
                while(i2>>temp)
                        B[j++]=temp;
		sort(B,B+k,greater<int>());
		long long sum=0;
		for(int j=0;j<k;j++)
			sum+=A[j]*B[j];
		outfile<<"Case #"<<i<<": "<<sum<<endl;
		i++;
	}
	infile.close();
	outfile.close();
}
