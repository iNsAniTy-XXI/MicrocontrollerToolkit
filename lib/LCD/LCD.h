#ifndef LCD_H
#define LCD_H 

#include <Arduino.h>
#include <LiquidCrystal.h>

class LCD {
public:
    LCD(int rs, int en, int d4, int d5, int d6, int d7);                       // Constructor to initialize LCD screen with corresponding pins.
    void configureDisplayGrid(int cols, int rows);                                      // Setup display. 
    void setCursor(int x, int y);                                                       // Set cursor to coordinate x,y
    int getRowIndex();
    int getColumnIndex();
    void displayMessage(String message);                                                 // Display a message.
    void clear();                                                                       // Clear the screen.
private:
    LiquidCrystal _lcd;
    int _rowIndex = 0;
    int _columnIndex = 0;
    bool _isConfigured = false;
};

#endif