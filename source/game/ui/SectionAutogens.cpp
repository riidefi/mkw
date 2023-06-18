#include "SectionAutogens.hpp"

// --- EXTERN DECLARATIONS BEGIN ---

extern "C" {

// Extern function references.
// PAL: 0x80622d08
void Section_addPage(void*, s32);
// PAL: 0x80622da0
void Section_addActivePage(void*, s32);
// PAL: 0x80897d94
extern UNKNOWN_DATA(lbl_80897d94);
}

// --- EXTERN DECLARATIONS END ---

void Section_addPages(void* pSection, int sectionId) {
  switch (sectionId) {
  case 6:
    Section_addPage(pSection, 0);
    break;
  case 7:
    Section_addPage(pSection, 0);
    break;
  case 8:
    Section_addPage(pSection, 0);
    break;
  case 9:
    Section_addPage(pSection, 0);
    break;
  case 10:
    Section_addPage(pSection, 0);
    break;
  case 11:
    Section_addPage(pSection, 0);
    break;
  case 12:
    Section_addPage(pSection, 0);
    break;
  case 13:
    Section_addPage(pSection, 0);
    break;
  case 14:
    Section_addPage(pSection, 0);
    break;
  case 15:
    Section_addPage(pSection, 0);
    break;
  case 16:
    Section_addPage(pSection, 3);
    Section_addPage(pSection, 79);
    Section_addPage(pSection, 93);
    break;
  case 17:
    Section_addPage(pSection, 3);
    Section_addPage(pSection, 79);
    Section_addPage(pSection, 83);
    Section_addPage(pSection, 93);
    break;
  case 18:
    Section_addPage(pSection, 3);
    Section_addPage(pSection, 79);
    Section_addPage(pSection, 83);
    Section_addPage(pSection, 93);
    break;
  case 19:
    Section_addPage(pSection, 4);
    Section_addPage(pSection, 83);
    Section_addPage(pSection, 93);
    break;
  case 20:
    Section_addPage(pSection, 5);
    Section_addPage(pSection, 93);
    break;
  case 21:
    Section_addPage(pSection, 6);
    Section_addPage(pSection, 93);
    break;
  case 22:
    Section_addPage(pSection, 1);
    break;
  case 23:
    Section_addPage(pSection, 2);
    break;
  case 24:
    Section_addPage(pSection, 2);
    break;
  case 25:
    Section_addPage(pSection, 7);
    break;
  case 26:
    Section_addPage(pSection, 8);
    break;
  case 27:
    Section_addPage(pSection, 9);
    break;
  case 28:
    Section_addPage(pSection, 10);
    break;
  case 29:
    Section_addPage(pSection, 11);
    break;
  case 30:
    Section_addPage(pSection, 12);
    Section_addPage(pSection, 23);
    Section_addPage(pSection, 32);
    Section_addPage(pSection, 44);
    Section_addPage(pSection, 47);
    Section_addPage(pSection, 48);
    Section_addPage(pSection, 58);
    break;
  case 31:
    Section_addPage(pSection, 13);
    Section_addPage(pSection, 25);
    Section_addPage(pSection, 33);
    Section_addPage(pSection, 41);
    Section_addPage(pSection, 43);
    Section_addPage(pSection, 45);
    Section_addPage(pSection, 46);
    Section_addPage(pSection, 58);
    Section_addPage(pSection, 167);
    break;
  case 32:
    Section_addPage(pSection, 14);
    Section_addPage(pSection, 24);
    Section_addPage(pSection, 34);
    Section_addPage(pSection, 47);
    Section_addPage(pSection, 48);
    Section_addPage(pSection, 58);
    break;
  case 33:
    Section_addPage(pSection, 15);
    Section_addPage(pSection, 24);
    Section_addPage(pSection, 34);
    Section_addPage(pSection, 44);
    Section_addPage(pSection, 47);
    Section_addPage(pSection, 48);
    Section_addPage(pSection, 58);
    break;
  case 34:
    Section_addPage(pSection, 16);
    Section_addPage(pSection, 24);
    Section_addPage(pSection, 34);
    Section_addPage(pSection, 44);
    Section_addPage(pSection, 47);
    Section_addPage(pSection, 48);
    Section_addPage(pSection, 58);
    break;
  case 35:
    Section_addPage(pSection, 17);
    Section_addPage(pSection, 24);
    Section_addPage(pSection, 34);
    Section_addPage(pSection, 44);
    Section_addPage(pSection, 47);
    Section_addPage(pSection, 48);
    Section_addPage(pSection, 58);
    break;
  case 36:
    Section_addPage(pSection, 14);
    Section_addPage(pSection, 24);
    Section_addPage(pSection, 34);
    Section_addPage(pSection, 47);
    Section_addPage(pSection, 50);
    Section_addPage(pSection, 58);
    break;
  case 37:
    Section_addPage(pSection, 15);
    Section_addPage(pSection, 24);
    Section_addPage(pSection, 34);
    Section_addPage(pSection, 44);
    Section_addPage(pSection, 47);
    Section_addPage(pSection, 50);
    Section_addPage(pSection, 58);
    break;
  case 38:
    Section_addPage(pSection, 16);
    Section_addPage(pSection, 24);
    Section_addPage(pSection, 34);
    Section_addPage(pSection, 44);
    Section_addPage(pSection, 47);
    Section_addPage(pSection, 50);
    Section_addPage(pSection, 58);
    break;
  case 39:
    Section_addPage(pSection, 17);
    Section_addPage(pSection, 24);
    Section_addPage(pSection, 34);
    Section_addPage(pSection, 44);
    Section_addPage(pSection, 47);
    Section_addPage(pSection, 50);
    Section_addPage(pSection, 58);
    break;
  case 40:
    Section_addPage(pSection, 18);
    Section_addPage(pSection, 26);
    Section_addPage(pSection, 35);
    Section_addPage(pSection, 36);
    Section_addPage(pSection, 51);
    Section_addPage(pSection, 52);
    Section_addPage(pSection, 58);
    break;
  case 41:
    Section_addPage(pSection, 19);
    Section_addPage(pSection, 26);
    Section_addPage(pSection, 35);
    Section_addPage(pSection, 36);
    Section_addPage(pSection, 44);
    Section_addPage(pSection, 51);
    Section_addPage(pSection, 52);
    Section_addPage(pSection, 58);
    break;
  case 42:
    Section_addPage(pSection, 20);
    Section_addPage(pSection, 26);
    Section_addPage(pSection, 35);
    Section_addPage(pSection, 36);
    Section_addPage(pSection, 44);
    Section_addPage(pSection, 51);
    Section_addPage(pSection, 52);
    Section_addPage(pSection, 58);
    break;
  case 43:
    Section_addPage(pSection, 21);
    Section_addPage(pSection, 26);
    Section_addPage(pSection, 35);
    Section_addPage(pSection, 36);
    Section_addPage(pSection, 44);
    Section_addPage(pSection, 51);
    Section_addPage(pSection, 52);
    Section_addPage(pSection, 58);
    break;
  case 44:
    Section_addPage(pSection, 22);
    Section_addPage(pSection, 27);
    Section_addPage(pSection, 37);
    Section_addPage(pSection, 44);
    Section_addPage(pSection, 58);
    break;
  case 45:
    Section_addPage(pSection, 22);
    Section_addPage(pSection, 27);
    Section_addPage(pSection, 38);
    Section_addPage(pSection, 42);
    Section_addPage(pSection, 53);
    Section_addPage(pSection, 58);
    break;
  case 46:
    Section_addPage(pSection, 44);
    Section_addPage(pSection, 54);
    Section_addPage(pSection, 56);
    Section_addPage(pSection, 58);
    break;
  case 47:
    Section_addPage(pSection, 33);
    Section_addPage(pSection, 43);
    Section_addPage(pSection, 55);
    Section_addPage(pSection, 57);
    Section_addPage(pSection, 58);
    Section_addPage(pSection, 167);
    break;
  case 48:
    Section_addPage(pSection, 13);
    Section_addPage(pSection, 28);
    Section_addPage(pSection, 29);
    Section_addPage(pSection, 30);
    Section_addPage(pSection, 39);
    Section_addPage(pSection, 40);
    Section_addPage(pSection, 44);
    Section_addPage(pSection, 45);
    Section_addPage(pSection, 46);
    Section_addPage(pSection, 58);
    break;
  case 49:
    Section_addPage(pSection, 13);
    Section_addPage(pSection, 28);
    Section_addPage(pSection, 29);
    Section_addPage(pSection, 30);
    Section_addPage(pSection, 39);
    Section_addPage(pSection, 40);
    Section_addPage(pSection, 44);
    Section_addPage(pSection, 45);
    Section_addPage(pSection, 46);
    Section_addPage(pSection, 58);
    Section_addPage(pSection, 136);
    break;
  case 50:
    Section_addPage(pSection, 31);
    Section_addPage(pSection, 44);
    Section_addPage(pSection, 55);
    Section_addPage(pSection, 58);
    Section_addPage(pSection, 167);
    break;
  case 51:
    Section_addPage(pSection, 31);
    Section_addPage(pSection, 44);
    Section_addPage(pSection, 55);
    Section_addPage(pSection, 58);
    Section_addPage(pSection, 167);
    break;
  case 52:
    Section_addPage(pSection, 31);
    Section_addPage(pSection, 44);
    Section_addPage(pSection, 55);
    Section_addPage(pSection, 58);
    Section_addPage(pSection, 167);
    break;
  case 53:
    Section_addPage(pSection, 59);
    Section_addPage(pSection, 60);
    break;
  case 54:
    Section_addPage(pSection, 59);
    Section_addPage(pSection, 60);
    break;
  case 55:
    Section_addPage(pSection, 59);
    Section_addPage(pSection, 60);
    break;
  case 56:
    Section_addPage(pSection, 59);
    Section_addPage(pSection, 60);
    break;
  case 57:
    Section_addPage(pSection, 61);
    break;
  case 58:
    Section_addPage(pSection, 61);
    break;
  case 59:
    Section_addPage(pSection, 61);
    Section_addPage(pSection, 62);
    break;
  case 60:
    Section_addPage(pSection, 61);
    Section_addPage(pSection, 62);
    break;
  case 61:
    Section_addPage(pSection, 63);
    Section_addPage(pSection, 79);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 83);
    Section_addPage(pSection, 127);
    break;
  case 62:
    Section_addPage(pSection, 63);
    Section_addPage(pSection, 79);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 83);
    Section_addPage(pSection, 127);
    break;
  case 63:
    Section_addPage(pSection, 77);
    Section_addPage(pSection, 82);
    Section_addPage(pSection, 84);
    Section_addPage(pSection, 85);
    Section_addPage(pSection, 86);
    Section_addPage(pSection, 87);
    Section_addPage(pSection, 88);
    Section_addPage(pSection, 89);
    Section_addPage(pSection, 90);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 101);
    break;
  case 64:
    Section_addPage(pSection, 77);
    Section_addPage(pSection, 82);
    Section_addPage(pSection, 84);
    Section_addPage(pSection, 85);
    Section_addPage(pSection, 86);
    Section_addPage(pSection, 87);
    Section_addPage(pSection, 88);
    Section_addPage(pSection, 89);
    Section_addPage(pSection, 90);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 101);
    break;
  case 65:
    Section_addPage(pSection, 77);
    Section_addPage(pSection, 82);
    Section_addPage(pSection, 84);
    Section_addPage(pSection, 85);
    Section_addPage(pSection, 86);
    Section_addPage(pSection, 87);
    Section_addPage(pSection, 88);
    Section_addPage(pSection, 89);
    Section_addPage(pSection, 90);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 101);
    break;
  case 66:
    Section_addPage(pSection, 77);
    Section_addPage(pSection, 82);
    Section_addPage(pSection, 84);
    Section_addPage(pSection, 85);
    Section_addPage(pSection, 86);
    Section_addPage(pSection, 87);
    Section_addPage(pSection, 88);
    Section_addPage(pSection, 89);
    Section_addPage(pSection, 90);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 101);
    break;
  case 67:
    Section_addPage(pSection, 77);
    Section_addPage(pSection, 82);
    Section_addPage(pSection, 84);
    Section_addPage(pSection, 85);
    Section_addPage(pSection, 86);
    Section_addPage(pSection, 87);
    Section_addPage(pSection, 88);
    Section_addPage(pSection, 89);
    Section_addPage(pSection, 90);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 101);
    break;
  case 68:
    Section_addPage(pSection, 58);
    Section_addPage(pSection, 95);
    break;
  case 69:
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 82);
    Section_addPage(pSection, 93);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 96);
    Section_addPage(pSection, 102);
    break;
  case 70:
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 82);
    Section_addPage(pSection, 93);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 96);
    Section_addPage(pSection, 102);
    break;
  case 71:
    Section_addPage(pSection, 78);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 82);
    Section_addPage(pSection, 93);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 96);
    Section_addPage(pSection, 102);
    Section_addPage(pSection, 103);
    Section_addPage(pSection, 104);
    Section_addPage(pSection, 206);
    Section_addPage(pSection, 207);
    Section_addPage(pSection, 208);
    Section_addPage(pSection, 209);
    Section_addPage(pSection, 210);
    break;
  case 72:
    Section_addPage(pSection, 75);
    Section_addPage(pSection, 77);
    Section_addPage(pSection, 79);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 82);
    Section_addPage(pSection, 83);
    Section_addPage(pSection, 92);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 105);
    Section_addPage(pSection, 106);
    Section_addPage(pSection, 107);
    Section_addPage(pSection, 108);
    Section_addPage(pSection, 109);
    Section_addPage(pSection, 110);
    Section_addPage(pSection, 111);
    Section_addPage(pSection, 112);
    Section_addPage(pSection, 113);
    Section_addPage(pSection, 114);
    Section_addPage(pSection, 115);
    Section_addPage(pSection, 116);
    Section_addPage(pSection, 117);
    Section_addPage(pSection, 118);
    Section_addPage(pSection, 119);
    Section_addPage(pSection, 120);
    Section_addPage(pSection, 121);
    Section_addPage(pSection, 127);
    Section_addPage(pSection, 167);
    break;
  case 73:
    Section_addPage(pSection, 75);
    Section_addPage(pSection, 77);
    Section_addPage(pSection, 79);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 82);
    Section_addPage(pSection, 83);
    Section_addPage(pSection, 92);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 105);
    Section_addPage(pSection, 106);
    Section_addPage(pSection, 107);
    Section_addPage(pSection, 108);
    Section_addPage(pSection, 109);
    Section_addPage(pSection, 110);
    Section_addPage(pSection, 111);
    Section_addPage(pSection, 112);
    Section_addPage(pSection, 113);
    Section_addPage(pSection, 114);
    Section_addPage(pSection, 115);
    Section_addPage(pSection, 116);
    Section_addPage(pSection, 117);
    Section_addPage(pSection, 118);
    Section_addPage(pSection, 119);
    Section_addPage(pSection, 120);
    Section_addPage(pSection, 121);
    Section_addPage(pSection, 127);
    Section_addPage(pSection, 167);
    break;
  case 74:
    Section_addPage(pSection, 75);
    Section_addPage(pSection, 77);
    Section_addPage(pSection, 79);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 82);
    Section_addPage(pSection, 83);
    Section_addPage(pSection, 92);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 105);
    Section_addPage(pSection, 106);
    Section_addPage(pSection, 107);
    Section_addPage(pSection, 108);
    Section_addPage(pSection, 109);
    Section_addPage(pSection, 110);
    Section_addPage(pSection, 111);
    Section_addPage(pSection, 112);
    Section_addPage(pSection, 113);
    Section_addPage(pSection, 114);
    Section_addPage(pSection, 115);
    Section_addPage(pSection, 116);
    Section_addPage(pSection, 117);
    Section_addPage(pSection, 118);
    Section_addPage(pSection, 119);
    Section_addPage(pSection, 120);
    Section_addPage(pSection, 121);
    Section_addPage(pSection, 127);
    Section_addPage(pSection, 167);
    break;
  case 75:
    Section_addPage(pSection, 75);
    Section_addPage(pSection, 78);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 82);
    Section_addPage(pSection, 83);
    Section_addPage(pSection, 92);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 110);
    Section_addPage(pSection, 111);
    Section_addPage(pSection, 127);
    Section_addPage(pSection, 167);
    break;
  case 76:
    Section_addPage(pSection, 75);
    Section_addPage(pSection, 78);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 82);
    Section_addPage(pSection, 83);
    Section_addPage(pSection, 92);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 120);
    Section_addPage(pSection, 121);
    Section_addPage(pSection, 127);
    Section_addPage(pSection, 167);
    break;
  case 77:
    Section_addPage(pSection, 75);
    Section_addPage(pSection, 77);
    Section_addPage(pSection, 79);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 82);
    Section_addPage(pSection, 83);
    Section_addPage(pSection, 92);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 105);
    Section_addPage(pSection, 106);
    Section_addPage(pSection, 107);
    Section_addPage(pSection, 108);
    Section_addPage(pSection, 109);
    Section_addPage(pSection, 110);
    Section_addPage(pSection, 111);
    Section_addPage(pSection, 112);
    Section_addPage(pSection, 113);
    Section_addPage(pSection, 114);
    Section_addPage(pSection, 115);
    Section_addPage(pSection, 116);
    Section_addPage(pSection, 117);
    Section_addPage(pSection, 118);
    Section_addPage(pSection, 119);
    Section_addPage(pSection, 120);
    Section_addPage(pSection, 121);
    Section_addPage(pSection, 127);
    Section_addPage(pSection, 167);
    break;
  case 78:
    Section_addPage(pSection, 75);
    Section_addPage(pSection, 77);
    Section_addPage(pSection, 92);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 107);
    Section_addPage(pSection, 108);
    Section_addPage(pSection, 109);
    Section_addPage(pSection, 127);
    Section_addPage(pSection, 167);
    break;
  case 79:
    Section_addPage(pSection, 75);
    Section_addPage(pSection, 77);
    Section_addPage(pSection, 92);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 107);
    Section_addPage(pSection, 108);
    Section_addPage(pSection, 109);
    Section_addPage(pSection, 127);
    Section_addPage(pSection, 167);
    break;
  case 80:
    Section_addPage(pSection, 75);
    Section_addPage(pSection, 77);
    Section_addPage(pSection, 92);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 107);
    Section_addPage(pSection, 108);
    Section_addPage(pSection, 109);
    Section_addPage(pSection, 127);
    Section_addPage(pSection, 167);
    break;
  case 81:
    Section_addPage(pSection, 79);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 92);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 167);
    Section_addPage(pSection, 182);
    break;
  case 82:
    Section_addPage(pSection, 79);
    Section_addPage(pSection, 92);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 167);
    Section_addPage(pSection, 177);
    Section_addPage(pSection, 178);
    break;
  case 83:
    Section_addPage(pSection, 79);
    Section_addPage(pSection, 92);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 167);
    Section_addPage(pSection, 177);
    Section_addPage(pSection, 178);
    break;
  case 84:
    Section_addPage(pSection, 75);
    Section_addPage(pSection, 76);
    Section_addPage(pSection, 77);
    Section_addPage(pSection, 82);
    Section_addPage(pSection, 92);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 96);
    Section_addPage(pSection, 97);
    Section_addPage(pSection, 98);
    Section_addPage(pSection, 99);
    Section_addPage(pSection, 100);
    Section_addPage(pSection, 107);
    Section_addPage(pSection, 110);
    Section_addPage(pSection, 111);
    Section_addPage(pSection, 114);
    Section_addPage(pSection, 115);
    Section_addPage(pSection, 116);
    Section_addPage(pSection, 117);
    Section_addPage(pSection, 119);
    Section_addPage(pSection, 120);
    Section_addPage(pSection, 121);
    Section_addPage(pSection, 127);
    Section_addPage(pSection, 128);
    Section_addPage(pSection, 129);
    Section_addPage(pSection, 130);
    Section_addPage(pSection, 131);
    break;
  case 85:
    Section_addPage(pSection, 76);
    Section_addPage(pSection, 77);
    Section_addPage(pSection, 78);
    Section_addPage(pSection, 79);
    Section_addPage(pSection, 80);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 82);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 107);
    Section_addPage(pSection, 108);
    Section_addPage(pSection, 109);
    Section_addPage(pSection, 118);
    Section_addPage(pSection, 127);
    Section_addPage(pSection, 132);
    Section_addPage(pSection, 133);
    Section_addPage(pSection, 134);
    Section_addPage(pSection, 135);
    Section_addPage(pSection, 136);
    Section_addPage(pSection, 137);
    Section_addPage(pSection, 139);
    Section_addPage(pSection, 140);
    Section_addPage(pSection, 141);
    Section_addPage(pSection, 143);
    Section_addPage(pSection, 149);
    Section_addPage(pSection, 150);
    Section_addPage(pSection, 151);
    Section_addPage(pSection, 152);
    Section_addPage(pSection, 153);
    Section_addPage(pSection, 155);
    Section_addPage(pSection, 156);
    Section_addPage(pSection, 157);
    Section_addPage(pSection, 158);
    Section_addPage(pSection, 165);
    Section_addPage(pSection, 166);
    Section_addPage(pSection, 167);
    break;
  case 86:
    Section_addPage(pSection, 76);
    Section_addPage(pSection, 77);
    Section_addPage(pSection, 78);
    Section_addPage(pSection, 79);
    Section_addPage(pSection, 80);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 82);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 107);
    Section_addPage(pSection, 108);
    Section_addPage(pSection, 109);
    Section_addPage(pSection, 118);
    Section_addPage(pSection, 127);
    Section_addPage(pSection, 132);
    Section_addPage(pSection, 133);
    Section_addPage(pSection, 134);
    Section_addPage(pSection, 135);
    Section_addPage(pSection, 136);
    Section_addPage(pSection, 137);
    Section_addPage(pSection, 139);
    Section_addPage(pSection, 140);
    Section_addPage(pSection, 141);
    Section_addPage(pSection, 143);
    Section_addPage(pSection, 149);
    Section_addPage(pSection, 150);
    Section_addPage(pSection, 151);
    Section_addPage(pSection, 152);
    Section_addPage(pSection, 153);
    Section_addPage(pSection, 155);
    Section_addPage(pSection, 156);
    Section_addPage(pSection, 157);
    Section_addPage(pSection, 158);
    Section_addPage(pSection, 165);
    Section_addPage(pSection, 166);
    Section_addPage(pSection, 167);
    break;
  case 87:
    Section_addPage(pSection, 76);
    Section_addPage(pSection, 77);
    Section_addPage(pSection, 78);
    Section_addPage(pSection, 79);
    Section_addPage(pSection, 80);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 82);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 107);
    Section_addPage(pSection, 108);
    Section_addPage(pSection, 109);
    Section_addPage(pSection, 118);
    Section_addPage(pSection, 127);
    Section_addPage(pSection, 132);
    Section_addPage(pSection, 133);
    Section_addPage(pSection, 134);
    Section_addPage(pSection, 135);
    Section_addPage(pSection, 136);
    Section_addPage(pSection, 137);
    Section_addPage(pSection, 139);
    Section_addPage(pSection, 140);
    Section_addPage(pSection, 141);
    Section_addPage(pSection, 143);
    Section_addPage(pSection, 149);
    Section_addPage(pSection, 150);
    Section_addPage(pSection, 151);
    Section_addPage(pSection, 152);
    Section_addPage(pSection, 153);
    Section_addPage(pSection, 155);
    Section_addPage(pSection, 156);
    Section_addPage(pSection, 157);
    Section_addPage(pSection, 158);
    Section_addPage(pSection, 165);
    Section_addPage(pSection, 166);
    Section_addPage(pSection, 167);
    break;
  case 88:
    Section_addPage(pSection, 78);
    Section_addPage(pSection, 80);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 92);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 110);
    Section_addPage(pSection, 111);
    Section_addPage(pSection, 127);
    Section_addPage(pSection, 136);
    Section_addPage(pSection, 144);
    Section_addPage(pSection, 145);
    Section_addPage(pSection, 146);
    break;
  case 89:
    Section_addPage(pSection, 78);
    Section_addPage(pSection, 80);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 92);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 120);
    Section_addPage(pSection, 121);
    Section_addPage(pSection, 127);
    Section_addPage(pSection, 136);
    Section_addPage(pSection, 144);
    Section_addPage(pSection, 145);
    Section_addPage(pSection, 146);
    break;
  case 90:
    Section_addPage(pSection, 82);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 96);
    Section_addPage(pSection, 97);
    Section_addPage(pSection, 98);
    Section_addPage(pSection, 99);
    Section_addPage(pSection, 100);
    Section_addPage(pSection, 138);
    break;
  case 91:
    Section_addPage(pSection, 76);
    Section_addPage(pSection, 77);
    Section_addPage(pSection, 78);
    Section_addPage(pSection, 79);
    Section_addPage(pSection, 80);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 82);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 107);
    Section_addPage(pSection, 118);
    Section_addPage(pSection, 127);
    Section_addPage(pSection, 129);
    Section_addPage(pSection, 130);
    Section_addPage(pSection, 132);
    Section_addPage(pSection, 133);
    Section_addPage(pSection, 134);
    Section_addPage(pSection, 135);
    Section_addPage(pSection, 136);
    Section_addPage(pSection, 137);
    Section_addPage(pSection, 139);
    Section_addPage(pSection, 140);
    Section_addPage(pSection, 141);
    Section_addPage(pSection, 143);
    Section_addPage(pSection, 149);
    Section_addPage(pSection, 150);
    Section_addPage(pSection, 151);
    Section_addPage(pSection, 152);
    Section_addPage(pSection, 153);
    Section_addPage(pSection, 155);
    Section_addPage(pSection, 156);
    Section_addPage(pSection, 157);
    Section_addPage(pSection, 158);
    Section_addPage(pSection, 165);
    Section_addPage(pSection, 166);
    Section_addPage(pSection, 167);
    break;
  case 92:
    Section_addPage(pSection, 76);
    Section_addPage(pSection, 77);
    Section_addPage(pSection, 78);
    Section_addPage(pSection, 79);
    Section_addPage(pSection, 80);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 82);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 107);
    Section_addPage(pSection, 118);
    Section_addPage(pSection, 127);
    Section_addPage(pSection, 129);
    Section_addPage(pSection, 130);
    Section_addPage(pSection, 132);
    Section_addPage(pSection, 133);
    Section_addPage(pSection, 134);
    Section_addPage(pSection, 135);
    Section_addPage(pSection, 136);
    Section_addPage(pSection, 137);
    Section_addPage(pSection, 139);
    Section_addPage(pSection, 140);
    Section_addPage(pSection, 141);
    Section_addPage(pSection, 143);
    Section_addPage(pSection, 149);
    Section_addPage(pSection, 150);
    Section_addPage(pSection, 151);
    Section_addPage(pSection, 152);
    Section_addPage(pSection, 153);
    Section_addPage(pSection, 155);
    Section_addPage(pSection, 156);
    Section_addPage(pSection, 157);
    Section_addPage(pSection, 158);
    Section_addPage(pSection, 165);
    Section_addPage(pSection, 166);
    Section_addPage(pSection, 167);
    break;
  case 93:
    Section_addPage(pSection, 76);
    Section_addPage(pSection, 77);
    Section_addPage(pSection, 78);
    Section_addPage(pSection, 79);
    Section_addPage(pSection, 80);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 82);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 107);
    Section_addPage(pSection, 118);
    Section_addPage(pSection, 127);
    Section_addPage(pSection, 129);
    Section_addPage(pSection, 130);
    Section_addPage(pSection, 132);
    Section_addPage(pSection, 133);
    Section_addPage(pSection, 134);
    Section_addPage(pSection, 135);
    Section_addPage(pSection, 136);
    Section_addPage(pSection, 137);
    Section_addPage(pSection, 139);
    Section_addPage(pSection, 140);
    Section_addPage(pSection, 141);
    Section_addPage(pSection, 143);
    Section_addPage(pSection, 149);
    Section_addPage(pSection, 150);
    Section_addPage(pSection, 151);
    Section_addPage(pSection, 152);
    Section_addPage(pSection, 153);
    Section_addPage(pSection, 155);
    Section_addPage(pSection, 156);
    Section_addPage(pSection, 157);
    Section_addPage(pSection, 158);
    Section_addPage(pSection, 165);
    Section_addPage(pSection, 166);
    Section_addPage(pSection, 167);
    break;
  case 94:
    Section_addPage(pSection, 78);
    Section_addPage(pSection, 80);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 92);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 110);
    Section_addPage(pSection, 111);
    Section_addPage(pSection, 127);
    Section_addPage(pSection, 136);
    Section_addPage(pSection, 144);
    Section_addPage(pSection, 145);
    Section_addPage(pSection, 146);
    break;
  case 95:
    Section_addPage(pSection, 78);
    Section_addPage(pSection, 80);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 92);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 120);
    Section_addPage(pSection, 121);
    Section_addPage(pSection, 127);
    Section_addPage(pSection, 136);
    Section_addPage(pSection, 144);
    Section_addPage(pSection, 145);
    Section_addPage(pSection, 146);
    break;
  case 96:
    Section_addPage(pSection, 78);
    Section_addPage(pSection, 80);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 92);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 110);
    Section_addPage(pSection, 111);
    Section_addPage(pSection, 127);
    Section_addPage(pSection, 136);
    Section_addPage(pSection, 144);
    Section_addPage(pSection, 145);
    Section_addPage(pSection, 146);
    break;
  case 97:
    Section_addPage(pSection, 78);
    Section_addPage(pSection, 80);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 92);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 110);
    Section_addPage(pSection, 111);
    Section_addPage(pSection, 127);
    Section_addPage(pSection, 136);
    Section_addPage(pSection, 144);
    Section_addPage(pSection, 145);
    Section_addPage(pSection, 146);
    break;
  case 98:
    Section_addPage(pSection, 78);
    Section_addPage(pSection, 80);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 92);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 120);
    Section_addPage(pSection, 121);
    Section_addPage(pSection, 127);
    Section_addPage(pSection, 136);
    Section_addPage(pSection, 144);
    Section_addPage(pSection, 145);
    Section_addPage(pSection, 146);
    break;
  case 99:
    Section_addPage(pSection, 78);
    Section_addPage(pSection, 80);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 92);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 120);
    Section_addPage(pSection, 121);
    Section_addPage(pSection, 127);
    Section_addPage(pSection, 136);
    Section_addPage(pSection, 144);
    Section_addPage(pSection, 145);
    Section_addPage(pSection, 146);
    break;
  case 100:
    Section_addPage(pSection, 78);
    Section_addPage(pSection, 80);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 92);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 110);
    Section_addPage(pSection, 111);
    Section_addPage(pSection, 127);
    Section_addPage(pSection, 136);
    Section_addPage(pSection, 144);
    Section_addPage(pSection, 145);
    Section_addPage(pSection, 146);
    break;
  case 101:
    Section_addPage(pSection, 78);
    Section_addPage(pSection, 80);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 92);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 110);
    Section_addPage(pSection, 111);
    Section_addPage(pSection, 127);
    Section_addPage(pSection, 136);
    Section_addPage(pSection, 144);
    Section_addPage(pSection, 145);
    Section_addPage(pSection, 146);
    break;
  case 102:
    Section_addPage(pSection, 78);
    Section_addPage(pSection, 80);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 92);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 120);
    Section_addPage(pSection, 121);
    Section_addPage(pSection, 127);
    Section_addPage(pSection, 136);
    Section_addPage(pSection, 144);
    Section_addPage(pSection, 145);
    Section_addPage(pSection, 146);
    break;
  case 103:
    Section_addPage(pSection, 78);
    Section_addPage(pSection, 80);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 92);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 120);
    Section_addPage(pSection, 121);
    Section_addPage(pSection, 127);
    Section_addPage(pSection, 136);
    Section_addPage(pSection, 144);
    Section_addPage(pSection, 145);
    Section_addPage(pSection, 146);
    break;
  case 104:
    Section_addPage(pSection, 49);
    Section_addPage(pSection, 58);
    Section_addPage(pSection, 64);
    Section_addPage(pSection, 69);
    Section_addPage(pSection, 70);
    Section_addPage(pSection, 71);
    Section_addPage(pSection, 72);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 136);
    Section_addPage(pSection, 148);
    break;
  case 105:
    Section_addPage(pSection, 49);
    Section_addPage(pSection, 58);
    Section_addPage(pSection, 65);
    Section_addPage(pSection, 69);
    Section_addPage(pSection, 70);
    Section_addPage(pSection, 71);
    Section_addPage(pSection, 72);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 136);
    Section_addPage(pSection, 148);
    break;
  case 106:
    Section_addPage(pSection, 58);
    Section_addPage(pSection, 72);
    Section_addPage(pSection, 73);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 136);
    Section_addPage(pSection, 147);
    Section_addPage(pSection, 148);
    break;
  case 107:
    Section_addPage(pSection, 58);
    Section_addPage(pSection, 72);
    Section_addPage(pSection, 73);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 136);
    Section_addPage(pSection, 147);
    Section_addPage(pSection, 148);
    break;
  case 108:
    Section_addPage(pSection, 18);
    Section_addPage(pSection, 49);
    Section_addPage(pSection, 51);
    Section_addPage(pSection, 58);
    Section_addPage(pSection, 69);
    Section_addPage(pSection, 70);
    Section_addPage(pSection, 71);
    Section_addPage(pSection, 72);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 136);
    Section_addPage(pSection, 148);
    break;
  case 109:
    Section_addPage(pSection, 19);
    Section_addPage(pSection, 49);
    Section_addPage(pSection, 51);
    Section_addPage(pSection, 58);
    Section_addPage(pSection, 69);
    Section_addPage(pSection, 70);
    Section_addPage(pSection, 71);
    Section_addPage(pSection, 72);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 136);
    Section_addPage(pSection, 148);
    break;
  case 110:
    Section_addPage(pSection, 51);
    Section_addPage(pSection, 58);
    Section_addPage(pSection, 72);
    Section_addPage(pSection, 74);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 136);
    Section_addPage(pSection, 147);
    Section_addPage(pSection, 148);
    break;
  case 111:
    Section_addPage(pSection, 51);
    Section_addPage(pSection, 58);
    Section_addPage(pSection, 72);
    Section_addPage(pSection, 74);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 136);
    Section_addPage(pSection, 147);
    Section_addPage(pSection, 148);
    break;
  case 112:
    Section_addPage(pSection, 47);
    Section_addPage(pSection, 48);
    Section_addPage(pSection, 58);
    Section_addPage(pSection, 66);
    Section_addPage(pSection, 68);
    Section_addPage(pSection, 72);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 136);
    Section_addPage(pSection, 148);
    break;
  case 113:
    Section_addPage(pSection, 47);
    Section_addPage(pSection, 50);
    Section_addPage(pSection, 58);
    Section_addPage(pSection, 66);
    Section_addPage(pSection, 68);
    Section_addPage(pSection, 72);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 136);
    Section_addPage(pSection, 148);
    break;
  case 114:
    Section_addPage(pSection, 18);
    Section_addPage(pSection, 51);
    Section_addPage(pSection, 52);
    Section_addPage(pSection, 58);
    Section_addPage(pSection, 68);
    Section_addPage(pSection, 72);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 136);
    Section_addPage(pSection, 148);
    break;
  case 115:
    Section_addPage(pSection, 18);
    Section_addPage(pSection, 51);
    Section_addPage(pSection, 52);
    Section_addPage(pSection, 58);
    Section_addPage(pSection, 68);
    Section_addPage(pSection, 72);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 136);
    Section_addPage(pSection, 148);
    break;
  case 116:
    Section_addPage(pSection, 47);
    Section_addPage(pSection, 48);
    Section_addPage(pSection, 58);
    Section_addPage(pSection, 67);
    Section_addPage(pSection, 68);
    Section_addPage(pSection, 72);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 136);
    Section_addPage(pSection, 148);
    break;
  case 117:
    Section_addPage(pSection, 47);
    Section_addPage(pSection, 50);
    Section_addPage(pSection, 58);
    Section_addPage(pSection, 67);
    Section_addPage(pSection, 68);
    Section_addPage(pSection, 72);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 136);
    Section_addPage(pSection, 148);
    break;
  case 118:
    Section_addPage(pSection, 19);
    Section_addPage(pSection, 51);
    Section_addPage(pSection, 52);
    Section_addPage(pSection, 58);
    Section_addPage(pSection, 68);
    Section_addPage(pSection, 72);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 136);
    Section_addPage(pSection, 148);
    break;
  case 119:
    Section_addPage(pSection, 19);
    Section_addPage(pSection, 51);
    Section_addPage(pSection, 52);
    Section_addPage(pSection, 58);
    Section_addPage(pSection, 68);
    Section_addPage(pSection, 72);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 136);
    Section_addPage(pSection, 148);
    break;
  case 120:
    Section_addPage(pSection, 93);
    Section_addPage(pSection, 137);
    break;
  case 121:
    Section_addPage(pSection, 93);
    Section_addPage(pSection, 137);
    break;
  case 122:
    Section_addPage(pSection, 77);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 82);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 162);
    Section_addPage(pSection, 163);
    Section_addPage(pSection, 164);
    break;
  case 123:
    Section_addPage(pSection, 77);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 82);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 162);
    Section_addPage(pSection, 163);
    Section_addPage(pSection, 164);
    break;
  case 124:
    Section_addPage(pSection, 77);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 82);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 162);
    Section_addPage(pSection, 163);
    Section_addPage(pSection, 164);
    break;
  case 125:
    Section_addPage(pSection, 78);
    Section_addPage(pSection, 79);
    Section_addPage(pSection, 80);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 82);
    Section_addPage(pSection, 110);
    Section_addPage(pSection, 111);
    Section_addPage(pSection, 132);
    Section_addPage(pSection, 133);
    Section_addPage(pSection, 134);
    Section_addPage(pSection, 136);
    Section_addPage(pSection, 137);
    Section_addPage(pSection, 149);
    Section_addPage(pSection, 167);
    Section_addPage(pSection, 168);
    Section_addPage(pSection, 170);
    Section_addPage(pSection, 171);
    Section_addPage(pSection, 172);
    Section_addPage(pSection, 173);
    Section_addPage(pSection, 174);
    Section_addPage(pSection, 175);
    break;
  case 126:
    Section_addPage(pSection, 78);
    Section_addPage(pSection, 79);
    Section_addPage(pSection, 80);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 82);
    Section_addPage(pSection, 132);
    Section_addPage(pSection, 133);
    Section_addPage(pSection, 134);
    Section_addPage(pSection, 136);
    Section_addPage(pSection, 137);
    Section_addPage(pSection, 149);
    Section_addPage(pSection, 169);
    Section_addPage(pSection, 170);
    Section_addPage(pSection, 171);
    Section_addPage(pSection, 174);
    Section_addPage(pSection, 175);
    Section_addPage(pSection, 176);
    break;
  case 127:
    Section_addPage(pSection, 75);
    Section_addPage(pSection, 77);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 107);
    Section_addPage(pSection, 108);
    Section_addPage(pSection, 109);
    Section_addPage(pSection, 127);
    Section_addPage(pSection, 159);
    Section_addPage(pSection, 160);
    Section_addPage(pSection, 161);
    break;
  case 128:
    Section_addPage(pSection, 75);
    Section_addPage(pSection, 77);
    Section_addPage(pSection, 78);
    Section_addPage(pSection, 80);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 82);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 107);
    Section_addPage(pSection, 108);
    Section_addPage(pSection, 109);
    Section_addPage(pSection, 127);
    Section_addPage(pSection, 132);
    Section_addPage(pSection, 133);
    Section_addPage(pSection, 134);
    Section_addPage(pSection, 136);
    Section_addPage(pSection, 137);
    Section_addPage(pSection, 159);
    Section_addPage(pSection, 160);
    Section_addPage(pSection, 161);
    break;
  case 129:
    Section_addPage(pSection, 75);
    Section_addPage(pSection, 77);
    Section_addPage(pSection, 78);
    Section_addPage(pSection, 80);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 82);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 107);
    Section_addPage(pSection, 108);
    Section_addPage(pSection, 109);
    Section_addPage(pSection, 127);
    Section_addPage(pSection, 132);
    Section_addPage(pSection, 133);
    Section_addPage(pSection, 134);
    Section_addPage(pSection, 136);
    Section_addPage(pSection, 137);
    Section_addPage(pSection, 160);
    Section_addPage(pSection, 161);
    break;
  case 130:
    Section_addPage(pSection, 77);
    Section_addPage(pSection, 79);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 167);
    Section_addPage(pSection, 179);
    Section_addPage(pSection, 180);
    Section_addPage(pSection, 181);
    break;
  case 131:
    Section_addPage(pSection, 76);
    Section_addPage(pSection, 77);
    Section_addPage(pSection, 78);
    Section_addPage(pSection, 79);
    Section_addPage(pSection, 80);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 82);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 107);
    Section_addPage(pSection, 108);
    Section_addPage(pSection, 109);
    Section_addPage(pSection, 118);
    Section_addPage(pSection, 127);
    Section_addPage(pSection, 132);
    Section_addPage(pSection, 133);
    Section_addPage(pSection, 134);
    Section_addPage(pSection, 135);
    Section_addPage(pSection, 136);
    Section_addPage(pSection, 137);
    Section_addPage(pSection, 142);
    Section_addPage(pSection, 143);
    Section_addPage(pSection, 149);
    Section_addPage(pSection, 150);
    Section_addPage(pSection, 151);
    Section_addPage(pSection, 152);
    Section_addPage(pSection, 153);
    Section_addPage(pSection, 155);
    Section_addPage(pSection, 156);
    Section_addPage(pSection, 157);
    Section_addPage(pSection, 158);
    Section_addPage(pSection, 165);
    Section_addPage(pSection, 166);
    Section_addPage(pSection, 167);
    break;
  case 132:
    Section_addPage(pSection, 76);
    Section_addPage(pSection, 77);
    Section_addPage(pSection, 78);
    Section_addPage(pSection, 79);
    Section_addPage(pSection, 80);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 82);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 107);
    Section_addPage(pSection, 108);
    Section_addPage(pSection, 109);
    Section_addPage(pSection, 118);
    Section_addPage(pSection, 127);
    Section_addPage(pSection, 132);
    Section_addPage(pSection, 133);
    Section_addPage(pSection, 134);
    Section_addPage(pSection, 135);
    Section_addPage(pSection, 136);
    Section_addPage(pSection, 137);
    Section_addPage(pSection, 142);
    Section_addPage(pSection, 143);
    Section_addPage(pSection, 149);
    Section_addPage(pSection, 150);
    Section_addPage(pSection, 151);
    Section_addPage(pSection, 152);
    Section_addPage(pSection, 153);
    Section_addPage(pSection, 154);
    Section_addPage(pSection, 155);
    Section_addPage(pSection, 156);
    Section_addPage(pSection, 157);
    Section_addPage(pSection, 158);
    Section_addPage(pSection, 165);
    Section_addPage(pSection, 166);
    Section_addPage(pSection, 167);
    break;
  case 133:
    Section_addPage(pSection, 75);
    Section_addPage(pSection, 77);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 107);
    Section_addPage(pSection, 108);
    Section_addPage(pSection, 109);
    Section_addPage(pSection, 127);
    Section_addPage(pSection, 183);
    Section_addPage(pSection, 184);
    Section_addPage(pSection, 187);
    break;
  case 134:
    Section_addPage(pSection, 75);
    Section_addPage(pSection, 77);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 107);
    Section_addPage(pSection, 108);
    Section_addPage(pSection, 109);
    Section_addPage(pSection, 127);
    Section_addPage(pSection, 183);
    Section_addPage(pSection, 184);
    Section_addPage(pSection, 187);
    break;
  case 135:
    Section_addPage(pSection, 78);
    Section_addPage(pSection, 79);
    Section_addPage(pSection, 80);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 132);
    Section_addPage(pSection, 133);
    Section_addPage(pSection, 134);
    Section_addPage(pSection, 136);
    Section_addPage(pSection, 137);
    Section_addPage(pSection, 185);
    break;
  case 136:
    Section_addPage(pSection, 91);
    Section_addPage(pSection, 186);
    break;
  case 137:
    Section_addPage(pSection, 91);
    Section_addPage(pSection, 186);
    break;
  case 138:
    Section_addPage(pSection, 79);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 82);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 189);
    Section_addPage(pSection, 190);
    Section_addPage(pSection, 191);
    break;
  case 139:
    Section_addPage(pSection, 80);
    Section_addPage(pSection, 81);
    Section_addPage(pSection, 82);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 188);
    break;
  case 140:
    Section_addPage(pSection, 77);
    Section_addPage(pSection, 78);
    Section_addPage(pSection, 93);
    Section_addPage(pSection, 192);
    Section_addPage(pSection, 193);
    Section_addPage(pSection, 194);
    Section_addPage(pSection, 195);
    Section_addPage(pSection, 196);
    Section_addPage(pSection, 197);
    Section_addPage(pSection, 198);
    Section_addPage(pSection, 199);
    Section_addPage(pSection, 200);
    Section_addPage(pSection, 201);
    Section_addPage(pSection, 202);
    Section_addPage(pSection, 203);
    Section_addPage(pSection, 204);
    break;
  case 141:
    Section_addPage(pSection, 93);
    Section_addPage(pSection, 202);
    Section_addPage(pSection, 203);
    Section_addPage(pSection, 204);
    break;
  case 142:
    Section_addPage(pSection, 93);
    Section_addPage(pSection, 197);
    Section_addPage(pSection, 204);
    break;
  case 143:
    Section_addPage(pSection, 78);
    Section_addPage(pSection, 93);
    Section_addPage(pSection, 194);
    Section_addPage(pSection, 195);
    Section_addPage(pSection, 198);
    Section_addPage(pSection, 199);
    Section_addPage(pSection, 200);
    Section_addPage(pSection, 201);
    Section_addPage(pSection, 204);
    break;
  case 144:
    Section_addPage(pSection, 91);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 127);
    Section_addPage(pSection, 205);
    break;
  case 145:
    Section_addPage(pSection, 91);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 127);
    Section_addPage(pSection, 205);
    break;
  case 146:
    Section_addPage(pSection, 91);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 127);
    Section_addPage(pSection, 205);
    break;
  case 147:
    Section_addPage(pSection, 91);
    Section_addPage(pSection, 94);
    Section_addPage(pSection, 127);
    Section_addPage(pSection, 205);
    break;
  case 148:
    Section_addPage(pSection, 122);
    Section_addPage(pSection, 123);
    Section_addPage(pSection, 124);
    Section_addPage(pSection, 125);
    Section_addPage(pSection, 126);
    break;
  default:
    return;
  }
}

