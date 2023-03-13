#ifndef Struct_H
#define Struct_H


typedef struct {
	char* surname, * name, * middle_name;
	char* Gender, * nationality, * height, * weight;
	char* year, *month, *day;
	char*	telephone_number;
	char* postal_code, * country, * ditrict, * area, * town, * street, * house, * apart;
}One_Person;
void allocate_memory_for_one_person(One_Person** person);
void free_memory_for_one_person(One_Person** person);
void scanf_file(FILE* file, One_Person* person);
void print_person(One_Person* person);
void sorting_for_surname( One_Person** person, int* n);
 #endif;
