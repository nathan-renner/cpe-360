#include <iostream>
using namespace std;

int fact(int N){
    if (N < 0)
        cout << "Can't do it" << endl;
    else {
        int result;
        for (int i = N; i > 0; i--)
            result *= i; 
        cout << "factorial: " << result << endl;
    }
}

int factorial(int N) {
    //anchor-value or base-case
    if (N == 0)
        return 1;
    //recursive step
    else
        return factorial (N - 1) * N;
}

int main() {
    int N;
    
    cout << "Give me a number, I'll compute the factorial" << endl;
    cin >> N;
    
    fact(N);
    cout << "Using recursion: " << factorial(N) << endl;
}