void Section_addActivePages(void* section, int sectionId) {
  switch (sectionId) {
  case 6:
    Section_addActivePage(section, 0);
    break;
  case 7:
    Section_addActivePage(section, 0);
    break;
  case 8:
    Section_addActivePage(section, 0);
    break;
  case 9:
    Section_addActivePage(section, 0);
    break;
  case 10:
    Section_addActivePage(section, 0);
    break;
  case 0xb:
    Section_addActivePage(section, 0);
    break;
  case 0xc:
    Section_addActivePage(section, 0);
    break;
  case 0xd:
    Section_addActivePage(section, 0);
    break;
  case 0xe:
    Section_addActivePage(section, 0);
    break;
  case 0xf:
    Section_addActivePage(section, 0);
    break;
  case 0x10:
    Section_addActivePage(section, 0x5d);
    Section_addActivePage(section, 3);
    break;
  case 0x11:
    Section_addActivePage(section, 0x5d);
    Section_addActivePage(section, 3);
    break;
  case 0x12:
    Section_addActivePage(section, 0x5d);
    Section_addActivePage(section, 3);
    break;
  case 0x13:
    Section_addActivePage(section, 0x5d);
    Section_addActivePage(section, 4);
    break;
  case 0x14:
    Section_addActivePage(section, 0x5d);
    Section_addActivePage(section, 5);
    break;
  case 0x15:
    Section_addActivePage(section, 0x5d);
    Section_addActivePage(section, 6);
    break;
  case 0x16:
    Section_addActivePage(section, 1);
    break;
  case 0x17:
    Section_addActivePage(section, 2);
    break;
  case 0x18:
    Section_addActivePage(section, 2);
    break;
  case 0x19:
    Section_addActivePage(section, 7);
    break;
  case 0x1a:
    Section_addActivePage(section, 8);
    break;
  case 0x1b:
    Section_addActivePage(section, 9);
    break;
  case 0x1c:
    Section_addActivePage(section, 10);
    break;
  case 0x1d:
    Section_addActivePage(section, 0xb);
    break;
  case 0x1e:
    Section_addActivePage(section, 0x3a);
    Section_addActivePage(section, 0xc);
    break;
  case 0x1f:
    Section_addActivePage(section, 0xa7);
    Section_addActivePage(section, 0x3a);
    Section_addActivePage(section, 0xd);
    break;
  case 0x20:
    Section_addActivePage(section, 0x3a);
    Section_addActivePage(section, 0xe);
    break;
  case 0x21:
    Section_addActivePage(section, 0x3a);
    Section_addActivePage(section, 0xf);
    break;
  case 0x22:
    Section_addActivePage(section, 0x3a);
    Section_addActivePage(section, 0x10);
    break;
  case 0x23:
    Section_addActivePage(section, 0x3a);
    Section_addActivePage(section, 0x11);
    break;
  case 0x24:
    Section_addActivePage(section, 0x3a);
    Section_addActivePage(section, 0xe);
    break;
  case 0x25:
    Section_addActivePage(section, 0x3a);
    Section_addActivePage(section, 0xf);
    break;
  case 0x26:
    Section_addActivePage(section, 0x3a);
    Section_addActivePage(section, 0x10);
    break;
  case 0x27:
    Section_addActivePage(section, 0x3a);
    Section_addActivePage(section, 0x11);
    break;
  case 0x28:
    Section_addActivePage(section, 0x3a);
    Section_addActivePage(section, 0x12);
    break;
  case 0x29:
    Section_addActivePage(section, 0x3a);
    Section_addActivePage(section, 0x13);
    break;
  case 0x2a:
    Section_addActivePage(section, 0x3a);
    Section_addActivePage(section, 0x14);
    break;
  case 0x2b:
    Section_addActivePage(section, 0x3a);
    Section_addActivePage(section, 0x15);
    break;
  case 0x2c:
    Section_addActivePage(section, 0x3a);
    Section_addActivePage(section, 0x16);
    break;
  case 0x2d:
    Section_addActivePage(section, 0x3a);
    Section_addActivePage(section, 0x16);
    break;
  case 0x2e:
    Section_addActivePage(section, 0x3a);
    Section_addActivePage(section, 0x36);
    break;
  case 0x2f:
    Section_addActivePage(section, 0xa7);
    Section_addActivePage(section, 0x3a);
    Section_addActivePage(section, 0x37);
    break;
  case 0x30:
    Section_addActivePage(section, 0x3a);
    Section_addActivePage(section, 0xd);
    break;
  case 0x31:
    Section_addActivePage(section, 0x3a);
    Section_addActivePage(section, 0x88);
    Section_addActivePage(section, 0xd);
    break;
  case 0x32:
    Section_addActivePage(section, 0xa7);
    Section_addActivePage(section, 0x3a);
    Section_addActivePage(section, 0x37);
    break;
  case 0x33:
    Section_addActivePage(section, 0xa7);
    Section_addActivePage(section, 0x3a);
    Section_addActivePage(section, 0x37);
    break;
  case 0x34:
    Section_addActivePage(section, 0xa7);
    Section_addActivePage(section, 0x3a);
    Section_addActivePage(section, 0x37);
    break;
  case 0x35:
    Section_addActivePage(section, 0x3b);
    break;
  case 0x36:
    Section_addActivePage(section, 0x3b);
    break;
  case 0x37:
    Section_addActivePage(section, 0x3b);
    break;
  case 0x38:
    Section_addActivePage(section, 0x3b);
    break;
  case 0x39:
    Section_addActivePage(section, 0x3d);
    break;
  case 0x3a:
    Section_addActivePage(section, 0x3d);
    break;
  case 0x3b:
    Section_addActivePage(section, 0x3e);
    Section_addActivePage(section, 0x3d);
    break;
  case 0x3c:
    Section_addActivePage(section, 0x3e);
    Section_addActivePage(section, 0x3d);
    break;
  case 0x3d:
    Section_addActivePage(section, 0x7f);
    Section_addActivePage(section, 0x3f);
    break;
  case 0x3e:
    Section_addActivePage(section, 0x7f);
    Section_addActivePage(section, 0x3f);
    break;
  case 0x3f:
    Section_addActivePage(section, 0x54);
    Section_addActivePage(section, 0x58);
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0x57);
    break;
  case 0x40:
    Section_addActivePage(section, 0x54);
    Section_addActivePage(section, 0x58);
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0x57);
    break;
  case 0x41:
    Section_addActivePage(section, 0x54);
    Section_addActivePage(section, 0x58);
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0x5a);
    break;
  case 0x42:
    Section_addActivePage(section, 0x54);
    Section_addActivePage(section, 0x58);
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0x65);
    break;
  case 0x43:
    Section_addActivePage(section, 0x54);
    Section_addActivePage(section, 0x58);
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0x65);
    break;
  case 0x44:
    Section_addActivePage(section, 0x3a);
    Section_addActivePage(section, 0x5f);
    break;
  case 0x45:
    Section_addActivePage(section, 0x5d);
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0x60);
    break;
  case 0x46:
    Section_addActivePage(section, 0x5d);
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0x60);
    break;
  case 0x47:
    Section_addActivePage(section, 0x5d);
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0x67);
    break;
  case 0x48:
    Section_addActivePage(section, 0x5c);
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0xa7);
    Section_addActivePage(section, 0x7f);
    Section_addActivePage(section, 0x69);
    break;
  case 0x49:
    Section_addActivePage(section, 0x5c);
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0xa7);
    Section_addActivePage(section, 0x7f);
    Section_addActivePage(section, 0x6b);
    break;
  case 0x4a:
    Section_addActivePage(section, 0x5c);
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0xa7);
    Section_addActivePage(section, 0x7f);
    Section_addActivePage(section, 0x6e);
    break;
  case 0x4b:
    Section_addActivePage(section, 0x5c);
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0xa7);
    Section_addActivePage(section, 0x7f);
    Section_addActivePage(section, 0x6e);
    break;
  case 0x4c:
    Section_addActivePage(section, 0x5c);
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0xa7);
    Section_addActivePage(section, 0x7f);
    Section_addActivePage(section, 0x78);
    break;
  case 0x4d:
    Section_addActivePage(section, 0x5c);
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0xa7);
    Section_addActivePage(section, 0x7f);
    break;
  case 0x4e:
    Section_addActivePage(section, 0x5c);
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0xa7);
    Section_addActivePage(section, 0x7f);
    Section_addActivePage(section, 0x6b);
    break;
  case 0x4f:
    Section_addActivePage(section, 0x5c);
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0xa7);
    Section_addActivePage(section, 0x7f);
    Section_addActivePage(section, 0x6b);
    break;
  case 0x50:
    Section_addActivePage(section, 0x5c);
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0xa7);
    Section_addActivePage(section, 0x7f);
    Section_addActivePage(section, 0x6b);
    break;
  case 0x51:
    Section_addActivePage(section, 0x5c);
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0xa7);
    Section_addActivePage(section, 0xb6);
    break;
  case 0x52:
    Section_addActivePage(section, 0x5c);
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0xa7);
    Section_addActivePage(section, 0xb1);
    break;
  case 0x53:
    Section_addActivePage(section, 0x5c);
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0xa7);
    Section_addActivePage(section, 0xb1);
    break;
  case 0x54:
    Section_addActivePage(section, 0x5c);
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0x7f);
    Section_addActivePage(section, 0x61);
    break;
  case 0x55:
    Section_addActivePage(section, 0x88);
    Section_addActivePage(section, 0xa7);
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0x95);
    Section_addActivePage(section, 0x7f);
    Section_addActivePage(section, 0x84);
    break;
  case 0x56:
    Section_addActivePage(section, 0x88);
    Section_addActivePage(section, 0xa7);
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0x95);
    Section_addActivePage(section, 0x7f);
    Section_addActivePage(section, 0x9b);
    break;
  case 0x57:
    Section_addActivePage(section, 0x88);
    Section_addActivePage(section, 0xa7);
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0x95);
    Section_addActivePage(section, 0x7f);
    Section_addActivePage(section, 0x96);
    break;
  case 0x58:
    Section_addActivePage(section, 0x88);
    Section_addActivePage(section, 0x5c);
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0x7f);
    Section_addActivePage(section, 0x90);
    break;
  case 0x59:
    Section_addActivePage(section, 0x88);
    Section_addActivePage(section, 0x5c);
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0x7f);
    Section_addActivePage(section, 0x90);
    break;
  case 0x5a:
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0x61);
    break;
  case 0x5b:
    Section_addActivePage(section, 0x88);
    Section_addActivePage(section, 0xa7);
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0x95);
    Section_addActivePage(section, 0x7f);
    Section_addActivePage(section, 0x84);
    break;
  case 0x5c:
    Section_addActivePage(section, 0x88);
    Section_addActivePage(section, 0xa7);
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0x95);
    Section_addActivePage(section, 0x7f);
    Section_addActivePage(section, 0x9b);
    break;
  case 0x5d:
    Section_addActivePage(section, 0x88);
    Section_addActivePage(section, 0xa7);
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0x95);
    Section_addActivePage(section, 0x7f);
    Section_addActivePage(section, 0x96);
    break;
  case 0x5e:
    Section_addActivePage(section, 0x88);
    Section_addActivePage(section, 0x5c);
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0x7f);
    Section_addActivePage(section, 0x90);
    break;
  case 0x5f:
    Section_addActivePage(section, 0x88);
    Section_addActivePage(section, 0x5c);
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0x7f);
    Section_addActivePage(section, 0x90);
    break;
  case 0x60:
    Section_addActivePage(section, 0x88);
    Section_addActivePage(section, 0x5c);
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0x7f);
    Section_addActivePage(section, 0x90);
    break;
  case 0x61:
    Section_addActivePage(section, 0x88);
    Section_addActivePage(section, 0x5c);
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0x7f);
    Section_addActivePage(section, 0x90);
    break;
  case 0x62:
    Section_addActivePage(section, 0x88);
    Section_addActivePage(section, 0x5c);
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0x7f);
    Section_addActivePage(section, 0x90);
    break;
  case 99:
    Section_addActivePage(section, 0x88);
    Section_addActivePage(section, 0x5c);
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0x7f);
    Section_addActivePage(section, 0x90);
    break;
  case 100:
    Section_addActivePage(section, 0x88);
    Section_addActivePage(section, 0x5c);
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0x7f);
    Section_addActivePage(section, 0x90);
    break;
  case 0x65:
    Section_addActivePage(section, 0x88);
    Section_addActivePage(section, 0x5c);
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0x7f);
    Section_addActivePage(section, 0x90);
    break;
  case 0x66:
    Section_addActivePage(section, 0x88);
    Section_addActivePage(section, 0x5c);
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0x7f);
    Section_addActivePage(section, 0x90);
    break;
  case 0x67:
    Section_addActivePage(section, 0x88);
    Section_addActivePage(section, 0x5c);
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0x7f);
    Section_addActivePage(section, 0x90);
    break;
  case 0x68:
    Section_addActivePage(section, 0x88);
    Section_addActivePage(section, 0x94);
    Section_addActivePage(section, 0x3a);
    Section_addActivePage(section, 0x40);
    break;
  case 0x69:
    Section_addActivePage(section, 0x88);
    Section_addActivePage(section, 0x94);
    Section_addActivePage(section, 0x3a);
    Section_addActivePage(section, 0x41);
    break;
  case 0x6a:
    Section_addActivePage(section, 0x88);
    Section_addActivePage(section, 0x94);
    Section_addActivePage(section, 0x3a);
    Section_addActivePage(section, 0x93);
    break;
  case 0x6b:
    Section_addActivePage(section, 0x88);
    Section_addActivePage(section, 0x94);
    Section_addActivePage(section, 0x3a);
    Section_addActivePage(section, 0x93);
    break;
  case 0x6c:
    Section_addActivePage(section, 0x88);
    Section_addActivePage(section, 0x94);
    Section_addActivePage(section, 0x3a);
    Section_addActivePage(section, 0x12);
    break;
  case 0x6d:
    Section_addActivePage(section, 0x88);
    Section_addActivePage(section, 0x94);
    Section_addActivePage(section, 0x3a);
    Section_addActivePage(section, 0x13);
    break;
  case 0x6e:
    Section_addActivePage(section, 0x88);
    Section_addActivePage(section, 0x94);
    Section_addActivePage(section, 0x3a);
    Section_addActivePage(section, 0x93);
    break;
  case 0x6f:
    Section_addActivePage(section, 0x88);
    Section_addActivePage(section, 0x94);
    Section_addActivePage(section, 0x3a);
    Section_addActivePage(section, 0x93);
    break;
  case 0x70:
    Section_addActivePage(section, 0x88);
    Section_addActivePage(section, 0x94);
    Section_addActivePage(section, 0x3a);
    Section_addActivePage(section, 0x42);
    break;
  case 0x71:
    Section_addActivePage(section, 0x88);
    Section_addActivePage(section, 0x94);
    Section_addActivePage(section, 0x3a);
    Section_addActivePage(section, 0x42);
    break;
  case 0x72:
    Section_addActivePage(section, 0x88);
    Section_addActivePage(section, 0x94);
    Section_addActivePage(section, 0x3a);
    Section_addActivePage(section, 0x12);
    break;
  case 0x73:
    Section_addActivePage(section, 0x88);
    Section_addActivePage(section, 0x94);
    Section_addActivePage(section, 0x3a);
    Section_addActivePage(section, 0x12);
    break;
  case 0x74:
    Section_addActivePage(section, 0x88);
    Section_addActivePage(section, 0x94);
    Section_addActivePage(section, 0x3a);
    Section_addActivePage(section, 0x43);
    break;
  case 0x75:
    Section_addActivePage(section, 0x88);
    Section_addActivePage(section, 0x94);
    Section_addActivePage(section, 0x3a);
    Section_addActivePage(section, 0x43);
    break;
  case 0x76:
    Section_addActivePage(section, 0x88);
    Section_addActivePage(section, 0x94);
    Section_addActivePage(section, 0x3a);
    Section_addActivePage(section, 0x13);
    break;
  case 0x77:
    Section_addActivePage(section, 0x88);
    Section_addActivePage(section, 0x94);
    Section_addActivePage(section, 0x3a);
    Section_addActivePage(section, 0x13);
    break;
  case 0x78:
    Section_addActivePage(section, 0x5d);
    Section_addActivePage(section, 0x89);
    break;
  case 0x79:
    Section_addActivePage(section, 0x5d);
    Section_addActivePage(section, 0x89);
    break;
  case 0x7a:
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0xa2);
    break;
  case 0x7b:
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0xa3);
    break;
  case 0x7c:
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0xa4);
    break;
  case 0x7d:
    Section_addActivePage(section, 0x88);
    Section_addActivePage(section, 0xa7);
    Section_addActivePage(section, 0xaa);
    Section_addActivePage(section, 0xab);
    Section_addActivePage(section, 0x95);
    Section_addActivePage(section, 0xa8);
    break;
  case 0x7e:
    Section_addActivePage(section, 0x88);
    Section_addActivePage(section, 0xaa);
    Section_addActivePage(section, 0xab);
    Section_addActivePage(section, 0x95);
    Section_addActivePage(section, 0xb0);
    break;
  case 0x7f:
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0x7f);
    Section_addActivePage(section, 0x9f);
    break;
  case 0x80:
    Section_addActivePage(section, 0x88);
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0x7f);
    Section_addActivePage(section, 0x9f);
    break;
  case 0x81:
    Section_addActivePage(section, 0x88);
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0x7f);
    Section_addActivePage(section, 0x84);
    break;
  case 0x82:
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0xa7);
    Section_addActivePage(section, 0xb3);
    break;
  case 0x83:
    Section_addActivePage(section, 0x88);
    Section_addActivePage(section, 0xa7);
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0x95);
    Section_addActivePage(section, 0x7f);
    Section_addActivePage(section, 0x84);
    break;
  case 0x84:
    Section_addActivePage(section, 0x88);
    Section_addActivePage(section, 0xa7);
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0x95);
    Section_addActivePage(section, 0x7f);
    Section_addActivePage(section, 0x84);
    break;
  case 0x85:
    Section_addActivePage(section, 0xbb);
    Section_addActivePage(section, 0x7f);
    Section_addActivePage(section, 0xb8);
    break;
  case 0x86:
    Section_addActivePage(section, 0xbb);
    Section_addActivePage(section, 0x7f);
    Section_addActivePage(section, 0xb7);
    break;
  case 0x87:
    Section_addActivePage(section, 0x88);
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0x84);
    break;
  case 0x88:
    Section_addActivePage(section, 0x5b);
    Section_addActivePage(section, 0xba);
    break;
  case 0x89:
    Section_addActivePage(section, 0x5b);
    Section_addActivePage(section, 0xba);
    break;
  case 0x8a:
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0xbd);
    break;
  case 0x8b:
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0xbc);
    break;
  case 0x8c:
    Section_addActivePage(section, 0x5d);
    Section_addActivePage(section, 0xcc);
    Section_addActivePage(section, 0xc0);
    break;
  case 0x8d:
    Section_addActivePage(section, 0x5d);
    Section_addActivePage(section, 0xcc);
    Section_addActivePage(section, 0xca);
    break;
  case 0x8e:
    Section_addActivePage(section, 0x5d);
    Section_addActivePage(section, 0xcc);
    Section_addActivePage(section, 0xc5);
    break;
  case 0x8f:
    Section_addActivePage(section, 0x5d);
    Section_addActivePage(section, 0xcc);
    Section_addActivePage(section, 0xc6);
    break;
  case 0x90:
    Section_addActivePage(section, 0x7f);
    Section_addActivePage(section, 0x5b);
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0xcd);
    break;
  case 0x91:
    Section_addActivePage(section, 0x7f);
    Section_addActivePage(section, 0x5b);
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0xcd);
    break;
  case 0x92:
    Section_addActivePage(section, 0x7f);
    Section_addActivePage(section, 0x5b);
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0xcd);
    break;
  case 0x93:
    Section_addActivePage(section, 0x7f);
    Section_addActivePage(section, 0x5b);
    Section_addActivePage(section, 0x5e);
    Section_addActivePage(section, 0xcd);
  }
}

