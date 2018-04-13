#include <stdio.h>
#include <string.h>

void gronsfeld(char* , char*, int, int, int);

int main(){
    int Key_Size = 0, str_size = 0, select = 1;
    char str[50] = {0, }, key[16] = {0, };

    printf("Enter plain text or Cipher text: ");
    scanf("%s", str);
wrong:
    printf("1 - Encryption 2 - Decryption\nChoose the work : ");
    scanf("%d", &select);
    if(select == 1 || select == 2) ;
    else goto wrong;
    fflush(stdin);
    printf("Enter the Key : ");
    scanf("%s", key);
    
    str_size = strlen(str);
    Key_Size = strlen(key);

    gronsfeld(str, key, str_size, Key_Size, select);
    printf("\n");
    if(select == 1) printf("Encrypted Key: %s", str);
    if(select == 2) printf("Decrypted Key: %s", str);
    
    return 0;
}

void gronsfeld(char* str, char* key, int str_size, int Key_Size, int select){
    int i, j, temp;

    for(i = 0,j = 0; i < str_size; i++, j++){
        j = i % Key_Size;

        int isUcharacter = ((str[i] >= 'a') && (str[i] <= 'z'));
        int isLcharacter = ((str[i] >= 'A') && (str[i] <= 'Z'));
        int isnumber = ((str[i] >= '0') && (str[i] <= '9'));

        if(select == 1){
            if(isUcharacter || isLcharacter || isnumber) {
               if(isUcharacter) str[i] -= 'a'; 
               else if(isLcharacter) str[i] -= 'A'; 
               else if(isnumber) str[i] -= '0';
                temp = key[j] - '0';
                while(str[i] + temp < 0) {
                    str[i] += 26;
                }

               str[i] = (str[i] + temp) % 26;
               if(isUcharacter) str[i] += 'a'; 
               else if(isLcharacter) str[i] += 'A';
               else if(isnumber) str[i] += '0';
            }
        }

        else if(select == 2){
            if(isUcharacter || isLcharacter || isnumber){
                if(isUcharacter) str[i] -= 'a'; 
                else if(isLcharacter) str[i] -= 'A'; 
                else if(isnumber) str[i] -= '0';
                temp = key[j] - '0';
                while(str[i] - temp < 0) str[i] += 26;
                str[i] = (str[i] - temp) % 26;
                if(isUcharacter) str[i] += 'a'; 
                else if(isLcharacter) str[i] += 'A'; 
                else if(isnumber) str[i] += '0';
            }
        }
        else ;
    }
}