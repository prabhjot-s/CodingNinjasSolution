#include <iostream>
#include <string>
#include "solution.h"
using namespace std;

int keypad(int num, string output[]){
    if(num==0||num==1){
        output[0]="";
        return 1;
    }
    string input[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string S = input[num%10];
    string other[100000];
    int small = keypad(num/10,other);
    int k = 0;
    for(int i =0;i<small;i++) {
        for(int j=0;j<S.size();j++){
             output[k]=other[i]+ S[j];
            k++;
        }
    }
    return k;
}
int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
