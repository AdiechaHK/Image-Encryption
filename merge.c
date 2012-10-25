#include <stdio.h>

int nextByte(int x_max, int y_max, int n_max, int* x, int* y, int* n);

int main(int test){
  int ipChar_d, header_indx, x_poz, y_poz, byte_no, i, bit_no, msg_int;
  int x_max = 128, y_max = 128, n_max = 3, merge_process = 1, file_complete = 0;
  char char_c, msg_char;

  FILE *msgFile;
  FILE *inputFile;
  FILE *outputFile;

  msgFile = fopen("sample.txt", "r");
  inputFile = fopen("black.bmp", "r");
  outputFile = fopen("black_enc.bmp", "a+");

  // Header Copy
  i = 0;
  while(i < 54) {
    ipChar_d = fgetc(inputFile);
    char_c = ipChar_d;
    fputc(char_c, outputFile);
    i++;
  }

  // Image Pixels Coping
  for (x_poz = 0, y_poz = 0, byte_no = 0, bit_no = 0; 1;) {
    /* code */
    ipChar_d = fgetc(inputFile);
    
    if(merge_process){

      // Gether Character from msg file if requers
      if(bit_no==0) {
        msg_char = fgetc(msgFile);
        if(msg_char == EOF){
          file_complete = 1;
        }
        if(msg_char < 0) msg_int = 256 + msg_char;
        else msg_int = msg_char;
        printf("\n[ int : %d, char : %c, hex : %x ]\n", msg_int, msg_int, msg_int);
      }

      // Process 

      // Condition LSB = 0   
      if(msg_int % 2 == 0) {
        if(ipChar_d % 2 == 1) ipChar_d--;

      // Condition LSB = 1
      } else {            
        if(ipChar_d % 2 == 0) ipChar_d++;
      }

      msg_int/=2;
      if(bit_no < 7) bit_no++;
      else {
        bit_no = 0;
        if(file_complete) merge_process = 0;
      }
    }

    char_c = ipChar_d;
    fputc(char_c, outputFile);
    printf(" [ X:%d, Y:%d, N:%d ] :: [ INT :: %d, CHAR :: %d ]\n", x_poz, y_poz, byte_no, ipChar_d, char_c);
    if(nextByte(x_max, y_max, n_max, &x_poz, &y_poz, &byte_no)) continue;
    else break;
  }

  fclose(msgFile);
  fclose(inputFile);
  fclose(outputFile);
  return 0;
}

int nextByte(int x_max, int y_max, int n_max, int* x, int* y, int* n) {
  int ret = 1;
  if((*n)<n_max-1) {
    (*n) = (*n) + 1;
  } else {
    (*n) = 0;
    if((*x)<x_max-1) {
      (*x) = (*x) + 1;
    } else {
      (*x) = 0;
      if((*y)<y_max-1) (*y) = (*y) + 1;
      else {
        ret = 0;
        printf("Finish\n");
      } 
    }
  }
  return ret;
}