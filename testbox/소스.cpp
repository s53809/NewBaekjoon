#include<iostream>
using namespace std;
typedef long long int lld;

int n;
lld arr[101] = { 0,1,1,1,2,2 };
lld fibo(long long a) {
    if (arr[a] != -1) {
        return arr[a];
    }
    else {
        arr[a] = fibo(a - 1) + fibo(a - 5);
        return  arr[a];
    }
}
lld b;
int main() {
    for (int i = 6; i <= 100; i++) {
        arr[i] = -1;
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> b;
        cout << fibo(b) << "\n";
    }

}