RKSceneID Section_getSceneId(s32 sectionId) {
  switch (sectionId) {
  case 0x00 ... 0x05:
    return RK_SCENE_ID_GAME_START;
  case 0x06 ... 0x07:
    return SCENE_UNK3;
  case 0x08:
    return SCENE_UNK6;
  case 0x09:
    return SCENE_UNK7;
  case 0x0A:
    return SCENE_UNK8;
  case 0x0B:
    return SCENE_UNK9;
  case 0x0C:
    return SCENE_UNK10;
  case 0x0D:
    return RK_SCENE_ID_RACE;
  case 0x0E:
    return SCENE_UNK11;
  case 0x0F:
    return RK_SCENE_ID_RACE;
  case 0x10 ... 0x18:
    return RK_SCENE_ID_MAIN_MENU;
  case 0x19 ... 0x3A:
    return RK_SCENE_ID_RACE;
  case 0x3B ... 0x43:
    return RK_SCENE_ID_MAIN_MENU;
  case 0x44:
    return RK_SCENE_ID_RACE;
  case 0x45 ... 0x54:
    return RK_SCENE_ID_MAIN_MENU;
  case 0x55 ... 0x57:
    return RK_SCENE_ID_MULTI;
  case 0x58 ... 0x59:
    return RK_SCENE_ID_MAIN_MENU;
  case 0x5A ... 0x5D:
    return RK_SCENE_ID_MULTI;
  case 0x5E ... 0x67:
    return RK_SCENE_ID_MAIN_MENU;
  case 0x68 ... 0x77:
    return RK_SCENE_ID_RACE;
  case 0x78 ... 0x79:
    return RK_SCENE_ID_MAIN_MENU;
  case 0x7A ... 0x87:
    return RK_SCENE_ID_MULTI;
  case 0x88 ... 0x89:
    return RK_SCENE_ID_MAIN_MENU;
  case 0x8A ... 0x8B:
    return RK_SCENE_ID_MULTI;
  case 0x8C ... 0x94:
    return RK_SCENE_ID_MAIN_MENU;
  default:
    return RK_SCENE_ID_MAIN_MENU;
  }
}

