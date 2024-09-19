#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct personal_details {
    char user_name[20], mail_id[20], gender[20], number[10];
    long int age;
    int code;
} person;

struct car_details {
    char car_name[20], color[20], model[20];
    int num;
    long int total_days, cost, adv, rem;
    struct Date {
        long int day, month, year;
    } rent_date, return_date;
} rent;

void print_to_file(FILE *);
void scan_from_file(FILE *);
int car_rental(FILE *);
int car_return(FILE *);

int main() {
    FILE *fp;
    int option;
    clrscr();
    printf("\n\t\t _________________________________________________\n");
    printf("\t\t|                                                 |\n");
    printf("\t\t|              - CAR RENTAL SERVICE -             |\n"); 
    printf("\t\t|_________________________________________________|\n");
    printf("\n\n\t\tSelect from the below options:");
	printf("\n\n\t\t _____________________\t\t ____________________");
	printf("\n\t\t|                     |\t\t|                    |");
    printf("\n\t\t|     1) Rental       |\t\t|     2) Return      |");
	printf("\n\t\t|_____________________|\t\t|____________________|");
    printf("\n\n\t\tType in the number: ");
    scanf("%d", &option);
	clrscr();
    
    switch (option) {
        case 1:
            car_rental(fp);
            break;
        case 2:
            fp = fopen("car_rental_service.txt", "r");
            if (fp == NULL) {
                printf("\nFile cannot be opened");
                return 0;
            }
            car_return(fp);
            fclose(fp);
            break;
        default:
            printf("\n Choose either option 1 or 2\n");
			getch();
    }

    return 0;
}

