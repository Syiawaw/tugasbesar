//123240200
//123240217
//123240224
//Point Point Revisi :
//1. Tidak ada bikin file dimenu input
//2. Tidak ada mencari file dimenu searching
//3. Tidak ada melanjutkan data yang sudah ada
//4. Kurangnya sorting descening di quick sort dan merge sort

#include <iostream>
#include <fstream> // untuk file I/O
using namespace std;

struct Reguler
{
    int no_menu[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    string nama_menu[20] = {"1A", "2A", "3A", "4A", "5A", "6A", "7A", "8A", "9A", "10A", 
                            "11A", "12A", "13A", "14A", "15A", "16A", "17A", "18A", "19A", "20A"};
    int harga_menu[20] = {5000, 5000, 5000, 5000, 5000, 5000, 5000, 5000, 5000, 5000, 
                          5000, 5000, 5000, 5000, 5000, 5000, 5000, 5000, 5000, 5000};
};

struct VIP
{
    int no_menu[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    string nama_menu[10] = {"1V", "2V", "3V", "4V", "5V", "6V", "7V", "8V", "9V", "10V"};
    int harga_menu[10] = {6000, 6000, 6000, 6000, 6000, 6000, 6000, 6000, 6000, 6000};
};

struct VVIP
{
    int no_menu[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    string nama_menu[10] = {"1VV", "2VV", "3VV", "4VV", "5VV", "6VV", "7VV", "8VV", "9VV", "10VV"};
    int harga_menu[10] = {8000, 8000, 8000, 8000, 8000, 8000, 8000, 8000, 8000, 8000};
};

struct ItemPesanan
{
    int no_menu;
    string nama_menu;
    int harga_menu;
};

struct Pemesanan
{
    string nama, pilihan;
    ItemPesanan menu_dipesan[10];
} pesanan;

Pemesanan member[40];  // Array untuk menyimpan data member yang telah diinput
int jumlah_member = 0; // Jumlah member yang sudah tersimpan

char pilih, yesno;
int menupil, pilihan, jam, menu_pesanan = 0, total_harga = 0;

void muatDataDariFile();
void Menu_Utama();
void Menu_Satu();
void Menu_Dua();
void Menu_Tiga();
void Menu_Empat();
void Menu_Reguler();
void Menu_VIP();
void Menu_VVIP();
void nota();
void simpanKeFilePerNama(const Pemesanan& data);
void cariFileMember();
void Menu_Sequential_Search_Non_Sentinel();
void Menu_Sequential_Search_Sentinel();
void Binary();
void Menu_ASC_dan_DCS();
void Bubble_Sort_Ascending();
void Bubble_Sort_Descending();
void Selection_Sort_Ascending();
void Selection_Sort_Descending();
void Insertion_Sort_Ascending();
void Insertion_Sort_Descending();
void Shell_Sort_Ascending();
void Shell_Sort_Descending();
void quickSort_Ascending(int low, int high);
void quickSort_Descending(int low, int high);
void Quick_Sort_Ascending();
void Quick_Sort_Descending();
void merge_Ascending(int left, int mid, int right);
void merge_Descending(int left, int mid, int right);
void mergeSort_Ascending(int left, int right);
void mergeSort_Descending(int left, int right);
void Merge_Sort_Ascending();
void Merge_Sort_Descending();
void Menu_Salah();
void Kembali();
void keluar();
void simpanPesanan(); // fungsi untuk menyimpan data pesanan
void bacaPesananDariFile();

int partition_Ascending(int low, int high)
{
    string pivot = member[high].nama;
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (member[j].nama <= pivot)
        {
            i++;
            swap(member[i], member[j]);
        }
    }

    swap(member[i + 1], member[high]);
    return i + 1;
}

int partition_Descending(int low, int high)
{
    string pivot = member[high].nama;
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (member[j].nama >= pivot)
        {
            i++;
            swap(member[i], member[j]);
        }
    }

