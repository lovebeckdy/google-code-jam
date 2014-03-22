#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

pair<int,int> twosum(vector<int> &prices, int credit){
	map<int,int> m;
	for(int i=0;i<prices.size();i++)
		m[prices[i]]=i;
	for(int i=0;i<prices.size();i++){
		int rem=credit-prices[i];
		if(m.find(rem)!=m.end() && m[rem]!=i){
			pair<int,int> ans;
			ans=make_pair(i+1,m[rem]+1);
			return ans;
		}
	}
}

int main(int argc, char *argv[])
{
	if (argc!=3){
		cout<<"usage: "<< argv[0] <<" <input_filename> <output_filename>\n";
		return 0;
	}
	

	ifstream readfile(argv[1]);
	string line;
	// n cases
	getline(readfile,line);
	istringstream first(line);
	int n;
	first>>n;

	vector<pair<int,int> > res;

	while(n>0){
		// credit
		getline(readfile,line);
		istringstream second(line);
		int c;
		second>>c;

		// # of items
		getline(readfile,line);
		int k=atoi(line.c_str());

		// prices
		getline(readfile,line);
		istringstream is(line);
		vector<int> cur;
		while(k>0){
			int i;
			is>>i;
			cur.push_back(i);
			k--;
		}
		pair<int,int> idx=twosum(cur,c);
		res.push_back(idx);
		n--;
	}
	readfile.close();

	// output result
	ofstream outfile(argv[2]);
	for(int i=0;i<res.size();i++){
		outfile<<"Case #"<<i+1<<": "<<res[i].first<<' '<<res[i].second<<endl;
	}
	outfile.close();
}
