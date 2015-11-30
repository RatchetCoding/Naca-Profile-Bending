#ifndef NODE_H
#define NODE_H

#define STR_LEN 20
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define RESET "\033[0m"

typedef struct naca{
	char type[20];
	double Lax;
	double deltaLax;
	double B12[5];
	double B2[5];
	double radius[5];
	double Mx[5];
	double My[5];
	double Px[31*5];
	double Py[31*5];
	double SPx[31*5];
	double SPy[31*5];
	double r;
	struct naca *next;
	struct naca *prev;
}Naca;

Naca* newNode();
Naca* tmp;
Naca* seekFirst(Naca* iterator);
Naca* seekLast(Naca* iterator);
void insert_Naca(Naca* iterator);

#endif