#ifndef UTIL_PROGRAM_H
#define UTIL_PROGRAM_H

/* ============================================
 * Student-Specific Configuration
 * Student ID: 5
 * Student Name: Surya Prasad Senthilkumaran
 * Generated automatically - DO NOT EDIT
 * ============================================ */

#define STUDENT_ID 5

/* Task 1 Configuration */
#define V1_SIZE 37
#define V1_TARGET 55

/* Task 2 Configuration */
#define V2_SIZE 53
#define V2_PURPLE 0x12340000
#define V2_GREEN 0x56780000
#define V2_BLUE 0x9abc0005

/* Task 3 Configuration */
#define V3_SIZE 45

/* Task 4 Configuration */
#define V4_SIZE 49

/* Task 5 Configuration */
#define V5_SIZE 53
#define V5_ROUND1 10000
#define V5_ROUND2 20000
#define V5_ROUND3 30005

/* Task 6 Configuration */
#define V6_SIZE 37

/* Task 7 Configuration */
#define V7_SIZE 45
#define V7_NAME "Student_5"

/* Task 8 Configuration */
#define V8_SIZE 485

/* Task 9 Configuration */
#define V9_SIZE 485

/* ============================================
 * Utility Function Declarations
 * ============================================ */

void initialize_buffer(char* buf, int size);
void read_from_file(const char* filename, char** str);
void write_to_file(const char* filename, char* buf, int len, int mode);

#define FILE_CLEAR 0
#define FILE_APPEND 1

#endif /* UTIL_PROGRAM_H */
