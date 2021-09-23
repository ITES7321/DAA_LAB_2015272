#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
int main(){
	ifstream in;
	in.open("input.txt");
	ofstream out;
	out.open("output.txt");
	int n,k,t;
	int comparisons=0;
	int arr[100];
	in >> t;
	while(t){
		in >> n;
		for(int i=0;i<n;i++){
			in >> arr[i];
		}
		in >> k;
		int last = sqrt(n);
		int first = 0;
		int c=0;
		while(arr[last]<=k&&last<n){
			first=last;
			last+=sqrt(n);
		}
		for(int i=first;i<last;i++){
			comparisons++;
			if(arr[i]==k){
				out << "Present " << comparisons << endl;
				c=1;
				break;
			}
		}
		if(c==0){
				out << "Not Present " << comparisons << endl;
			}
		t--;
	}
}
