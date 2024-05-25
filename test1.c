#include <reg51.h>

#define LCD_PORT P1
sbit RS = P3^0; // Register select
sbit EN = P3^1; // Enable

void delay(unsigned int msec) {
    int i, j;
    for (i = 0; i < msec; i++)
        for (j = 0; j < 1275; j++);
}

void LCD_command(unsigned char cmd) {
    LCD_PORT = cmd;
    RS = 0; // Command mode
    EN = 1; // High-to-low pulse on enable pin
    delay(5);
    EN = 0;
}

void LCD_data(unsigned char dat) {
    LCD_PORT = dat;
    RS = 1; // Data mode
    EN = 1; // High-to-low pulse on enable pin
    delay(5);
    EN = 0;
}

void LCD_init() {
    LCD_command(0x38); // 2 lines, 5x7 matrix
    LCD_command(0x0E); // Display on, cursor blinking
    LCD_command(0x01); // Clear screen
    LCD_command(0x80); // Move cursor to beginning of first line
}

void display(int num) {
    LCD_data(num/10 + '0');
    LCD_data(num%10 + '0');
}

void main() {
    int seconds = 0;
    int running = 0; // Flag to indicate if the clock is running or stopped

    P2 = 0xFF; // Set Port 2 as input

    LCD_init();

    while(1) {
        if (P2^0 == 0 && running == 0) { // Start the clock
            running = 1;
        }

        if (P2^1 == 0 && running == 1) { // Stop the clock
            running = 0;
        }

        if (running == 1) {
            display(seconds);
            delay(1000); // Delay for 1 second
            seconds++;
            if (seconds == 100) // Reset the seconds after reaching 99
                seconds = 0;
        }
    }
}