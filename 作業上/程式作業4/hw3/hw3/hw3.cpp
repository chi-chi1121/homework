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
	int candidate_votes[4] = { 0 }, winner_index = 0;/*砞ミ跑计:匡眔布计墓產ま计*/
	double candidate_percentage[4] = { 0 }, total_vote = 0;/*砞ミ跑计:匡眔布瞯羆布计*/
	char winner;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {/*璸衡布计*/
			total_vote += race_table[i][j];
			candidate_votes[j] += race_table[i][j];
		}
	}
	for (int i = 0; i < 4; i++) {/*璸衡眔布瞯*/
		candidate_percentage[i] = candidate_votes[i] / total_vote;
	}
	printf(" Precinct        Candidate A       Candidate B       Candidate C       Candidate D\n");/*酚Α块*/
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
	for (int i = 0; i < 4; i++) {/*璝眔布瞯>50玥钡蝴墓產*/
		if (candidate_percentage[i] > 50.0) {
			winner = 'A' + i;
			break;
		}
		winner = '0';
	}

	if (winner == '0') {/*璝礚眔布瞯>50*/
		winner = 'A';
		for (int i = 1; i < 4; i++) {/*ゑ耕眔布瞯*/
			printf("Candidate %c received votes: %d", winner, candidate_votes[winner_index]);
			printf("  V.S  ");
			printf("Candidate %c received votes: %d ", 'A' + i, candidate_votes[i]);
			printf(" >> ");
			if (candidate_votes[i] > candidate_votes[winner_index]) {
				winner_index = i;
				winner = 'A' + i;
			}
			printf("%c win\n", winner);/*块墓產*/
		}
		printf("\n");
	}
	printf("the winner is Candidate %c", winner);
	return 0;
}