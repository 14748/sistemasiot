#include <wiringPi.h>
#include <wiringPiI2C.h>

#define LCD_ADDRESS 0x27
#define LCD_WIDTH 16

int lcd;

void lcd_command(unsigned char command) {
    wiringPiI2CWrite(lcd, command);
    delay(5);
}

void lcd_init() {
    lcd_command(0x33);
    lcd_command(0x32);
    lcd_command(0x06);
    lcd_command(0x0C);
    lcd_command(0x28);
    lcd_command(0x01);
    delay(5);
}

void lcd_clear() {
    lcd_command(0x01);
    delay(5);
}

void lcd_write_string(char *str) {
    while (*str) {
        wiringPiI2CWriteReg8(lcd, 0x40, *str++);
    }
}

int main() {
    wiringPiSetup();
    lcd = wiringPiI2CSetup(LCD_ADDRESS);

    lcd_init();
    lcd_clear();
    lcd_write_string("Hello, world!");

    return 0;
}
