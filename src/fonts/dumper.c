#include <stdio.h>

const unsigned NUMBER_START = 48;
const unsigned LETTER_START = 65;

int main() {
    FILE *fp;

    unsigned size = 16 * 5400;
    unsigned char font[size];
    fp = fopen("PixeloidSans.ttf" , "r");
    fgets (font, size, fp);
    fclose(fp);

    fp = fopen("font_hex.txt" , "w");
    char buf[5];
    for (int i = 0; i < size; i++) {
        unsigned char a = (font[i] & 0b11110000) >> 4;
        unsigned char b = font[i] & 0b00001111;

        if (a < 10) a += NUMBER_START;
        else a += LETTER_START - 10;

        if (b < 10) b += NUMBER_START;
        else b += LETTER_START - 10;
        buf[0] = '0';
        buf[1] = 'x';
        buf[2] = a;
        buf[3] = b;
        buf[4] = ',';
        fwrite(buf , 1 , sizeof(buf) , fp);
    }
    fclose(fp);
    
    return(0);
}