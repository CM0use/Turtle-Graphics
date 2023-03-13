/**
 ** This file is part of https://github.com/CM0use/Turtle-Graphics
 ** Copyright 2023 CM0use <dilanuzcs@gmail.com>.
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

# include "../header/turtle.h"

int main(void)
{
    char map[MAX_COLUMNS][MAX_ROWS] = {0};
    uint16_t command;
    animal turtle;

    startSettings(&turtle, map);

    do {
        CLEAN_SCREEN
        instructions();
        showMap(map);
        
        printf(">>> ");
        while ( !input(&command) || ( command > 9 ) )
            printf("Invalid input\nTry again\n>>> ");
        
        CLEAN_SCREEN
        switch (command) {
            case 0:
            case 1:
            case 2:
                turtle.pen = command;
                break;

            case 3: orientation(&turtle); break;

            case 4: move(&turtle, map); break;
                
            case 6: showValues(&turtle); break;
            
            case 8: startSettings(&turtle, map);
            
            default: break;
        }
    } while (command != 9);
    
    return EXIT_SUCCESS;
}
