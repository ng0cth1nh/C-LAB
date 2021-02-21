
/* 
 * File:   main.c
 * Author: ThinhVNHE141345
 * Purpose: Convert binary, octal and hexadecimal to decimal.
 */

#include <stdio.h>
#include <math.h>
#include <string.h>


/*  Author: ThinhVNHE141345
*  Date: 20/01/2020 (tuy theo ngay code)
*  Purpose: check whether the string input of hexadecimal or octal or binary is valid
*/
int checkInput(char input[], int option) {
    switch (option) {
        case 1:
        {
            for (int i = 0; i < strlen(input); i++) {
                //the i parameter begin from 0 to the length of the string input binary and counts the position
                if (input[i] < '0' || input[i] > '1')
                    return 0;
                
                //if each element of the string input hexadecimal isn't between 0 to 1 then return 0
            }
            return 1;

        }
        case 2:
        {

            for (int i = 0; i < strlen(input); i++) {
                //the i parameter begin from 0 to the length of the string input octal and counts the position
                if (input[i] < '0' || input[i] > '7')
                    return 0;
                
                //if each element of the string input hexadecimal isn't between 0 to 7 then return 0
            }
            return 1;

        }
        case 3:
        {
            for (int i = 0; i < strlen(input); i++) {
                //the i parameter begin from 0 to the length of the string input hexadecimal and counts the position
                if (input[i] < '0' || input[i] > '9' && input[i] < 'A' || input[i] > 'F' && input[i] < 'a' || input[i] > 'f')
                    return 0;
                
                //if each element of the string input hexadecimal isn't between A to F or 0 to 9 or a to f then return 0
            }
            return 1;

        }
    }
}

/*  Author: ThinhVNHE141345
*  Date: 20/01/2020 (tuy theo ngay code)
*  Purpose: Convert binary number to decimal number
*/
void binToDec() {

    do {
        char op;
        char bin[100]; 
        //the string array was initialized has capacity is 100 and to remain the string input binary 
        while (1) {
            printf("Enter binary number: ");
            scanf("%s", bin);
            fpurge(stdin);
            if (checkInput(bin, 1) == 1)break; 
            //if the string input hexadecimal is satisfy all the regulations then the while loop will end
        }
        int p = strlen(bin) - 1; 
        //the p parameter was initialized has value is 0
        int dec = 0; 
        //the dec parameter was initialized has value is 0 and to remain the decimal 
        for (int i = 0; i < strlen(bin); i++) {
            dec += (bin[i] - 48) * pow(2, p); 
            //the new decimal number equals result of that integer element multiple by the power of 2 with p
            p--; 
            //the p parameter will decrease to 1 after 1 time loop
        }
        printf("Decimal number is:%d\n", dec);
        do {
            fpurge(stdin);
            printf("Press y to continue or n to return the main menu: ");
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
*  Purpose: Convert octal number to decimal number
*/
void otcToDec() {

    do {
        char op;
        char oct[100]; 
        //the string array was initialized has capacity is 100 and to remain the string input octal    
        while (1) {
            printf("Enter octal number: ");
            scanf("%s", oct); 
            //scan with octal number is %o in C
            fpurge(stdin);
            if (checkInput(oct, 2) == 1)break; 
            //if the string input hexadecimal is satisfy all the regulations then the while loop will end
        }
        int p = strlen(oct) - 1; 
        //the p parameter was initialized has value is 0
        int dec = 0; 
        //the dec parameter was initialized has value is 0 and to remain the decimal 
        for (int i = 0; i < strlen(oct); i++) {
            dec += (oct[i] - 48) * pow(8, p); 
            //the new decimal number equals result of that integer element multiple by the power of 8 with p
            p--; 
            //the p parameter will decrease to 1 after 1 time loop
        }
        printf("Decimal number is:%d\n", dec);
        do {
            fpurge(stdin);
            printf("Press y to continue or n to return the main menu: ");
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
*  Purpose: Convert hexadecimal number to decimal number
*/
void hexToDec() {

    do {
        char op;
        char hexa[100]; 
        //the string array was initialized has capacity is 100 and to remain the string input hexadecimal 
        int del = 0; 
        //the del parameter was initialized has value is 0 and to remain the decimal 
        while (1) {
            printf("Enter hexadecimal number: ");
            scanf("%s", hexa);
            fpurge(stdin);
            if (checkInput(hexa, 3) == 1)break; 
            //if the string input hexadecimal is satisfy all the regulations then the while loop will end
        }
        int p = strlen(hexa) - 1;
        
        //the p parameter was initialized has value equals the length of the string input hexadecimal decreased to 1 and counts the index of each elements in string
        for (int i = 0; i < strlen(hexa); i++) {
            //the i parameter begin from 0 to the length of the string input hexadecimal decreased to 1 and counts the position
            if (hexa[i] >= '0' && hexa[i] <= '9')
            //if i element of the string input hexadecimal is from '0' to '9'
                del += (hexa[i] - 48) * pow(16, p); 
                //the new decimal number equals result of that integer element (ASCII2) multiple by the power of 16 with p
            else if (hexa[i] >= 'a' && hexa[i] <= 'f') 
            //if i element of the string input hexadecimal is from 'a' to 'f'
                del += (hexa[i] - 87) * pow(16, p); 
                //the new decimal number equals result of that integer element (ASCII2) multiple by the power of 16 with p
            else  
            //if i element of the string input hexadecimal is from 'A' to 'F'
                del += (hexa[i] - 55) * pow(16, p); 
                //the new decimal number equals result of that integer element (ASCII2) multiple by the power of 16 with p         
            p--; 
            //the p parameter will decrease to 1 after 1 time loop
        }
        printf("Decimal number is:%d\n", del);
        do {
            fpurge(stdin);
            printf("Press y to continue or n to return the main menu: ");
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
void run() {
    do {
        int op; 
        //parameter of choose of user
        printf("1.Convert binary number to decimal number\n");
        printf("2.Convert octal number to decimal number\n");
        printf("3.Convert hexadecimal number to decimal number\n");
        printf("4.Exit\n");
        printf("Please choose number (1 to 4): ");
        scanf("%d", &op);
        switch (op) {
            case 1:
            {
                
                //Convert octal number to decimal number
                binToDec();
                break;
            }

            case 2:
            {
                
                //Convert octal number to decimal number
                otcToDec();
                break;
            }

            case 3:
            {
                
                //Convert hexadecimal number to decimal number
                hexToDec();
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
    run();
}