// Symbol: Section_getResourceName
// PAL: 0x80631734..0x80631a58
MARK_BINARY_BLOB(Section_getResourceName, 0x80631734, 0x80631a58);
asm UNKNOWN_FUNCTION(Section_getResourceName){
#include "asm/80631734.s"
}

// Symbol: Section_hasBackModel
// PAL: 0x80631a58..0x80631af8
MARK_BINARY_BLOB(Section_hasBackModel, 0x80631a58, 0x80631af8);
asm UNKNOWN_FUNCTION(Section_hasBackModel){
#include "asm/80631a58.s"
}

// Symbol: SectionId_hasDriver
// PAL: 0x80631af8..0x80631bf0
MARK_BINARY_BLOB(SectionId_hasDriver, 0x80631af8, 0x80631bf0);
asm UNKNOWN_FUNCTION(SectionId_hasDriver){
#include "asm/80631af8.s"
}

// Symbol: SectionManager_getPageName
// PAL: 0x80631bf0..0x80631c00
MARK_BINARY_BLOB(SectionManager_getPageName, 0x80631bf0, 0x80631c00);
asm UNKNOWN_FUNCTION(SectionManager_getPageName){
#include "asm/80631bf0.s"
}

// Symbol: SectionManager_getSectionName
// PAL: 0x80631c00..0x80631c10
MARK_BINARY_BLOB(SectionManager_getSectionName, 0x80631c00, 0x80631c10);
asm UNKNOWN_FUNCTION(SectionManager_getSectionName){
#include "asm/80631c00.s"
}

