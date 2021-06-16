#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX 5

typedef struct Coordinate {
	int x, y;
} COORD_t[1], *COORD;

typedef struct Location {
	int label;
	double area;
	COORD coord;
} LOC_t[1], *LOC;

LOC init_location() {
	LOC l = malloc(sizeof(LOC_t));
	l->label = -1;
	l->area = 0.0;

	return l;
}

LOC **init_location_arr(int size) {
	LOC **new_arr;
	int i, j;

	new_arr = malloc(sizeof(LOC) * size);
	for (i = 0; i < size; ++i) {
		new_arr[i] = malloc(sizeof(LOC));
		for (j = 0; j < 3; ++j) {
			new_arr[i][j] = init_location();
		}
	}

	return new_arr;
}

COORD init_cordination() {
	return malloc(sizeof(COORD_t));
}

void free_triangles(LOC **loc_arr, int N) {
	int i;
	while (N) {
		for (i = 0; i < 2; i++)
			free(loc_arr[N][i]);
		N--;
	}
	free(loc_arr);
}

void print_triangles(LOC *arr) {
	printf("---Triangle (%d %d %d)---\n", arr[0]->label, arr[1]->label, arr[2]->label);
	printf("%d %d, ", arr[0]->coord->x, arr[0]->coord->y);
	printf("%d %d, ", arr[1]->coord->x, arr[1]->coord->y);
	printf("%d %d ", arr[2]->coord->x, arr[2]->coord->y);
	printf("area : %lf \n", arr[0]->area);
}

void print_nontria(LOC *arr) {
	printf("---NON-Triangle (%d %d %d)---\n", arr[0]->label, arr[1]->label, arr[2]->label);
	printf("%d %d, ", arr[0]->coord->x, arr[0]->coord->y);
	printf("%d %d, ", arr[1]->coord->x, arr[1]->coord->y);
	printf("%d %d \n", arr[2]->coord->x, arr[2]->coord->y);
}

void store(LOC **loc_arr, LOC *cand) {
	int j = 0;
	while (loc_arr[j][0]->label != -1){ j++; }
	loc_arr[j][0] = cand[0];
	loc_arr[j][1] = cand[1];
	loc_arr[j][2] = cand[2];
}

int gen_number() {
	return (rand() % MAX);
}

int is_dublicate(LOC *arr) {
	int i, j;

	for (i = 0; i < 3; ++i) {
		for (j = i+1; j <= 2; ++j) {
			if ((arr[i]->coord->x == arr[j]->coord->x) &&
				(arr[i]->coord->y == arr[j]->coord->y)) {
				return 1;
			}
		}
	}

	return 0;
}

int check_is_triangle(LOC *temp_arr, double *ptr_area) {
	int x1, y1, x2, y2, x3, y3, res = 0;
	double s, a, b, c, area;

	x1 = temp_arr[0]->coord->x; y1 = temp_arr[0]->coord->y;
	x2 = temp_arr[1]->coord->x; y2 = temp_arr[1]->coord->y;
	x3 = temp_arr[2]->coord->x; y3 = temp_arr[2]->coord->y;

	if (!is_dublicate(temp_arr)) {
		c = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
		b = sqrt(pow((x3 - x1), 2) + pow((y3 - y1), 2));
		a = sqrt(pow((x3 - x2), 2) + pow((y3 - y2), 2));

		if (((abs(b - c) < a) < (b + c)) && ((abs(a - c) < b) < (a + c))
			                             && ((abs(a - b) < c) < (a + b))) {
			s = (float)(a + b + c)/2;
			area = (float)sqrt(s*(s-a)*(s-b)*(s-c));
			*ptr_area = area;
			res = 1;
		} else {
			res = 0;
		}
	} else {
		res = 0;
	}

	return res;
}

void generate_triangles(LOC **tri_arr, int noftria) {
	LOC l, *cand_tria;
	int i, j = 0, idx = 0;
	double area;

	cand_tria = malloc(sizeof(LOC) * 3);
	for (i = 0; i < 3; ++i) {
		cand_tria[i] = init_location();
	}
	for (i = 0, j = 0; i < noftria;) {
		l = init_location();
		l->coord = init_cordination();
		l->label = j++;
		l->coord->x = gen_number();
		l->coord->y = gen_number();
		cand_tria[idx] = l;
		if ((idx + 1) % 3 == 0) {
			if (check_is_triangle(cand_tria, &area)) {
				store(tri_arr, cand_tria);
				tri_arr[i][0]->area = area;
				i++;
			} else {
				print_nontria(cand_tria);
			}
			idx = 0;
		} else {
			idx++;
		}
	}
}

int main() {
	srand(time(NULL));
	int i, noftria = 5;
	LOC **tria_arr;

	tria_arr = init_location_arr(noftria);
	generate_triangles(tria_arr, noftria);

	for (i = 0; i < noftria; ++i) {
		print_triangles(tria_arr[i]);
	}

	free_triangles(tria_arr, noftria-1);

	return 0;
}

