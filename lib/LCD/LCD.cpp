#include "LCD.h"
#include <Arduino.h>

#define NUMBER_OF_COLUMNS 16
#define NUMBER_OF_ROWS 2

LCD::LCD(int rs, int en, int d4, int d5, int d6, int d7) : _lcd(rs, en, d4, d5, d6, d7) {
    configureDisplayGrid(NUMBER_OF_COLUMNS, NUMBER_OF_ROWS);
};

void LCD::configureDisplayGrid(int cols, int rows) {
    clear();

    _lcd.begin(cols, rows);
    _isConfigured = true;

    setCursor(0, 0);
}

void LCD::setCursor(int x, int y) {
    if (_isConfigured) {
        _rowIndex = x;
        _columnIndex = y;

        _lcd.setCursor(_columnIndex, _rowIndex);
    }
}

int LCD::getRowIndex() {
    return _rowIndex;
}

int LCD::getColumnIndex() {
    return _columnIndex;
}

void LCD::displayMessage(String message) {
    if (_isConfigured) {
        _lcd.print(message);
    }
}

void LCD::clear() {
    if (_isConfigured) {
        _lcd.clear();
    }
}