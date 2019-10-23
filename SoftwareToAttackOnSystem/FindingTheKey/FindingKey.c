/*Finding the key to attack on the Ciphertext of letter to Templar*/

#include <stdio.h>
#include <string.h>


// function to interchange the position of two characters in string
void interchange(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

//function to permutate the input string
void cipher_Permutation(char *character, int startindex, int endindex)
{
   int i;
   if (startindex == endindex)
     printf("%s\t",character);
   else
   {
       for (i = startindex; i <= endindex; i++)
       {
          interchange((character+startindex), (character+i));
          cipher_Permutation(character, startindex+1, endindex);
          interchange((character+startindex), (character+i));
       }
   }
}

//main function
int main()
{
    char str[20];
    char pos[]="1234567"; //initial index of the block of seven characters
   printf("\nEnter the block of ciphertext:\t"); //
   scanf("%s", str);
   printf("\n *Program to get Permutations of a given cipher* :\n");
   printf("########################################################\n");
    int l = strlen(str);
    int p = strlen(pos);
    
//cipher permutation function is called to get various possible permutations of the index
    printf("\n\nThe various key combinations are: \n\n");
    cipher_Permutation(pos, 0, p-1);
    

/*cipher pernmutation program is called to get the various possible permutation of the
cipher block*/
    printf("\n\nThe permutations of the given cipher are : \n\n");
    cipher_Permutation(str, 0, l-1);
    getchar();
    return 0;
}


