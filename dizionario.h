/* 
 * File:   dizionario.h
 * Author: Sabbiolino
 *
 * Created on 6 ottobre 2013, 22.54
 */

#ifndef DIZIONARIO_H
#define	DIZIONARIO_H

#define ITALIANO 0
#define INGLESE 1
#define FRANCESE 2
#define TEDESCO 3
#define SPAGNOLO 4
#define PORTOGHESE 5
#define RUSSO 6
#define POLACCO 7

const unsigned char testi[8][26][16]={
    {//ITALIANO
    "Parziale [l]    ",
    "Parziale [m3]   ",
    "Parziale [gal]  ",
    "Totale [l]      ",
    "Totale [m3]     ",
    "Totale [gal]    ",
    "Flusso [l/min]  ",
    "Flusso [m3/h] ",
    "Flusso [gal/min]",
    "Lingua          ",
    "Impulsi per Litr",
    "Impulsi per m3  ",
    "Impulsi per Gall",
    {0x55,0x6e,0x69,0x74,0x85,0x20,0x64,0x69,0x20,0x4d,0x69,0x73,0x75,0x72,0x61,0x00},//"Unit� di Misura ",
    "       Litri [l]",
    "   Galloni [gal]",
    " Metri Cubi [m3]",
    "Evidenzia       ",
    "          Totale",
    "          Flusso",
    "        Parziale",
    "Tempo Illuminaz.",
    {0x4c,0x75,0x6d,0x69,0x6e,0x6f,0x73,0x69,0x74,0x85,0x20,0x20,0x20,0x20,0x20,0x20},//              "Luminosit�      ",
    "Tempo Spegnimen.",
    "        Italiano",
    "Decimali        "
},
    {//INGLESE
    "Partial [l]     ",
    "Partial [m3]    ",
    "Partial [gal]   ",
    "Total [l]       ",
    "Total [m3]      ",
    "Total [gal]     ",
    "Flow r. [l/min] ",
    "Flow r. [m3/h]",
    "Flow r.[gal/min]",
    "Language        ",
    "Pulses per Liter",
    "Pulses per m3   ",
    "Pulses per Gallo",
    "Unit of Measure ",
    "      Liters [l]",
    "   Gallons [gal]",
    "   Cubic m. [m3]",
    "Highlights      ",
    "           Total",
    "       Flow rate",
    "         Partial",
    "Backlight Time  ",
    "Brightness      ",
    "Shutdown Timeout",
    "         English",
    "Decimal Places  "
},
    {//FRANCESE
    "Partiel [l]     ",
    "Partiel [m3]    ",
    "Partiel [gal]   ",
    "Total [l]       ",
    "Total [m3]      ",
    "Total [gal]     ",
    {0x44,0x82,0x62,0x69,0x74,0x20,0x5b,0x6c,0x2f,0x6d,0x69,0x6e,0x5d,0x00,0x00,0x00},//"D�bit [l/min]   ",
    {0x44,0x82,0x62,0x69,0x74,0x20,0x5b,0x6d,0x33,0x2f,0x68,0x5d,0x20,0x20,0x00,0x00},//"D�bit [m3/min]  ",
    {0x44,0x82,0x62,0x69,0x74,0x20,0x5b,0x67,0x61,0x6c,0x2f,0x6d,0x69,0x6e,0x5d,0x00},//"D�bit [gal/min] ",
    "Langue          ",
    "Impul. par Litre",
    "Impul. par m3   ",
    "Imp. par Gallon ",
    {0x55,0x6e,0x69,0x74,0x82,0x20,0x64,0x65,0x20,0x4d,0x65,0x73,0x75,0x72,0x65,0x00},//"Unit� de Mesure ",
    "      Litres [l]",
    "   Gallons [gal]",
    {0x4d,0x8a,0x74,0x72,0x65,0x73,0x20,0x43,0x75,0x62,0x2e,0x20,0x5b,0x6d,0x33,0x5d},//"M�tres Cub. [m3]",
    "Surligner       ",
    "           Total",
    {0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x44,0x82,0x62,0x69,0x74},//"           D�bit",
    "         Partiel",
    "Temps Eclairage ",
    {0x4c,0x75,0x6d,0x69,0x6e,0x6f,0x73,0x69,0x74,0x82,0x00,0x00,0x00,0x00,0x00,0x00},//"Luminosit�      ",
    {0x44,0x82,0x6c,0x61,0x69,0x20,0x45,0x78,0x74,0x69,0x6e,0x63,0x74,0x69,0x6f,0x6e},//"D�lai Extinction",
    {0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x46,0x72,0x61,0x6e,0x87,0x61,0x69,0x73},//"        Fran�ais"
    {0x44,0x82,0x63,0x69,0x6d,0x61,0x6c,0x65,0x73,0x20,0x20,0x20,0x20,0x20,0x20,0x20}
},
    {//TEDESCO
    "Partial [l]     ",
    "Partial [m3]    ",
    "Partial [gal]   ",
    "Gesamt [l]      ",
    "Gesamt [m3]     ",
    "Gesamt [gal]    ",
    "D.fluss [l/min] ",
    "D.fluss [m3/h]",
    "D.fluss[gal/min]",
    "Sprache         ",
    "Impulse pro l   ",
    "Impulse pro m3  ",
    "Impulse pro gal ",
    {0x4d,0x61,0xe1,0x65,0x69,0x6e,0x68,0x65,0x69,0x74,0x00,0x00,0x00,0x00,0x00,0x00},//"Ma�einheit      ",
    "       Liter [l]",
    "  Gallonen [gal]",
    " Kubikmeter [m3]",
    "Hervorheben     ",
    "          Gesamt",
    "         D.fluss",
    "         Partial",
    "Beleuchtungszeit",
    "Helligkeit      ",
    "Abschaltzeit    ",
    "         Deutsch",
    "Dezimalstellen  "
},
    {//SPAGNOLO
    "Parcial [L]     ",
    "Parcial [m3]    ",
    "Parcial [gal]   ",
    "Total [L]       ",
    "Total [m3]      ",
    "Total [gal]     ",
    "Caudal [L/min]  ",
    "Caudal [m3/h] ",
    "Caudal [gal/min]",
    "Idioma          ",
    "Pulsos por Litro",
    "Pulsos por m3   ",
    {0x50,0x75,0x6c,0x73,0x6f,0x73,0x20,0x70,0x6f,0x72,0x20,0x47,0x61,0x6c,0xa2,0x6e},//"Pulsos por Gal�n",
    "Unid. de Medida ",
    "      Litros [L]",
    "   Galones [gal]",
    {0x20,0x4d,0x2e,0x20,0x43,0xa3,0x62,0x69,0x63,0x6f,0x73,0x20,0x5b,0x6d,0x33,0x5d},//" M. C�bicos [m3]",
    "Resalte         ",
    "           Total",
    "          Caudal",
    "         Parcial",
    "Tiempo Luz Tras.",
    "Luminosidad     ",
    "Tiempo Apagar   ",
    {0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x45,0x73,0x70,0x61,0xa4,0x6f,0x6c},//"         Espa�ol"
    "Cifras Decimales"
},
    {//PORTOGHESE
    "Parcial [l]     ",
    "Parcial [m3]    ",
    "Parcial [gal]   ",
    "Total [l]       ",
    "Total [m3]      ",
    "Total [gal]     ",
    {0x56,0x61,0x7a,0xc6,0x6f,0x20,0x5b,0x6c,0x2f,0x6d,0x69,0x6e,0x5d,0x00,0x00,0x00},//"Vaz�o [l/min]   ",
    {0x56,0x61,0x7a,0xc6,0x6f,0x20,0x5b,0x6d,0x33,0x2f,0x68,0x5d,0x20,0x20,0x20,0x20},//"Vaz�o [m3/min]  ",
    {0x56,0x61,0x7a,0xc6,0x6f,0x20,0x5b,0x67,0x61,0x6c,0x2f,0x6d,0x69,0x6e,0x5d,0x20},//"Vaz�o [gal/min] ",
    "Idioma          ",
    "Pulsos por Litro",
    "Pulsos por m3   ",
    {0x50,0x75,0x6c,0x73,0x6f,0x73,0x20,0x70,0x6f,0x72,0x20,0x47,0x61,0x6c,0xc6,0x6f},//"Pulsos por Gal�o",
    "Unid. de Medida ",
    "      Litros [L]",
    {0x20,0x20,0x20,0x20,0x47,0x61,0x6c,0xe4,0x65,0x73,0x20,0x5b,0x67,0x61,0x6c,0x5d},//"    Gal�es [gal]",
    {0x20,0x4d,0x2e,0x20,0x43,0xa3,0x62,0x69,0x63,0x6f,0x73,0x20,0x5b,0x6d,0x33,0x5d},//" M. C�bicos [m3]",
    {0x52,0x65,0x61,0x6c,0x87,0x61,0x72,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20},//"Real�ar         ",
    "           Total",
    {0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x56,0x61,0x7a,0xc6,0x6f},//"           Vaz�o",
    "         Parcial",
    "Tempo Luz Fundo ",
    "Luminosidade    ",
    "Tempo Desligar  ",
    {0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x50,0x6f,0x72,0x74,0x75,0x67,0x75,0x88,0x73},//"       Portugu�s"
    "Casas Decimais  "
},
    {//RUSSO
    {0x009a,0x0061,0x0063,0x0094,0x009e,0x00aa,0x0098,0x006f,0x0065,0x0020,0x005b,0x0095,0x005d,0x00,0x00,0x00},//"????????? [?]   ",
    {0x009a,0x0061,0x0063,0x0094,0x009e,0x00aa,0x0098,0x006f,0x0065,0x0020,0x005b,0x009d,0x0033,0x005d,0x00,0x00},//"????????? [?3]  ",
    {0x009a,0x0061,0x0063,0x0094,0x009e,0x00aa,0x0098,0x006f,0x0065,0x0020,0x005b,0x00b2,0x0061,0x0095,0x002e,0x005d},//"????????? [???.]",
    {0x004f,0x008f,0x0097,0x0065,0x0065,0x0020,0x005b,0x0095,0x005d,0x00,0x00,0x00,0x00,0x00,0x00,0x00},//"????? [?]       ",
    {0x004f,0x008f,0x0097,0x0065,0x0065,0x0020,0x005b,0x009d,0x0033,0x005d,0x00,0x00,0x00,0x00,0x00,0x00},//"????? [?3]      ",
    {0x004f,0x008f,0x0097,0x0065,0x0065,0x0020,0x005b,0x00b2,0x0061,0x0095,0x002e,0x005d,0x00,0x00,0x00,0x00},//"????? [???.]    ",
    {0x0050,0x0061,0x0063,0x0078,0x006f,0x0081,0x0020,0x005b,0x0095,0x002f,0x009d,0x009e,0x0098,0x005d,0x00,0x00},//"?????? [?/???]  ",
    {0x0050,0x0061,0x0063,0x0078,0x006f,0x0081,0x0020,0x005b,0x009d,0x0033,0x002f,0x0068,0x005d,0x00,0x00,0x00},//"?????? [?3/???] ",
    {0x0050,0x0061,0x0063,0x0078,0x006f,0x0081,0x0020,0x005b,0x00b2,0x0061,0x0095,0x002f,0x009d,0x009e,0x0098,0x005d},//"?????? [???/???]",
    {0x00c2,0x00d3,0x00e2,0x009b,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},// "????            ",
    {0x008e,0x009d,0x0096,0x0079,0x0095,0x00f2,0x0063,0x00e2,0x0020,0x0098,0x0061,0x0020,0x0095,0x009e,0x0094,0x0070},//"???????? ?? ????",
    {0x008e,0x009d,0x0096,0x0079,0x0095,0x00f2,0x0063,0x00e2,0x0020,0x0098,0x0061,0x0020,0x009d,0x0033,0x00,0x00},//"???????? ?? ?3  ",
    {0x008e,0x009d,0x0096,0x0079,0x0095,0x002e,0x0020,0x0098,0x0061,0x0020,0x00b2,0x0061,0x0095,0x0095,0x006f,0x0098},//"?????. ?? ??????",
    {0x0045,0x0081,0x009e,0x0098,0x009e,0x0099,0x0061,0x0020,0x009e,0x00d3,0x009d,0x0065,0x0070,0x0065,0x0098,0x002e},//"??????? ???????.",
    {0x0020,0x0020,0x0020,0x0020,0x0020,0x0020,0x0020,0x00a5,0x009e,0x0094,0x0070,0x00e2,0x0020,0x005b,0x0095,0x005d},//"       ????? [?]",
    {0x0020,0x0020,0x0092,0x0061,0x0095,0x0095,0x006f,0x0098,0x00e2,0x0020,0x005b,0x00b2,0x0061,0x0095,0x002e,0x005d},//"  ??????? [???.]",
    {0x0020,0x0020,0x004b,0x0079,0x008f,0x006f,0x009d,0x0065,0x0094,0x0070,0x00e2,0x0020,0x005b,0x009d,0x0033,0x005d},//"  ????????? [?3]",
    {0x0042,0x00e2,0x0081,0x0065,0x0095,0x009e,0x0094,0x00f2,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},//"????????        ",
    {0x0020,0x0020,0x0020,0x0020,0x0020,0x0020,0x0020,0x0020,0x0020,0x0020,0x0020,0x004f,0x008f,0x0097,0x0065,0x0065},//"          ?????",
    {0x0020,0x0020,0x0020,0x0020,0x0020,0x0020,0x0020,0x0020,0x0020,0x0020,0x0050,0x0061,0x0063,0x0078,0x006f,0x0081},//"          ??????",
    {0x0020,0x0020,0x0020,0x0020,0x0020,0x0020,0x0020,0x009a,0x0061,0x0063,0x0094,0x009e,0x00aa,0x0098,0x006f,0x0065},//"       ?????????",
    {0x0042,0x0070,0x0065,0x009d,0x00d2,0x0020,0x0096,0x006f,0x0081,0x0063,0x00f1,0x0065,0x0094,0x009b,0x009e,0x00},//"????? ????????? ",
    {0x00c2,0x0070,0x009b,0x006f,0x0063,0x0094,0x00f2,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},//"???????         ",
    {0x0042,0x0070,0x0065,0x009d,0x00d2,0x0020,0x00f1,0x00e2,0x009b,0x0095,0x002e,0x00,0x00,0x00,0x00,0x00},//"????? ????.     ",
    {0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x50,0x79,0x63,0x63,0x9b,0x9e,0xae},//"         P??????"
    {0x81,0x65,0x63,0xD2,0x94,0x9e,0xaa,0x98,0xe2,0x65,0x20,0xd3,0x98,0x61,0x9b,0x9e}//0xd3 mettere maiuscolo ****
},
    {//POLACCO
    "Czesciowy [l]   ",
    "Czesciowy [m3]  ",
    "Czesciowy [gal] ",
    "Calkowity [l]   ",
    "Calkowity [m3]  ",
    "Calkowity [gal] ",
    "Przeplyw [l/min]",
    "Przepl. [m3/h]",
    "Przepl.[gal/min]",
    "Jezyk           ",
    "Impulsy na Litr ",
    "Impulsy na m3   ",
    "Impulsy na Galon",
    "Jednostka Miary ",
    "       Litry [l]",
    "    Galony [gal]",
    {0x4d,0x65,0x74,0x72,0x79,0x20,0x53,0x7a,0x65,0x93,0x83,0x20,0x5b,0x6d,0x33,0x5d},//"Metry Sze?? [m3]",
    "Zaznacz         ",
    "       Calkowity",
    "  Natez. przepl.",
    "       Czesciowy",
    "Czas Podswietl. ",
    "Jasnosc         ",
    "Czas Wylacz.    ",
    "          Polski",
    {0x4d,0x69,0x65,0x6a,0x73,0x63,0x20,0x44,0x7a,0x69,0x65,0x73,0x69,0x65,0x74,0x20}//terzultima lettera ****
}
};

const unsigned char strlowbatt[16]={32,32,32,32,32,32,32,32,32,32,32,32,32,1,2,3};

#endif	/* DIZIONARIO_H */

