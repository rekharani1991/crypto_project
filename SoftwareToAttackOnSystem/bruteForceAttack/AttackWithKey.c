/* Brute force attack on the letter ot templar ciphertext*/

#include <stdio.h>
#include <stdlib.h>

void decrypt(char str[], FILE *PTptr);

int main() {
    char str[7];
    //Read ciphertext file
    FILE *fptr;
    char ch;
    fptr = fopen("/Users/prince/Desktop/crypto_project/bruteForceAttack/ciphertext.txt","r");
    if(fptr == NULL) {
        fprintf(stderr, "Error! Cannot open ciphertext file \n");
        exit(0);
    }
    // opening the plaintext file in which data would be written after applying the key
    FILE *PTptr;
       PTptr = fopen("/Users/prince/Desktop/crypto_project/bruteForceAttack/plaintext.txt","w");
       if(PTptr == NULL) {
           printf("Error! Cannot open plaintext file \n");
           exit(0);
       }
    
    ch = fgetc(fptr);
    // seven character of data are read from the ciphertext file at a time
    while(ch != EOF) {
    for(int i =0; i<7;i++) {
        str[i] = ch;
        if(ch != EOF) {
        ch = fgetc(fptr);
        }
    }
        decrypt(str, PTptr); // decrypt function call
    }
    fclose(PTptr);
    return 0;    
}

// function to decrypt the ciphertext into plaintext and storing that in text file
void decrypt(char str[], FILE *PTptr) {
    printf("\n\nCipher Text:");
    printf("%s\n",str);
    char plaintext[7];
    int key[7] = {5,3,6,7,2,4,1};
    for(int i =0; i<7; i++) {
        plaintext[key[i]-1] = str[i];
    }
    
    
for(int i =0; i<7; i++) {
    fprintf(PTptr, "%c", plaintext[i]);
    }
    printf("Plain Text:\t");
    for(int i= 0;i<7;i++){
    printf("%c",plaintext[i]);
    }
}


