/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: ThinhVNHE141345
 * Purpose: Make Simple Slot Machine.
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*  Author: ThinhVNHE141345
 *  Date: 20/01/2020 (tuy theo ngay code)
 *  Purpose: save money to the txt file in the computer
 */
void saveMoney(float *money) {

	FILE *fp = NULL; 
    // initialized a file pointer fp
	fp = fopen("MONEY.txt", "w");
	if (fp != NULL) {
    // if fp is exist data, the command inside its will implement
		fprintf(fp, "%.2f", *money);
		printf("Your money had saved!\n");
		fclose(fp);
	} else
	printf("Failed to save money!\n");
}


/*  Author: ThinhVNHE141345
 *  Date: 20/01/2020 (tuy theo ngay code)
 *  Purpose: create a random number from 0 to 999 and return it
 */
int ranDom() {

	srand((int) time(0));
	return rand() % 1000; 
    //create a random number at the moment the user run the program
    //the algorithm: 
    //randomNumberAtBetween = minNumber + randomNumber / (maxNumber + 1 - minNumber)
    //minNumber = 0
    //maxNumber = 999
}

/*  Author: ThinhVNHE141345
 *  Date: 20/01/2020 (tuy theo ngay code)
 *  Purpose: check an integer 3 digits number whether 2 in 3 digits is a match
 */
int splitNumber(int number) {

	int a[3];
     // an array has 3 values which to save each digit of the number
	int i = 0; 
    //parameter i was initialized to counts the number of the array
	while (number != 0) {
		a[i] = number % 10; 
        //the algorithm splits each digit of the number from units to hundreds and assigns into temp
		++i; 
        //increase the position of the array to 1 
		number /= 10; 
        //the number decreases to 10 times
	}
	if (a[0] == a[1] || a[0] == a[2] || a[1] == a[2])
    //if 2 in 3 value in the array are equal, the function will return 1
		return 1;
	else
		return 0;
}

/*  Author: ThinhVNHE141345
 *  Date: 20/01/2020 (tuy theo ngay code)
 *  Purpose: check an integer number whether the digits inside its is equal or not 
 */
int checkShows(int random) {

	if (random >= 100 && random <= 999) {
    //check the number from 100 to 999
		if (random % 111 == 0)
			return 3; 
            //if the number has 3 digits is equal then return 3
		else if (splitNumber(random) == 1)
			return 2; 
            //if the number has 2 in 3 digits is equal then return 2
		else
			return 1; 
            //if the number has 3 digits isn't equal then return 1
	} else if (random >= 10 && random < 100) {
    		//check the number from 10 to 99
		if (random % 10 == 0 || random % 11 == 0)
			return 2; 
            //if the number is divisible by 10 or 11 then return 1
		else
			return 1; 
            //if the number isn't divisible by 10 or 11 then return 1
	} else {
    		//check the number from 0 to 9
		if (random == 0)
			return 3; 
            //if the number is 0 then return 3
		else
			return 2; 
            //if the number is from 1 to 9 then return 2
	}
}

/*  Author: ThinhVNHE141345
 *  Date: 20/01/2020 (tuy theo ngay code)
 *  Purpose: Play the slot machine
 */
void play(float *money) {
    
    *money -= 0.25; 
    //the user gotta pay 25 cents for each round
    int temp = ranDom(); 
    //a temp parameter was assigned from a random number 
   
    if (temp >= 10 && temp <= 99)
    	printf("The slot machine shows 0%d.\n", temp);
    else if (temp >= 0 && temp <= 9)
    	printf("The slot machine shows 00%d.\n", temp);
    else
    	printf("The slot machine shows %d.\n", temp);
    if (checkShows(temp) == 3) {
        *money += 10; 
        //if the i parameter equals 3, the money will increase to 10 dollars 
        printf("You win the big prize!, $10.00!\n");
    } else if (checkShows(temp) == 2) {
        *money +=0.5; 
        //if the i parameter equals 2, the money will increase to 10 dollars 
        printf("You win 50 cents!\n");
    } else
    printf("Sorry you don't win anything!\n");
}


/*  Author: ThinhVNHE141345
 *  Date: 20/01/2020 (tuy theo ngay code)
 *  Purpose: read money from the txt file in the computer
 */
float loadMoney() {
    
    FILE *fp;
     // initialized a file pointer fp
    fp = fopen("MONEY.txt", "rt"); 
    // open txt file in the computer
    float fMoney; 
    // the fMoney parameter to remain money which was read from file
    if (fp != NULL)
    // if command to checks whether file is null or not
    	fscanf(fp, "%f", &fMoney);
    else
    	printf("Can't load your MONEY!\n");    
    fclose(fp);
    return fMoney; 
    //return money which was read from file
}


/*  Author: ThinhVNHE141345
 *  Date: 20/01/2020 (tuy theo ngay code)
 *  Purpose: label and get the option of user
 */
void run(float money) {
    
	do {
        if (money == 0) {
        //if ran out of money the game will end    
        	printf("\n");
        	printf("-------------------------------------------------\n");
        	printf("You ran out of money! You need to top up to play.\n");
        	exit(0);
        }
        int option; 
        //parameter of choose of user
        printf("You have $%.2f\n", money);
        printf("Choose one of the following menu options:\n");
        printf("1). Play the slot machine\n");
        printf("2). Save game\n");
        printf("3). Cash out\n");
        scanf("%d", &option);
        fflush(stdin);       
        switch(option){
        	case 1:{
                play(&money); 
                //Play the slot machine
                break;
            }
            case 2:{
                saveMoney(&money); 
                //Save game
                break;
            }
            case 3:{
                printf("Thank you for playing! You end with $%.2f!\n", money); 
                //Cash out
                exit(0);
            }
        }
    } while (1);
}

int main(int argc, char** argv) {
    float money = loadMoney(); 
    //the money parameter was initialized has the value from money which was read from file
    run(money);
     //implement run function 
}

