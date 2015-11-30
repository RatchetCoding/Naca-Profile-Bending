#include <stdio.h>
#include <stdlib.h>
#include "File_IO.h"
#include "Node.h"

#define I(i,k) ((i)*26+(k))


void save(Naca* firstNode){

	iterator = firstNode;
	j=0;
	l=0;
	
	while(iterator != NULL){
		snprintf(buff,sizeof(buff),"./Profiles/Profile%d_%s.dat",l,iterator->type);
		FILE* file = fopen(buff,"w");
		for(i=0;i<=4;i++){
			for(k=0;k<=30;k++){
				fprintf(file,"%lf;%lf;%lf\n",iterator->Px[I(i,k)],iterator->Py[I(i,k)],(iterator->r)*j);
				fprintf(file,"%lf;%lf;%lf\n",iterator->SPx[I(i,k)],iterator->SPy[I(i,k)],(iterator->r)*j);
			}
			j+=0.25;
		}
		iterator = iterator->next;
		l++;
		fclose(file);
	}
	

}

Naca* load(){

	FILE* file=fopen("Winkel.csv","r");
	while(!feof(file)){

		if(iterator==NULL){
			iterator=newNode();
			firstNode=iterator;

			}else{
				iterator->next=newNode();
				iterator->next->prev = iterator;
				iterator=iterator->next;
			}
		fscanf(file,"%lf;%lf;%lf;%lf;%lf;%lf;%lf;%lf;%lf;%lf;%lf;%lf;%lf;%s",&(iterator->Lax),&(iterator->deltaLax),&(iterator->r),&(iterator->B12[0]),&(iterator->B12[1]),&(iterator->B12[2]),&(iterator->B12[3]),&(iterator->B12[4]),&(iterator->B2[0]),&(iterator->B2[1]),&(iterator->B2[2]),&(iterator->B2[3]),&(iterator->B2[4]),iterator->type);
		
	}
	fclose(file);
	printf(KGRN "File successfully loaded!\n" RESET);
	return firstNode;

}
