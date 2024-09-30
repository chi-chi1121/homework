#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void fget_point_mass(FILE* input, int points[][3], int mass[], int* n);/*�]�ߨ禡:���o�I���q*/
void center_grav(const int points[][3], const int mass[], const int n, double center_gravity[]);/*�]�ߨ禡:���o�I���߭��O*/
void fwrite_point_mass(FILE* output, const int points[][3], const int mass[], const int n, const double cen_gravity[]);/*�]�ߨ禡:���q�g�J�ɮ�*/
int main(void) {

	int n = 0, point[10][3] = { 0 }, mass[10] = { 0 };/*�]���ܼ�:�I���ƶq�B�I�B���q*/
	double center_gravity[3];/*�]���ܼ�:���߭��O*/
	FILE* input = fopen("input.txt", "r"), * output = fopen("output.txt", "w");/*�}���ɮ�*/
	fget_point_mass(input, point, mass, &n);
	center_grav(point, mass, n, center_gravity);
	fwrite_point_mass(output, point, mass, n, center_gravity);
	fclose(input);
	fclose(output);
	return 0;
}

void fget_point_mass(FILE* input, int points[][3], int mass[], int* n) {

	fscanf(input, "%d", n);/*Ū���I���ƶq*/
	if (*n < 3 || *n >10) {/*�Yn�W�X�d��h�tn=-1*/
		*n = -1;
	}
	else {
		for (int i = 0; i < *n; i++) { /*Ū���ɮפ����I�򭫶q*/
			for (int j = 0; j < 3; j++) {
				fscanf(input, "%d", &points[i][j]);
			}
			fscanf(input, "%d", &mass[i]);
		}
	}
}

void center_grav(const int points[][3], const int mass[], const int n, double center_gravity[]) {
	double sum_x = 0, sum_y = 0, sum_z = 0, sum_mass = 0;/*�]���ܼ�:x���`�M�By���`�M�Bz���`�M�M���q�`�M*/
	for (int i = 0; i < n; i++) {/*�p��U���`�M*/
		sum_x += mass[i] * points[i][0];
		sum_y += mass[i] * points[i][1];
		sum_z += mass[i] * points[i][2];
		sum_mass += mass[i];
	}
	center_gravity[0] = sum_x / sum_mass;/*�p��U��V�����O*/
	center_gravity[1] = sum_y / sum_mass;
	center_gravity[2] = sum_z / sum_mass;
}

void fwrite_point_mass(FILE* output, const int points[][3], const int mass[], const int n, const double cen_gravity[]) {
	fprintf(output, "location   ");/*�N�p��X�����O���D�خ榡��X���ɮ�*/
	for (int i = 0; i < n; i++) {
		if (i != 0) {
			if (points[i][0] < 0) {
				fprintf(output, "          ");
			}
			else {
				fprintf(output, "           ");
			}
		}
		for (int j = 0; j < 3; j++) {
			fprintf(output, " %d", points[i][j]);
			if (points[i][j + 1] < 0) {
				fprintf(output, "    ");
			}
			else {
				fprintf(output, "     ");
			}
		}
		fprintf(output, "\n");
	}

	fprintf(output, "mass    ");
	for (int i = 0; i < n; i++) {
		if (i != 0) {
			fprintf(output, "        ");
		}
		fprintf(output, "%d\n", mass[i]);
	}
	fprintf(output, "n");
	fprintf(output, "       %d\n", n);

	fprintf(output, "center of gravity  %.2f  %.2f  %.2f", cen_gravity[0], cen_gravity[1], cen_gravity[2]);
}