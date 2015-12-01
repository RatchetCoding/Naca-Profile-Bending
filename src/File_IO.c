#include <stdio.h>
#include <stdlib.h>
#include "File_IO.h"
#include "Node.h"
#define I(i,k) ((i)*26+(k))

/*
* This function saves the coordinates into ".dat" files, seperated by commas.
*/

void save(Naca* firstNode){

	/* 
	*We get the first Node as input and run through the chain from there 
	*/
	iterator = firstNode;
	j=0;
	l=0;
	
	while(iterator != NULL){

		/* 
		*We use "snprintf" to create the filename. We want one file for every group of 5 profiles. 
		*/
		snprintf(buff,sizeof(buff),"./Profiles/Profile%d_%s.dat",l,iterator->type);
		FILE* file = fopen(buff,"w");
		for(int i=0;i<=4;i++){
			for(int k=0;k<=30;k++){

				/*
				* We print the coordinatepoints to the file. At first the one above the x-axis, then the one below
				*/
				fprintf(file,"%lf;%lf;%lf\n",iterator->Px[I(i,k)],iterator->Py[I(i,k)],(iterator->z)*j);
				fprintf(file,"%lf;%lf;%lf\n",iterator->SPx[I(i,k)],iterator->SPy[I(i,k)],(iterator->z)*j);
			}

			/*
			* We want the profiles to be spread linear over the distance z. The factor "j" takes care of that by adding 0.25 after every run through the loop.
			*/
			j+=0.25;
		}

		//Going to the next node in the chain.
		iterator = iterator->next;

		// "l" counts how many profiles we have, so we can name the files accordingly
		l++;
		fclose(file);
	}
	

}

/*
* This function loads the data from a ".csv" file. All data get saved into their according variable in the struct. 
*/
Naca* load(){

	FILE* file=fopen("Winkel.csv","r");
	if(file == NULL){
		printf("Can't find file, please get sure it's in the same folder as the executable\n");
		return NULL;
	}
	while(!feof(file)){

		/* 
		*If it's the first time we are entering the loop, "newNode()" from Node.c gets called and creates the first element of the chain. Otherwise we are creating the next element of the chain and link it properly.
		*/
		if(iterator==NULL){
			iterator=newNode();
			firstNode=iterator;

		}else{
				iterator->next=newNode();
				iterator->next->prev = iterator;
				iterator=iterator->next;
			}
		/*
		* The reading of the file is dirty, hard to read and no error checks, this is the part I would like to learn how to do properly.
		*/
		fscanf(file,"%lf;%lf;%lf;%lf;%lf;%lf;%lf;%lf;%lf;%lf;%lf;%lf;%lf;%s",&(iterator->Lax),&(iterator->deltaLax),&(iterator->z),&(iterator->B12[0]),&(iterator->B12[1]),&(iterator->B12[2]),&(iterator->B12[3]),&(iterator->B12[4]),&(iterator->B2[0]),&(iterator->B2[1]),&(iterator->B2[2]),&(iterator->B2[3]),&(iterator->B2[4]),iterator->type);
		
	}
	fclose(file);
	printf(KGRN "File successfully loaded!\n" RESET);

	//First item of the chain gets returned
	return firstNode;

}
