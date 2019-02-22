#include <stdio.h>
#include <stdlib.h>

/**
computes points for every throwing
@return the point of throwing

*/

int calculation_function_first(int throwing_point_2, char type_of_place_2)
{

    if (type_of_place_2 == 'I') {
        throwing_point_2 = 50;
    } else if (type_of_place_2 == 'S') {
        throwing_point_2 *= 1;
    } else if (type_of_place_2 == 'O') {
        throwing_point_2 = 25;
    } else if (type_of_place_2 == 'D') {
        throwing_point_2 *= 2;
    } else if (type_of_place_2 == 'T') {
        throwing_point_2 *= 3;
    }

    return throwing_point_2;
}

/**
computes remaining point from target
@return the remainder

*/
int calculation_function_second(int aim_3, int calculated_throwing_point, char type_of_place_3)
{
    int remainder;

    remainder = aim_3 - calculated_throwing_point;

    return remainder;
}

int main()
{

    char type_of_place_1;
    int throwing_point_1, aim_1, aim_2;

    printf("Target: ");
    scanf("%d", &aim_1);
    aim_2 = aim_1;
    while (aim_2 == aim_1) {

        printf("\nThrow: ");
        scanf("%d %c", &throwing_point_1, &type_of_place_1);
        if (type_of_place_1 == 'D' && calculation_function_second(aim_2, calculation_function_first(throwing_point_1, type_of_place_1), type_of_place_1) < aim_2) {

            aim_2 = calculation_function_second(aim_2, calculation_function_first(throwing_point_1, type_of_place_1), type_of_place_1);
        }
        printf("Points: %d", aim_2);
        while (aim_2 != aim_1 && aim_2 != 0) {
            printf("\nThrow: ");
            scanf("%d %c", &throwing_point_1, &type_of_place_1);
            if (type_of_place_1 == 'D' && calculation_function_first(throwing_point_1, type_of_place_1) <= aim_2) {

                aim_2 = calculation_function_second(aim_2, calculation_function_first(throwing_point_1, type_of_place_1), type_of_place_1);
            } else if (type_of_place_1 == 'I' && calculation_function_first(throwing_point_1, type_of_place_1) < aim_2) {

                aim_2 = calculation_function_second(aim_2, calculation_function_first(throwing_point_1, type_of_place_1), type_of_place_1);
            } else if (type_of_place_1 == 'O' && calculation_function_first(throwing_point_1, type_of_place_1) < aim_2) {

                aim_2 = calculation_function_second(aim_2, calculation_function_first(throwing_point_1, type_of_place_1), type_of_place_1);
            } else if (type_of_place_1 == 'S' && calculation_function_first(throwing_point_1, type_of_place_1) < aim_2) {

                aim_2 = calculation_function_second(aim_2, calculation_function_first(throwing_point_1, type_of_place_1), type_of_place_1);
            } else if (type_of_place_1 == 'T' && calculation_function_first(throwing_point_1, type_of_place_1) < aim_2) {

                aim_2 = calculation_function_second(aim_2, calculation_function_first(throwing_point_1, type_of_place_1), type_of_place_1);
            }
            printf("Points: %d", aim_2);
        }
    }
    printf("\n");
    return EXIT_SUCCESS;
}