    swap(member[i + 1], member[high]);
    return i + 1;
}

int main()
{
    muatDataDariFile();
    while (true)
    {
        Menu_Utama();
        switch (pilihan)
        {
        case 1:
            Menu_Satu();
            switch (pilihan)
            {
            case 1:
                Menu_Reguler();
                nota();
                break;
            case 2:
                Menu_VIP();
                nota();
                break;
            case 3:
                Menu_VVIP();
                nota();
                break;
            default:
                Menu_Salah();
                break;
            }
            break;
        case 2:
            Menu_Dua();
            break;
        case 3:
            Menu_Tiga();
            switch (pilihan)
            {
            case 1:
                Menu_Sequential_Search_Non_Sentinel();
                break;
            case 2:
                Menu_Sequential_Search_Sentinel();
                break;
            case 3:
                Binary();
                break;
            default:
                Menu_Salah();
                break;
            }
            break;
        case 4:
            Menu_Empat();
            switch (pilihan)
            {
            case 1:
                Menu_ASC_dan_DCS();
                if (pilihan == 1)
                    Bubble_Sort_Ascending();
                else if (pilihan == 2)
                    Bubble_Sort_Descending();
                break;
            case 2:
                Menu_ASC_dan_DCS();
                if (pilihan == 1)
                    Selection_Sort_Ascending();
                else if (pilihan == 2)
                    Selection_Sort_Descending();
                break;
            case 3:
                Menu_ASC_dan_DCS();
                if (pilihan == 1)
                    Insertion_Sort_Ascending();
                else if (pilihan == 2)
                    Insertion_Sort_Descending();
                break;
            case 4:
                Menu_ASC_dan_DCS();
                if (pilihan == 1)
                    Shell_Sort_Ascending();
                else if (pilihan == 2)
                    Shell_Sort_Descending();
                break;
            case 5:
                Menu_ASC_dan_DCS();
                if (pilihan == 1)
                    Quick_Sort_Ascending();
                else if (pilihan == 2)
                    Quick_Sort_Descending();
                break;
            case 6:
                Menu_ASC_dan_DCS();
                if (pilihan == 1)
                    Merge_Sort_Ascending();
                else if (pilihan == 2)
                    Merge_Sort_Descending();
                break;
            default:
                Menu_Salah();
                break;
            }
            break;
        case 5:
            simpanPesanan();
            keluar();
            return 0;
        default:
            Menu_Salah();
            break;
        }

        // Tambahan konfirmasi setelah 1 siklus
        cout << "\nKembali ke menu utama? (y/n): ";
        cin >> yesno;
        if (yesno == 'n' || yesno == 'N') {
            keluar();
            break;
        }
        system("cls");
    }

    return 0;
}

void muatDataDariFile()
{
    ifstream file_in("data_member.txt");
    if (file_in.is_open()) 
    {
        jumlah_member = 0; // Reset jumlah member
        string line;
        while (getline(file_in, line)) 
        {
            if (line.find("Nama: ") != string::npos) 
            {
                member[jumlah_member].nama = line.substr(6);
            }
            else if (line.find("Jenis: ") != string::npos) 
            {
                member[jumlah_member].pilihan = line.substr(7);
            }
            else if (line.find("Ruangan: ") != string::npos) 
            {
                member[jumlah_member].menu_dipesan[0].nama_menu = line.substr(9);
            }
            else if (line.find("Harga/Jam: Rp ") != string::npos) 
            {
                member[jumlah_member].menu_dipesan[0].harga_menu = stoi(line.substr(15));
            }
            else if (line.find("-----------------------------") != string::npos) 
            {
                jumlah_member++; // pindah ke member berikutnya
            }
        }
        file_in.close();
    }
}

void Menu_Utama()
{
    cout << "=== MAIN MENU ===\n\n";
    cout << "1. INPUT MEMBER\n";
    cout << "2. SHOW MEMBER\n";
    cout << "3. SEARCHING\n";
    cout << "4. SORTING\n";
    cout << "5. EXIT\n";
    cout << "Pilih Opsi : "; 
    cin >> pilihan;
    system("cls");
}

void Menu_Satu()
{
    cout << "# SELAMAT DATANG DI AMBANET #" << endl;
    cout << "\t\t  Menu\t\t\t" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "| Nama Menu\t| Harga\t\t\t|" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "| 1. REGULER\t| Rp 5.000,-/jam\t|" << endl;
    cout << "| 2. VIP\t| Rp 6.000,-/jam\t|" << endl;
    cout << "| 3. VVIP\t| Rp 8.000,-/jam\t|" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Pilih Menu : ";
    cin >> pilihan;
    cin.ignore();
    cin.fail();
    cin.clear();
}

void Menu_Reguler()
{
    Reguler list_menu_reguler;
    system("cls");
    cout << "Masukkan Nama Member : ";
    getline(cin >> ws, pesanan.nama);
    
    pesanan.pilihan = "Reguler";
    
    char lanjut;
        // Error handling untuk input nomor PC yang benar
        do
        {
            cout << "Masukkan Nomor PC yang dipilih (1-20): "; 
            cin >> menupil;
            cout << "Ingin bermain berapa jam : "; 
            cin >> jam;
            if (menupil > 20 || menupil < 1)
                cout << "Pilih menu dengan benar" << endl;
        } while (menupil < 1 || menupil > 20);
        
        for (int i = 0; i < 20; i++)
        {
            if (list_menu_reguler.no_menu[i] == menupil)
            {
                pesanan.menu_dipesan[menu_pesanan].no_menu = list_menu_reguler.no_menu[i];
                pesanan.menu_dipesan[menu_pesanan].nama_menu = list_menu_reguler.nama_menu[i];
                pesanan.menu_dipesan[menu_pesanan].harga_menu = list_menu_reguler.harga_menu[i];
            }
        }
        menu_pesanan++;

        if (jumlah_member < 20) 
        {
            member[jumlah_member] = pesanan;
            simpanKeFilePerNama(pesanan); // Tambahan simpan per file
            jumlah_member++;
        }
}

void Menu_VIP()
{
    VIP list_menu_VIP;
    system("cls");
    cout << "Masukkan Nama Member : ";
    getline(cin >> ws, pesanan.nama);
    
    pesanan.pilihan = "VIP";
    
    char lanjut;
        // Error handling untuk input nomor PC yang benar
        do
        {
            cout << "Masukkan Nomor PC yang dipilih (1-10): "; 
            cin >> menupil;
            cout << "Ingin bermain berapa jam : "; 
            cin >> jam;
            if (menupil > 10 || menupil < 1)
                cout << "Pilih menu dengan benar" << endl;
        } while (menupil < 1 || menupil > 10);
        
        for (int i = 0; i < 10; i++)
        {
            if (list_menu_VIP.no_menu[i] == menupil)
            {
                pesanan.menu_dipesan[menu_pesanan].no_menu = list_menu_VIP.no_menu[i];
                pesanan.menu_dipesan[menu_pesanan].nama_menu = list_menu_VIP.nama_menu[i];
                pesanan.menu_dipesan[menu_pesanan].harga_menu = list_menu_VIP.harga_menu[i];
            }
        }
        menu_pesanan++;
        if (jumlah_member < 10) 
        {
            member[jumlah_member] = pesanan;
            simpanKeFilePerNama(pesanan); // Tambahan simpan per file
            jumlah_member++;
        }
}

void Menu_VVIP()
{
    VVIP list_menu_VVIP;
    system("cls");
    cout << "Masukkan Nama Member : ";
    getline(cin >> ws, pesanan.nama);
    
    pesanan.pilihan = "VVIP";
    
    char lanjut;
        // Error handling untuk input nomor PC yang benar
        do
        {
            cout << "Masukkan Nomor PC yang dipilih (1-10): "; 
            cin >> menupil;
            cout << "Ingin bermain berapa jam : "; 
            cin >> jam;
            if (menupil > 10 || menupil < 1)
                cout << "Pilih menu dengan benar" << endl;
        } while (menupil < 1 || menupil > 10);
        
        for (int i = 0; i < 10; i++)
        {
            if (list_menu_VVIP.no_menu[i] == menupil)
            {
                pesanan.menu_dipesan[menu_pesanan].no_menu = list_menu_VVIP.no_menu[i];
                pesanan.menu_dipesan[menu_pesanan].nama_menu = list_menu_VVIP.nama_menu[i];
                pesanan.menu_dipesan[menu_pesanan].harga_menu = list_menu_VVIP.harga_menu[i];
            }
        }
        menu_pesanan++;
        if (jumlah_member < 10) 
        {
            member[jumlah_member] = pesanan;
            simpanKeFilePerNama(pesanan); // Tambahan simpan per file
            jumlah_member++;
        }
}

void nota()
{
    Pemesanan *ptrPesanan = &pesanan;

    cout << "----------  Nota  ----------" << endl;
    cout << "Nama\t\t: " << ptrPesanan->nama << endl;

    for (int j = 0; j < menu_pesanan; j++)
    {
        ItemPesanan *ptrItem = &ptrPesanan->menu_dipesan[j];
        cout << "Pesanan " << j + 1 << "\t: " << ptrItem->nama_menu << endl;
        cout << "Harga\t\t: Rp " << ptrItem->harga_menu << endl;
        cout << "Total Jam\t: " << jam << endl;
        total_harga += jam * ptrItem->harga_menu;
    }

    cout << "----------------------------" << endl;
    cout << "Total\t\t: Rp " << total_harga << endl;
    cout << "--------Terima Kasih--------" << endl;

    // Reset setelah nota tampil
    menu_pesanan = 0;
    total_harga = 0;
    jam = 0;
    
}

void simpanKeFilePerNama(const Pemesanan& data) 
{
    string filename = data.nama + ".txt";
    ofstream file_out(filename);
    if (file_out.is_open()) 
    {
        file_out << "Nama\t: " << data.nama << endl;
        file_out << "Jenis\t: " << data.pilihan << endl;
        file_out << "Ruangan\t: " << data.menu_dipesan[0].nama_menu << endl;
        file_out << "Harga/Jam: Rp " << data.menu_dipesan[0].harga_menu << endl;
        file_out << "-----------------------------" << endl;
        file_out.close();
    } 
    else 
    {
        cout << "Gagal menyimpan ke file " << filename << endl;
    }
}

void Menu_Dua()
{
    system("cls");
    cout << "========== DATA PESANAN ==========\n";

    // Menampilkan data dari array member
    if (jumlah_member == 0)
    {
        cout << "Belum ada member yang mendaftar.\n";
    }
    else
    {
        for (int i = 0; i < jumlah_member; i++)
        {
            cout << "Member " << i + 1 << endl;
            cout << "Nama\t: " << member[i].nama << endl;
            cout << "Jenis\t: " << member[i].pilihan << endl;
            cout << "Ruangan\t: " << member[i].menu_dipesan[0].nama_menu << endl;
            cout << "-------------------------------\n";
        }
    }
    // Tambahan: baca ulang dari file
    cout << "\n>>> Data disimpan di file:\n";
    bacaPesananDariFile();
}

void Menu_Tiga()
{
    int *ptrPilihan = &pilihan; // pointer ke variabel pilihan

    cout << "=== MENU SEARCHING ===\n\n";
    cout << "1. SEQUENTIAL SEARCH NON SENTINEL\n";
    cout << "2. SEQUENTIAL SEARCH SENTINEL\n";;
    cout << "3. BINARY\n";
    cout << "Pilih Opsi : "; 
    cin >> *ptrPilihan; // input nilai ke alamat yang ditunjuk pointer
    cin.ignore();
    system("cls");
}

void Menu_Sequential_Search_Non_Sentinel()
{
    string nama_file;
    cout << "Masukkan nama file member (tanpa ekstensi): ";
    cin >> nama_file;

    ifstream file(nama_file + ".txt");
    if (file.is_open())
    {
        string baris;
        cout << "Isi file " << nama_file << ".txt:\n";
        while (getline(file, baris))
        {
            cout << baris << endl;
        }
        file.close();
    }
    else
    {
        cout << "File tidak ditemukan.\n";
    }
}

void Menu_Sequential_Search_Sentinel()
{
    string nama_file;
    cout << "Masukkan nama file member (tanpa ekstensi): ";
    cin >> nama_file;

    // Tambahkan sentinel
    member[jumlah_member].nama = nama_file;

    int i = 0;
    while (member[i].nama != nama_file)
    {
        i++;
    }

    if (i < jumlah_member)
    {
        ifstream file(nama_file + ".txt");
        if (file.is_open())
        {
            string baris;
            cout << "\n=== Isi file " << nama_file << ".txt ===\n";
            while (getline(file, baris))
            {
                cout << baris << endl;
            }
            file.close();
        }
    }
    else
    {
        cout << "Data tidak ditemukan.\n";
    }
}

void Binary()
{
    if (jumlah_member == 0)
    {
        cout << "Belum ada data yang tersimpan.\n";
        return;
    }

    // Mengurutkan array member berdasarkan nama sebelum melakukan Binary Search
    for (int i = 0; i < jumlah_member - 1; i++)
    {
        for (int j = 0; j < jumlah_member - i - 1; j++)
        {
            if (member[j].nama > member[j + 1].nama)
            {
                swap(member[j], member[j + 1]);
            }
        }
    }

    string nama_file;
    cout << "Masukkan nama file member (tanpa ekstensi): ";
    cin >> nama_file;

    int kiri = 0, kanan = jumlah_member - 1;
    bool ditemukan = false;

    while (kiri <= kanan)
    {
        int tengah = (kiri + kanan) / 2;

        if (member[tengah].nama == nama_file)
        {
            ditemukan = true;

            ifstream file(nama_file + ".txt");
            if (file.is_open())
            {
                cout << "\n=== Isi file " << nama_file << ".txt ===\n";
                string baris;
                while (getline(file, baris))
                {
                    cout << baris << endl;
                }
                file.close();
            }
            break;
        }
        else if (member[tengah].nama < nama_file)
        {
            kiri = tengah + 1;
        }
        else
        {
            kanan = tengah - 1;
        }
    }

    if (!ditemukan)
    {
        cout << "Data tidak ditemukan.\n";
    }
}

void Menu_Empat()
{
    int *ptrPilihan = &pilihan; // pointer ke variabel pilihan

    cout << "=== MENU SORTING ===\n\n";
    cout << "1. BUBBLE SORT\n";
    cout << "2. SELECTION SORT\n";
    cout << "3. INSERTION SORT\n";
    cout << "4. SHELL SORT\n";
    cout << "5. QUICK SORT\n";;
    cout << "6. MERGE SORT\n";
    cout << "Pilih Opsi : "; 
    cin >> *ptrPilihan; // input nilai ke alamat yang ditunjuk pointer
    cin.ignore();
    system("cls");
}

void Menu_ASC_dan_DCS()
{
    int *ptrPilihan = &pilihan; // pointer ke variabel pilihan

    cout << "=== MENU ASCENDING DAN DESCENDING ===\n";
    cout << "PENCARIAN BERDASARKAN NAMA\n\n";
    cout << "1. ASCENDING\n";
    cout << "2. DISCENDING\n";
    cout << "Pilih Opsi : "; 
    cin >> *ptrPilihan; // input nilai ke alamat yang ditunjuk pointer
    cin.ignore();
    system("cls");
}

void Bubble_Sort_Ascending()
{
    for (int i = 0; i < jumlah_member - 1; i++)
    {
        for (int j = 0; j < jumlah_member - i - 1; j++)
        {
            if (member[j].nama > member[j + 1].nama)
            {
                swap(member[j], member[j + 1]);
            }
        }
    }
    cout << "Data telah diurutkan menggunakan Bubble Sort!\n";
    cout << "Silahkan cek di menu ke-2 (SHOW MEMBER)\n";
} 

void Bubble_Sort_Descending()
{
    for (int i = 0; i < jumlah_member - 1; i++)
    {
        for (int j = 0; j < jumlah_member - i - 1; j++)
        {
            if (member[j].nama < member[j + 1].nama)
            {
                swap(member[j], member[j + 1]);
            }
        }
    }
    cout << "Data telah diurutkan menggunakan Bubble Sort!\n";
    cout << "Silahkan cek di menu ke-2 (SHOW MEMBER)\n";
} 

void Selection_Sort_Ascending()
{
    for (int i = 0; i < jumlah_member - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < jumlah_member; j++)
        {
            if (member[j].nama < member[min_index].nama)
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            swap(member[i], member[min_index]);
        }
    }

