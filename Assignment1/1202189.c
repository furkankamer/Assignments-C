#include <stdio.h>
#include <stdlib.h>

int main()
{

    int day, month, year, offset, endyear, weekday, c, d, weekday2, j, year2, endyear2;

    printf("Enter date [year month day]: ");
    scanf("%d%d%d", &year, &month, &day);

    if ((month % 2 == 0 && month < 8 && day > 30) || (month % 2 == 0 && month >= 8 && day > 31) || (month % 2 != 0 && month < 8 && day > 31) || (month % 2 != 0 && month >= 8 && day > 30) || (month == 2 && day > 28)) {
        printf("Invalid date.\n");
        return EXIT_FAILURE;
    } else {

        printf("Enter end year: ");
        scanf("%d", &endyear);
        year2 = year;
        c = year;

        if (endyear > year && day <= 31 && day > 0 && month <= 12 && month) {

            if (month == 1 || month == 2) {
                year--;
                month += 12;
                endyear2 = endyear - 1;
            } else {
                c += 1;
                endyear2 = endyear;
            }
            offset = year % 100;
            j = year / 100;
            weekday = (day + ((13 * (month + 1)) / 5) + offset + (offset / 4) + (j / 4) + (5 * j)) % 7;

            d = 0;

            if (weekday == 0) {

                while (c <= endyear2) {

                    offset = c % 100;
                    j = c / 100;
                    weekday2 = (day + ((13 * (month + 1)) / 5) + offset + (offset / 4) + (j / 4) + (5 * j)) % 7;
                    if (weekday2 == 0) {
                        d++;
                    }
                    c++;
                }

                printf("It's a Saturday.\n");

                printf("Same day-and-month on same weekday between %d and %d: %d\n", year2 + 1, endyear, d);

            } else if (weekday == 1) {
                while (c <= endyear2) {

                    offset = c % 100;
                    j = c / 100;
                    weekday2 = (day + ((13 * (month + 1)) / 5) + offset + (offset / 4) + (j / 4) + (5 * j)) % 7;
                    if (weekday2 == 1) {
                        d++;
                    }
                    c++;
                }

                printf("It's a Sunday.\n");

                printf("Same day-and-month on same weekday between %d and %d: %d\n", year2 + 1, endyear, d);

            } else if (weekday == 2) {

                while (c <= endyear2) {

                    offset = c % 100;
                    j = c / 100;
                    weekday2 = (day + ((13 * (month + 1)) / 5) + offset + (offset / 4) + (j / 4) + (5 * j)) % 7;
                    if (weekday2 == 2) {
                        d++;
                    }
                    c++;
                }

                printf("It's a Monday.\n");

                printf("Same day-and-month on same weekday between %d and %d: %d\n", year2 + 1, endyear, d);

            } else if (weekday == 3) {

                while (c <= endyear2) {

                    offset = c % 100;
                    j = c / 100;
                    weekday2 = (day + ((13 * (month + 1)) / 5) + offset + (offset / 4) + (j / 4) + (5 * j)) % 7;
                    if (weekday2 == 3) {
                        d++;
                    }
                    c++;
                }

                printf("It's a Tuesday.\n");

                printf("Same day-and-month on same weekday between %d and %d: %d\n", year2 + 1, endyear, d);

            } else if (weekday == 4) {

                while (c <= endyear2) {

                    offset = c % 100;
                    j = c / 100;
                    weekday2 = (day + ((13 * (month + 1)) / 5) + offset + (offset / 4) + (j / 4) + (5 * j)) % 7;
                    if (weekday2 == 4) {
                        d++;
                    }
                    c++;
                }

                printf("It's a Wednesday.\n");

                printf("Same day-and-month on same weekday between %d and %d: %d\n", year2 + 1, endyear, d);

            } else if (weekday == 5) {

                while (c <= endyear2) {

                    offset = c % 100;
                    j = c / 100;
                    weekday2 = (day + ((13 * (month + 1)) / 5) + offset + (offset / 4) + (j / 4) + (5 * j)) % 7;
                    if (weekday2 == 5) {
                        d++;
                    }
                    c++;
                }

                printf("It's a Thursday.\n");

                printf("Same day-and-month on same weekday between %d and %d: %d\n", year2 + 1, endyear, d);

            } else if (weekday == 6) {

                while (c <= endyear2) {

                    offset = c % 100;
                    j = c / 100;
                    weekday2 = (day + ((13 * (month + 1)) / 5) + offset + (offset / 4) + (j / 4) + (5 * j)) % 7;
                    if (weekday2 == 6) {
                        d++;
                    }
                    c++;
                }

                printf("It's a Friday.\n");

                printf("Same day-and-month on same weekday between %d and %d: %d\n", year2 + 1, endyear, d);
            }
        }
    }

    return EXIT_SUCCESS;
}