// Symbol: unk_80631c10
// PAL: 0x80631c10..0x80631c68
MARK_BINARY_BLOB(unk_80631c10, 0x80631c10, 0x80631c68);
asm UNKNOWN_FUNCTION(unk_80631c10){
#include "asm/80631c10.s"
}

// Symbol: unk_80631c68
// PAL: 0x80631c68..0x80631ef8
MARK_BINARY_BLOB(unk_80631c68, 0x80631c68, 0x80631ef8);
asm UNKNOWN_FUNCTION(unk_80631c68) {
#include "asm/80631c68.s"
}

extern "C" u32 Section_getSoundType(s32 a1) {
  switch (a1) {
  case 0x0 ... 0xC:
    return -1;
  case 0xD:
    return 8;
  case 0xE:
    return -1;
  case 0xF:
    return 9;
  case 0x10 ... 0x34:
    return -1;
  case 0x35 ... 0x38:
    return 8;
  case 0x39 ... 0x3A:
    return 9;
  case 0x3B ... 0x3C:
    return 10;
  case 0x3D ... 0x3E:
    return 11;
  case 0x3F ... 0x44:
    return 5;
  case 0x45 ... 0x47:
    return 6;
  case 0x48 ... 0x54:
    return 7;
  case 0x55 ... 0x67:
    return 3;
  case 0x68 ... 0x79:
    return -1;
  case 0x7A ... 0x7C:
    return 2;
  case 0x7D ... 0x7E:
    return 4;
  case 0x7F ... 0x8B:
    return 3;
  case 0x8C ... 0x8F:
    return 6;
  case 0x90 ... 0x93:
    return 12;
  case 0x94:
    return -1;
  case 0x95 ... 0xAC:
    return -1;
  case 0xAD ... 0xB2:
    return -1;
  default:
    return -1;
  }
}

