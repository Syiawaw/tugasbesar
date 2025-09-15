#include <iostream>
using namespace std;

struct pesanan //struct pesanan untuk menyimpan data dan node untuk linked list
{
    string nama;//untuk menyimpan data nama pemesan
    int antri;//untuk menyimpan data nomor antrian
    pesanan* next;//untuk pointer ke nod selanjutnya
};


pesanan* head =NULL;//sebagai pointer head untuk menunjuk awal linked list

void tambahpesanan(string nama, int antri){//sebagai fungsi untuk tambah pesanan
    pesanan* baru = new pesanan; //untuk membuat node baru secara dinamis
    baru->nama = nama; //untuk isi data nama
    baru->antri = antri; //untuk isi data no antri
    baru->next = NULL;

    if(head == NULL) //error handling semisal linked list masih kosong
    {
        head = baru; //node baru jadi head
    }
    else{//untuk cari node akhir
        pesanan* temp = head;
         while (temp->next != NULL)
    {
        temp =temp->next;//untuk maju ke node berikutnya
    }temp->next = baru; //untuk menghubungkan node akhir ke baru

    }
   cout<<"Nama : "<<nama<<"\nNo antri : "<<antri<<"\nBerhasil ditambahkan"<<endl;
    
}
void hapuspesanan(string nama){ //fungsi untuk hapus pesanan
    if(head == NULL){//error handling semisal linked list masih kosong
        cout<<"Data belum ada"<<endl;
        return;
    }
    pesanan*temp = head; // sebagai pointer bantu
    pesanan*prev = NULL; // sebagai pointer simpan node sebelumnya
    while (temp != NULL && temp->nama !=nama)
    {
        prev = temp; //sebagai pointer bantu
        temp = temp->next;//untuk pointer menyimpan node sebelumnya
    }
    if (temp == NULL) //sebagai error handling jika nama yang di input tidak ada
    {
        cout<<"Identitas dengan nama : "<<nama<<" tidak ditemukan"<<endl;
        return;
    }
    if(prev == NULL){ //Jika node yang dihapus adalah head
        head = head->next; // menmindahkan head ke node berikutnya

    }else{
        prev->next = temp->next; // untuk melewati node yang dihapus
    }
    delete temp; // untuk hapus node di memori
    cout<<"Data pesanan berhasil dihapus";

}
void datapesanan(){// fungsi untuk melihat data pemesanan
    if (head == NULL) //error handling semisal linked list masih kosong
    {
        cout<<"Data masih kosong"<<endl;
        return;
    }
    
    cout<<"==Data Antrian=="<<endl; //menampilkan data yang sudah ditambahkan
    pesanan* temp = head; // mulai dari head
    while (temp !=NULL)
    {
        cout<<"Nama : "<<temp->nama<<"\nNo antri : "<<temp->antri<<endl;
        temp =temp->next; // untuk next ke node selanjutnya
    }
    
}
void caripesanan(string nama){ // untuk fungsi mencari data pemesanan
     if (head == NULL) //error handling semisal linked list masih kosong
    {
        cout<<"Data masih kosong"<<endl;
        return;
    }
    pesanan* temp =head; //sebagai pointer bantu
    while (temp !=NULL)
    {
        if (temp->nama == nama ) // Untuk jika nama yang diinput cocok
        {
            cout<<"Nama pemesan : "<<temp->nama<<"\n No antri : "<<temp->antri<< endl;
            return;
        }
        temp = temp->next; //untuk lanjut ke node selanjutnya
    }
    cout<<"Nama tidak ditemukan"<<endl;
}

int main()// sebagai fungsi utama
{
    string nama; //untuk input nama
    int antri; //untuk input no antri
    int pil; //untuk input menu pilihan
do //sebagai perulangan di menu
{
    cout<<"= Menu antrian pemesanan Restoran ="<<endl;
    cout<<"1. Tambahkan pesanan"<<endl;
    cout<<"2. Hapus pesanan"<<endl;
    cout<<"3. Data antrian pesanan"<<endl;
    cout<<"4. Cari data pesanan"<<endl;
    cout<<"0. Keluar"<<endl;
    cout<<"Pilih (masukkan angka) : ";cin>>pil;cout<<endl; //input pilihan
        switch (pil) //untuk pilihan
        {
        case 1 : //untuk input data pemesanan
            cout<<"Masukkan nama pemesan : ";cin>>nama;
            cout<<"Masukkan No antri : ";cin>>antri;cout<<endl;

            tambahpesanan(nama, antri);
            break;
        case 2://untuk hapus pesanan
            cout<<"Masukkan nama yang ingin dihapus : ";cin>>nama;cout<<endl;    

            hapuspesanan(nama);
            break;
        case 3://untuk menampilkan data
            datapesanan();
            break;
        case 4://untuk mencari data
            cout<<"Masukkan nama pemesan yang ingin dicari : ";cin>>nama;cout<<endl;

            caripesanan(nama);
            break;
        case 5: //untuk keluar
            cout<<"Anda keluar.."<<endl;
            break;
        }

} while (pil != 0);//jika pilihan selain 0 akan lanjut perulangan
return 0;
}