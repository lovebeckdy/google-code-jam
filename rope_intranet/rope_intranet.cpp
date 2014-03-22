#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;

struct rope{
    int x;
    int y;
};

bool comp(const rope &a, const rope &b){
    return a.x<b.x;
}

int main(int argc, char *argv[]){
    if(argc!=3){
        cout<<"Usage: "<<argv[0]<<" <input_filename> <output_filename>"<<endl;
    }
    ifstream infile(argv[1]);
    ofstream outfile(argv[2]);
    string line;
    getline(infile,line);
    istringstream is(line);
    int T;
    is>>T;
    int t=1;
    while(t<=T){
        getline(infile,line);
        istringstream is1(line);
        int N;
        is1>>N;
        vector<rope> ropes;
        while(N>0){
            getline(infile,line);
            istringstream is2(line);
            rope r;
            is2>>r.x;
            is2>>r.y;
            ropes.push_back(r);
            N--;
        }

        long long count=0;
        for(int i=0;i<ropes.size();i++){
            for(int j=0;j<ropes.size();j++){
                if(i==j) break;
                if(ropes[i].x<ropes[j].x && ropes[i].y>ropes[j].y) count++;
                else if(ropes[i].x>ropes[j].x && ropes[i].y<ropes[j].y) count++;
            }
        }
        ropes.clear();
        outfile<<"Case #"<<t<<": "<<count<<endl;
        t++;
    }
    infile.close();
    outfile.close();
}

