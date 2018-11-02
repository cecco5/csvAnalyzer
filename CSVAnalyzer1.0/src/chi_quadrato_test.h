/*
 * chi_quadrato_test.h
 *
 *  Created on: 26 ott 2018
 *      Author: Francesco
 */

#ifndef SRC_CHI_QUADRATO_TEST_H_
#define SRC_CHI_QUADRATO_TEST_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "csvparser.h"
#include <math.h>

#define N 2 //tabella di contingenza 2*2
#define EPSILON 0.05 //percentuale di rischio fissata al 5%
#define ALPHA 3.841  //percentile del chi-quadro per epsilon = 5%, se il valore trovato è maggiore di questa soglia rifiuto H0

typedef double tabella[N][N];   //tabella di contingenza 2 x 2

typedef struct {

	//i due valori della variabile indipendente (uomo/donna, farmaco1/farmaco2)
	char* first_indValue;
	char* second_indValue;

	//i due valori della variabile dipendente (del tipo affermativo/negativo)
	char* aff_dipValue;
	char* neg_dipValue;
}vars;

typedef vars* variabili;



tabella* getTabella(char* nomeFile, variabili v); //in input devo dare il file e il tipo di valori delle variabili (indipendente e dipendente))

double p_value(tabella* t);

void test(double p_value);






#endif /* SRC_CHI_QUADRATO_TEST_H_ */
