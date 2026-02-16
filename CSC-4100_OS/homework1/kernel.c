#include "libos.h"

int clear_scr(int start_row, int start_col, int width, int height) {
    // Ensure we don't go out of bounds
    if (start_row + height > term_txtheight() || start_col + width > term_txtwidth()) {
        return 1;
    }

    // Fill the area with spaces
    for (int r = start_row; r < start_row + height; r++) {
        for (int c = start_col; c < start_col + width; c++) {
            putc_to(r, c, ' ');
        }
    }
    return 0;
}

int main(void) {
    // Requirements: srow=21, scol=49, erow=27, ecol=79
    unsigned int srow = 21;
    unsigned int scol = 49;
    unsigned int erow = 27;
    unsigned int ecol = 79;

    int width = (ecol - scol) + 1;
    int height = (erow - srow) + 1;

    clear_scr(srow, scol, width, height);
    box(srow, scol, erow, ecol);
    print_to(24, 59, "Hello world");

    while (1) {
        // Inifinite loop
    };
    return 0;
}