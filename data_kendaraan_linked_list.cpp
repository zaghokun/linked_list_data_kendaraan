#include <iostream>

using namespace std;

typedef struct node{
    string plat_nomor;
    string jenis;
    string merk;
    string warna;
    node *next;
} dt;

void tambah_depan(dt *& head, string plat, string jenis, string merk, string warna){
    dt * newnode = new dt();
    newnode -> plat_nomor = plat;
    newnode -> jenis = jenis;
    newnode -> merk = merk;
    newnode -> warna = warna;
    newnode -> next = head;
    head = newnode;
}

void tambah_belakang(dt *& head, string plat, string jenis, string merk, string warna){
    dt * newnode = new dt();
    newnode -> plat_nomor = plat;
    newnode -> jenis = jenis;
    newnode -> merk = merk;
    newnode -> warna = warna;
    newnode -> next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        dt * temp = head;
        while (temp -> next != NULL) {
            temp = temp -> next;
        }
        temp -> next = newnode;
    }
}

void sisipkan_data(dt *& head, string plat, string jenis, string merk, string warna, int posisi){
    dt * newnode = new dt();
    newnode -> plat_nomor = plat;
    newnode -> jenis = jenis;
    newnode -> merk = merk;
    newnode -> warna = warna;

    if(posisi == 1){
        newnode -> next = head;
        head = newnode;
        return;
    }

    dt * temp = head;
    for(int i = 1; i < posisi - 1 && temp != NULL; i++){
        temp = temp -> next;
    }

    if (temp == NULL){
        cout << "Posisi tidak valid!" << endl;
        delete newnode;
        return;
    }

    newnode -> next = temp -> next;
    temp -> next = newnode;
}

void hapus_depan(dt *& head){
    if (head == NULL){
        cout << "List kosong, tidak ada yang dihapus \n";
        return;
    }

    dt * temp = head;
    head = head -> next;
    delete temp;
}

void hapus_belakang(dt *& head){
    if (head == NULL){
        cout << "List kosong, tidak ada yang dihapus \n";
        return;
    }
    if(head -> next == NULL){
        delete head;
        head == NULL;
        return;
    }
    dt * temp = head;
    while(temp->next->next != NULL){
        temp = temp ->next;
    }
    delete temp -> next;
    temp -> next = NULL;
}

void tampilkan_data(dt * head){
    dt * temp = head;
    
    while (temp != NULL){
        cout << "Plat Nomor : " << temp -> plat_nomor << endl;
        cout << "Jenis Kendaraan : " << temp -> jenis << endl;
        cout << "Merk Kendaraan : " << temp -> merk << endl;
        cout << "Warna Kendaraan : " << temp -> warna << endl;
        temp = temp -> next;
    }
}

int main(){

    dt *head = NULL;
    // Data yang dimasukkan
    string plat, jenis, merk, warna;
    bool con1 = true;
    int pilihan = 0;
    int posisi = 0;

    while(con1 == true)
    {
        // Pilihan Menu
        cout << "===========================  MENU DATA KENDARAAN ===========================\n";
        cout << "1. Tambah data kendaraan dari depan\n";
        cout << "2. Tambah data kendaraan dari belakang\n";
        cout << "3. Sisipkan data kendaraan baru\n";
        cout << "4. Hapus data depan \n";
        cout << "5. Hapus data belakang \n";
        cout << "6. Tampilkan data kendaraan\n";
        cout << "7. EXIT\n";
        cout << "===========================  MENU DATA KENDARAAN ===========================\n";
        cout << "Pilih menu: "; 
        cin >> pilihan; // Memasukkan menu yang dipilih
        cin.ignore();

        if(pilihan == 1){
            cout << "Masukkan plat nomor : ";
            getline(cin, plat);
            cout << "Masukkan jenis kendaraan : ";
            getline(cin, jenis);
            cout << "Masukkan merk dari kendaraan : ";
            getline(cin, merk);
            cout << "Masukkan warna kendaraan : ";
            getline(cin, warna);

            tambah_depan(head, plat, jenis, merk, warna);
        }else if(pilihan == 2){
            cout << "Masukkan plat nomor : ";
            getline(cin, plat);
            cout << "Masukkan jenis kendaraan : ";
            getline(cin, jenis);
            cout << "Masukkan merk dari kendaraan : ";
            getline(cin, merk);
            cout << "Masukkan warna kendaraan : ";
            getline(cin, warna);

            tambah_belakang(head, plat, jenis, merk, warna);
        }else if(pilihan == 3){
            cout << "Masukkan posisi yang ingin disisipkan data : ";
            cin >> posisi;
            cin.ignore();
            cout << "Masukkan plat nomor : ";
            getline(cin, plat);
            cout << "Masukkan jenis kendaraan : ";
            getline(cin, jenis);
            cout << "Masukkan merk dari kendaraan : ";
            getline(cin, merk);
            cout << "Masukkan warna kendaraan : ";
            getline(cin, warna);

            sisipkan_data(head, plat, jenis, merk, warna, posisi);
        }else if(pilihan == 4){
            hapus_depan(head);
            cout << "Data depan telah dihapus \n";
        }else if(pilihan == 5){
            hapus_belakang(head);
            cout << "Data belakang telah dihapus \n";
        }else if(pilihan == 6){
            cout << "***********************  DATA KENDARAAN ***********************\n";
            tampilkan_data(head);
        }else if(pilihan == 7){
            cout << "Terima kasih telah menggunakan program ini\n";
            con1 = false;
        }
    }
    return 0;
}