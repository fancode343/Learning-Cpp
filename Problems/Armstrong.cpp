
#include <iostream>
#include <string> 
#include <cmath>
using namespace std;

int mathPower(int number, int power);

int main(){
    cout << "Enter Number: ";
    int number;
    cin >> number;
    string stringnum = to_string(number);
    int ans = 0;
    for(int i = 0; i<stringnum.length(); i++){
        int Numlength = stringnum.length();
        int num = stringnum[i];
        int squared = mathPower(num, Numlength);
        ans += squared;
    }
    cout << ans << " " << stringnum.length();
    return 0;
}

int mathPower (int number, int power){
    int result = 1;
    for(int i = 0; i<power; i++){
        result *= number;
    }
    return result;
}
