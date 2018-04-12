#include <stdio.h>
#include <string.h>

void affine_Cipher(char *str, int size, int key1, int key2, int choice){
    int i;
    
    for(int i = 0; i < size; i++){
        if((str[i] >= 'A') && (str[i] <= 'Z')){
            str[i] -= 'A';
            if(choice == 1){
                if((str[i]*key1 + key2) < 0)
                    str[i] += 26;           
                str[i] = (str[i]*key1 + key2) % 26;
            }
            else if(choice == 2){
                if((str[i] - key2) / key1 < 0)
                    str[i] += 26;
                str[i] = ((str[i] - key2) / key1) % 26;
            }
            str[i] += 'A';
        }
        else if((str[i] >= 'a') && (str[i] <= 'z')){
            str[i] -= 'a';
            if(choice == 1){
                if((str[i]*key1 + key2) < 0)
                    str[i] += 26;           
                str[i] = (str[i]*key1 + key2) % 26;
            }
            else if(choice == 2){
                if((str[i] - key2) / key1 < 0)
                    str[i] += 26;
                str[i] = ((str[i] - key2) / key1) % 26;
            }
            str[i] += 'a';
        }
        else ;
    }
}

int main(){
    int i = 0, key1 = 0, key2 = 0, str_size = 0, choice = 0;
    char str[50] = {0, };

    printf("평문 또는 암호문을 입력하시오: ");
    scanf("%s", str);

wrong:
    printf("암호는 1번, 복호는 2번: ");
    scanf("%d", &choice);
    if(choice == 1 || choice == 2) ;
    else goto wrong;

    printf("키1 값을 입력하시오: ");
    scanf("%d", &key1);

    printf("키2 값을 입력하시오: ");
    scanf("%d", &key2);

    str_size = strlen(str);

    affine_Cipher(str, str_size, key1, key2, choice);

    printf("\n암호화 또는 복호화된 결과 출력: ");
    puts(str);

    return 0;
}