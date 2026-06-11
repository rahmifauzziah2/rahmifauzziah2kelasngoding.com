#include <stdio.h> 
#include <string.h> 

// Manajemen Data untuk menyimpan informasi mahasiswa 
struct Mahasiswa { 
     char nama[50]; 
     int nilai; 
     char huruf; 
}; 

// Fungsi untuk menentukan Grade Nilai Huruf (Soal 1) [cite: 34-39] 
char tentukanGrade(int n) { 
    if (n >= 85) return 'A'; // >= 85 [cite: 35]  
    else if (n >= 70) return 'B'; // 70-84 [cite: 36]  
    else if (n >= 60) return 'C'; // 60-69 [cite: 37]  
    else if (n >= 50) return 'D'; // 50-59 [cite: 38]  
    else return 'E'; // < 50 [cite: 39] 
} 

int main() { 
   // Array untuk menyimpan data mahasiswa [cite: 26]  
    struct Mahasiswa mhs[100]; 
    int jumlah = 0; 
    int pilihan; 
    // Perulangan Menu Utama (Soal 4) [cite: 63, 71]  
    do { 
        printf("\n=========================================="); 
        printf("\n PROGRAM PENGELOLA DATA NILAI ");  
        printf("\n==========================================");  
        printf("\n1. Input Data Mahasiswa"); // [cite: 64] 
        printf("\n2. Tampilkan Semua Data"); // [cite: 65] 
        printf("\n3. Analisis Nilai"); // [cite: 66] 
        printf("\n4. Tampilkan Ranking"); // [cite: 67] 
        printf("\n5. Keluar"); // [cite: 68] 
        printf("\n------------------------------------------");  
        printf("\nPilih Menu (1-5): "); 
      
       // Membersihkan buffer dan mengambil input menu [cite: 72]
       if (scanf(" %d", &pilihan) != 1) { 
          while (getchar() != '\n'); 
          pilihan = 0; 
       } 
      
       switch(pilihan) { 
          case 1: { // Soal 1: Input dan Validasi [cite: 27]  
            int n_baru; 
            printf("Masukkan jumlah mahasiswa yang ingin diinput:  "); 
            
            scanf("%d", &n_baru); // [cite: 28] 
 
            for (int i = 0; i < n_baru; i++) { 
              printf("\nData Mahasiswa ke-%d\n", jumlah + 1); 
              printf("Nama mahasiswa: "); // [cite: 30] 
              scanf(" %[^\n]s", mhs[jumlah].nama); 
              
              // Validasi rentang 0-100 (Soal 1) do { 
                  printf("Nilai (0-100): "); 
                  scanf("%d", &mhs[jumlah].nilai); 
                  if (mhs[jumlah].nilai < 0 || mhs[jumlah].nilai  
 > 100) { 
                      printf("[!] Nilai tidak valid! Masukkan 
 angka 0-100.\n"); 
                  } 
              } while (mhs[jumlah].nilai < 0 ||
 mhs[jumlah].nilai > 100); 
                     mhs[jumlah].huruf =  
tentukanGrade(mhs[jumlah].nilai); 
                    jumlah++; 
              } 
              break; 
          } 

            case 2: { // Output: Tampilkan Seluruh Data [cite: 40, 41] 
              if (jumlah == 0) { 
                printf("\n[!] Data masih kosong. Silakan input di  menu 1."); 
              } else { 
                  printf("\n%-20s | %-10s | %-10s", "NAMA", "NILAI",  "ABJAD"); 
                  printf("\n---------------------------------------- --"); 
                  for (int i = 0; i < jumlah; i++) {
                    printf("\n%-20s | %-10d | %-10c", mhs[i].nama,  mhs[i].nilai, mhs[i].huruf); 
                                                   } 
              } 
              break; 
            } 
     
            case 3: { // Soal 2: Analisis Data Nilai [cite: 47, 49]  if (jumlah == 0) {
              printf("\n[!] Belum ada data untuk dianalisis.");
            } else {
              float total = 0;
              int max = mhs[0].nilai, min = mhs[0].nilai;
              int lulus = 0, gagal = 0;
              for (int i = 0; i < jumlah; i++) {
                total += mhs[i].nilai;
                if (mhs[i].nilai > max) max = mhs[i].nilai; //  
 [cite: 51] 
                if (mhs[i].nilai < min) min = mhs[i].nilai; // 
 [cite: 52] 
                if (mhs[i].nilai >= 60) lulus++; // 
 Lulus >= 60 [cite: 53] 
                else gagal++;                   // 
 Tidak lulus [cite: 54] 
        } 
        
        printf("\n--- ANALISIS DATA NILAI ---");  
        printf("\nRata-rata Nilai : %.2f", total /  jumlah); // [cite: 50] 
        printf("\nNilai Tertinggi : %d", max);
        printf("\nNilai Terendah : %d", min); 
        printf("\nJumlah Mahasiswa Lulus : %d", lulus); 
        printf("\nJumlah Mahasiswa Gagal : %d", gagal); 
      } 
      break; 
    }
          case 4: { // Soal 3: Pengurutan Data (Ranking) [cite: 56,  57]
              if (jumlah == 0) {
                printf("\n[!] Data kosong.");
              } else { 
                // Algoritma Bubble Sort: Tertinggi ke Terendah  
     [cite: 59]
              for (int i = 0; i < jumlah - 1; i++) {
                  for (int j = 0; j < jumlah - i - 1; j++) {
                      if (mhs[j].nilai < mhs[j+1].nilai) {
                        struct Mahasiswa temp = mhs[j];
                        mhs[j] = mhs[j+1];
                        mhs[j+1] = temp;
                      } 
                  }
     }
                printf("\n--- DATA MAHASISWA BERDASARKAN RANGKING  ---"); // [cite: 61]
                printf("\n%-5s | %-20s | %-10s", "RANK", "NAMA",  "NILAI");
                for (int i = 0; i < jumlah; i++) {
                  printf("\n%-5d | %-20s | %-10d", i + 1,  mhs[i].nama, mhs[i].nilai);
                }
              } 
          break;
        }
      
            case 5: // Keluar [cite: 68, 70] 
              printf("\nKeluar dari program. Pengisian Administrasi  
     Selesai!"); 
              break; 
     
     default:
       printf("\n[!] Pilihan tidak tersedia.");  }
       printf("\n\nTekan Enter untuk kembali ke menu...");
       getchar();getchar(); 
    } while (pilihan != 5); // [cite: 70] 
    
     return 0;
    } 
