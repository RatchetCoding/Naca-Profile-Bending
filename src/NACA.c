#include "File_IO.h"
#include "Node.h"
#include "Math.h"
#include "Naca.h"
#include <stdio.h>
#include <time.h>
int main()
{
	/*
	*Starting a clock to measure runtime on CPU, so we can have cool output at the end.
	*/
	clock_t begin, end;
	double time_spent;
	begin = clock();
	/*
	*The coordinates of our profile that gets bend.
	*/
	double Profile_x[31] ={0,0.005,0.0075,0.0125,0.025,0.05,0.075,0.1,0.15,0.2,0.25,0.3,0.35,0.4,0.45,0.5,0.55,0.6,0.65,0.7,0.75,0.8,0.85,0.9,0.95,0.992,0.995,0.997,0.998,0.999,1};
	double Profile_y[31] ={0,0.006098,0.007354,0.009216,0.012528,0.017394,0.021170667,0.024326667,0.029356667,0.033172,0.036046667,0.038114667,0.039423333,0.039993333,0.039674667,0.038382,0.036091333,0.032963333,0.0297792344,0.0265951358,0.023411037,0.0202269386,0.01704284,0.0138587414,0.010674642,0.008,0.0074161984,0.0062449979,0.0052915026,0.0038729833,0};
	/*
	* Loading the given data into the chain of structs
	*/
	printf("\nLoading File...\n");
	firstProfile=load();
	/*
	* We give the first profile to the solve function, it calculates 
	* radius and position of the skeleton line.
	*/
	printf("Solving for radius and position of skeleton line...\n");
	loesen(firstProfile);

	// Right now it only prints out success although were not checking it. 
	// TODO: Implement check if parameter solving was successful.
	printf(KGRN "All parameters determined!\n"RESET);

	/*
	* Taking profile data and bending it accoring to the new skeleton line. Also given the first node of the chain.
	*/
	printf("Bending profile according to skeleton line...\n");
	calculate_Profile(firstProfile,Profile_x,Profile_y);
	printf(KGRN "New Profile determined!\n"RESET);

	/*
	* Saving the freshly acquired coordinates
	*/
	printf("Saving...\n");
	save(firstProfile);
	printf(KGRN "Successfully saved!\n\n"RESET);

	/* 
	*Outputting the time it took for the program. Other data are precalculated and do not depend on the actual code. Don't take seriously
	*/
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Congratulations, you calculated 105 profiles with 18900 coordinate points\nusing 16095 calculations in %lf seconds!!\n\n",time_spent);
	return 0;
}