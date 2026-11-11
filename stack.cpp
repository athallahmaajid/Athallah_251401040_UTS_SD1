#include <iostream>
#include <string>
using namespace std;

#define MAX 100
char stack[MAX];
int top = -1;

void push (char value) {
    if (top == MAX - 1){
        cout << "Stack Penuh !\n";
    } else {
        top++;
        stack[top] = value;
    }
}

string display () {
    string k = "";
    if (top == -1 ){
        cout << "Stack kosong\n";
    } else {
        cout << "\nKata dibalik:";
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << "";
            k = k + stack[i];
        }
        cout << endl;
    }
    return k;
}

int main () {
    cout << "Masukkan kata: ";
    string a;
    cin >> a;
    for (int i=0; i < a.length(); i++) {
        push(a[i]);
    }
    cout << "Pengecekan" << endl;
    string k = display();
    bool check = true;
    for (int i=0; i<a.length();i++) {
        if (a[i] != k[i]){
            check = false;
        }
    }
    if (check == false) {
        cout << "Kesimpulan: BUKAN PALINDROM" << endl;
    } else {
        cout << "Kesimpulan: PALINDROM" << endl;
    }

    return 0;
}
