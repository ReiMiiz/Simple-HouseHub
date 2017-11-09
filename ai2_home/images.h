#define Logo_width 43
#define Logo_height 41
const char Logo_bits[] PROGMEM = {
0x00, 0x00, 0x00, 0x08, 0x00, 0xd8, 
0x00, 0x00, 0x7e, 0x1c, 0x00, 0x00, 
0x00, 0x80, 0xff, 0x3b, 0x00, 0x00, 
0x00, 0xf0, 0xff, 0x7f, 0x00, 0x00, 
0x00, 0xc0, 0xff, 0xff, 0x00, 0x00, 
0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 
0x00, 0x0e, 0xe0, 0xff, 0x01, 0x00, 
0x80, 0x7f, 0x80, 0xff, 0x01, 0x00, 
0xe0, 0x7f, 0x40, 0xf0, 0x01, 0x00, 
0xf0, 0x1f, 0x20, 0xe8, 0x05, 0x00, 
0xf8, 0x07, 0xf3, 0xd7, 0x0c, 0x00, 
0xfc, 0xc0, 0xc3, 0x8f, 0x1c, 0x00, 
0x0c, 0xe0, 0x80, 0x23, 0x38, 0x00, 
0x00, 0x70, 0x00, 0x70, 0x78, 0x00, 
0x40, 0x20, 0x08, 0xe0, 0xf0, 0x00, 
0x78, 0x00, 0xfc, 0xc0, 0xf1, 0x00, 
0x7c, 0x06, 0xdc, 0x83, 0xe1, 0x00, 
0x3e, 0x06, 0x0c, 0x8e, 0xe3, 0x00, 
0x3e, 0x02, 0x0c, 0x0e, 0x43, 0x00, 
0x1f, 0x03, 0x0c, 0x0e, 0x00, 0x00, 
0x1f, 0x03, 0x8e, 0x0f, 0x00, 0x02, 
0x1f, 0x03, 0xfe, 0x03, 0x82, 0x03, 
0x0f, 0x03, 0xfe, 0x01, 0xc6, 0x03, 
0x0f, 0x00, 0xfe, 0x01, 0xc6, 0x03, 
0x07, 0x00, 0xc6, 0x03, 0xc3, 0x03, 
0x07, 0x02, 0x83, 0x03, 0xc2, 0x03, 
0x22, 0x02, 0x03, 0x07, 0xc3, 0x01, 
0x30, 0x06, 0x01, 0x0c, 0xe1, 0x01, 
0x70, 0x0c, 0x01, 0x08, 0xe0, 0x00, 
0x78, 0x18, 0x01, 0x00, 0x30, 0x00, 
0xf8, 0x30, 0x00, 0x60, 0x00, 0x00, 
0xfc, 0x00, 0x00, 0x38, 0x00, 0x00, 
0xf8, 0x81, 0x01, 0x0e, 0xe0, 0x00, 
0xf8, 0x01, 0x3f, 0x03, 0x7e, 0x00, 
0xf0, 0x03, 0x30, 0x80, 0x3f, 0x00, 
0xe0, 0xe7, 0x00, 0xe8, 0x3f, 0x00, 
0xc0, 0xe7, 0x07, 0xfc, 0x1f, 0x00, 
0x80, 0xc7, 0x3f, 0xf8, 0x07, 0x00, 
0x00, 0xc6, 0xff, 0xc0, 0x03, 0x00, 
0x00, 0x8c, 0xff, 0x03, 0x00, 0x00, 
0x00, 0x00, 0xff, 0x0f, 0x00, 0x00, 
0x00, 0x00, 0xfc, 0x03, 0x00, 0x00,
  };
  
