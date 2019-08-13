#include<iostream>
#include<vector>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
string valid="023456789abcdefghijkmnopqrstuvwxyz";
bool pd(string str1,string str2){
	for(int i=0;i<str1.length();i++){
		if(str1[i]!=str2[i]){
			return false;
		}
	}
	return true;
}
string create(int len){
	
	string str="1000";
	for(int i=0;i<len;i++){
		str[i]=valid[rand()%34];
	}
	return str;
}
int main(){
	srand((unsigned)time(NULL));
	vector<string> p;
	int count=0;
	string str=create(4);
	for(int i=1;i<10000;i++){
		string str=create(4);
		//cout<<str<<" ";
		int flag=0;
		for(int j=0;j<p.size();j++){
			if(pd(str,p[j])){
				flag=1;
				count++;
				break;
			}
		}
		if(flag==0){
			p.push_back(str);
		}
	}
	cout<<count;
	
} 
