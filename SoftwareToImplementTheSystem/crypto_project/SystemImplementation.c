/* SYSTEM IMPLEMENTATION FOR CONVERTING THE PLAINTEXT INTO CIPHERTEXT FOR  THE CIPHER GIVEN IN LETTER TO TEMPLAR*/

#include <stdio.h>
#include <stdlib.h>
void encryption(char str[], FILE *PTptr);
//main function

int main()
{
    char str[7];
    //Opening the plaintext file and reading from it
    FILE *fptr;
    char ch;
    fptr = fopen("//Users/prince/Desktop/crypto_project/crypto_project/plaintext.txt","r");
    if(fptr == NULL) {
        fprintf(stderr, "Cannot open plaintext file \n");
        exit(0);
    }
    
    //Opening the Ciphertext file
    FILE *PTptr;
       PTptr = fopen("/Users/prince/Desktop/crypto_project/crypto_project/ciphertext.txt","w");
       if(PTptr == NULL) {
           printf("Cannot open ciphertext file \n");
           exit(0);
       }
    
    // reading the seven character at a time from the plaintext file
    ch = fgetc(fptr);
    while(ch != EOF) {
    for(int i =0; i<7;i++) {
        str[i] = ch;
        if(ch != EOF) {
        ch = fgetc(fptr);
        }
    }
        //function call to encrypft the plaintext
        encryption(str, PTptr);
    }
    fclose(PTptr);
    return 0;
}


// Function to Encrypt the plaintext into ciphertext and storing that to text file
void encryption(char str[], FILE *PTptr) {
    printf("\n\nPlain Text: ");
    printf("%s\n",str);
    char plaintext[7];
    int key[7] = {7,5,3,1,4,2,6};
    for(int i =0; i<7; i++) {
        plaintext[key[i]-1] = str[i];
    }
    for(int i =0; i<7; i++) {
        fprintf(PTptr, "%c", plaintext[i]);
       }
        printf("Cipher Text:");
    for(int i= 0;i<7;i++){
      printf("%c",plaintext[i]);
    }
}

