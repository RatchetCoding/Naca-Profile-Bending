#include "Math.h"
#include <math.h>
#define I(i,k) ((i)*26+(k))
void loesen(Naca* iterator){

		while(iterator!=NULL){

			for(int i=0;i<=4;i++){

				iterator->radius[i]=(iterator->Lax + iterator->deltaLax * i*0.25)/(sin_d((iterator->B12[i])+(iterator->B2[i]))-sin_d(iterator->B2[i]));
				// printf("%lf ",iterator->B12[i]);
				// printf("%lf ",iterator->B2[i]);
				// printf("%lf ",iterator->radius[i]);
				iterator->Mx[i]=sin_d((iterator->B12[i])+(iterator->B2[i])) * (iterator->radius[i]);
				iterator->My[i]= -cos_d((iterator->B12[i])+(iterator->B2[i]))*(iterator->radius[i]);
				//printf("%lf ",iterator->Mx[i]);
				// printf("%lf\n",iterator->My[i]);

			}
			iterator = iterator->next;

		}


}
void calculate_Profile(Naca* iterator, double* Profile_x,double* Profile_y){

	float alpha;
	while(iterator!= NULL){
	for(int i=0;i<=4;i++){
			for(int k=0;k<=30;k++){
				alpha=asin(((iterator->Mx[i])-(Profile_x[k] * (iterator->Lax + iterator->deltaLax * i*0.25)))/iterator->radius[i]);
			
				iterator->Px[I(i,k)]=iterator->Mx[i] - ((iterator->radius[i])+(Profile_y[k] * (iterator->Lax + iterator->deltaLax * i*0.25)))*sin(alpha);

				iterator->Py[I(i,k)]=iterator->My[i] + ((iterator->radius[i])+(Profile_y[k] * (iterator->Lax + iterator->deltaLax * i*0.25)))*cos(alpha);

				iterator->SPx[I(i,k)]=iterator->Mx[i] - ((iterator->radius[i])-(Profile_y[k] * (iterator->Lax + iterator->deltaLax * i*0.25)))*sin(alpha);

				iterator->SPy[I(i,k)]=iterator->My[i] + ((iterator->radius[i])-(Profile_y[k] * (iterator->Lax + iterator->deltaLax * i*0.25)))*cos(alpha);
				
				}
		}
		iterator=iterator->next;
}
}
