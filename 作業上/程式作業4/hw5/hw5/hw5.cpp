#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int search(char COLOR_CODES[][7], int arr, char input[]);  /*�]�ߨ禡:�j�M�C��*/
double Cal_Kilo_Ohms(int color_index[]);                   /*�]�ߨ禡:�p��q��*/             
int Again();                                         /*�]�ߨ禡:�O�_���ƿ�J*/                            

int main(void) {

	char input[3][100],   /*�]���ܼ�*/
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
		for (int i = 0; i < 3; i++) {/*��J*/
			printf("Band %d => ", i + 1);
			scanf("%s", input[i]);
			scanf("%c", &discard);          
		}

		for (int i = 0; i < 3; i++) {                                  /*�j�M�C��*/
			color_index[i] = search(COLOR_CODES, 10, input[i]);
			if (color_index[i] == -1) { /*������~*/
				printf("Invalid color: %s\n", input[i]);
				error = 1;
			}
		}

		if (!error) {                                        
			result_kilo_ohms = Cal_Kilo_Ohms(color_index);/*�p��q��*/
			printf("Resistance value: %.3lf kilo-ohms\n", result_kilo_ohms);
		}

		printf("Do you want to decode another resistor?\n=>");   
		again = Again();

	} while (again);



	return 0;
}

int search(char COLOR_CODES[][7], int arr, char input[]) {
	int char_index,match,i = arr - 1;                  /*�]���ܼ�:�}�C�޼ơB�O�_�t��B�}�C�̪���Ƽ�*/

	for (i; i >= 0; i--) {     /*�b��Ӱ}�C���j�M�O�_���ǰt��*/
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
	return i;                      /*�^�ǰt��쪺�}�C�޼�*/
}

double Cal_Kilo_Ohms(int color_index[]) {/*�̽ҥ������p��q��*/
	double result = (color_index[0] * 10 + color_index[1]) / 1000.0;            
	for (int i = 0; i < color_index[2]; i++) {
		result *= 10;
	}

	return result;         
}

int Again() {/*�T�{�O�_�n���s��J*/
	char reply,              
		discard = '\0';    
	int again,             
		error;               
	do {
		error = 0;               

		scanf("%c", &reply);     

		if (reply == 'y') {/*�Y��J��y�h�n*/
			again = 1;
		}
		else if (reply == 'n') {/*�Y��J��n�h�_*/
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