    cout << "Data telah diurutkan menggunakan Selection Sort!\n";
    cout << "Silahkan cek di menu ke-2 (SHOW MEMBER)\n";
}

void Selection_Sort_Descending()
{
    for (int i = 0; i < jumlah_member - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < jumlah_member; j++)
        {
            if (member[j].nama > member[min_index].nama)
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            swap(member[i], member[min_index]);
        }
    }

    cout << "Data telah diurutkan menggunakan Selection Sort!\n";
    cout << "Silahkan cek di menu ke-2 (SHOW MEMBER)\n";
}

void Insertion_Sort_Ascending()
{
    for (int i = 1; i < jumlah_member; i++)
    {
        Pemesanan key = member[i];
        int j = i - 1;

        // Geser elemen yang lebih besar ke kanan
        while (j >= 0 && member[j].nama > key.nama)
        {
            member[j + 1] = member[j];
            j--;
        }

        // Tempatkan elemen pada posisi yang tepat
        member[j + 1] = key;
    }

    cout << "Data telah diurutkan menggunakan Insertion Sort!\n";
    cout << "Silahkan cek di menu ke-2 (SHOW MEMBER)\n";
}

void Insertion_Sort_Descending()
{
    for (int i = 1; i < jumlah_member; i++)
    {
        Pemesanan key = member[i];
        int j = i - 1;

        // Geser elemen yang lebih kecil ke kanan (untuk urutan descending)
        while (j >= 0 && member[j].nama < key.nama)
        {
            member[j + 1] = member[j];
            j--;
        }

        // Tempatkan elemen pada posisi yang tepat
        member[j + 1] = key;
    }

    cout << "Data telah diurutkan secara descending menggunakan Insertion Sort!\n";
    cout << "Silahkan cek di menu ke-2 (SHOW MEMBER)\n";
}

