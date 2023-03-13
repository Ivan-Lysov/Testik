#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header_Practice_2_1.h"
#define LONGLINE 255

void allocate_memory_for_one_person(One_Person** person) {
	*person = (One_Person*)malloc(sizeof(One_Person) * 1);//One structure for one person
	if ((*person) == NULL) printf("Memory was not allocated");//Ñhecking for memory allocation 
	(*person)->surname = (char*)malloc(sizeof(char) * 50);
	if (((*person)->surname) == NULL) printf("Memory was not allocated for surname");//Checking for memory allocation for person`s surname
	(*person)->name = (char*)malloc(sizeof(char) * 50);
	if (((*person)->name) == NULL) printf("Memory was not allocated for name");//Checking for memory allocation for person`s name
	(*person)->middle_name = (char*)malloc(sizeof(char) * 50);
	if (((*person)->middle_name) == NULL) printf("Memory was not allocated for middle_name");//Checking for memory allocation for person`s middle_name
	(*person)->Gender = (char*)malloc(sizeof(char) * 15);
	if (((*person)->Gender) == NULL) printf("Memory was not allocated for Gender");//Checking for memory allocation for person`s Gender
	(*person)->nationality = (char*)malloc(sizeof(char) * 30);
	if (((*person)->nationality) == NULL) printf("Memory was not allocated for nationality");//Checking for memory allocation for person`s nationality
	(*person)->height = (char*)malloc(sizeof(char) * 5);
	if (((*person)->height) == NULL) printf("Memory was not allocated for height");//Checking for memory allocation for person`s height
	(*person)->weight = (char*)malloc(sizeof(char) * 5);
	if (((*person)->weight) == NULL) printf("Memory was not allocated for height");//Checking for memory allocation for person`s weight
	(*person)->telephone_number = (char*)malloc(sizeof(char) * 10);
	if (((*person)->telephone_number) == NULL) printf("Memory was not allocated for telephone number");//Checking for memory allocation for person`s telephone number
	(*person)->year = (char*)malloc(sizeof(char) * 2);
	if (((*person)->year) == NULL) printf("Memory was not allocated for year");//Checking for memory allocation for person`s year
	(*person)->month = (char*)malloc(sizeof(char) * 2);
	if (((*person)->month) == NULL) printf("Memory was not allocated for month");//Checking for memory allocation for person`s month
	(*person)->day = (char*)malloc(sizeof(char) * 2);
	if (((*person)->day) == NULL) printf("Memory was not allocated for day");//Checking for memory allocation for person`s day
	(*person)->postal_code = (char*)malloc(sizeof(char) * 10);
	if (((*person)->postal_code) == NULL) printf("Memory was not allocated for postal code");//Checking for memory allocation for person`s postal code
	(*person)->country = (char*)malloc(sizeof(char) * 15);
	if (((*person)->country) == NULL) printf("Memory was not allocated for country");//Checking for memory allocation for person`s country
	(*person)->ditrict = (char*)malloc(sizeof(char) * 15);
	if (((*person)->ditrict) == NULL) printf("Memory was not allocated for ditrict");//Checking for memory allocation for person`s ditrict
	(*person)->area = (char*)malloc(sizeof(char) * 15);
	if (((*person)->area) == NULL) printf("Memory was not allocated for area");//Checking for memory allocation for person`s area
	(*person)->town = (char*)malloc(sizeof(char) * 8);
	if (((*person)->town) == NULL) printf("Memory was not allocated for town");//Checking for memory allocation for person`s town
	(*person)->  street=(char*)malloc(sizeof(char) * 8);
	if (((*person)->street) == NULL) printf("Memory was not allocated for street");//Checking for memory allocation for person`s street
	(*person)->house = (char*)malloc(sizeof(char) * 5);
	if (((*person)->house) == NULL) printf("Memory was not allocated for house");//Checking for memory allocation for person`s house
	(*person)->apart = (char*)malloc(sizeof(char) * 85);
	if (((*person)->apart) == NULL) printf("Memory was not allocated for apart");//Checking for memory allocation for person`s apart



}
void free_memory_for_one_person(One_Person** person) {
	free((*person)->surname);
	free((*person)->name);
	free((*person)->middle_name);
	free((*person)->Gender);
	free((*person)->nationality);
	free((*person)->height);
	free((*person)->weight);
	free((*person)->telephone_number);
	free((*person)->year);
	free((*person)->month);
	free((*person)->day);
	free((*person)->postal_code);
	free((*person)->country);
	free((*person)->ditrict);
	free((*person)->area);
	free((*person)->town);
	free((*person)->street);
	free((*person)->house);
	free((*person)->apart);
	free(*person);
}
void print_person(One_Person* person) {
	printf("=================================================================");
	printf("Surname: %s", person->surname); printf("\n Name %s", person->name); printf("\n middle_name %s", person->middle_name);
	printf("\nGender: %s", person->Gender);
	printf("\n Nationality: %s", person->nationality);
	printf("\n Height: %s", person->height);
	printf("\n Weight: %s", person->weight);
	printf("Birthday: %s.%s.%s", person->day, person->month, person->year);
	printf("Telephone Number %s", person->telephone_number);
	printf("=================================================================");
	printf("Home adress");
	printf("Postal Code: %s", person->postal_code);
	printf("Country: %s", person->country);
	printf("District: %s", person->ditrict);
	printf("Areal: %s", person->area);
	printf("Town: %s", person->town);
	printf("Street: %s", person->street);
	printf("House: %s", person->house);
	printf("Apaptament: %s", person->apart);
}
void sorting_for_surname(One_Person** person, int* n) {//linear sorting by surname
	One_Person** temp;
	temp = (One_Person**)malloc(sizeof(One_Person*) * 1);
	allocate_memory_for_one_person(temp);
	int i;
	int j;
	for (int i = 0; i < n; i++) {
		for (int j = 1 + i; j < n; j++) {
			if (strcmp(person[j]->surname, person[i]->surname) != 0) {
				if (strcmp(person[j]->surname, person[i]->surname) < 0) {
					*temp = person[i];
					person[i] = person[j];
					person[j] = *temp;
				}
				else if (strcmp(person[j]->surname, person[i]->surname) == 0) {//If the surnames match, then sort by name
					if (strcmp(person[j]->name, person[i]->name) < 0) {
						*temp = person[i];
						person[i] = person[j];
						person[j] = *temp;
					}
				}
			}
			else if ((strcmp(person[j]->surname, person[i]->surname) == 0) && (strcmp(person[j]->name, person[i]->name) == 0)) {//If the surnames and first names match, then sort by patronymic
				if (strcmp(person[j]->middle_name, person[i]->middle_name) < 0) {
					*temp = person[i];
					person[i] = person[j];
					person[j] = *temp;
				}
			}

		}
	}
}
void scanf_file(FILE* file, One_Person* person) {
	 int n, count = 0;
	 char line[LONGLINE];
	 char* position1;
	 char separate[] = ";";
	 while (fgetc(line, LONGLINE, file) != NULL)
	 {
		 position1 = strtok(line, separate);
		 if (*position1 == "\n") {
			 break;
		 }
	 
		 strcpy(person->surname, position1);
		 n = 0;
		 while (position1 != NULL)
		 {
			 position1 = strtok(NULL, separate);
			 switch (n) {
			 case(0): {
				 strcpy(person->name, position1);
				 n++;
				 break;
			 }
			 case(1): {
				 strcpy(person->middle_name, position1);
				 n++;
				 break;
			 }
			 case(2): {
				 strcpy(person->Gender, position1);
				 n++;
				 break;
			 }
			 case(3): {
				 strcpy(person->nationality, position1);
				 n++;
				 break;
			 }
			 case(4): {
				 strcpy(person->height, position1);
				 n++;
				 break;
			 }
			 case(5): {
				 strcpy(person->weight, position1);
				 n++;
				 break;
			 }
			 case(6): {
				 strcpy(person->height, position1);
				 n++;
				 break;
			 }
			 case(7): {
				 strcpy(person->year, position1);
				 n++;
				 break;
			 }
			 case(8): {
				 strcpy(person->month, position1);
				 n++;
				 break;
			 }
			 case(9): {
				 strcpy(person->day, position1);
				 n++;
				 break;
			 }
			 case(10): {
				 strcpy(person->telephone_number, position1);
				 n++;
				 break;
			 }
			 case(11): {
				 strcpy(person->postal_code, position1);
				 n++;
				 break;
			 }
			 case(12): {
				 strcpy(person->country, position1);
				 n++;
				 break;
			 }
			 case(13): {
				 strcpy(person->ditrict, position1);
				 n++;
				 break;
			 }
			 case(14): {
				 strcpy(person->area, position1);
				 n++;
				 break;
			 }
			 case(15): {
				 strcpy(person->town, position1);
				 n++;
				 break;
			 }
			 case(16): {
				 strcpy(person->street, position1);
				 n++;
				 break;
			 }
			 case(17): {
				 strcpy(person->house, position1);
				 n++;
				 break;
			 }
			 case(18): {
				 strcpy(person->apart, position1);
				 n++;
				 break;
			 }
			 }
		 }
		 count++;
		 person++;
	 }
	 return count;
 }
				