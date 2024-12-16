#include "tests.h"
#include "student.h"
#include "course.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>

// Определяем максимальное количество студентов
#define MAX_STUDENTS 100

// Тест 1: Добавление студента на курс
void testAddStudentToCourse() {
    printf("Тест по добавлению накурс...\n");

    
    Student student1 = {"Вася Пупкин", 20, 4.7};
    Student student2 = {"Дредноут", 22, 3.9};
    
    Course course = {"Курс дальнобоя", {}, 0};


    addStudentToCourse(&course, &student1);
    assert(course.studentCount == 1); // Проверяем, что студент добавлен
    assert(strcmp(course.students[0].name, "Вася Пупкин") == 0); // Проверка имени

    
    addStudentToCourse(&course, &student2);
    assert(course.studentCount == 2); // Проверяем, что второй студент добавлен
    assert(strcmp(course.students[1].name, "Дредноут") == 0); // Проверка имени

    
    for (int i = 0; i < MAX_STUDENTS - 2; i++) {
        Student newStudent = {"Student", 20, 4.0};  // создаём нового студента
        addStudentToCourse(&course, &newStudent);
    }
    assert(course.studentCount == MAX_STUDENTS); // Проверяем, что количество студентов достигло максимума

    printf("  Закончен успешно.\n");
}

// Тест 2: Поиск студента с максимальным средним баллом
void testFindTopStudent() {
    Course course = {"Курс", {}, 0};
    Student student1 = {"Вася Пупкин", 20, 4.5};
    Student student2 = {"Дредноут", 22, 3.9};

    addStudentToCourse(&course, &student1);
    addStudentToCourse(&course, &student2);

    Student topStudent = findTopStudent(&course);


    if (topStudent.averageGrade == 4.5) {
        printf("Тест пройден\n");
    } else {
        printf("Тест непройден\n");
    }
}


// Тест 3: Поиск студента на пустом курсе
void testFindTopStudentEmptyCourse() {
    printf("Тест по поиску в пустом курсе...\n");

    Course course = {"курс дальнобоя", {}, 0};

    // Ищем студента с максимальным средним баллом
    Student topStudent = findTopStudent(&course);

    // Проверяем, что возвращён пустой студент
    assert(strcmp(topStudent.name, "") == 0);
    assert(topStudent.averageGrade == 0.0);

    printf("  Пройдено, тест все врено обработал.\n");
}

// Функция для запуска всех тестов
void runTests() {
    testAddStudentToCourse();
    testFindTopStudent();
    testFindTopStudentEmptyCourse();
}

