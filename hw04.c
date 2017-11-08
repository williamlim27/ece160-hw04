#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
  NAME_ONLY = 0,
  MAJOR_AND_NAME = 1, 
  YEAR_AND_NAME = 2,
  YEARS_LEFT_AND_NAME = 3,
} Mode;

typedef struct {
  char *first_name;
  char *last_name;
  char *major;
  int year;
  int yearsleft;
  // TODO: add fields here for major and year
} Student;

void print_student(Mode m, Student s) {
  switch (m) {
    case NAME_ONLY:
      printf("%s %s\n", s.first_name, s.last_name);
      break;
	// TODO: handle other cases
	case MAJOR_AND_NAME:
		 printf("%s %s %s\n", s.major, s.first_name,s.last_name);
		 break;
	case YEAR_AND_NAME:
		 printf("%d %s %s\n", s.year, s.first_name, s.last_name);
		break;
	case YEARS_LEFT_AND_NAME:
		 printf("%d %s %s\n", s.yearsleft, s.first_name, s.last_name);
		break;
	}
}


int main(int argc, char *argv[]) {
  char *filename = argv[1];
  FILE *fp;  // = fopen(filename, "r");
 
  // create a buffer that can hold 3 strings of
  // up to 255 characters each
  char buffer[256];
  
  // open file for reading
  fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Could not open %s\n", filename);
    return -1;
  }

Student student_array[256];

  // read one line at a time and send it to calc function for processing
  char *s;
  int i = 0;
  Student students;
  //first loop to process input file
  while ((s = fgets(buffer, 255, fp)) != NULL) {
  // printf("buffer: %s",buffer);
		
		size_t len = strlen(buffer);
		size_t len_bytes = (len + 1) * sizeof(char);
		//char *new_string = malloc(len * sizeof(char));
		//option 1 : memcpy
		//memcpy(new_string, buffer, len_bytes);
		//option 2 :loop
		// for (int c = 0; c <= len; c++) {
			// new_string[c] = buffer[c];
			// }
		students.first_name = malloc(len_bytes);
		students.last_name = malloc(len_bytes);
		students.major = malloc(len_bytes);
	
		//s[i].yearsleft = malloc([len_bytes]);
		sscanf(buffer,"%s %s %s %d", students.first_name, students.last_name, students.major, &students.year);
		students.yearsleft = students.year - 2017;
		student_array[i] = students;
		
		i++;
  }
 int mode;
 int index;
 char answer;
  while(1){
	  scanf("%d %d", &index, &mode);
	  print_student(mode, student_array[index]);
	   
  }
  
  fclose(fp);
	
  return 0;
  
}


  // final loop to clean up memory
  // for (int j = 0; j < i; j++) {
	  // if (student_array[j] != NULL) {
	  // free(student_array[j]);
	  // }
  // }
  // printf ("End of loop");
  
  // fclose(fp);
  // return 0;
// }
	  
	// gbd  in 
	// clang -g file.c compile with debugging symbols

	