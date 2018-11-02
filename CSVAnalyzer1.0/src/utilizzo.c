/*
 * utilizzo.c
 *
 *  Created on: 26 ott 2018
 *      Author: Francesco
 */


#include "chi_quadrato_test.h"

int main() {

	printf("--------------------TEST---------------------\n");

	variabili v = (variabili) malloc (sizeof(v));
		v->aff_dipValue = "Y";
		v->neg_dipValue = "N";
		v->first_indValue = "M";
		v->second_indValue = "F";


		printf("ciao\n");

		tabella* x = getTabella("ESPERIMENTO1.csv",v);





	printf("successi uomo:%f\ninsuccessi uomo:%f\nsuccessi donne:%f\ninsuccessi donne:%f\n",*(x[1][1]),*(x[1][0]),*(x[0][1]),*(x[0][0]));
	double p_result = p_value(x);
	printf("p_value: %f\n",p_result);
	test(p_result);

	return 0;
}
/*int main() {

	double a,b,c,d;
	a = b = c = d = 0;

	double risultatoTest;

	int i =  0;
	//                                   file, delimiter, first_line_is_header?
	CsvParser *csvparser = CsvParser_new("ESPERIMENTO1.csv", ",", 1);
	CsvRow *row;
	const CsvRow *header = CsvParser_getHeader(csvparser);

	if (header == NULL) {
		printf("%s\n", CsvParser_getErrorMessage(csvparser));
		return 1;
	}
	const char **headerFields = CsvParser_getFields(header);
	for (i = 0 ; i < CsvParser_getNumFields(header) ; i++) {
		printf("ATTRIBUTE: %s\n", headerFields[i]);
	}
	while ((row = CsvParser_getRow(csvparser)) ) {
		printf("==NEW LINE==\n");

		const char **rowFields = CsvParser_getFields(row);

		if(strcmp(rowFields[0],"M")) {
			if(strcmp(rowFields[1],"Y"))
				a++;
			else b++;
		}
		else if(strcmp(rowFields[1],"Y"))
			c++;
		else d++;


		CsvParser_destroy_row(row);
		printf("\n");
	}



	CsvParser_destroy(csvparser);
	printf("successi uomo:%f\ninsuccessi uomo:%f\nsuccessi donne:%f\ninsuccessi donne:%f\n",d,c,b,a);

	risultatoTest = c


	return 0;
}

*/

