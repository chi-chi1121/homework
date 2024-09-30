#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LENGTH_OF_LIST 4  

typedef struct {                
	unsigned int  addr_first;    
	unsigned int addr_second;    
	unsigned int  addr_third;    
	unsigned int addr_fourth;   
	char nickname[11];           /*設立一個結構*/
} address_t;

void initial(address_t list_of_address[], int num_of_addr);        // 初始化結構
int is_the_end_of_addr(address_t* list_of_address);                //檢測是否結束
int scan_address(address_t list_of_address[], FILE* faddress);     // 檢測輸入
void print_address(address_t list_of_address[]);                   //輸出地址
int local_address(address_t* addres1, address_t* addres2);         // 比較地址

int main(void) {

	address_t list_of_address[LENGTH_OF_LIST]{};                
	FILE* faddress;                                             
	int num_of_addr;                                           

	faddress = fopen("LISTOFADDR.txt", "r");                    
	if (!faddress) {
		printf("ERROR::FAILED TO OPEN LISTOFADDR.txt");
		fclose(faddress);
		return -1;
	}

	initial(list_of_address, LENGTH_OF_LIST);                   

	num_of_addr = scan_address(list_of_address, faddress);      

	if (num_of_addr == -1) {
		printf("There are too much address in the LISTOFADDR.txt file");      
	}
	else {
		print_address(list_of_address);                          
		printf("\n\n");

		for (int i = 0; i < num_of_addr - 1; ++i) {              
			for (int j = i + 1; j < num_of_addr; ++j) {
				if (local_address(&list_of_address[i], &list_of_address[j])) {
					printf("Machines %s and %s are on the same local network.\n", list_of_address[i].nickname, list_of_address[j].nickname);
				}
			}
		}
	}



	fclose(faddress);
	system("pause");
	return 0;
}

void initial(address_t list_of_address[], int num_of_addr) {/*初始化結構*/
	for (int i = 0; i < num_of_addr; ++i) {
		list_of_address[i].addr_first = 1;       
		list_of_address[i].addr_second = 0;
		list_of_address[i].addr_third = 0;
		list_of_address[i].addr_fourth = 0;
		list_of_address[i].nickname[0] = '\0';
	}
}

int is_the_end_of_addr(address_t* list_of_address) {
	int is_the_end = 0;
	if (list_of_address->addr_first +
		list_of_address->addr_second +
		list_of_address->addr_third +
		list_of_address->addr_fourth == 0
		&&
		strcmp(list_of_address->nickname, "none") == 0) {      // 如果遇到none則結束

		is_the_end = 1;
	}

	return is_the_end;
}

int scan_address(address_t list_of_address[], FILE* faddress) {
	char point_discard;
	int addr_counter = 0;

	do {
		if (addr_counter == LENGTH_OF_LIST) {
			addr_counter = 0;
			break;
		}
		fscanf(faddress, "%d", &list_of_address[addr_counter].addr_first);
		fscanf(faddress, "%c", &point_discard);
		fscanf(faddress, "%d", &list_of_address[addr_counter].addr_second);
		fscanf(faddress, "%c", &point_discard);
		fscanf(faddress, "%d", &list_of_address[addr_counter].addr_third);
		fscanf(faddress, "%c", &point_discard);
		fscanf(faddress, "%d", &list_of_address[addr_counter].addr_fourth);
		fscanf(faddress, "%s", list_of_address[addr_counter].nickname);
	} while (!is_the_end_of_addr(&list_of_address[addr_counter++]));

	return addr_counter - 1;
}

void print_address(address_t list_of_address[]) {
	int addr_index = 0;

	while (!is_the_end_of_addr(&list_of_address[addr_index])) {
		printf("%d.%d.%d.%d\t\t  %s\n", list_of_address[addr_index].addr_first,
			list_of_address[addr_index].addr_second,
			list_of_address[addr_index].addr_third,
			list_of_address[addr_index].addr_fourth,
			list_of_address[addr_index].nickname);

		++addr_index;
	}
}

int local_address(address_t* addres1, address_t* addres2) {
	int islocal = 0;

	if (addres1->addr_first == addres2->addr_first && addres1->addr_second == addres2->addr_second) {
		islocal = 1;
	}

	return islocal;
}