/*********************************************************************************
Logic Overview:
1) Create a student struct that stores a student ID and 4 grades 
2) Return the student's resulting grade average and letter from the 4 grade input

*********************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// Define struct
typedef struct StudentRecord {
   int studentId;
   int quizGrade1;
   int quizGrade2;
   int midtermGrade;
   int finalGrade;
   double avgGrade;
   char letterGrade;
} StudentRecord;

// Prototypes
void input(StudentRecord * student);
void computeGrade(StudentRecord * student);
void output(const StudentRecord student);

int main() 
{   
    struct StudentRecord s1;
    input(&s1);
    computeGrade(&s1);
    output(s1);

    return 0;
}
void input(StudentRecord * student) {
    printf("Please enter the student number:\n");
    scanf("%d", &student->studentId);
    printf("Please enter two 10 point quiz grades:\n");
    scanf("%d", &student->quizGrade1);
    scanf("%d", &student->quizGrade2);
    printf("Please enter the midterm and final exam grades:\n");
    scanf("%d", &student->midtermGrade);
    scanf("%d", &student->finalGrade);
}
void computeGrade(StudentRecord * student) {
    // First, put all scores under the same denominator (100) for the weighted avg
    int quiz1 = ((*student).quizGrade1)*10;
    int quiz2 = ((*student).quizGrade2)*10;
    int midterm = (*student).midtermGrade;
    int final = (*student).finalGrade;
    double quizWeight = 0.125;
    double midtermWeight = 0.25;
    double finalWeight = 0.5;
    // Get the weighted avg of the 4 scores
    double weightedAvg = (quiz1*quizWeight + quiz2*quizWeight + midterm*midtermWeight + final*finalWeight);
    (*student).avgGrade = weightedAvg;
    // Translate the avg score to a letter grade
    if(weightedAvg >= 90){
       (*student).letterGrade = 'A'; 
    } else if(weightedAvg >= 80){
       (*student).letterGrade = 'B'; 
    } else if(weightedAvg >= 70){
       (*student).letterGrade = 'C'; 
    } else if(weightedAvg >= 60){
       (*student).letterGrade = 'D'; 
    } else{
       (*student).letterGrade = 'F'; 
    }
}
void output(StudentRecord student) {
    printf("The record for student number: %d \n",student.studentId); 
    printf("The quiz grades are: %d %d\n",student.quizGrade1, student.quizGrade2); 
    printf("The midterm and exam grades are: %d %d\n",student.midtermGrade, student.finalGrade); 
    printf("The numeric average is: %.2f \n",student.avgGrade);
    printf("and the letter grade assigned is %c \n",student.letterGrade);
}


