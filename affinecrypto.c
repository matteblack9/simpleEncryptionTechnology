#include <stdio.h>
#include <string.h>

void affine_Cipher(char *, int , int , int , int);

int main(){
    int i = 0, key1 = 0, key2 = 0, str_size = 0, choice = 0;
    char str[50] = {0, };

    printf("Enter plain text or Cipher text: ");
    scanf("%s", str);

wrong:
    printf("1 - Encryption 2 - Decryption\nChoose the work : ");
    scanf("%d", &choice);
    if(choice == 1 || choice == 2) ;
    else goto wrong;

    printf("Enter the value of KEY1: ");
    scanf("%d", &key1);

    printf("Enter the value of KEY2: ");
    scanf("%d", &key2);

    str_size = strlen(str);

    affine_Cipher(str, str_size, key1, key2, choice);

    printf("\nDecrypted Text or Encrypted Text: ");
    puts(str);

    return 0;
}

void affine_Cipher(char *str, int size, int key1, int key2, int choice){
    int i;
    
    for(int i = 0; i < size; i++){
        int upper = (str[i] >= 'A') && (str[i] <= 'Z');
        int lower = (str[i] >= 'a') && (str[i] <= 'z');
        int number = (str[i] >= '0') && (str[i] <= '9');

        if(upper || lower || number){
            if(upper) str[i] -= 'A';
            else if(lower) str[i] -= 'a';
            else if(number) str[i] -= '0';

            if(choice == 1){
                if((str[i]*key1 + key2) < 0){
                    if(upper || lower)
                        str[i] += 26;
                    else if(number)
                        str[i] += 10;           
                }
                if(upper || lower)
                    str[i] = (str[i]*key1 + key2) % 26;
                else if(number)
                    str[i] = (str[i]*key1 + key2) % 10;  
            }
            else if(choice == 2){
                int temp = str[i] - key2;
                while(temp % key1 != 0 || temp < 0){
                    if(upper || lower)
                        temp += 26;
                    else if(number)
                        temp += 10; 
                }
                if(upper || lower)
                    str[i] = (temp / key1) % 26;
                else if(number)
                    str[i] = (temp / key1) % 10;  
            }
            if(upper) str[i] += 'A';
            else if(lower) str[i] += 'a';
            else if(number) str[i] += '0';
        }
        else ;
    }
}