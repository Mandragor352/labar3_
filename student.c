#include "student.h"
#include <stdio.h>  // Добавляем для использования printf

void changeAverageGrade(Student *student, float newGrade) {
    // Проверка, что новый балл в допустимом диапазоне
    if (newGrade >= 0.0 && newGrade <= 5.0) {
        student->averageGrade = newGrade;  // Обновляем средний балл студента
    } else {
        printf("Invalid grade. Grade must be between 0.0 and 5.0.\n");  // Сообщение об ошибке, если балл вне допустимого диапазона
    }
}

int isHonorStudent(const Student *student) {
    // Проверка, является ли студент отличником
    return student->averageGrade >= 4.5;
}


