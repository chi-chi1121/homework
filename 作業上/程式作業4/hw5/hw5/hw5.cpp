#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int search(char COLOR_CODES[][7], int arr, char input[]);  /*設立函式:搜尋顏色*/
double Cal_Kilo_Ohms(int color_index[]);                   /*設立函式:計算電阻*/             
int Again();                                         /*設立函式:是否重複輸入*/                            

int main(void) {

	char input[3][100],   /*設立變數*/
		COLOR_CODES[10][7] = {          
	   "black",
	   "brown",
	   "red",
	   "orange",
	   "yellow",
	   "green",
	   "blue",
	   "violet",
	   "gray",
	   "white"
	};
	int color_index[3],                 
		error = 0,                      
		again;                           
	double result_kilo_ohms;             
	char discard;                        

	do {
		error = 0;              

		printf("Enter the colors of the resistor's three bands, beginning with the band nearest the end. Type the colors in lowercase letters only, NO CAPS.\n");
		for (int i = 0; i < 3; i++) {/*輸入*/
			printf("Band %d => ", i + 1);
			scanf("%s", input[i]);
			scanf("%c", &discard);          
		}

		for (int i = 0; i < 3; i++) {                                  /*搜尋顏色*/
			color_index[i] = search(COLOR_CODES, 10, input[i]);
			if (color_index[i] == -1) { /*檢驗錯誤*/
				printf("Invalid color: %s\n", input[i]);
				error = 1;
			}
		}

		if (!error) {                                        
			result_kilo_ohms = Cal_Kilo_Ohms(color_index);/*計算電阻*/
			printf("Resistance value: %.3lf kilo-ohms\n", result_kilo_ohms);
		}

		printf("Do you want to decode another resistor?\n=>");   
		again = Again();

	} while (again);



	return 0;
}

int search(char COLOR_CODES[][7], int arr, char input[]) {
	int char_index,match,i = arr - 1;                  /*設立變數:陣列引數、是否配對、陣列裡的資料數*/

	for (i; i >= 0; i--) {     /*在整個陣列中搜尋是否有匹配的*/
		match = 1;                          
		char_index = 0;                   

		do {                         
			if (COLOR_CODES[i][char_index] != input[char_index]) {      
				match = 0;
				break;
			}
			char_index++;              
		} while (COLOR_CODES[i][char_index - 1] != '\0');

		if (match == 1) {             
			break;
		}
	}
	return i;                      /*回傳配對到的陣列引數*/
}

double Cal_Kilo_Ohms(int color_index[]) {/*依課本公式計算電阻*/
	double result = (color_index[0] * 10 + color_index[1]) / 1000.0;            
	for (int i = 0; i < color_index[2]; i++) {
		result *= 10;
	}

	return result;         
}

int Again() {/*確認是否要重新輸入*/
	char reply,              
		discard = '\0';    
	int again,             
		error;               
	do {
		error = 0;               

		scanf("%c", &reply);     

		if (reply == 'y') {/*若輸入為y則要*/
			again = 1;
		}
		else if (reply == 'n') {/*若輸入為n則否*/
			again = 0;
		}
		else {
			printf("Invalid input, please input y or n\n=> ");         
			error = 1;
		}

		while (discard != '\n' && reply != '\n') {                    
			scanf("%c", &reply);
		}

	} while (error);

	return again;                 
}