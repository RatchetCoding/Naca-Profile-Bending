#ifndef FILE_IO_H
#define FILE_IO_H

#include "Node.h"
#include <stdio.h>

Naca* iterator;
Naca* firstNode;
void save(Naca* firstNode);
Naca* load();
char buff[0x100];
float  j;
int l;


#endif