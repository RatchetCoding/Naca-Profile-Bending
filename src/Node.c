#include "Node.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Naca* newNode(){

	Naca* newNode = malloc(sizeof(Naca));
	memset(newNode,0,sizeof(Naca));
	return newNode;
}
Naca* seekFirst(Naca* iterator){

	while(iterator->prev!=NULL){
		iterator = iterator->prev;
	}
	return iterator;
}

Naca* seekLast(Naca* iterator){

	while(iterator->next!=NULL){
		iterator = iterator->next;
	}
	return iterator;
}

void insert_Naca(Naca* iterator){

	tmp = newNode();
	tmp->prev = iterator;
	tmp->next = iterator->next;
	iterator->next=tmp;

}