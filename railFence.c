#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void railFence(char*, char*, char*, char**);
int row_num = 0, col_num = 0, size = 0, select = 0, cnt = 0, rail = 0;

int main(){
    char text[64], c_text[64], d_text[64];
    char **tmp_text;

wrong:
    printf("암호는 1번, 복호는 2번 선택 : ");
    scanf("%d", &select);

    if(select == 1) 
        printf("평문 입력 : ");
    else if(select == 2) 
        printf("암호문 입력 : ");
    else goto wrong;

    scanf("%s", text);
    size = strlen(text);
    
    printf("Rail의 수 : ");
    scanf("%d", &rail);
    tmp_text = (char**)malloc(sizeof(char*) * rail);
    for(int i = 0; i < rail; i++)
		tmp_text[i] = (char*)malloc(sizeof(char) * size + 1);

	railFence(text, c_text, d_text, tmp_text);
    return 0;
}

void railFence(char* text, char* c_text, char* d_text, char** tmp_text){
    if(select == 1){
        for(col_num  = 0; col_num < size; col_num++){
            if(((text[col_num] >= 'a') && (text[col_num] <= 'z')) ||
                ((text[col_num] >= 'A') && (text[col_num] <= 'Z'))){
                    for(int i = 0; i < rail; i++)
                        if(col_num % rail == i) 
                            tmp_text[i][col_num / rail] = text[col_num]; 
			}
			else ;
        }
		int adder, loc = 0, r = size % rail, q = size / rail;
        for(col_num = 0; col_num < (size / rail); col_num++){
			c_text[col_num] = tmp_text[0][col_num];
			loc = col_num;
			int temp = r;
            for(int j = 1; j < rail; j++){
				if((temp > 0)) adder = 1;
				else adder = 0;
                c_text[loc = loc + (size / rail) + adder] = tmp_text[j][col_num];
				--temp;
            }
		}
		loc = 0;
		for(int j = 0; j < size % rail; j++){
			c_text[loc = loc  + q] = tmp_text[j][col_num]; loc++;
		}
		c_text[size] = '\0';
		printf("암호문 : %s\n", c_text);
    }

	else if(select == 2){
        for(col_num  = 0; col_num < size / rail; col_num++){
            if(((text[col_num] >= 'a') && (text[col_num] <= 'z')) ||
                ((text[col_num] >= 'A') && (text[col_num] <= 'Z'))){
                    for(int i = 0; i < rail; i++)
                        if(col_num % rail == i) 
                        	text[col_num] = tmp_text[i][col_num / rail];
			}
			else ;
        }
		int adder, loc = 0, r = size % rail, q = size / rail;
        for(col_num = 0; col_num < (size / rail); col_num++){
			c_text[col_num] = tmp_text[0][col_num];
			loc = col_num;
			int temp = r;
            for(int j = 1; j < rail; j++){
				if((temp > 0)) adder = 1;
				else adder = 0;
                c_text[loc = loc + (size / rail) + adder] = tmp_text[j][col_num];
				--temp;
            }
		}
		loc = 0;
		for(int j = 0; j < size % rail; j++){
			c_text[loc = loc  + q] = tmp_text[j][col_num]; loc++;
		}
	}
}