#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
int main(void) {
	char bat;/*�]���ܼ�:�O�_����*/
	int i, j = 0, num, n = 17;/*�]���ܼ�:����j���ܼơB�y���s���B���j��W��*/
	double rate, hit, all;/*�]���ܼ�:�����v�B�������ơB�����򴧴θ��Ŧ���*/

	for (i = 0; i < 3; i++) {/*�@��J�T���A�ҥH�i��T���j��*/
		hit = 0;/*��l�ƥ������ơB�����򴧴θ��Ŧ���*/
		all = 0;
		scanf("%d", &num);/*��J�y���s��*/
		printf("Player %d's record:", num);
		if (i > 0) {/*�ĤG���j��}�l��J�o�ƾڬ�15���A���]�ݥ[�Ů�ҥH��16*/
			n = 16;
		}
		for (j = 0; j < n; j++) {
			scanf("%c", &bat);/*��J��������*/
			printf("%c", bat);

			if (bat == 'H') {/*�Y��H�h�������ơB�����򴧴θ��Ŧ���+1*/
				hit += 1;
				all += 1;
			}

			else if (bat == 'O') {/*�Y��O�h�����򴧴θ��Ŧ���+1*/
				all += 1;
			}
		}
		rate = hit / all;/*�p�⥴����v*/
		printf("\nPlayer %d's batting average: %.3f\n", num, rate);/*��X*/
	}
	return(0);
}