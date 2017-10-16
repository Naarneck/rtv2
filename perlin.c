#include <math.h>
#include <stdio.h>
# define PI 3.14159265

double CosInterpolate(double v1, double v2, double a)
{
	double angle = a * PI;
	double prc = (1.0f - cos(angle)) * 0.5f;
	return  (v1 * (1.0f - prc) + v2 * prc);
}

double Noise2D(int x, int y)
{
	int n = (x + y * 57) ;
		n = (n << 13) ^ n;
	return (1.0 - ((n * (n * n * 15731 + 789221) + 1376312589) & 0x7fffffff) / 1073741824.0);
}

double SmoothedNoise2D(int x, int y)
{
	double corners = (Noise2D(x - 1, y - 1) + Noise2D(x + 1, y - 1) + Noise2D(x - 1, y + 1) + Noise2D(x + 1, y + 1)) / 16;
	double sides = (Noise2D(x - 1, y) + Noise2D(x + 1, y) + Noise2D(x, y - 1) + Noise2D(x, y + 1)) / 8;
	double center = Noise2D(x, y) / 4;

	return corners + sides + center;
}


double	InterpolatedNoise2D(double x, double y)
{
	int integer_X = (int)x;
	double fractional_X = x - integer_X;

	int integer_Y = (int)y;
	double fractional_Y = y - integer_Y;

	double v1 = SmoothedNoise2D(integer_X, integer_Y);
	double v2 = SmoothedNoise2D(integer_X + 1, integer_Y);
	double v3 = SmoothedNoise2D(integer_X, integer_Y + 1);
	double v4 = SmoothedNoise2D(integer_X + 1, integer_Y + 1);

	double i1 = CosInterpolate(v1, v2, fractional_X);
	double i2 = CosInterpolate(v3, v4, fractional_X);

	return CosInterpolate(i1, i2, fractional_Y);
}

double PerlinNoise2D(double x, double y)
{
	double total = 0;
	double p = 0.25;
	double n = 5;

	for (int i = 0; i <= n; ++i)
	{
		double frequency = pow(2, i);
		double amplitude = pow(p, i);
		total = total + InterpolatedNoise2D(x * frequency, y * frequency) * amplitude;
	}
    return (total + 0.7);
}


// int perlin_noise(int width, int height, double frq)
// {
// 	int x;
// 	int y;
// 	float value;

// 	frq /= (float)width;
// 	y = 0;
// 	while (y < height)
// 	{
// 		x = 0;
// 		while (x < width)
// 		{
// 			value = PerlinNoise2D(x,y);
// 			printf("%f ", value);
// 			x++;
// 		}
// 		printf("\n");
// 		y++;
// 	}
// 	return (0);
// }

// int main(int argc, char const *argv[])
// {
// 	perlin_noise(20, 20, 5.0f);
// 	return 0;
// }