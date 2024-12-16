#include "course.h"
#include <stdio.h>

void addStudentToCourse(Course *course, const Student *student) {
    // Проверка, что курс не переполнен
    if (course->studentCount < MAX_STUDENTS) {
        course->students[course->studentCount] = *student;  // Добавляем студента в курс
        course->studentCount++;  // Увеличиваем счётчик студентов
    } else {
        printf("Курс полный, более нельзя добавить.\n");
    }
}

Student findTopStudent(const Course *course) {
    // Возвращаем пустого студента, если курс пустой
    Student topStudent = {"", 0, 0.0};  // Инициализация пустого студента

    if (course->studentCount == 0) {
        return topStudent;  // Если студентов нет, возвращаем пустого студента
    }

    topStudent = course->students[0];  // Инициализация первого студента как топового
    for (int i = 1; i < course->studentCount; i++) {
        if (course->students[i].averageGrade > topStudent.averageGrade) {
            topStudent = course->students[i];  // Обновляем топ-студента, если найден студент с более высоким средним баллом
        }
    }
    return topStudent;
}

void printAllStudents(const Course *course) {
    printf("Студенты на курсе %s:\n", course->courseName);
    for (int i = 0; i < course->studentCount; i++) {
        printf("  %s (Возраст: %d) - Бал: %.2f\n", 
               course->students[i].name, 
               course->students[i].age, 
               course->students[i].averageGrade);
    }
}


