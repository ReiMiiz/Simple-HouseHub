#define WiFi_Logo_width 43
#define WiFi_Logo_height 41
const char WiFi_Logo_bits[] PROGMEM = {
0xff, 0xff, 0xff, 0xf7, 0xff, 0xdf, 
0xff, 0xff, 0x81, 0xe3, 0xff, 0x07, 
0xff, 0x7f, 0x00, 0xc4, 0xff, 0x07, 
0xff, 0x0f, 0x00, 0x80, 0xff, 0x07, 
0xff, 0x3f, 0x00, 0x00, 0xff, 0x07, 
0xff, 0xff, 0x00, 0x00, 0xff, 0x07, 
0xff, 0xf1, 0x1f, 0x00, 0xfe, 0x07, 
0x7f, 0x80, 0x7f, 0x00, 0xfe, 0x07, 
0x1f, 0x80, 0xbf, 0x0f, 0xfe, 0x07, 
0x0f, 0xe0, 0xdf, 0x17, 0xfa, 0x07, 
0x07, 0xf8, 0x0c, 0x28, 0xf3, 0x07, 
0x03, 0x3f, 0x3c, 0x70, 0xe3, 0x07, 
0xf3, 0x1f, 0x7f, 0xdc, 0xc7, 0x07, 
0xff, 0x8f, 0xff, 0x8f, 0x87, 0x07, 
0xbf, 0xdf, 0xf7, 0x1f, 0x0f, 0x07, 
0x87, 0xff, 0x03, 0x3f, 0x0e, 0x07, 
0x83, 0xf9, 0x23, 0x7c, 0x1e, 0x07, 
0xc1, 0xf9, 0xf3, 0x71, 0x1c, 0x07, 
0xc1, 0xfd, 0xf3, 0xf1, 0xbc, 0x07, 
0xe0, 0xfc, 0xf3, 0xf1, 0xff, 0x07, 
0xe0, 0xfc, 0x71, 0xf0, 0xff, 0x05, 
0xe0, 0xfc, 0x01, 0xfc, 0x7d, 0x04, 
0xf0, 0xfc, 0x01, 0xfe, 0x39, 0x04, 
0xf0, 0xff, 0x01, 0xfe, 0x39, 0x04, 
0xf8, 0xff, 0x39, 0xfc, 0x3c, 0x04, 
0xf8, 0xfd, 0x7c, 0xfc, 0x3d, 0x04, 
0xdd, 0xfd, 0xfc, 0xf8, 0x3c, 0x06, 
0xcf, 0xf9, 0xfe, 0xf3, 0x1e, 0x06, 
0x8f, 0xf3, 0xfe, 0xf7, 0x1f, 0x07, 
0x87, 0xe7, 0xfe, 0xff, 0xcf, 0x07, 
0x07, 0xcf, 0xff, 0x9f, 0xff, 0x07, 
0x03, 0xff, 0xff, 0xc7, 0xff, 0x07, 
0x07, 0x7e, 0xfe, 0xf1, 0x1f, 0x07, 
0x07, 0xfe, 0xc0, 0xfc, 0x81, 0x07, 
0x0f, 0xfc, 0xcf, 0x7f, 0xc0, 0x07, 
0x1f, 0x18, 0xff, 0x17, 0xc0, 0x07, 
0x3f, 0x18, 0xf8, 0x03, 0xe0, 0x07, 
0x7f, 0x38, 0xc0, 0x07, 0xf8, 0x07, 
0xff, 0x39, 0x00, 0x3f, 0xfc, 0x07, 
0xff, 0x73, 0x00, 0xfc, 0xff, 0x07, 
0xff, 0xff, 0x00, 0xf0, 0xff, 0x07, 
0xff, 0xff, 0x03, 0xfc, 0xff, 0x07,
  };

const char activeSymbol[] PROGMEM = {
    B00000000,
    B00000000,
    B00011000,
    B00100100,
    B01000010,
    B01000010,
    B00100100,
    B00011000
};

const char inactiveSymbol[] PROGMEM = {
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00011000,
    B00011000,
    B00000000,
    B00000000
};
