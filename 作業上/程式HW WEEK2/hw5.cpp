#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
bool within_x_percent(double ref, double data);/*;�]�ߤ@�Ө禡�^�ǿ�J���Ʀr�O�_�b�D�حn�D���϶�*/
int main(void) {
	double ref, data;/*�]���ܼƿ�J�ūשM�зǪm�I*/
	int i = 1; /*�]���ܼƨӱ���swich*/
	scanf("%lf", &ref);/*��J�ū�*/
	switch (i)/*��swich�Ӥ������P�m�I��case*/
	{	case 1:
			data = 100;/*�O�зǪm�I=�Ӫ��骺�m�I*/
			if (within_x_percent(ref,data) ){/*�Q�α��󦡧P�_�O�_�ŦX�ԭz*/
				printf("Water");
				break;
			}
			i++;
		case 2:
			data = 357;/*�O�зǪm�I=�Ӫ��骺�m�I*/
			if (within_x_percent(ref, data)) {/*�Q�α��󦡧P�_�O�_�ŦX�ԭz*/
				printf("Mercury");/*��X����*/
				break;	
			}
			i++;
		case 3:
			data = 1187;/*�O�зǪm�I=�Ӫ��骺�m�I*/
			if (within_x_percent(ref, data)) {/*�Q�α��󦡧P�_�O�_�ŦX�ԭz*/
				printf("Copper");/*��X����*/
				break;
			}
			i++;
		case 4:
			data = 2193;/*�O�зǪm�I=�Ӫ��骺�m�I*/
			if (within_x_percent(ref, data)) {/*�Q�α��󦡧P�_�O�_�ŦX�ԭz*/
				printf("Silver");/*��X����*/
				break;
			}
			i++;
		case 5:
			data = 2660;/*�O�зǪm�I=�Ӫ��骺�m�I*/
			if (within_x_percent(ref, data)) {/*�Q�α��󦡧P�_�O�_�ŦX�ԭz*/
				printf("Gold");/*��X����*/
				break;
			}
		default:
			printf("Substance unknown");/*��X����*/
			break;
	}
	return(0);
}
bool  within_x_percent(double ref, double data) {
	if (ref - ref * 5 / 100 <= data && ref + ref * 5 / 100 >= data) {/*�p���J�ū׬O�_�b�m�I�����t5%��*/
		return true;
	}
	else
	{
		return false;
	}
	
}