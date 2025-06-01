#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;


 
struct tanggal{
  int tanggal,bulan,tahun;
};
const int maks = 100;
struct biodata{
    string namapelanggan;
    string namafilm;
    int judulfilm;
    string studio;
    int pembayaran;
    float jam;
};
biodata pelanggan[maks];
struct tayang
{
    int no_film[4] = {1,2,3,4};
     string judul[4] ={"Spiderman No Way Home","Guardian Galaxy","Kimetsu No Yaiba Mugen Train","Jujusu Kaisen Zero"};
     int harga = 35000;
}tayanganfilm;
struct studio
{
    string nokursi[10] = {"1","2","3","4","5","6","7","8","9","10"};
    string posisikursi[4] = {"A","B","C","D"};
};


 int harga;
int pilihan;
void film() {
    cout<<"\t======== Daftar Film =========== \t\n";
    cout<<"\t1. Spiderman No Way Home \t\n";
    cout<<"\t2. Guardian Galaxy \t\n";
    cout<<"\t3. Kimetsu No Yaiba Mugen Train \t\n";
    cout<<"\t4. Jujusu Kaisen Zero \t\n";
    cout<<"harga tiket : Rp 35.000\t\n";
}
void inputpelanggan(){
film();
int pembelian;

cout<<"masukan jumlah pembelian : ";cin>>pembelian;
    for (int i = 0; i < pembelian; i++)
    {
        cout<<"Masukan Film (1-6)"; cin>>pelanggan[i].judulfilm ;
        if (pelanggan[i].judulfilm == tayanganfilm.no_film[i] )
        {
            tayanganfilm.judul[i];
            pelanggan[i].pembayaran = pembelian * tayanganfilm.harga;
        }
       cout<<"masukan nomor kursi : ";
    }
}
 void menuutama(){
      string user,pass;
    int coba = 0;
    bool login;
    do
    {
        
    cout<<"Silakan Login \n";
    cout<<"Masukan Username : "; cin>>user;
    cout<<"Masukan Password : "; cin>>pass;
    
    if (user == "admin" && pass == "123")
    {
        login = true;
        break;
    }
    else{
        cout<<"Login Invalid Silahkan Login Kembali\n";
        coba++;
    }
    }  while (login == true && coba <= 3);
      cout<<"===Selamat Datang Di Bioskop Sigma===\n";
    cout<<"1. Pembelian Tiket Film\n";
    cout<<"2. Data Pembelian Tiket Film\n";
    cout<<"3. Pencarian Data Pembeli\n";
    cout<<"4. Sorting Data Pembeli\n";

    cout<<"masukan pilihan anda :";cin>>pilihan;
    switch (pilihan)
    {
    case 1:
        
        break;
    
    default:
        break;
    }
  
    
 }

int main(){
   
    
    }
   
    
    
 
    

