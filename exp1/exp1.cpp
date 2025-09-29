#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char name[50];
    int rollno;
    int marks;
    char grade;
}s[3];

int main(){
    int i;

    for(i = 0; i < 3; i++)
    {
        printf("\nEnter details for Student %d\n", i + 1);
        printf("Enter name: ");
        scanf("%s", s[i].name);
        

        printf("Enter roll number: ");
        scanf("%d", &s[i].rollno);
        

        printf("Enter marks: ");
        scanf("%d", &s[i].marks); 
    }

    char nam[50];
    printf("\nEnter student name to search for: ");
    scanf("%s", nam);

    int flag = 0;
    i = 0;
    while(flag == 0){
        if(strcmp(nam, s[i].name) == 0){
            printf("Name: %s\n", s[i].name);
            printf("Roll No: %d\n", s[i+1].rollno);
            printf("Marks: %d\n", s[i].marks);
            flag = 1;
            break;
        }
        if(i>3){
            break;
        }
        else{
            continue;
        }
        i++;
    }
    if(flag = 0){
        printf("Student not found :(");
    }

    return 0;
}