#define icon_res 32
const char lightOff[] PROGMEM = {
0x00, 0x00, 0x00, 0x00, 
0x00, 0xc0, 0x03, 0x00, 
0x00, 0x38, 0x1c, 0x00, 
0x00, 0x06, 0x60, 0x00, 
0x00, 0x01, 0x80, 0x00, 
0x80, 0x00, 0x00, 0x01, 
0x80, 0x00, 0x00, 0x01, 
0x80, 0x00, 0x00, 0x01, 
0x40, 0x00, 0x00, 0x02, 
0x40, 0x00, 0x00, 0x02, 
0x40, 0x00, 0x00, 0x02, 
0x80, 0x00, 0x00, 0x01, 
0x80, 0x00, 0x00, 0x01, 
0x80, 0x00, 0x00, 0x01, 
0x00, 0x01, 0x80, 0x00, 
0x00, 0x91, 0x89, 0x00, 
0x00, 0x62, 0x46, 0x00, 
0x00, 0x22, 0x44, 0x00, 
0x00, 0x24, 0x24, 0x00, 
0x00, 0x48, 0x12, 0x00, 
0x00, 0x48, 0x12, 0x00, 
0x00, 0x50, 0x0a, 0x00, 
0x00, 0x50, 0x0a, 0x00, 
0x00, 0xe0, 0x07, 0x00, 
0x00, 0x00, 0x00, 0x00, 
0x00, 0xe0, 0x07, 0x00, 
0x00, 0x40, 0x02, 0x00, 
0x00, 0xe0, 0x07, 0x00, 
0x00, 0x40, 0x02, 0x00, 
0x00, 0xc0, 0x03, 0x00, 
0x00, 0x80, 0x01, 0x00, 
0x00, 0x00, 0x00, 0x00,
};

const char lightOn[] PROGMEM = {
0x02, 0x00, 0x00, 0x40, 
0x04, 0xc0, 0x03, 0x20, 
0x08, 0xf8, 0x1f, 0x10, 
0x10, 0xfe, 0x7f, 0x08, 
0x00, 0xff, 0xff, 0x00, 
0x80, 0xff, 0xff, 0x01, 
0x80, 0xff, 0xff, 0x01, 
0x80, 0xff, 0xff, 0x01, 
0xc0, 0xff, 0xff, 0x03, 
0xc0, 0xff, 0xff, 0x03, 
0xc0, 0xff, 0xff, 0x03, 
0x80, 0xff, 0xff, 0x01, 
0x80, 0xff, 0xff, 0x01, 
0x80, 0xff, 0xff, 0x01, 
0x00, 0xff, 0xff, 0x00, 
0x00, 0xff, 0xff, 0x00, 
0x00, 0xfe, 0x7f, 0x00, 
0x00, 0xfe, 0x7f, 0x00, 
0x00, 0xfc, 0x3f, 0x00, 
0x00, 0xf8, 0x1f, 0x00, 
0x20, 0xf8, 0x1f, 0x00, 
0x10, 0xf0, 0x0f, 0x08, 
0x08, 0xf0, 0x0f, 0x10, 
0x04, 0xe0, 0x07, 0x20, 
0x00, 0x00, 0x00, 0x40, 
0x00, 0xe0, 0x07, 0x00, 
0x00, 0x40, 0x02, 0x00, 
0x00, 0xe0, 0x07, 0x00, 
0x00, 0x40, 0x02, 0x00, 
0x00, 0xc0, 0x03, 0x00, 
0x00, 0x80, 0x01, 0x00, 
0x00, 0x00, 0x00, 0x00,
};

const char ac[] PROGMEM = {
0x00, 0x00, 0x01, 0x00, 
0x00, 0x00, 0x01, 0x00, 
0x00, 0x10, 0x19, 0x00, 
0x00, 0x60, 0x0f, 0x00, 
0x00, 0x80, 0x01, 0x00, 
0x20, 0x00, 0x01, 0x00, 
0x20, 0x18, 0x11, 0x08, 
0x36, 0x62, 0x9d, 0x08, 
0x1c, 0x82, 0x83, 0xc8, 
0x30, 0x02, 0x81, 0x78, 
0xcc, 0x03, 0x81, 0x1c, 
0x03, 0x03, 0x81, 0x37, 
0x80, 0x0f, 0xc1, 0x41, 
0x70, 0x18, 0x71, 0x06, 
0x00, 0x60, 0x1d, 0x0c, 
0x00, 0xc0, 0x03, 0x00, 
0x00, 0xc0, 0x03, 0x00, 
0x70, 0x38, 0x0d, 0x18, 
0xc0, 0x0e, 0x39, 0x0e, 
0x83, 0x03, 0xe1, 0x03, 
0xe6, 0x02, 0x81, 0x61, 
0x38, 0x03, 0xc1, 0x3f, 
0x1e, 0x01, 0x41, 0x1c, 
0x13, 0x01, 0x41, 0x34, 
0x10, 0xe1, 0x07, 0x64, 
0x10, 0x30, 0x19, 0x04, 
0x00, 0x00, 0x21, 0x00, 
0x00, 0x80, 0x01, 0x00, 
0x00, 0x60, 0x07, 0x00, 
0x00, 0x00, 0x19, 0x00, 
0x00, 0x00, 0x01, 0x00, 
0x00, 0x00, 0x01, 0x00,
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

