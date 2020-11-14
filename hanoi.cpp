#include <iostream>
using namespace std;


void hanoi(int N, char S, char I, char D){
    static int counter = 0; // static is a variable that is shared across a FUNCTION
    // anchor-value or base-case
    if (N == 1) {
        cout << ++counter << " Move disc " << N << " from " << S << " ---> " << D << endl;
    }
    // recurrent relationship
    else {
        hanoi(N-1, S, D, I); // move n-1 from S --> I
        cout << ++counter << " Move disc " << N << " from " << S << " ---> " << D << endl; // n S --> D
        hanoi(N-1, I, S, D);
    }
    // Total moves are (2^N - 1)
}

int main(){
    int N;
    char S = 'S', I ='I', D = 'D';
    
    cout << "How many discs?" << endl;
    cin >> N;
    
    hanoi(N, S, I, D);

    return 1;
}
