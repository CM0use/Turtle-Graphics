/**
 ** This file is part of Turtle-Graphics project
 ** Copyright 2023 CM0use dilanuzcs@gmail.com
 ** URL: https://github.com/CM0use/Turtle-Graphics
 **
 ** This program is free software: you can redistribute it and/or modify
 ** it under the terms of the GNU General Public License as published by
 ** the Free Software Foundation, either version 3 of the License, or
 ** (at your option) any later version.
 **
 ** This program is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ** GNU General Public License for more details.
 **
 ** You should have received a copy of the GNU General Public License
 ** along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **/

# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <stdint.h>
# include <errno.h>
# include <limits.h>
# include <time.h>
int nanosleep(const struct timespec *req, struct timespec *rem);

# include "../header/turtle.h"

extern void
instructions(void)
{
    puts("---------------------------\n"
         "0. Pen up (NO DRAWING).\n"
         "1. Pen down (DRAW).\n"
         "2. Draft\n\n"
         "3. Turtle Direction\n"
         "4. Moving forward.\n"
         "6. Print the turtle values.\n\n"
         "8. Restart game\n"
         "9. End of program.\n"
         "---------------------------");
}

extern void 
startSettings(animal *const turtle,
              char map[MAX_COLUMNS][MAX_ROWS])
{
    if (!turtle) return;

    for(uint8_t c = 0; c < MAX_COLUMNS; c++)
        for(uint8_t r = 0; r < MAX_ROWS; r++)
            *(*(map+c)+r) = 0;

    turtle->y = 0;
    turtle->x = 0;
    turtle->icon = ICON;
    turtle->pen = ABOVE;
    turtle->direction = RIGHT;

    *(*(map)) = ICON;
}

extern void
showValues(const animal *const turtle)
{
    if (!turtle) return;

    printf("---------------------------\n"
           "Turtle position\ny = %hu   x = %hu\n"
           "Turtle icon: %c\n"
           "Turtle direction: %s\n"
           "Pen: %s\n",
           turtle->y, turtle->x,
           turtle->icon,
           (turtle->direction == UP) ? "UP" :
           (turtle->direction == DOWN) ? "DOWN" :
           (turtle->direction == LEFT) ? "LEFT" : "RIGHT",

           (turtle->pen == ABOVE) ? "ABOVE" :
           (turtle->pen == BELOW) ? "BELLOW" : "DRAFT"
          );
    
    printf("Enter To Continue: ");
    while ((getchar()) != '\n');
}

extern void
showMap(char map[MAX_COLUMNS][MAX_ROWS])
{
    printf("This map is %hux%hu\n\n", MAX_ROWS, MAX_COLUMNS);
    
    for (uint8_t c = 0; c < MAX_COLUMNS; c++) {
        for (uint8_t r = 0; r < MAX_ROWS; r++) {
            if (!map[c][r] || map[c][r] == 2) putchar(' ');
            else if (map[c][r] == ICON) putchar(ICON);
            else putchar('*');
        }
        putchar('\n');
    }
}

extern void
orientation(animal *const turtle)
{
    if (!turtle) return;

    uint16_t direc;

    printf("\nUP: 0\nDOWN: 1\nLEFT: 2\nRIGHT: 3\n"
           ">>> ");
    while (!input(&direc) || ( direc > 4 ))
        printf("Invalid input\nTry again\n>>> ");
    
    turtle->direction = direc;
}

extern void
move(animal *const turtle,
     char map[MAX_COLUMNS][MAX_ROWS])
{
    if (!turtle) return;
    
    uint16_t steps;

    printf("\nSteps\n>>> ");
    while (!input(&steps))
        printf("Invalid input\nTry again\n>>> ");

    for (uint16_t i = 0; i < steps; i++) {
        switch (turtle->direction) {
            case UP:
                if (turtle->y > 0) {
                    map[turtle->y--][turtle->x] = turtle->pen;
                    map[turtle->y][turtle->x] = ICON;
                } else i = steps;
                break;
                
            case DOWN:
                if (turtle->y < MAX_COLUMNS-1) {
                    map[turtle->y++][turtle->x] = turtle->pen;
                    map[turtle->y][turtle->x] = ICON;
                } else i = steps;
                break;
                
            case LEFT:
                if (turtle->x > 0) {
                    map[turtle->y][turtle->x--] = turtle->pen;
                    map[turtle->y][turtle->x] = ICON;
                } else i = steps;
                break;

            case RIGHT:
                if (turtle->x < MAX_ROWS-1) {
                    map[turtle->y][turtle->x++] = turtle->pen;
                    map[turtle->y][turtle->x] = ICON;
                } else i = steps;
                break;

            default:
                puts("\?\?\?!!!");
                i = steps;
                break;
        }
        CLEAN_SCREEN
        instructions();
        showMap(map);
        nanosleep(&(const struct timespec){.tv_nsec=100000000}, NULL);
    }
}

uint16_t input(uint16_t *const n)
{
    if (!n)                         return 0;
    
    int32_t a;
    char buf[1024],
        *endptr;
        
    if (!fgets(buf, 1024, stdin))   return 0;

    errno = 0;
    a = strtol(buf, &endptr, 10);
    
    if (errno == ERANGE)            return 0;
    if (endptr == buf)              return 0;
    if (*endptr && *endptr != '\n') return 0;
    if (a > USHRT_MAX || a < 0)     return 0;
    
    *n = (uint16_t)a;
    
    return 1;
}
