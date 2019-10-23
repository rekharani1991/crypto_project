/* Program to remove the blank space from the plaintext*/

#include <stdio.h>
#include <stdlib.h>

//main function
int main(){
FILE *fplaintext,*fplaintext1;
char ch;
    //opening real plaintext file for reading data with spaces from it
fplaintext=fopen("/Users/prince/Desktop/crypto_project/crypto_project/real_plaintext.txt","r");
    //opening plaintext file to write data after removing the spaces
fplaintext1=fopen("/Users/prince/Desktop/crypto_project/crypto_project/plaintext.txt","w");
    
if(fplaintext==NULL)  {
printf("Error! File cannot be opened");
exit(0);
}
else  {
    //reading from file until end of file is reached
while((ch=fgetc(fplaintext))!=EOF)  {
if(ch==' '|| ch=='\n') {
}
else  {
fprintf(fplaintext1,"%c",ch);
}
}
}
    //closing the file
fclose(fplaintext);
return 0;
}

