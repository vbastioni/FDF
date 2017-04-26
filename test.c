#include <stdio.h>
#include <math.h>
#include <stdlib.h>

# define torad(x) (x * 3.14159265359 / 180.0)
# define todef(x) (x * 180.0 / 3.14159265359)

int main(int ac, char **av)
{
	if (ac < 3)
		return (0);
	int x = atoi(av[1]);
	int y = atoi(av[2]);
	printf("x: %d, y: %d\n", x, y);
	double tr30 = torad(30);
	double tr150 = torad(150);
	printf("tr30: %f, tr150: %f\n", tr30, tr150);
	double nx = tr30 * x + tr150 * y;
	double ny = tr150 * x + tr30 * y;
	printf("nx: %f, ny: %f\n", nx, ny);
	return (0);
}
