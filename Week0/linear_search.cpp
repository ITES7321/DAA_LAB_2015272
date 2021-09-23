#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
	ifstream File;
	int c=0;
	string nameFile;
	File.open("input.txt");
	ofstream myFile;
	myFile.open("output.txt");
	if (!File){
    cout << "Unable to open file input.txt";
    exit(1);
    }
    int n,k;
    int a[100];
    while(!File.eof()){
    	File >> n;
    	for(int i=0;i<n;i++){
    		File >> a[i];
		}
		File >> k;
	}
	
	for(int i=0;i<n;i++){

		if(a[i]==k){
			c=1;
		}
	}
	if(c==1){
		myFile << "Key Element Found" << endl;
	}
	else{
		myFile << "Key Element Not Found" << endl;
	}
    
}
