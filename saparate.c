#include <stdio.h>
#include <math.h>


int main(int test){
  int ipChar_d, header_indx, x_poz, y_poz, byte_no, i, bit_no, msg_int, LSB;
  int x_max = 128, y_max = 128, n_max = 3, saparation_process = 1, file_complete = 0;
  char char_c, msg_char;

  FILE *msgFile;
  FILE *inputFile;

  msgFile = fopen("sample_new.txt", "a+");
  inputFile = fopen("black_enc.bmp", "r");

  // Header Copy
  i = 0;
  while(i < 54) {
    ipChar_d = fgetc(inputFile);
    char_c = ipChar_d;
    i++;
  }

  // Image Pixels Coping
  for (x_poz = 0, y_poz = 0, byte_no = 0, bit_no = 0, msg_int = 0; saparation_process;) {
    /* code */
    ipChar_d = fgetc(inputFile);

    // Saparation process
    LSB = ipChar_d % 2;
    msg_int += LSB * pow(2, bit_no);

    if(bit_no < 7) bit_no++;
    else bit_no = 0;

    if(bit_no==0) { 
      printf(" - %d", msg_int);
      // if(msg_int > 127) msg_int -= 256;
      msg_char = msg_int;
      msg_int = 0;
      if(msg_char==EOF) saparation_process = 0;
      else fputc(msg_char, msgFile); 
      printf("\n[  >> %c <<  ]\n\n", msg_char);
    }

  }

  fclose(msgFile);
  fclose(inputFile);
  return 0;
}