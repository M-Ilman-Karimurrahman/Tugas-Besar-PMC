#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//* 1. Fungsi Input Array SOP dan POS
void array_input(int ijenis_input, int ibit, int* aiSOP[15], int* aiPOS[15]){
    int a, b;
    if(ijenis_input == 1){
        for(a=0; a < ibit; a++){
            printf("m.%d = ", a);
            scanf("%d", aiSOP[a]);
            if(aiSOP[a] == 0){
                aiPOS[a] = 1;
            }
            else{
                aiPOS = 0;
            }
        }
    }
    else if(ijenis_input == 2){
        for(a=0; a < ibit; a++){
            printf("M.%d = ", a);
            scanf("%d", aiPOS[a]);
            if(aiSOP[a] == 0){
                aiPOS[a] = 1;
            }
            else{
                aiPOS = 0;
            }
        }
    }
}
//* 2. Fungsi Cetak Karnaugh Map
//  Hasil:
//      \\ x1x2
//  x3x4 \\______________________
//        | 00 || 01 || 11 || 10 |
//      --|----------------------|
//      00|  x ||  x ||  x ||  x |
//      --|----------------------|
//      01|  x ||  x ||  x ||  x |
//      --|----------------------|
//      11|  x ||  x ||  x ||  x |
//      --|----------------------|
//      10|  x ||  x ||  x ||  x |
//         ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯

void kmap_print(int itotal_variabel, int* aiSOP){
    if(itotal_variabel == 2){
        printf("   \\ x1");
        printf(" x2 \\________");
        printf("     | 0 || 1 |");
        printf("   --|--------|");
        printf("    0| %d || %d |",
            aiSOP[0], aiSOP[2]);
        printf("   --|--------|");
        printf("    1| %d || %d |",
            aiSOP[1], aiSOP[3]);
        printf("      ¯¯¯¯¯¯¯¯");

    }
    else if(itotal_variabel == 3){
        printf("   \\ x1x2");
        printf(" x3 \\______________________");
        printf("     | 00 || 01 || 11 || 10 |");
        printf("   --|----------------------|");
        printf("    0|  %d ||  %d ||  %d ||  %d |",
            aiSOP[0], aiSOP[2], aiSOP[6], aiSOP[4]);
        printf("   --|----------------------|");
        printf("    1|  %d ||  %d ||  %d ||  %d |",
            aiSOP[1], aiSOP[3], aiSOP[7], aiSOP[5]);
        printf("      ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯");


    }
    else if(itotal_variabel == 4){
        printf("     \\ x1x2\n");
        printf(" x3x4 \\______________________\n");
        printf("       | 00 || 01 || 11 || 10 |\n");
        printf("     --|----------------------|\n");
        printf("     00|  %d ||  %d ||  %d ||  %d |\n", 
            aiSOP[0], aiSOP[4], aiSOP[12], aiSOP[8]);
        printf("     --|----------------------|\n");
        printf("     01|  %d ||  %d ||  %d ||  %d |\n",
            aiSOP[1], aiSOP[5], aiSOP[13], aiSOP[9]);
        printf("     --|----------------------|\n");
        printf("     11|  %d ||  %d ||  %d ||  %d |\n",
            aiSOP[3], aiSOP[7], aiSOP[15], aiSOP[11]);
        printf("     --|----------------------|\n");
        printf("     10|  %d ||  %d ||  %d ||  %d |\n",
            aiSOP[2], aiSOP[6], aiSOP[14], aiSOP[10]);
        printf("        ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯");
    }
}

//* Cetak Fungsi (Kasar)
void fungsi_kasar_print(int ijenis_input, int* aiSOP, int* aiPOS){
    
}

//* Program Utama
int main(){
    int a, b, c, d, e;
    int ibit;
    int itotal_variabel; 
    int aiSOP[16];
    int aiPOS[16];
    int ijenis_input;
    printf("Logic Minimization dalam C\n");
    printf("Masukkan jumlah variabel (maks. 4): ");
    scanf("%d", itotal_variabel);
    ibit = square(itotal_variabel);
    
    // Jenis Input Array SOP/POS
    printf("Jenis Input: \n");
    printf("1. SOP\n 2. POS\n");
    printf("Pilihan Jenis Input: ");
    scanf("%d", ijenis_input);
    array_input(ijenis_input, ibit, aiSOP, aiPOS);
    kmap_print(itotal_variabel, aiSOP);
    

    return 0;
}