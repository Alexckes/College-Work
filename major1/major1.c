//authors: James Heath, Khalil Hayes-Reed, Alexander Kesler, Ji-A Lee
#include "major1.h"
#include <stdio.h>

int main() {
    while(1) {
        unsigned int choice = 0;
        unsigned int lhs = 0;
        unsigned int rhs = -1;
        char* menu = "Enter the menu option for the operation to preform\n"
                    "(1) Count Leading Zeros\n"
                    "(2) Endian Swap\n"
                    "(3) Rotate-right\n"
                    "(4) Parity\n"
                    "(5) EXIT\n"
                    "--> ";

        printf("%s", menu);

        //needs more input checking and better error messages
        while (scanf("%u", &choice) != 1 || choice < 1 || 5 < choice) {
            printf("Error: Invalid menu option. Please try again.\n");
            printf("%s", menu);
        }
        if(choice == 5) {
            printf("Program terminating. Goodbye...\n");
            break;
        }

        do {
            printf("Enter a 32-bit number (>=1 and <=4294967295, inclusively): ");
        } while(scanf("%u", &lhs) != 1 || lhs == 0);

        if (choice == 3) {
            do {
                printf("Enter the number of positions to rotate-right the input (between 0 and 31, inclusively): ");
            } while(scanf("%u", &rhs) != 1 || 31 < rhs);
        }


        //printf output in case clause using the unsigned ints lhs and rhs and result
        unsigned int result;
        switch(choice) {
            //Count Leading Zeros - James Heath
            case 1:
                result = clz(lhs);
                printf("The number of leading zeros in %u is %u\n", lhs, result);
                break;

            //Endian Swap
            case 2:
		result = endian(lhs);
		printf("%u endian swapped is %u\n", lhs, result);
                break;

            //Rotate Right
            case 3:
                break;

            //Parity
            case 4:
                break;
        }
        
    }
    
    return 0;
}