void Shell_Sort_Ascending()
{
    for (int gap = jumlah_member / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < jumlah_member; i++)
        {
            Pemesanan temp = member[i];
            int j;
            for (j = i; j >= gap && member[j - gap].nama > temp.nama; j -= gap)
            {
                member[j] = member[j - gap];
            }
            member[j] = temp;
        }
    }

    cout << "Data telah diurutkan menggunakan Shell Sort!\n";
    cout << "Silahkan cek di menu ke-2 (SHOW MEMBER)\n";
}

void Shell_Sort_Descending() 
{
    for (int gap = jumlah_member / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < jumlah_member; i++)
        {
            Pemesanan temp = member[i];
            int j;
            // Ubah > menjadi < agar sorting menjadi descending
            for (j = i; j >= gap && member[j - gap].nama < temp.nama; j -= gap)
            {
                member[j] = member[j - gap];
            }
            member[j] = temp;
        }
    }

    cout << "Data telah diurutkan secara descending menggunakan Shell Sort!\n";
    cout << "Silahkan cek di menu ke-2 (SHOW MEMBER)\n";
}

void quickSort_Ascending(int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition_Ascending(low, high);
        quickSort_Ascending(low, pivotIndex - 1);
        quickSort_Ascending(pivotIndex + 1, high);
    }
}

