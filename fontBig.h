///*
// * File:   fontBig.h
// * Author: fabiobaraldi
// *
// * Created on 3 settembre 2012, 16.49
// */
//
////riga superiore
//const char fontBig[13][12] = {
//{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},//spazio
//{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},//.
//{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},//,
//{0b00000000,0b11111000,0b00000110,0b00000001,0b00000001,0b00000001,0b00000001,0b00000001,0b00000001,0b00000110,0b11111000,0b00000000},//0
//{0b00000000,0b00010000,0b00001000,0b00000100,0b00000010,0b11111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},//1
//{0b00000000,0b00011000,0b00000110,0b00000001,0b00000001,0b10000001,0b01000001,0b01000001,0b00100010,0b00011100,0b00000000,0b00000000},//2
//{0b00000000,0b00000000,0b00001100,0b00000010,0b00000001,0b00000001,0b01000001,0b01000001,0b10100010,0b00011100,0b00000000,0b00000000},//3
//{0b00000000,0b10000000,0b01000000,0b00110000,0b00001000,0b00000110,0b11111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},//4
//{0b00000000,0b00000000,0b00111111,0b00010001,0b00001001,0b00001001,0b00001001,0b00001001,0b00010001,0b00100001,0b11000000,0b00000000},//5
//{0b00000000,0b11110000,0b01001100,0b00100010,0b00010001,0b00010001,0b00010001,0b00010001,0b00100001,0b11000000,0b00000000,0b00000000},//6
//{0b00000000,0b00000000,0b00000011,0b00000001,0b00000001,0b00000001,0b00000001,0b11100001,0b00011001,0b00000111,0b00000000,0b00000000},//7
//{0b00000000,0b10000000,0b01011100,0b00100010,0b00100001,0b00100001,0b00100001,0b00100010,0b01011100,0b10000000,0b00000000,0b00000000},//8
//{0b00000000,0b11111100,0b00000010,0b00000001,0b00000001,0b00000001,0b00000001,0b00000001,0b10000110,0b11111000,0b00000000,0b00000000}//9
//};
//
////riga inferiore
//const char fontBig2[13][12] = {
//{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},//spazio
//{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b01100000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},//.
//{0b00000000,0b00000000,0b00000000,0b00000000,0b10000000,0b01100000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},//,
//{0b00000000,0b00000111,0b00011000,0b00100000,0b00100000,0b00100000,0b00100000,0b00100000,0b00100000,0b00011000,0b00000111,0b00000000},//0
//{0b00000000,0b00100000,0b00100000,0b00100000,0b00100000,0b00111111,0b00100000,0b00100000,0b00100000,0b00100000,0b00000000,0b00000000},//1
//{0b00000000,0b00111100,0b00100010,0b00100001,0b00100001,0b00100000,0b00100000,0b00100000,0b00100000,0b00100000,0b00011000,0b00000000},//2
//{0b00000000,0b00001100,0b00010000,0b00100000,0b00100000,0b00100000,0b00100000,0b00100000,0b00010000,0b00001111,0b00000000,0b00000000},//3
//{0b00000110,0b00000101,0b00000100,0b00000100,0b00000100,0b00000100,0b00111111,0b00000100,0b00000100,0b00000100,0b00000000,0b00000000},//4
//{0b00000000,0b00001100,0b00010000,0b00100000,0b00100000,0b00100000,0b00100000,0b00100000,0b00010000,0b00001000,0b00000111,0b00000000},//5
//{0b00000000,0b00000111,0b00011000,0b00100000,0b00100000,0b00100000,0b00100000,0b00100000,0b00010000,0b00001111,0b00000000,0b00000000},//6
//{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00111111,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},//7
//{0b00000000,0b00001111,0b00010000,0b00100000,0b00100000,0b00100000,0b00100000,0b00100000,0b00010000,0b00001111,0b00000000,0b00000000},//8
//{0b00000000,0b00000000,0b00100001,0b00100010,0b00100010,0b00100010,0b00100010,0b00010001,0b00001100,0b00000011,0b00000000,0b00000000}//9
//};