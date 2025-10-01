#include <iostream>
using namespace std;
 
int main() {

long x = 1;

    for (int i = 1; i <= 128; i += 1) {
    x += x;
}
    
    cout << "X = " << x << endl;
    
    
 
}