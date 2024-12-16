#include <stdio.h>
#include "student.h"
#include "course.h"
#include "tests.h"


int main() {
    // Запуск тестов
    printf("Запуск теста...\n");
    runTests();  
    printf("\nТесты закончились.\n");

    // Создаём студентов
    Student student1 = {"Вася Пупкин", 20, 4.7};
    Student student2 = {"Дредноут", 22, 3.9};
    Student student3 = {"Капитан Кларк", 19, 4.5};

   
    Course course = {"Курс дальнобойщика", {}, 0};

    // Добавляем студентов на курс
    addStudentToCourse(&course, &student1);
    addStudentToCourse(&course, &student2);
    addStudentToCourse(&course, &student3);

    // Выводим всех студентов на курсе
    printAllStudents(&course);

    // Находим и выводим студента с максимальным баллом
    Student topStudent = findTopStudent(&course);
    printf("\nЛучдший студент: %s с лучшим балом %.2f\n", 
           topStudent.name, 
           topStudent.averageGrade);

    return 0;
}
