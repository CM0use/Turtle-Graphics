
//          Copyright CM0use.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

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
