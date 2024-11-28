#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

int main() {
	double R;
	scanf("%lf", &R);
	printf("%.6lf\n%.6lf", M_PI * R * R, 2 * R * R);
}