#include<iostream>
#include<fstream>
using namespace std;
int main(){
	ifstream in;
	ofstream out;
	in.open("input.txt");
	out.open("output.txt");
	int n,t;
	long int k;
	int arr[100];
	int mid;
	in >> t;

	int c;
	while(t){
		in >> n;
 
		c=0;
		int idx=0;
		for(int i=0;i<n;i++){
			in >> arr[i];
		}
		in >> k;
		 
		int start = 0;
		int end = n-1;
		while(start<=end){
		mid = start + ((end-start)/2);
		if(arr[mid]==k){
			c=1;
		}
		if(arr[mid]>k){
			end=mid-1;
		}
		else{
			start=mid+1;
		}
		idx++;
	}
	if(c==1){
		out << "Present "<< idx <<endl;
	}
	else{
		out << "Not Present " <<idx <<endl;
	}
	t--;
	}
}