void Quick_Sort_Ascending()
{
    quickSort_Ascending(0, jumlah_member - 1);
    cout << "Data telah diurutkan menggunakan Quick Sort!\n";
    cout << "Silahkan cek di menu ke-2 (SHOW MEMBER)\n";
}

void quickSort_Descending(int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition_Descending(low, high);
        quickSort_Descending(low, pivotIndex - 1);
        quickSort_Descending(pivotIndex + 1, high);
    }
}

void Quick_Sort_Descending()
{
    quickSort_Descending(0, jumlah_member - 1);
    cout << "Data telah diurutkan menggunakan Quick Sort!\n";
    cout << "Silahkan cek di menu ke-2 (SHOW MEMBER)\n";
}

void merge_Ascending(int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Buat array sementara
    Pemesanan* L = new Pemesanan[n1];
    Pemesanan* R = new Pemesanan[n2];

    // Salin data ke array sementara
    for (int i = 0; i < n1; i++)
        L[i] = member[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = member[mid + 1 + j];

    int i = 0, j = 0, k = left;
    // Merge kembali ke array utama dengan urutan berdasarkan nama
    while (i < n1 && j < n2) {
        if (L[i].nama <= R[j].nama) 
        {
            member[k] = L[i];
            i++;
        } else 
        {
            member[k] = R[j];
            j++;
        }
        k++;
    }

    // Salin sisa elemen L jika ada
    while (i < n1) 
    {
        member[k] = L[i];
        i++;
        k++;
    }

    // Salin sisa elemen R jika ada
    while (j < n2) 
    {
        member[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort_Ascending(int left, int right)
{
    if (left < right) 
    {
        int mid = left + (right - left) / 2;

        mergeSort_Ascending(left, mid);
        mergeSort_Ascending(mid + 1, right);

        merge_Ascending(left, mid, right);
    }
}

void Merge_Sort_Ascending()
{
    mergeSort_Ascending(0, jumlah_member - 1);
    cout << "Data telah diurutkan menggunakan Merge Sort!\n";
    cout << "Silahkan cek di menu ke-2 (SHOW MEMBER)\n";
}

void merge_Descending(int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Buat array sementara
    Pemesanan* L = new Pemesanan[n1];
    Pemesanan* R = new Pemesanan[n2];

    // Salin data ke array sementara
    for (int i = 0; i < n1; i++)
        L[i] = member[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = member[mid + 1 + j];

    int i = 0, j = 0, k = left;
    // Merge kembali ke array utama dengan urutan berdasarkan nama
    while (i < n1 && j < n2) {
        if (L[i].nama >= R[j].nama) 
        {
            member[k] = L[i];
            i++;
        } else 
        {
            member[k] = R[j];
            j++;
        }
        k++;
    }

    // Salin sisa elemen L jika ada
    while (i < n1) 
    {
        member[k] = L[i];
        i++;
        k++;
    }

    // Salin sisa elemen R jika ada
    while (j < n2) 
    {
        member[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort_Descending(int left, int right)
{
    if (left < right) 
    {
        int mid = left + (right - left) / 2;

        mergeSort_Descending(left, mid);
        mergeSort_Descending(mid + 1, right);

        merge_Descending(left, mid, right);
    }
}

void Merge_Sort_Descending()
{
    mergeSort_Descending(0, jumlah_member - 1);
    cout << "Data telah diurutkan menggunakan Merge Sort!\n";
    cout << "Silahkan cek di menu ke-2 (SHOW MEMBER)\n";
}

void keluar()
{
    cout << "= Terima kasih, sampai jumpa nanti lagi! =";
}

void Kembali()
{
    cout << "\nKembali ke menu utama? (y/n) ";
    cin >> yesno;
    if (yesno == 'y' || yesno == 'Y')
    {
        system("CLS");
        main();
    }
    else if (yesno == 'n' || yesno == 'N')
    {
        keluar();
    }
    else
    {
        system("cls");
        keluar();
    }
}

void Menu_Salah()
{
    system("cls");
    cout << "Tolong pilih angka yang baik dan benar ";
}

void simpanPesanan()
{
    ofstream file_out("data_member.txt", ios::app); // membuka file untuk ditambahkan (append)
    if (file_out.is_open()) {
        for (int i = 0; i < jumlah_member; i++) {
            file_out << "Nama\t: " << member[i].nama << endl;
            file_out << "Jenis\t: " << member[i].pilihan << endl;
            file_out << "Ruangan\t: " << member[i].menu_dipesan[0].nama_menu << endl;
            file_out << "Harga/Jam: Rp " << member[i].menu_dipesan[0].harga_menu << endl;
            file_out << "-----------------------------" << endl;
        }
        file_out.close();
        cout << "\nData berhasil disimpan ke file data_member.txt\n";
    } else {
        cout << "Gagal menyimpan data ke file.\n";
    }
}

void bacaPesananDariFile() 
{
    ifstream file_in("data_member.txt");
    if (file_in.is_open()) {
        string baris;
        cout << "=== DATA DARI FILE data_member.txt ===\n";
        while (getline(file_in, baris)) {
            cout << baris << endl;
        }
        file_in.close();
    }
}