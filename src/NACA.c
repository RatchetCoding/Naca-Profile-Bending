#include "File_IO.h"
#include "Node.h"
#include "Math.h"
#include "Naca.h"
#include <stdio.h>
#include <time.h>
int main()
{
	clock_t begin, end;
	double time_spent;
	begin = clock();
	double Profile_x[31] ={0,0.005,0.0075,0.0125,0.025,0.05,0.075,0.1,0.15,0.2,0.25,0.3,0.35,0.4,0.45,0.5,0.55,0.6,0.65,0.7,0.75,0.8,0.85,0.9,0.95,0.992,0.995,0.997,0.998,0.999,1};
	double Profile_y[31] ={0,0.006098,0.007354,0.009216,0.012528,0.017394,0.021170667,0.024326667,0.029356667,0.033172,0.036046667,0.038114667,0.039423333,0.039993333,0.039674667,0.038382,0.036091333,0.032963333,0.029204,0.024951333,0.020384,0.015622,0.010854667,0.006307333,0.002355333,0};
	printf("\nLoading File...\n");
	firstProfile=load();
	printf("Solving for radius and position of skeleton line...\n");
	loesen(firstProfile);
	printf(KGRN "All parameters determined!\n"RESET);
	printf("Bending profile according to skeleton line...\n");
	calculate_Profile(firstProfile,Profile_x,Profile_y);
	printf(KGRN "New Profile determined!\n"RESET);
	printf("Saving...\n");
	save(firstProfile);
	printf(KGRN "Successfully saved!\n\n"RESET);
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Congratulations, you calculated 105 profiles with 18900 coordinate points\nusing 16095 calculations in %lf seconds!!\n\n",time_spent);
	return 0;
}