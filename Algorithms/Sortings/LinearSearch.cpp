#include<iostream>

using namespace std;
bool linearSearch(int n,int arr[],int k){
	for(int i=0;i<n;i++){
		if(k==arr[i]){
			return true;
		}
	}
	return false;
}
int main(){
	int n,k;
	cout<<"Enter the size of Array: ";
	cin>>n;
	if(n<=0){ cout<<"invalid size"; return -1;}
	int arr[n];
	cout<<"Enter the Array elements: ";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<"Enter the key to search: ";
	cin>>k;
	if(linearSearch(n,arr,k)) cout<< "Key Present in the array";
	else	cout<<"Key is not present in the Array";
	return 0;
}
