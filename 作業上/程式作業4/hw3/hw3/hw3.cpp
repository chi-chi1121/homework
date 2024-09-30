#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {

	int race_table[5][4] = {
		/*Precinct*/   /*Candidate A*/   /*Candidate B*/   /*Candidate C*/   /*Candidate D*/
		/* 1 */    {        192,              48,              206,               37         },
		/* 2 */    {        147,              90,              312,               21         },
		/* 3 */    {        186,              12,              121,               38         },
		/* 4 */    {        114,              21,              108,               39         },
		/* 5 */    {        267,              13,              382,               29         }, };
	int candidate_votes[4] = { 0 }, winner_index = 0;/*�]���ܼ�:�Կ�H�o���ơBĹ�a���޼�*/
	double candidate_percentage[4] = { 0 }, total_vote = 0;/*�]���ܼ�:�Կ�H�o���v�B�`����*/
	char winner;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {/*�p�Ⲽ��*/
			total_vote += race_table[i][j];
			candidate_votes[j] += race_table[i][j];
		}
	}
	for (int i = 0; i < 4; i++) {/*�p��o���v*/
		candidate_percentage[i] = candidate_votes[i] / total_vote;
	}
	printf(" Precinct        Candidate A       Candidate B       Candidate C       Candidate D\n");/*�Ӯ榡��X*/
	for (int i = 0; i < 5; i++) {
		printf("    %d", i + 1);

		for (int j = 0; j < 4; j++) {
			printf("               ");
			printf("%d", race_table[i][j]);
		}
		printf("\n");
	}
	printf("Total received\nvotes    ");
	for (int i = 0; i < 4; i++) {
		printf("          ");
		printf("%d(%.0f%%)", candidate_votes[i], candidate_percentage[i] * 100);
	}
	printf("\n");

	printf("\n");
	for (int i = 0; i < 4; i++) {/*�Y�o���v>50�h������Ĺ�a*/
		if (candidate_percentage[i] > 50.0) {
			winner = 'A' + i;
			break;
		}
		winner = '0';
	}

	if (winner == '0') {/*�Y�L�H�o���v>50*/
		winner = 'A';
		for (int i = 1; i < 4; i++) {/*�ǭǤ���o���v*/
			printf("Candidate %c received votes: %d", winner, candidate_votes[winner_index]);
			printf("  V.S  ");
			printf("Candidate %c received votes: %d ", 'A' + i, candidate_votes[i]);
			printf(" >> ");
			if (candidate_votes[i] > candidate_votes[winner_index]) {
				winner_index = i;
				winner = 'A' + i;
			}
			printf("%c win\n", winner);/*��XĹ�a*/
		}
		printf("\n");
	}
	printf("the winner is Candidate %c", winner);
	return 0;
}