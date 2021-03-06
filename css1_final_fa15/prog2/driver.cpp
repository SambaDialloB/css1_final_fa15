// Program comments here 
// 
// 
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const int R = 30;
const int C = 50;
 
void fillArray(ifstream& A_in, string S[][C]);
void check(ofstream& aout, string map[][C]);

int main()
{
	ifstream fin;
	fin.open("northpole.txt");
	ofstream fout;
	fout.open("status.txt");
	fout << "Samba Diallo" << endl;
	string map[R][C];
	fillArray(fin, map);
	check(fout, map);
	fin.close();
	fout.close();
	return 0;
}

// ********************************
void fillArray(ifstream& A_in, string S[][C])
{
	string str;
	for(int i = 0; i < R; i++)
	{
		for(int j = 0; j < C; j++)
		{
			A_in >> str;	
			S[i][j] = str;
			//cout << str;
		}
		//cout << endl;
	}
}//end fillArray

void check(ofstream& aout, string map[][C])
{	
	int tot = 0;
	for(int i = 1; i < R-1; i++)
	{
		for(int j = 1; j < C; j++)
		{
			if(map[i][j] == "@")
			{	tot = 0;
				if(map[i][j+1] == "!")
					tot = tot+1; 
				if(map[i][j-1] == "!")
					tot = tot+1;
				if(map[i+1][j] == "!")
					tot = tot+1;
				if(map[i-1][j] == "!")
					tot = tot+1;
				if(tot == 3)
					aout << "elf[" << i << "][" << j << "]: Run!" << endl;
				if(tot == 4)
					aout << "elf[" << i << "][" << j << "]: Munch!" << endl;
			}
		}
		//cout << endl;
	}
	return;


}


 
