#include <iostream>
using namespace std;

//Iterative 
int factorial(int n){
    int fact=1;

    for(int i=1; i<=n; i++){
        fact *= i;
    }
    return fact;
}

//Recursive
int Factorial2(int n){
    if(n==0 || n==1){
        return 1;
    }
    else{
        return n*Factorial2(n-1);
    }
}

int main(){
    int n;
    cout<<"Enter a num:";
    cin>>n;

    cout<<"Factorial of "<<n<<"by iterative method is:"<<factorial(n)<<endl;
    cout<<"Factorial of "<<n<<"by recursive method is:"<<Factorial2(n)<<endl;

    return 0;
}