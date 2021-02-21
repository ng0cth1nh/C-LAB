/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: ThinhVNHE141345
 * Purpose: Array Manipulations.
 * Created on January 20, 2020, 10:07 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*  Author: ThinhVNHE141345
*  Date: 20/01/2020 (tuy theo ngay code)
*  Purpose: To add an integer to array and display all elements of array
*/
void add(int a[], int *i) {
    
    printf("Please enter an integer number: ");
    scanf("%d", &a[(*i)++]);
    display(a, (*i));
}

/*  Author: ThinhVNHE141345
*  Date: 20/01/2020 (tuy theo ngay code)
*  Purpose: Display all elements of array
*/
void display(int a[], int i) {
    
    printf("Output Array: ");
    int k; 
    // parameter k begin from 0 to the last element of array and count the position of each element
    for (k = 0; k < i; k++)
        printf("%d  ", a[k]);
    printf("\n");
}

/*  Author: ThinhVNHE141345
*  Date: 20/01/2020 (tuy theo ngay code)
*  Purpose: Search position of any element in the array by value of its element
*/
void search(int a[], int i) {
     
    int searchNumber;  
    // parameter of number wanna search
    int check = 0; 
    // parameter count times search number appear and initialized with 0
    printf("The number you wanna search: ");
    scanf("%d", &searchNumber);
        int k,j;
        // parameter k begin from 0 to the last element of array and counts the position of each element
        for (k = 0; k < i; k++) {
            if (a[k] == searchNumber && j == 0){ 
                // if command to check each element and search number if equal then display all position of its in array
                printf("Number %d in array at: %d ", searchNumber,k + 1);
                 ++j;
                check ++;
            }
            else if(a[k] == searchNumber)
                printf("%d ", k + 1);
            
        }
        if(check == 0) printf("There isn't exist in array!\n"); 
        // if command to check parameter check if different with 0 then implement all command inside its
            else printf("\n");      
        
}

/*  Author: ThinhVNHE141345
*  Date: 20/01/2020 (tuy theo ngay code)
*  Purpose: Remove the first existence of a value
*/
void remove1(int a[], int *i) {
    int remNumber;  
    // parameter of number wanna remove
    int check = 0; 
    // parameter count times remove number appear and initialized with 0
    printf("The number you wanna remove: ");
    scanf("%d", &remNumber);
        int j;
        // parameter j begin from 0 to the last element of array and counts the position of each element
        for (j = 0; j < (*i); j++) {
            if (a[j] == remNumber) {
                // if command to check each element and remove number if equal then implement for loop command
                for (int k = j + 1; k < (*i); k++) { 
                    // parameter k begin from first position of remove number to the last element of array
                    a[j] = a[k]; 
                    // assign each element after the number remove to each element in before them
                    j++; 
                    // parameter j increase 1 after.
                }
                check++;
                (*i)--; 
                // the number of element of array decreases to 1 after remove 
                break; 
                // to exit for loop
            }
        }
        if (check == 0 ) printf("There isn't exist in array!\n");
        else display(a, (*i)); 
        // display array

        
}

/*  Author: ThinhVNHE141345
*  Date: 20/01/2020 (tuy theo ngay code)
*  Purpose: Remove all existence of a value
*/
void remove2(int a[], int *i) {
    
    int remNumber; 
    // parameter of number wanna remove
    int check = 0; 
    // parameter count times remove number appear and initialized with 0
    printf("The number you wanna remove: ");
    scanf("%d", &remNumber);
    for (int j = 0; j < (*i);) {
        // parameter j begin from 0 to the last element of array and counts the position of each element
        if (a[j] == remNumber) {
            // if command to check each element and remove number if equal then implement for loop command
            for (int k = j; k < (*i); k++)
            // parameter k begin from first position of remove number to the last element of array
                a[k] = a[k + 1];
                //swap value each elements standing right next to each other after remove 1 times number remove
            check++;
            (*i)--;
            //the number of elements decreases to 1 after remove 1 times number remove
        } else
            j++;

    }

    if (check == 0) printf("There isn't exist in array!\n");
    else display(a, (*i));
     
}

/*  Author: ThinhVNHE141345
*  Date: 20/01/2020 (tuy theo ngay code)
*  Purpose: Sort the array in ascending order
*/
void ascending(int a[], int *i) {
    
    int j;
    // parameter j begin from 0 to the previous element of the last element of array and counts the position of each element
    for (j = 0; j < (*i) - 1; j++) {
        int k;
        // parameter k begin right after j 1 value to the last element of array counts the position of each element
        for (k = j + 1; k < (*i); k++) {
            //if command to compare the value of each element standing right next to each other
            if (a[j] > a[k]) {
                int temp = a[j];
                a[j] = a[k];
                a[k] = temp;
                
                //if value of the previous element is greater than the after element then swap the value of two element
            }
        }
    }
    display(a, (*i));

}

/*  Author: ThinhVNHE141345
*  Date: 20/01/2020 (tuy theo ngay code)
*  Purpose: Sort the array in descending order
*/

void descending(int a[], int *i) {
    
    int j;
    // parameter j begin from 0 to the previous element of the last element of array and counts the position of each element
    for (j = 0; j < (*i) - 1; j++) {
        int k;
        // parameter k begin right after j 1 value to the last element of array counts the position of each element
        for (k = j + 1; k < (*i); k++) {
            if (a[j] < a[k]) { 
                //if command to compare the value of each element standing right next to each other
                int temp = a[j];
                a[j] = a[k];
                a[k] = temp;
                
                //if value of the previous element is less than the after element then swap the value of two element
            }
        }
    }
    display(a, (*i));

}

/*  Author: ThinhVNHE141345
*  Date: 20/01/2020 (tuy theo ngay code)
*  Purpose: implement each function of program
*/

void funtion2(int a[], int option, int *i) {
    
    switch (option) {
        case 1:
        {   
            
            //Add a value
            add(a, i);
            break;
        }
        case 2:
        {
            
            //Search a value
            search(a, (*i));
            break;
        }
        case 3:
        {   
            
            //Remove the first existence of a value
            remove1(a, i);
            break;
        }
        case 4:
        {   
            
            //Remove all existences of a value
            remove2(a, i);
            break;
        }
        case 5:
        {
            
            //Print out the array
            display(a, (*i));
            break;
        }
        case 6:
        {
            
            //Sort the array in ascending order
            ascending(a,i);
            break;
        }
        case 7:
        {
            
            //Sort the array in descending order
            descending(a,i);
            break;
        }
        case 8:{
            exit(0);
            // if user enter '8' the program will end    
        }
    }
}

/*  Author: ThinhVNHE141345
*  Date: 20/01/2020 (tuy theo ngay code)
*  Purpose: label and get the option of user
*/
void run(int a[]) {
    
    
    int i = 0;
    //parameter i is the number of element in array initialized with 0
    int option;
    //parameter of choose of user
    do {
        printf("1- Add a value\n");
        printf("2- Search a value\n");
        printf("3- Remove the first existence of a value\n");
        printf("4- Remove all existences of a value\n");
        printf("5- Print out the array\n");
        printf("6- Sort the array in ascending order\n");
        printf("7- Sort the array in descending order\n");
        printf("8- Exit\n");
        while (1) {
            printf("Please choose 1 to 8 : ");
            scanf("%d", &option);
            if (option <= 8 && option >= 1) break;
        }
        
        funtion2(a, option, &i);          
    } while (1);
}

int main(int argc, char** argv) {
    int a[100]; 
    // initialized an array with capacity is 100 elements
    run(a);

}

