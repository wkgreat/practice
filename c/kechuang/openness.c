#include<stdio.h>

/* not successful  */

void openness(double matrix[], int strides[], int shapes[], double pos[], double neg[], int radius, double cellsize, double z_factor);
void openness_cell(double matrix[], int strides[], int shapes[], int h, int w, int radius, double cellsize, double z_factor);
struct bi_tuple
{
	int dh;
	int dw;
};

struct directions
{
	struct bi_tuple n;
	struct bi_tuple ne;
	struct bi_tuple e;
	struct bi_tuple se;
	struct bi_tuple s;
	struct bi_tuple sw;
	struct bi_tuple w;
	struct bi_tuple nw;
} direct = 
{
	{-1, 0},
	{-1, 1},
	{ 0, 1},
	{ 1, 1},
	{ 1, 0},
	{ 1,-1},
	{ 0,-1},
	{ -1,-1}
};

main()
{

	printf("%d", direct.n.dw);

	return 0;
}


