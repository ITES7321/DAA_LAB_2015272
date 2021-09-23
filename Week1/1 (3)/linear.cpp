#include<iostream>
#include<fstream>
using namespace std;
int main(){
	ifstream in;
	in.open("input.txt");
	ofstream out;
	out.open("output.txt");
	int t;
	int arr[100];
	in >> t;
	int n,k;
	int c=0,idx;
	while(t){
		c=0;
		idx=0;
		in >> n;
		for(int i=0;i<n;i++){
			in >> arr[i];
		}
		in >> k;
		for(int i=0;i<n;i++){
			if(arr[i]==k){
				c=1;
				idx=i+1;
			}
		}
		if(c==1){
			out << "Present "<<idx << endl;
		}
		else{
			out << "Not Present " << n << endl;
		}
		t--;
	}

		
}