int car_rental(FILE *fp) {
    fp = fopen("car_rental_service.txt", "a+");
    if (fp == NULL) {
        printf("File cannot be opened");
        return 0;
    }

    printf("\n\t-------------- Answer the below questions to rent a car --------------");
    rent.num = 1;
    
    printf("\n\n(provide your initial with an underscore. Don't use whitespace character)\n Enter your name: ");
    scanf(" %[^\n]", person.user_name);
    printf("\n Enter your age: ");
    scanf("%ld", &person.age);
    if (person.age < 18) {
        printf("\n You are not eligible to rent a car");
		getch();
        fclose(fp);
        exit(1);
    }
    printf("\n Enter your gender: ");
    scanf(" %[^\n]", person.gender);
    printf("\n Enter your mail id: ");
    scanf(" %[^\n]", person.mail_id);
    printf("\n Enter your mobile number: ");
    scanf(" %[^\n]", person.number);
    printf("\n Enter a 2 digit password code: ");
    scanf("%d", &person.code);
	printf("\n\n\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
    printf("\n\t+                -* Thank you for registering *-                +");
	printf("\n\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
    getch();
    clrscr();

    printf("\n Take a look at the below catalog: ");
    printf("\n\n ####################################################################");
    printf("\n # S.NO # CAR BRAND #   MODEL       #PER DAY(Rs)#        COLOR      #");
    printf("\n ####################################################################");
    printf("\n #  1   #  HYUNDAI  # Creta AT      #   3000    #  Copper Brown     #");
    printf("\n #  2   #  SUZUKI   # Celerio       #   3000    #  Glistening grey  #");
    printf("\n #  3   #  HONDA    # Civic         #   3500    #  Pearl White      #");
    printf("\n #  4   #  TOYOTA   # Innova Crysta #   4800    #  Tornado Red      #");
    printf("\n #  5   #  FORD     # Explorer      #   5000    #  Stone Blue       #");
    printf("\n #  6   #  TATA     # Indigo        #   3000    #  Spanish Tan      #");
    printf("\n #  7   #  KIYA     # Carens        #   4500    #  Sparkling Silver #");
    printf("\n #  8   #  AUDI     # Q3            #   6250    #  Ibis White       #");
    printf("\n #  9   #  JAGUAR   # XJL           #   22000   #  Farallon Black   #");
    printf("\n #  10  #  BENZ     # Mercedes      #   25000   #  Emerald Green    #");
    printf("\n ####################################################################");
    getch();
    clrscr();

    printf("\n Select the serial number of the car from the catalog: ");
    scanf("%d", &rent.num);
    
    if (rent.num < 1 || rent.num > 10) {
        printf("\n Invalid serial number. Please choose a number between 1 and 10.\n");
		getch();
        fclose(fp);
        exit(1);
    }

    printf("\n Enter the car renting day(dd): ");
    scanf("%ld", &rent.rent_date.day);
    printf("\n Enter the car renting month(mm): ");
    scanf("%ld", &rent.rent_date.month);
    printf("\n Enter the car renting year(yyyy): ");
    scanf("%ld", &rent.rent_date.year);
    printf("\n Enter the car returning date(dd): ");
    scanf("%ld", &rent.return_date.day);
    printf("\n Enter the car returning month(mm): ");
    scanf("%ld", &rent.return_date.month);
    printf("\n Enter the car returning year(yyyy): ");
    scanf("%ld", &rent.return_date.year);

    if (rent.rent_date.day > rent.return_date.day) {
        if (rent.rent_date.month % 2 == 1 || rent.rent_date.month == 8) {
            rent.total_days = (rent.return_date.day + 32) - rent.rent_date.day;
        } else {
            rent.total_days = (rent.return_date.day + 31) - rent.rent_date.day;
        }
    } else {
        rent.total_days = rent.return_date.day - rent.rent_date.day;
    }

    switch (rent.num) {
        case 1: {
            strcpy(rent.car_name, "HYUNDAI");
            strcpy(rent.model, "Creta_AT");
            strcpy(rent.color, "Copper_Brown");
            rent.cost = rent.total_days * 3000;
            break;
        }
		case 2: {
            strcpy(rent.car_name, "SUZUKI");
            strcpy(rent.model, "Celerio");
            strcpy(rent.color, "Glistening_Grey");
            rent.cost = rent.total_days * 3000;
            break;
        }
        case 3: {
            strcpy(rent.car_name, "HONDA");
            strcpy(rent.model, "Civic");
            strcpy(rent.color, "Pearl_White");
            rent.cost = rent.total_days * 3500;
            break;
        }
        case 4: {
            strcpy(rent.car_name, "TOYOTA");
            strcpy(rent.model, "Innova_Crysta");
            strcpy(rent.color, "Tornado_Red");
            rent.cost = rent.total_days * 4800;
            break;
        }
        case 5: {
            strcpy(rent.car_name, "FORD");
            strcpy(rent.model, "Explorer");
            strcpy(rent.color, "Stone_Blue");
            rent.cost = rent.total_days * 5000;
            break;
        }
        case 6: {
            strcpy(rent.car_name, "TATA");
            strcpy(rent.model, "Indigo");
            strcpy(rent.color, "Spanish_Tan");
            rent.cost = rent.total_days * 3200;
            break;
        }
        case 7: {
            strcpy(rent.car_name, "KIYA");
            strcpy(rent.model, "Carens");
            strcpy(rent.color, "Royal_Blue");
            rent.cost = rent.total_days * 4500;
            break;
        }
        case 8: {
            strcpy(rent.car_name, "AUDI");
            strcpy(rent.model, "Q3");
            strcpy(rent.color, "Ibis_White");
            rent.cost = rent.total_days * 6250;
            break;
        }
        case 9: {
            strcpy(rent.car_name, "JAGUAR");
            strcpy(rent.model, "XJL");
            strcpy(rent.color, "Farallon_Black");
            rent.cost = rent.total_days * 22000;
            break;
        }
        case 10: {
            strcpy(rent.car_name, "BENZ");
            strcpy(rent.model, "Mercedes");
            strcpy(rent.color, "Emerald_Green");
            rent.cost = rent.total_days * 25000;
            break;
        }
        default: {
            printf("\nSerial number not found");
            fclose(fp);
            exit(1);
        }
    }

    rent.adv = rent.cost / 3;
    rent.rem = rent.cost - rent.adv;

    fwrite(&person, sizeof(person), 1, fp);
    fwrite(&rent, sizeof(rent), 1, fp);

    fclose(fp);

    printf("\n\n\n\t****************** Thank you for renting ******************\n");
	getch();
	clrscr();
	printf(" \n\n\t __________________________________________________________________\n");
	printf("\t|                                                                  |\n");
    printf("\t|                 ========> USER DETAILS <========                 |\n");
	printf("\t|__________________________________________________________________|\n");
	printf("\n\t\t________________________________________________________");
    printf("\n\t\t  User name        : %s                                 ", person.user_name);
	printf("\n\t\t________________________________________________________");
    printf("\n\t\t  Age              : %ld", person.age);
    printf("\n\t\t  Gender           : %s", person.gender);
    printf("\n\t\t  Mail id          : %s", person.mail_id);
    printf("\n\t\t  Mobile number    : %s", person.number);
	printf("\n\t\t________________________________________________________");
    printf("\n\t\t  Password code     : %d                                ", person.code);
	printf("\n\t\t________________________________________________________");
	printf("\n\t __________________________________________________________________\n\n");
	printf("\n\n NOTE: SAVE YOUR USERNAME AND PASSWORD CODE WHICH IS MANDATORY WHILE RETURNING");
	getch();
	clrscr();
	printf(" \n\n\t _________________________________________________________________\n");
	printf("\t|                                                                 |\n");
    printf("\t|                 ========> CAR DETAILS <========                 |\n");
	printf("\t|_________________________________________________________________|\n");
    printf("\n\t\tCar brand        : %s", rent.car_name);
    printf("\n\t\tModel            : %s", rent.model);
    printf("\n\t\tColor            : %s", rent.color);
    printf("\n\t\tTotal cost       : Rs.%ld", rent.cost);
    printf("\n\t\tAdvance amount   : Rs.%ld", rent.adv);
    printf("\n\t\tRemaining amount : Rs.%ld", rent.rem);
	printf("\n\t\tStatus           : RENTED");
	printf("\n\t __________________________________________________________________");
	printf("\n\n\t\t************ CAR RENTED SUCCESSFULLY ************");
	getch();
	clrscr();
    return 0;
}

int car_return(FILE *fp) {
    long int passcode;
    char user_name[20];
    printf("\n Enter the user name: ");
    scanf(" %[^\n]", user_name);

    printf("\n Enter the password code: ");
    scanf("%ld", &passcode);
    rewind(fp);
    while (fread(&person, sizeof(person), 1, fp)) {
        fread(&rent, sizeof(rent), 1, fp);
        if (strcmp(person.user_name, user_name) == 0 && person.code == passcode) {
	getch();
	clrscr();
	printf(" \n\n\t __________________________________________________________________\n");
	printf("\t|                                                                  |\n");
    printf("\t|                 ========> USER DETAILS <========                 |\n");
	printf("\t|__________________________________________________________________|\n");
    printf("\n\t\tUser name        : %s", person.user_name);
    printf("\n\t\tAge              : %ld", person.age);
    printf("\n\t\tGender           : %s", person.gender);
    printf("\n\t\tMail id          : %s", person.mail_id);
    printf("\n\t\tMobile number    : %s", person.number);
	printf("\n\t ________________________________________________________________");
	getch();
	clrscr();
	printf(" \n\n\t _________________________________________________________________\n");
	printf("\t|                                                                 |\n");
    printf("\t|                 ========> CAR DETAILS <========                 |\n");
	printf("\t|_________________________________________________________________|\n");
    printf("\n\t\tCar brand        : %s", rent.car_name);
    printf("\n\t\tModel            : %s", rent.model);
    printf("\n\t\tColor            : %s", rent.color);
    printf("\n\t\tTotal cost       : Rs.%ld", rent.cost);
    printf("\n\t\tAdvance amount   : Rs.%ld", rent.adv);
    printf("\n\t\tRemaining amount : Rs.%ld", rent.rem);
	printf("\n\t\tStautus          : RETURNED");
	printf("\n\t ________________________________________________________________");
	printf("\n\n\t\t************ CAR RETURNED SUCCESSFULLY ************");
	getch();
	clrscr();
	return 0;
        }
		else{
			printf("\n\n\n\n\t\t\t\tYou have not rented a car \n \t\t\t\t\t(or) \n\t\t The username or password you entered is incorrect");
			getch();
			clrscr();
			return 0;
    }
	}

    printf("\n Car details not found for the given user name and advance amount.");
    return 0;
}