#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<ctype.h>
enum state { start, stop, build_num, number, build_id, identifier, build_float, float_num, build_sign, othersign };/*�]�ߦC�|�ܼ�:���A*/
enum state transition(enum state, char);/*�]�ߨ禡*/
int main()
{
	enum state cur_state = start;/*�O�{�b���A��start*/
	char input;/*�]���ܼ�:��J*/
	while (cur_state != stop) {/*�j��A�Y���A��stop�h����*/

		if (cur_state == start) {/*�Y���A���}�l*/
			scanf("%c", &input);/*��J*/
			cur_state = transition(cur_state, input);/*���ܪ��A*/
		}

		if (cur_state != stop) {
			printf("%c", input);/*��X*/
		}

		while (cur_state == build_num) {/*���A��build_num�ɰ���*/
			scanf("%c", &input);/*��J*/
			printf("%c", input);/*��X*/
			cur_state = transition(cur_state, input);/*���ܪ��A*/
		}

		while (cur_state == build_float) {/*���A��build_float�ɰ���*/
			scanf("%c", &input);/*��J*/
			printf("%c", input);/*��X*/
			cur_state = transition(cur_state, input);/*���ܪ��A*/
		}

		while (cur_state == build_id) {/*���A��build_id�ɰ���*/
			scanf("%c", &input);/*��J*/
			printf("%c", input);/*��X*/
			cur_state = transition(cur_state, input);/*���ܪ��A*/
		}
		while (cur_state == build_sign) {/*���A��build_sign�ɰ���*/
			scanf("%c", &input);/*��J*/
			printf("%c", input);/*��X*/
			cur_state = transition(cur_state, input);/*���ܪ��A*/
		}
		if (cur_state == identifier) {/*�p�G���A��identifier*/
			printf(" - Identifie\n");/*��X*/
			cur_state = transition(cur_state, input);/*���ܪ��A*/
		}

		if (cur_state == number) {/*�p�G���A��number*/
			printf(" - Number\n");/*��X*/
			cur_state = transition(cur_state, input);/*���ܪ��A*/
		}

		if (cur_state == float_num) {/*�p�G���A��float_num*/
			printf(" - Floating number\n");/*��X*/
			cur_state = transition(cur_state, input);/*���ܪ��A*/
		}

		if (cur_state == othersign) {/*�p�G���A��float_num*/
			printf(" - Operational sign\n");/*��X*/
			cur_state = transition(cur_state, input);/*���ܪ��A*/
		}

	}
	return 0;
}
enum state transition(enum state cur_state, char input) {/*���ܪ��A���禡*/

	if (cur_state == start) {/*�Y���A��start*/
		if (input == ' ') {/*�Y��J���Ů�*/
			return start;/*�^��start*/
		}
		if (isalpha(input)) {/*�Y��J���r��*/
			return build_id;/*�^��build_id*/
		}
		else if (isdigit(input)) {/*�Y��J���Ʀr*/
			return build_num;/*�^��build_num*/
		}
		else if (input == '.') {/*�Y��J��.*/
			return stop;/*�^��stop*/
		}
		else {/*�Y��J���ҫD�W�z��*/
			return build_sign;/*�^��build_sign*/
		}
	}

	if (cur_state == build_id) {/*�Y���A��build_id*/
		if (isalpha(input)) {/*�Y��J���r��*/
			return build_id;/*�^��build_id*/
		}
		if (isdigit(input)) {/*�Y��J���Ʀr*/
			return build_id;/*�^��build_id*/
		}
		if (input == ' ') {/*�Y��J��' '*/
			return identifier;/*�^��identifier*/
		}
	}

	if (cur_state == build_num) {/*�Y���A��*/
		if (isalpha(input)) {/*�Y��J���r��*/
			return build_num;/*�^��build_num*/
		}
		if (isdigit(input)) {/*�Y��J���Ʀr*/
			return build_num;/*�^��build_num*/
		}
		if (input == '.') {/*�Y��J��.*/
			return build_float;/*�^��build_float*/
		}
		if (input == ' ') {/*�Y��J��' '*/
			return number;/*�^��number*/
		}
	}

	if (cur_state == build_sign) {/*�Y���A��build_sign*/
		if (!isalpha(input) && !isdigit(input) && input != ' '&&input != '.') {/*�Y��J�D�r���B�Ʀr�B�Ů�M.*/
			return build_sign;/*�^��build_sign;*/
		}
		if (input == ' ') {/*�Y��J��' '*/
			return othersign;/*�^��othersign*/
		}
	}

	if (cur_state == build_float) {
		if (isdigit(input)) {/*�Y��J���Ʀr*/
			return build_float;/*�^��build_float*/
		}
		if (input == ' ') {/*�Y��J��' '*/
			return float_num;/*�^��float_num*/
		}
	}

	if (cur_state == identifier || cur_state == number || cur_state == float_num || cur_state == othersign) {/*�Y���A��identifier��number�� float_num��othersign*/
		return start;/*�^��start*/
	}
}