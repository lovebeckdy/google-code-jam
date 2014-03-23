#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void rotate(vector<vector<char> > &board){
	int n=board.size();
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			char temp=board[i][j];
			board[i][j]=board[j][i];
			board[j][i]=temp;
		}
		reverse(board[i].begin(),board[i].end());
	}

}

void gravity(vector<vector<char> > &board){
    int n=board.size();
    for(int j=0;j<n;j++){
        //for each column
        vector<char> temp;
        for(int i=0;i<n;i++){
            if(board[i][j]!='.'){
                temp.push_back(board[i][j]);
                board[i][j]='.';
            }
        }
        int i=n-1;
        while(!temp.empty()){
            board[i][j]=temp.back();
            temp.pop_back();
            i--;
        }
    }
}

bool check(vector<vector<char> > board, char symbol, int k){
    int n=board.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]==symbol){
                //checking 4 directions is sufficient
                int p=1;
                while(j+p<n && p<k && board[i][j+p]==symbol) p++;
                if(p==k) return true;
                p=1;
                while(i+p<n && p<k && board[i+p][j]==symbol) p++;
                if(p==k) return true;
                p=1;
                while(i+p<n && j+p<n && p<k && board[i+p][j+p]==symbol) p++;
                if(p==k) return true;
                p=1;
                while(i+p<n && j-p>=0 && p<k && board[i+p][j-p]==symbol) p++;
                if(p==k) return true;
            }
        }
    }
    return false;
}

int main(int argc, char *argv[]){
	if(argc!=3){
		cout<<"Usage: "<<argv[0]<<" <input_filename> <output_filename>"<<endl;
		return -1;
	}
	ifstream infile(argv[1]);
	ofstream outfile(argv[2]);
	string line;
	int T, t=1;
	getline(infile,line);
	istringstream is(line);
	is>>T;

	while(t<=T){
		int N, K;
		getline(infile,line);
		istringstream is1(line);
		is1>>N>>K;
		vector<vector<char> > board(N,vector<char>(N,'.'));
		//read board
		for(int i=0;i<N;i++){
			getline(infile,line);
			for(int j=0;j<N;j++){
				board[i][j]=line[j];
			}
		}
		//rotate board
		rotate(board);
		//gravity
		gravity(board);

		bool rwin=check(board,'R',K);
		bool bwin=check(board,'B',K);

		string result;
		if(rwin && bwin) result="Both";
		else if(rwin) result="Red";
		else if(bwin) result="Blue";
		else result="Neither";

        outfile<<"Case #"<<t<<": "<<result<<endl;
		t++;
	}

	infile.close();
	outfile.close();
}