// Symbol: unk_80632080
// PAL: 0x80632080..0x806321b4
MARK_BINARY_BLOB(unk_80632080, 0x80632080, 0x806321b4);
asm UNKNOWN_FUNCTION(unk_80632080) {
#include "asm/80632080.s"
}

extern "C" s32 Section_getSoundTrigger(s32 x) {
  switch (x) {
  case 0:
    return 6;
  case 1:
    return 6;
  case 2:
  case 3:
  case 4:
    return 6;
  case 5:
    return 6;
  case 6:
    return 6;
  case 7:
  case 8:
  case 9:
  case 10:
  case 0xb:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
  case 0x10:
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x14:
  case 0x15:
  case 0x16:
  case 0x17:
  case 0x18:
  case 0x19:
  case 0x1a:
  case 0x1b:
  case 0x1c:
  case 0x1d:
  case 0x1e:
  case 0x1f:
  case 0x20:
  case 0x21:
  case 0x22:
  case 0x23:
  case 0x24:
  case 0x25:
  case 0x26:
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x2c:
  case 0x2d:
  case 0x2e:
  case 0x2f:
  case 0x30:
  case 0x31:
  case 0x32:
  case 0x33:
  case 0x34:
  case 0x35:
  case 0x36:
  case 0x37:
  case 0x38:
  case 0x39:
  case 0x3a:
  case 0x3b:
  case 0x3c:
  case 0x3d:
  case 0x3e:
  case 0x3f:
  case 0x40:
  case 0x41:
  case 0x42:
  case 0x43:
  case 0x44:
  case 0x45:
  case 0x46:
  case 0x47:
  case 0x48:
  case 0x49:
  case 0x4a:
    return 6;
  case 0x4b:
    return 6;
  case 0x4c:
    return 6;
  case 0x4d:
    return 6;
  case 0x4e:
  case 0x4f:
  case 0x50:
  case 0x51:
  case 0x52:
  case 0x53:
  case 0x54:
  case 0x55:
  case 0x56:
    return 6;
  case 0x57:
    return 0;
  case 0x58:
  case 0x59:
    return 6;
  case 0x5a:
    return 5;
  case 0x5b:
    return 6;
  case 0x5c:
    return 6;
  case 0x5d:
    return 6;
  case 0x5e:
    return 6;
  case 0x5f:
    return 0;
  case 0x60:
  case 0x61:
  case 0x62:
  case 99:
  case 100:
    return 6;
  case 0x65:
    return 5;
  case 0x66:
  case 0x67:
  case 0x68:
    return 6;
  case 0x69:
  case 0x6a:
    return 0;
  case 0x6b:
  case 0x6c:
  case 0x6d:
    return 1;
  case 0x6e:
  case 0x6f:
    return 2;
  case 0x70:
  case 0x71:
    return 2;
  case 0x72:
  case 0x73:
    return 0;
  case 0x74:
    return 1;
  case 0x75:
    return 0;
  case 0x76:
    return 1;
  case 0x77:
    return 0;
  case 0x78:
  case 0x79:
    return 2;
  case 0x7a:
  case 0x7b:
  case 0x7c:
  case 0x7d:
  case 0x7e:
    return 2;
  case 0x7f:
    return 6;
  case 0x80:
    return 0;
  case 0x81:
  case 0x82:
  case 0x83:
    return 1;
  case 0x84:
    return 0;
  case 0x85:
  case 0x86:
  case 0x87:
  case 0x88:
  case 0x89:
    return 6;
  case 0x8a:
    return 6;
  case 0x8b:
    return 0;
  case 0x8c:
    return 1;
  case 0x8d:
    return 0;
  case 0x8e:
    return 0;
  case 0x8f:
    return 2;
  case 0x90:
  case 0x91:
  case 0x92:
    return 3;
  case 0x93:
  case 0x94:
    return 6;
  case 0x95:
    return 6;
  case 0x96:
  case 0x97:
    return 2;
  case 0x98:
  case 0x99:
    return 6;
  case 0x9a:
    return 6;
  case 0x9b:
    return 2;
  case 0x9c:
    return 1;
  case 0x9d:
  case 0x9e:
    return 6;
  case 0x9f:
    return 0;
  case 0xa0:
    return 6;
  case 0xa1:
    return 2;
  case 0xa2:
  case 0xa3:
  case 0xa4:
    return 6;
  case 0xa5:
  case 0xa6:
  case 0xa7:
    return 6;
  case 0xa8:
  case 0xa9:
  case 0xaa:
  case 0xab:
  case 0xac:
  case 0xad:
  case 0xae:
  case 0xaf:
  case 0xb0:
    return 6;
  case 0xb1:
  case 0xb2:
    return 6;
  case 0xb3:
    return 6;
  case 0xb4:
    return 2;
  case 0xb5:
    return 6;
  case 0xb6:
  case 0xb7:
    return 6;
  case 0xb8:
    return 6;
  case 0xb9:
  case 0xba:
    return 6;
  case 0xbb:
  case 0xbc:
  case 0xbd:
  case 0xbe:
  case 0xbf:
    return 6;
  case 0xc0:
  case 0xc1:
  case 0xc2:
  case 0xc3:
  case 0xc4:
  case 0xc5:
  case 0xc6:
  case 199:
  case 200:
  case 0xc9:
    return 6;
  case 0xca:
  case 0xcb:
    return 6;
  case 0xcc:
    return 6;
  case 0xcd:
  case 0xce:
  case 0xcf:
  case 0xd0:
  case 0xd1:
  case 0xd2:
    return 6;
  default:
    return 6;
  }
}
