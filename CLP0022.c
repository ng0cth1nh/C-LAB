/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: ThinhVNHE141345
 * Purpose: Manage student.
 */
#include<stdio.h>
#include <strings.h>
#define MAX 10000

/*  Author: ThinhVNHE141345
 *  Date: 20/01/2020 (tuy theo ngay code)
 *  Purpose: initialized a student structure has 4 attributes are code, name, birthday and point
 */
struct student {    
    char code[50];
    char name[50];
    char birthDay[50];
    float point;
};

struct student student[MAX]; 
//initialized the student array with capacity is 10000 students

/*  Author: ThinhVNHE141345
 *  Date: 20/01/2020 (tuy theo ngay code)
 *  Purpose: sort student in ascending order by name
 */
int comparator(const void* p, const void* q) {
    
    return strcmp(((struct student*) p)->name, ((struct student*) q)->name);
}


/*  Author: ThinhVNHE141345
 *  Date: 20/01/2020 (tuy theo ngay code)
 *  Purpose: read data from the txt file in the computer
 */
int loadData() {
    
    FILE *fp; 
    // initialized a file pointer fp
    fp = fopen("Student.txt", "rt"); 
    // open txt file in the computer
    int index; 
    // parameter to get the number of students were saved in file
    if (fp != NULL) {
    // if command to checks whether file is null or not
        while (1) {
        // while loop to makes sure read all data in file          
            int k = fscanf(fp, "%[^_]_%[^_]_%[^_]_%f[^\n]", student[index].code, student[index].name, student[index].birthDay, &student[index].point);
            if (k < 4) {
            // check the number of type data on each line in txt file is less then 4 if satisfy then implement the command inside
                return index; 
                // return the number of student was read from file
            }
            index++; 
            //the number of student was increased to 1 when had read 1 line in the file
        }

    } else
        printf("Not found");
    fclose(fp); 
    // close the file
}


/*  Author: ThinhVNHE141345
 *  Date: 20/01/2020 (tuy theo ngay code)
 *  Purpose: save data to the txt file in the computer
 */
void saveFile(struct student student[], int *index) {
    
    FILE *fp; 
    // initialized a file pointer fp
    fp = fopen("Student.txt", "w"); 
    // initialized a txt file in the computer
    if (fp != NULL) {
    // if command to checks whether file is null or not the number of student is increase 1 when read 1 line in the file 
        int i; 
        // parameter i begin from 0 to the last element of array and counts the position of each element
        for (i = 0; i < *index; i++) {
            fprintf(fp, "%s_%s_%s_%.1f", student[i].code, student[i].name, student[i].birthDay, student[i].point);
            fprintf(fp, "\n");
        }
        fclose(fp); 
        // close the file
    } else
        printf("Failed to save file !:((\n");
}

/*  Author: ThinhVNHE141345
 *  Date: 20/01/2020 (tuy theo ngay code)
 *  Purpose: Enter new student
 */
void enter(struct student student[], int *index) {
   
    printf("\n");
    printf("Enter new student: \n");
    printf("-----------------------------\n");
    char op;
    do {
        printf("\n");
        printf("Student code: ");
        scanf("%s", student[*index].code);
        fpurge(stdin);
        printf("Student name: ");
        gets(student[*index].name);
        fpurge(stdin);
        printf("Date of birth: ");
        scanf("%s", student[*index].birthDay);
        fpurge(stdin);
        printf("Learning point: ");
        scanf("%f", &student[*index].point);
        fpurge(stdin);
        (*index)++; 
        // increase 1 the number of student after enter all the attribute of student


        do {
            fpurge(stdin);
            printf("Do you wanna add anymore ? (y/n): ");
            scanf("%c", &op);
        } while (op != 'n' && op != 'N' && op != 'y' && op != 'Y');
        if (op == 'y' || op == 'Y')
        //if user enter 'y', the function will run again
            continue;
        else{
            printf("\n");
            printf("Added student already!\n");
            printf("-----------------------------\n");
            qsort(student, (*index), sizeof (struct student), comparator); 
            // sort student in ascending order by name before save to file
            saveFile(student, index); 
            // save to file txt in the computer
            break; 
            // end while loop
        }

    } while (1);

}

/*  Author: ThinhVNHE141345
 *  Date: 20/01/2020 (tuy theo ngay code)
 *  Purpose: display all the students in the structure
 */
void display(struct student student[], int index) {
    
    printf("\n");
    printf("Student list:\n");
    printf("---------------------------\n");
    printf("\n");
    for (int i = 0; i < index; i++) { 
    // parameter i begin from 0 to the last element of array and counts the position of each element  
        printf("Student code: %s\n", student[i].code);
        printf("Student name: %s\n", student[i].name);
        printf("Date of birth: %s\n", student[i].birthDay);
        printf("Learning point: %.1f\n", student[i].point);
        printf("\n");
        printf("---------------------------\n");
        printf("\n");
    }
}

/*  Author: ThinhVNHE141345
 *  Date: 20/01/2020 (tuy theo ngay code)
 *  Purpose: look up a student by name
 */
void lookUp(struct student student[], int index) {
   
    char op;
    do {
        char searchName[50];
        printf("Please enter student name: ");
        scanf("%s", searchName);
        fpurge(stdin);
        int check = 0; 
        // parameter check counts times the student appear in the array and initialized with 0
        int i; 
        // parameter i begin from 0 to the last element of array and counts the position of each element
        for (i = 0; i < index; i++)
            if (strcmp(student[i].name, searchName) == 0) {
            //compare the searching name to each student's name in the array if match then print out that student
                printf("\n");
                printf("Student code: %s\n", student[i].code);
                printf("Student name: %s\n", student[i].name);
                printf("Date of birth: %s\n", student[i].birthDay);
                printf("Learning point: %.1f\n", student[i].point);
                printf("\n");
                check++;
            }

        if (check == 0) printf("Don't have student on the list\n");

        do {
            fpurge(stdin);
            printf("Do you wanna search anymore ? (y/n): ");
            scanf("%c", &op);
        } while (op != 'n' && op != 'N' && op != 'y' && op != 'Y');
        if (op == 'y' || op == 'Y')
        //if user enter 'y', the function will run again
            continue;
        else
            break; 
            //if the user enter anything else except 'y', the function will end  

    } while (1);
}

/*  Author: ThinhVNHE141345
 *  Date: 20/01/2020 (tuy theo ngay code)
 *  Purpose: label and get the option of user
 */
void run(int *index) {

    do {
        int option; 
        //parameter of choose of user
        printf("1. Enter student list\n");
        printf("2. Look up student\n");
        printf("3. Display student list\n");
        printf("4. Exit\n");
        printf("Please choose menu (1 – 4): ");
        scanf("%d", &option);
        fpurge(stdin);
        switch (option) {
            case 1:
            {
                
                //Enter student list
                enter(student, index);
                break;
            }
            case 2:
            {
                
                //Look up student
                lookUp(student, (*index));
                break;
            }
            case 3:
            {
                
                //Display student list
                display(student, (*index));
                break;
            }
            case 4:
            {
                exit(0); 
                //if the user enter '4', the program will end  
            }

        }
    } while (1);
}

int main(int argc, char** argv) {
    int index = loadData(); 
    //the index parameter was initialized has the value from the number of student which was read from file
    run(&index); 
    //implement run function 
}

