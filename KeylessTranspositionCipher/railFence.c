#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void railFence(char*, char*, char*);
int row_num = 0, col_num = 0, size = 0, select = 0, cnt = 0, rail = 0;

int main(){
    char text[64], c_text[64], d_text[64];

wrong:
    printf("Encryption - 1, Decryption - 2 : ");
    scanf("%d", &select);

    if(select == 1) 
        printf("Enter plain text : ");
    else if(select == 2) 
        printf("Enter cipher text : ");
    else goto wrong;

    scanf("%s", text);
    size = strlen(text);
    
    printf("Number of rails : ");
    scanf("%d", &rail);

	railFence(text, c_text, d_text);
    return 0;
}

void railFence(char* text, char* c_text, char* d_text){
    if(select == 1){
    	int k = 0;
    	for(int i = 0; i < rail; i++){
    		if (i == 0 || i == rail - 1){
    			int j = i;
				while(j < size){
					c_text[k++] = text[j];
					j = j + 2*(rail - 1);
				}
			}
			
			else{
				int j = i, check = 0;
				while(j < size){
					if(!check){
						c_text[k++] = text[j];
						j = j + 2*(rail - i - 1);
					}
					else{
						c_text[k++] = text[j];
						j = j + 2*i;
					}
					check = !check;
				}
			}
		}
		c_text[size] = '\0';
		printf("Cipher : %s\n", c_text);
    }

	else if(select == 2){
    	int k = 0;
    	for(int i = 0; i < rail; i++){
    		if (i == 0 || i == rail - 1){
    			int j = i;
				while(j < size){
					d_text[j] = text[k++];
					j = j + 2*(rail - 1);
				}
			}
			
			else{
				int j = i, check = 0;
				while(j < size){
					if(!check){
						d_text[j] = text[k++];
						j = j + 2*(rail - i - 1);
					}
					else{
						d_text[j] = text[k++];
						j = j + 2*i;
					}
					check = !check;
				}
			}
		}
		d_text[size] = '\0';
		printf("Decipher : %s\n", d_text);
	}
}
