#include <wiringPiI2C.h>

// Define I2C bus and LCD address
#define I2C_ADDR 0x27
#define LCD_CHR  1
#define LCD_CMD  0

// Function to send commands to the LCD
void lcd_command(int fd, unsigned char cmd) {
  wiringPiI2CWriteReg8(fd, LCD_CMD, cmd);
  delay(50);
}

// Function to send data to the LCD
void lcd_data(int fd, unsigned char data) {
  wiringPiI2CWriteReg8(fd, LCD_CHR, data);
  delay(50);
}

// Function to initialize the LCD
void lcd_init(int fd) {
  lcd_command(fd, 0x33);
  lcd_command(fd, 0x32);
  lcd_command(fd, 0x06);
  lcd_command(fd, 0x0C);
  lcd_command(fd, 0x28);
  lcd_command(fd, 0x01);
  delay(50);
}

int main() {
  // Initialize the I2C bus and LCD display
  int fd = wiringPiI2CSetup(I2C_ADDR);
  lcd_init(fd);

  // Set the cursor to the start of the display
  lcd_command(fd, 0x80);

  // Write the string to the display
  char* message = "Hello, world!";
  for(int i = 0; i < strlen(message); i++) {
    lcd_data(fd, message[i]);
  }

  return 0;
}
