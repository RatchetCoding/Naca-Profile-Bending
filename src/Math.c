#include "Math.h"
#include <math.h>
#define I(i,k) ((i)*61+(k))
#define Is(i,k) ((i+1)*61-(k))

/*
* I guess this is where the magic happens. It's just real simple geometry. We calculate a skeleton line in "solve()" and bend the profile accordingly in "calculate_Profile".
*/
void loesen(Naca* iterator){

		while(iterator!=NULL){

			for(int i=0;i<=4;i++){

				/* 
				* For the curious: In the given data we have two angles (B12 and B2) and a distance (Lax). We are looking for an arc, which has those angles at the given distance.
				* At first the radius of a circle is calculated, which would have those two angles at the given distance. Then it's position is determined, thus the beginning
				* of the skeleton line is at the point (0;0);
				*/
				iterator->radius[i]=(iterator->Lax + iterator->deltaLax * i*0.25)/(sin_d((iterator->B12[i])+(iterator->B2[i]))-sin_d(iterator->B2[i]));
				iterator->Mx[i]=sin_d((iterator->B12[i])+(iterator->B2[i])) * (iterator->radius[i]);
				iterator->My[i]= -cos_d((iterator->B12[i])+(iterator->B2[i]))*(iterator->radius[i]);
				

			}
			iterator = iterator->next;

		}


}
void calculate_Profile(Naca* iterator, double* Profile_x,double* Profile_y){

	float alpha;
	while(iterator!= NULL){
	for(int i=0;i<=4;i++){
			for(int k=0;k<=30;k++){

				/* 
				* Again for the curious: Kinda hard to explain, will maybe add someday.
				*/
				alpha=asin(((iterator->Mx[i])-(Profile_x[k] * (iterator->Lax + iterator->deltaLax * i*0.25)))/iterator->radius[i]);
			
				iterator->Px[I(i,k)]=iterator->Mx[i] - ((iterator->radius[i])+(Profile_y[k] * (iterator->Lax + iterator->deltaLax * i*0.25)))*sin(alpha);

				iterator->Py[I(i,k)]=iterator->My[i] + ((iterator->radius[i])+(Profile_y[k] * (iterator->Lax + iterator->deltaLax * i*0.25)))*cos(alpha);

				iterator->Px[Is(i,k)]=iterator->Mx[i] - ((iterator->radius[i])-(Profile_y[k] * (iterator->Lax + iterator->deltaLax * i*0.25)))*sin(alpha);

				iterator->Py[Is(i,k)]=iterator->My[i] + ((iterator->radius[i])-(Profile_y[k] * (iterator->Lax + iterator->deltaLax * i*0.25)))*cos(alpha);
				
			}
		}
		iterator=iterator->next;
	}
}

void com(Naca* iterator){

	/*
	* First we calculate the area of our profile, we need it later for the center of mass calculation
	*/
	while(iterator!=NULL){

	for(int i=0;i<=4;i++){
		iterator->area[i]=0;

			for(int k=0;k<=60;k++){
				
				iterator->area[i]+= iterator->Px[I(i,k)] * iterator->Py[I(i,k+1)] - iterator->Px[I(i,k+1)] * iterator->Py[I(i,k)];

		}
		iterator->area[i] = iterator->area[i] * 1/2;
	}
	for(int i=0;i<=4;i++){
		iterator->comx[i]=0;

			for(int k=0;k<=60;k++){
				
				iterator->comx[i]+= (iterator->Px[I(i,k)] + iterator->Px[I(i,k+1)]) * (iterator->Px[I(i,k)] * iterator->Py[I(i,k+1)] - iterator->Px[I(i,k+1)] * iterator->Py[I(i,k)]);
 
		}
		iterator->comx[i] = iterator->comx[i] * (1/iterator->area[i]) * 1/6;
		printf("%lf\n",iterator->comx[i]);
	}
	for(int i=0;i<=4;i++){
		iterator->comy[i]=0;

			for(int k=0;k<=60;k++){
				
				iterator->comy[i]+= (iterator->Py[I(i,k)] + iterator->Py[I(i,k+1)]) * (iterator->Px[I(i,k)] * iterator->Py[I(i,k+1)] - iterator->Px[I(i,k+1)] * iterator->Py[I(i,k)]);
 
		}
		iterator->comy[i] = iterator->comy[i] * (1/iterator->area[i]) * 1/6;
	}
	iterator= iterator->next;

}

}