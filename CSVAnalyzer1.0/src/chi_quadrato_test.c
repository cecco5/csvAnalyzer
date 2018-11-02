/*
 * chi_quadrato_test.c
 *
 *  Created on: 26 ott 2018
 *      Author: Francesco
 */


#include "chi_quadrato_test.h"

tabella* getTabella(char* nomeFile, variabili v) {



	tabella* t = (tabella*) malloc (sizeof(t));

	double a,b,c,d = 0;

	CsvParser *csvparser = CsvParser_new(nomeFile, ",", 1);
	CsvRow *row;

	const CsvRow *header = CsvParser_getHeader(csvparser);

	if (header == NULL) {
		printf("%s\n", CsvParser_getErrorMessage(csvparser));
		exit(1);
	}
	//conto a,b,c,d
	while ((row = CsvParser_getRow(csvparser)) ) {

		const char **rowFields = CsvParser_getFields(row);


		if(strcmp(rowFields[0],v->first_indValue) && strcmp(rowFields[1],v->aff_dipValue))
			a++;
		else if (strcmp(rowFields[0],v->first_indValue) && strcmp(rowFields[1],v->neg_dipValue))
			b++;

		else if	(strcmp(rowFields[0],v->second_indValue) && strcmp(rowFields[1],v->aff_dipValue) )
			c++;



		else d++;


		CsvParser_destroy_row(row);
	}

	CsvParser_destroy(csvparser);


	//inserisco i valori nella tabella
	*(t[0][0])=a;
	*(t[0][1])=b;
	*(t[1][0])=c;
	*(t[1][1])=d;


	return t;
}


double p_value(tabella* t) {

	double a,b,c,d;
	a=*(t[0][0]);
	b=*(t[0][1]);
	c=*(t[1][0]);
	d=*(t[1][1]);

	double pv;
	double ntot_dati = a+b+c+d;


	if((ntot_dati<200) && (a<5 || b<5 || c<5 || d<5 ))
		pv = (pow((abs((a*d)-(b*c))-(ntot_dati/2)),2) * ntot_dati) / ((a+b)*(a+c)*(b+d)*(c+d)); //test del chi-quadro con correzione di Yates
	else if(ntot_dati>200)
		pv =( pow(((a*d)-(b*c)),2) * ntot_dati ) / ((a+b)*(a+c)*(b+d)*(c+d)); //test del chi-quadro
	else pv = 0;

	return pv;
}


void test(double p_value) {
	if (p_value > ALPHA )
		printf("%f > %f : rifiuto H0, il test è significativo al 95%%", p_value,ALPHA);
	else printf("%f <= %f : accetto H0, il test non è significativo al 95%%",p_value,ALPHA);


}

















