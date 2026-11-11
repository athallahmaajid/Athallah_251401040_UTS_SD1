#include <iostream>
#include <string>
using namespace std;

// Deklarasi sebuah struktur node
struct Node {
    string name;
    int value;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

// TODO : Insert di Depan
void insertFirst(int n, string name) {
    Node *newNode = new Node;
    newNode -> name = name;
    newNode -> value = n;
    newNode -> next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = head;
    }
    else {
        newNode -> next = head;
        head = newNode;
    }
}

// TODO : Insert di belakang
void insertLast(int n, string name) {
    Node *newNode = new Node;
    newNode -> name = name;
    newNode -> value = n;
    newNode -> next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = head;
    }
    else {
        tail -> next = newNode;
        tail = newNode;
    }
}

void printList() {
    Node *temp = head;
    cout << "Daftar Peserta Lolos (skor >=75)\n";
    while(temp != NULL) {
        if (temp -> value >= 75) {
            cout << "- " << temp -> name << " (Skor: " << temp -> value << ")\n";
        }
        temp = temp -> next;
    }
}

void deleteFirst() {
    if (head == NULL) {
        cout << "gbs" << endl;
        return;
    }
    Node *temp = head;
    head = head -> next;
    if (head == NULL) tail = NULL;
    delete temp;
}

void menu() {
    cout << "\n========== MENU LINKED LIST ==========\n";
    cout << "1. Insert First\n";
    cout << "2. Insert Last\n";
    cout << "3. Delete Head\n";
    cout << "4. Print List\n";
    cout << "0. Keluar\n";
    cout << "======================================\n";
    cout << "Pilih menu: ";
}

int main () {
int pilihan;
    int nilai;
    string name;
    int check;

    do {
        menu();
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilai;

                cout << "Masukkan nama": ;
                cin >> name;

                insertFirst(nilai, name);
                cout << "Node berhasil ditambahkan di depan.\n";
                break;

            case 2:
                cout << "Masukkan nilai: ";
                cin >> nilai;

                cout << "Masukkan nama: ";
                cin >> name;

                insertLast(nilai, name);
                cout << "Node berhasil ditambahkan di belakang.\n";
                break;

            case 3:
                deleteFirst();
                cout << "Node pertama berhasil dihapus.\n";
                break;
            case 4:
                printList();
                break;

            case 0:
                cout << "Program selesai.\n";
                break;

            default:
                cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 0);

    return 0;
}