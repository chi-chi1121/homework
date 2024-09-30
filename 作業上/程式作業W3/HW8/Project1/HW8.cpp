#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<ctype.h>
enum state { start, stop, build_num, number, build_id, identifier, build_float, float_num, build_sign, othersign };/*設立列舉變數:狀態*/
enum state transition(enum state, char);/*設立函式*/
int main()
{
	enum state cur_state = start;/*令現在狀態為start*/
	char input;/*設立變數:輸入*/
	while (cur_state != stop) {/*迴圈，若狀態為stop則停止*/

		if (cur_state == start) {/*若狀態為開始*/
			scanf("%c", &input);/*輸入*/
			cur_state = transition(cur_state, input);/*改變狀態*/
		}

		if (cur_state != stop) {
			printf("%c", input);/*輸出*/
		}

		while (cur_state == build_num) {/*狀態為build_num時執行*/
			scanf("%c", &input);/*輸入*/
			printf("%c", input);/*輸出*/
			cur_state = transition(cur_state, input);/*改變狀態*/
		}

		while (cur_state == build_float) {/*狀態為build_float時執行*/
			scanf("%c", &input);/*輸入*/
			printf("%c", input);/*輸出*/
			cur_state = transition(cur_state, input);/*改變狀態*/
		}

		while (cur_state == build_id) {/*狀態為build_id時執行*/
			scanf("%c", &input);/*輸入*/
			printf("%c", input);/*輸出*/
			cur_state = transition(cur_state, input);/*改變狀態*/
		}
		while (cur_state == build_sign) {/*狀態為build_sign時執行*/
			scanf("%c", &input);/*輸入*/
			printf("%c", input);/*輸出*/
			cur_state = transition(cur_state, input);/*改變狀態*/
		}
		if (cur_state == identifier) {/*如果狀態為identifier*/
			printf(" - Identifie\n");/*輸出*/
			cur_state = transition(cur_state, input);/*改變狀態*/
		}

		if (cur_state == number) {/*如果狀態為number*/
			printf(" - Number\n");/*輸出*/
			cur_state = transition(cur_state, input);/*改變狀態*/
		}

		if (cur_state == float_num) {/*如果狀態為float_num*/
			printf(" - Floating number\n");/*輸出*/
			cur_state = transition(cur_state, input);/*改變狀態*/
		}

		if (cur_state == othersign) {/*如果狀態為float_num*/
			printf(" - Operational sign\n");/*輸出*/
			cur_state = transition(cur_state, input);/*改變狀態*/
		}

	}
	return 0;
}
enum state transition(enum state cur_state, char input) {/*改變狀態的函式*/

	if (cur_state == start) {/*若狀態為start*/
		if (input == ' ') {/*若輸入為空格*/
			return start;/*回傳start*/
		}
		if (isalpha(input)) {/*若輸入為字母*/
			return build_id;/*回傳build_id*/
		}
		else if (isdigit(input)) {/*若輸入為數字*/
			return build_num;/*回傳build_num*/
		}
		else if (input == '.') {/*若輸入為.*/
			return stop;/*回傳stop*/
		}
		else {/*若輸入的皆非上述的*/
			return build_sign;/*回傳build_sign*/
		}
	}

	if (cur_state == build_id) {/*若狀態為build_id*/
		if (isalpha(input)) {/*若輸入為字母*/
			return build_id;/*回傳build_id*/
		}
		if (isdigit(input)) {/*若輸入為數字*/
			return build_id;/*回傳build_id*/
		}
		if (input == ' ') {/*若輸入為' '*/
			return identifier;/*回傳identifier*/
		}
	}

	if (cur_state == build_num) {/*若狀態為*/
		if (isalpha(input)) {/*若輸入為字母*/
			return build_num;/*回傳build_num*/
		}
		if (isdigit(input)) {/*若輸入為數字*/
			return build_num;/*回傳build_num*/
		}
		if (input == '.') {/*若輸入為.*/
			return build_float;/*回傳build_float*/
		}
		if (input == ' ') {/*若輸入為' '*/
			return number;/*回傳number*/
		}
	}

	if (cur_state == build_sign) {/*若狀態為build_sign*/
		if (!isalpha(input) && !isdigit(input) && input != ' '&&input != '.') {/*若輸入非字母、數字、空格和.*/
			return build_sign;/*回傳build_sign;*/
		}
		if (input == ' ') {/*若輸入為' '*/
			return othersign;/*回傳othersign*/
		}
	}

	if (cur_state == build_float) {
		if (isdigit(input)) {/*若輸入為數字*/
			return build_float;/*回傳build_float*/
		}
		if (input == ' ') {/*若輸入為' '*/
			return float_num;/*回傳float_num*/
		}
	}

	if (cur_state == identifier || cur_state == number || cur_state == float_num || cur_state == othersign) {/*若狀態為identifier或number或 float_num或othersign*/
		return start;/*回傳start*/
	}
}