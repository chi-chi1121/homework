#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void fget_point_mass(FILE* input, int points[][3], int mass[], int* n);/*設立函式:取得點重量*/
void center_grav(const int points[][3], const int mass[], const int n, double center_gravity[]);/*設立函式:取得點中心重力*/
void fwrite_point_mass(FILE* output, const int points[][3], const int mass[], const int n, const double cen_gravity[]);/*設立函式:重量寫入檔案*/
int main(void) {

	int n = 0, point[10][3] = { 0 }, mass[10] = { 0 };/*設立變數:點的數量、點、重量*/
	double center_gravity[3];/*設立變數:中心重力*/
	FILE* input = fopen("input.txt", "r"), * output = fopen("output.txt", "w");/*開啟檔案*/
	fget_point_mass(input, point, mass, &n);
	center_grav(point, mass, n, center_gravity);
	fwrite_point_mass(output, point, mass, n, center_gravity);
	fclose(input);
	fclose(output);
	return 0;
}

void fget_point_mass(FILE* input, int points[][3], int mass[], int* n) {

	fscanf(input, "%d", n);/*讀取點的數量*/
	if (*n < 3 || *n >10) {/*若n超出範圍則另n=-1*/
		*n = -1;
	}
	else {
		for (int i = 0; i < *n; i++) { /*讀取檔案中的點跟重量*/
			for (int j = 0; j < 3; j++) {
				fscanf(input, "%d", &points[i][j]);
			}
			fscanf(input, "%d", &mass[i]);
		}
	}
}

void center_grav(const int points[][3], const int mass[], const int n, double center_gravity[]) {
	double sum_x = 0, sum_y = 0, sum_z = 0, sum_mass = 0;/*設立變數:x的總和、y的總和、z的總和和重量總和*/
	for (int i = 0; i < n; i++) {/*計算各個總和*/
		sum_x += mass[i] * points[i][0];
		sum_y += mass[i] * points[i][1];
		sum_z += mass[i] * points[i][2];
		sum_mass += mass[i];
	}
	center_gravity[0] = sum_x / sum_mass;/*計算各方向的重力*/
	center_gravity[1] = sum_y / sum_mass;
	center_gravity[2] = sum_z / sum_mass;
}

void fwrite_point_mass(FILE* output, const int points[][3], const int mass[], const int n, const double cen_gravity[]) {
	fprintf(output, "location   ");/*將計算出的重力依題目格式輸出至檔案*/
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