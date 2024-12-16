#ifndef COURSE_H
#define COURSE_H

#include "student.h"

#define MAX_STUDENTS 100

typedef struct {
    char courseName[50];
    Student students[MAX_STUDENTS];
    int studentCount;
} Course;

void addStudentToCourse(Course *course, const Student *student);
Student findTopStudent(const Course *course);
void printAllStudents(const Course *course);  // Прототип функции для вывода всех студентов

#endif // COURSE_H

