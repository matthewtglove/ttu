#include "libos.h"

// Clear a rectangular area of the screen
int clear_scr(int start_row, int start_col, int width, int height) {
    // check if the parameters are valid
    if (start_row < 0 || start_col < 0 || width < 0 || height < 0) {
        return 1;
    }
    if (start_row + height > term_txtheight() || start_col + width > term_txtwidth()) {
        return 1;
    }

    // loop through the rows and columns of the rectangular area and print a space character
    for (int r = start_row; r < start_row + height; r++) {
        for (int c = start_col; c < start_col + width; c++) {
            putc_to(r, c, ' ');
        }
    }
    return 0;
}

int main(void) {
    clear_scr(0, 0, term_txtwidth(), term_txtheight());

    // call the box function with the start row, start column, end row, and end column of the box
    unsigned int srow = 21;
    unsigned int scol = 49;
    unsigned int erow = 27;
    unsigned int ecol = 79;
    box(srow, scol, erow, ecol);

    // call print_to with the row and column, and string to print
    int row = 24;
    int col = 59;
    char *string = "Hello world";
    print_to(row, col, string);

    return 0;
}
