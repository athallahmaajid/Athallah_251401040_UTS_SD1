#include <iostream>
using namespace std;


int kanan;
int kiri;

struct Node {
    int data;
    Node* kiri;
    Node* kanan;
};

Node* buatNode(int data) {
    Node* baru = new Node;

    baru->data = data;
    baru->kiri = NULL;
    baru->kanan = NULL;

    return baru;
}

Node* insert(Node* akar, int data) {

    if(akar == NULL){
        return buatNode(data);
    }

    if(data < akar->data){
        kiri = data;
        akar->kiri = insert(akar->kiri, data);
    }

    else if(data > akar->data){
        akar->kanan = insert(akar->kanan, data);
    }
    return akar;
}


void inOrder(Node* akar) {
    if(akar != NULL){
        inOrder(akar->kiri);
        cout << akar->data << " ";
        if (akar->kanan == NULL) {
            kanan = akar->data;
        }
        inOrder(akar->kanan);
    }
}

int main() {

    Node* akar = NULL;
    int angka;

    cout << "Masukkan angka (0 untuk berhenti):\n";

    while (true) {

        cout << "Input: ";
        cin >> angka;

        if(angka == 0){
            break;
        }
    
        akar = insert(akar, angka);
    }

    cout << "\nData (In-order) : ";
    inOrder(akar);
    cout << endl;

    cout << "Nilai terkecil: " << kiri << endl;
    cout << "Nilai terbesar: " << kanan << endl;
 
    return 0;
}