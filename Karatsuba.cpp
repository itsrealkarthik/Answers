#include<iostream>
#include<stdio.h>
#include<string>
#include<ctime>
using namespace std;
int makeEqualLength(string &a, string &b)
{
	if(a.length() > b.length()){
        while(a.length()!=b.length()){
            b='0'+b;
        }
        return a.length();
    }
    else{
        while(b.length()!=a.length()){
            a='0'+a;
        }
        return b.length();
    }
}
string addstr(string a, string b){
    int n= makeEqualLength(a,b);
    int carry=0;
    string result;
    for(int i=n-1;i>=0;i--){
        int first=a[i]-'0';
        int second=b[i]-'0';
        int sum= (first^second^carry)+'0';
        result=(char)sum+result;
        carry=(first&second)|(second&carry)|(first&carry);
    }
    if(carry){
        result='1'+result;
    }
    
    return result;
}
long int multiply(string a, string b){   
    int n = makeEqualLength(a,b);
    if(n==0){
        return 0;
    }
    if(n==1){
        return ((a[0]-'0')*(b[0]-'0'));
    }
    int mid=n/2;
    int sh = (n-mid);
    string aLower= a.substr(0,mid);
    string aUpper= a.substr(mid,sh);
    
    string bLower= b.substr(0,mid);
    string bUpper= b.substr(mid,sh);

    long int P1= multiply(aLower,bLower);
    long int P2=multiply(aUpper,bUpper);
    long int P3=multiply(aUpper,bLower);
    long int P4=multiply(aLower,bUpper);
    string P5= addstr(to_string(P3),to_string(P4));
    long int P6=multiply(P5,"1");
    return P6*(2^sh)+P1/(2^sh)+P2;
}
int main(){
    string a,b;
    cin>>a;
    cin>>b;
    clock_t start=clock();
    long int muk=multiply(a,b);
    double time=(double)(clock() - start)/CLOCKS_PER_SEC;
    cout<<muk;
    
}