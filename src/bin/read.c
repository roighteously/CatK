#include "console.h"
#include "vga.h"

int readnum;

void read() {
    printf("\n");
    while (1) {
            // Read a key scancode
            unsigned char scancode = read_key();

            if (scancode == 0x48)
            {
                return 0;
            }

            // Convert the scancode to a character
            char key = scancode_to_char(scancode);

            // Check if a valid character was returned
            if (key != 0) {
                // Print the character to the console
                if (scancode == ENTER_KEY_SCANCODE) {
                    break; // Exit the inner loop
                }
                if (scancode == 0x48) {
                    console_scroll(1);
                }
                if (scancode == 0x02)
                {
                    readnum = 1;
                }
                if (scancode == 0x03)
                {
                    readnum = 2;
                }
                if (scancode == 0x04)
                {
                    readnum = 3;
                }
                if (scancode == 0x05)
                {
                    readnum = 4;
                }
                printf("%c", key);
            }
        
    }
}
