/*
 * usage_example_with_header.c
 *
 *  Created on: 25 ott 2018
 *      Author: Francesco
 */


#include <stdio.h>

#include "csvparser.h"
#include <string.h>
/*
int main() {
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
        for (i = 0 ; i < CsvParser_getNumFields(row) ; i++) {
            printf("FIELD: %s\n", rowFields[i]);
        }
		printf("\n");
        CsvParser_destroy_row(row);
    }
    CsvParser_destroy(csvparser);

    return 0;
}
*/

