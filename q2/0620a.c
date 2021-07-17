#include<stdio.h>

int main(void) {
    int mm[16] = {0x00B6,0x000C,0x00BB,0x000D,0x00B7,0x000E,0x00B6,0x000F,0x0027,0x0008,0x0000,0x0000,0x0123,0x0456,0x0000,0x0000};
    int up_rom[20][19] = {
        {0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,1,0,0}, //00
        {0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0}, //01
        {0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,0}, //02
        {1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0}, //03
        {0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,1,0,0}, //04
        {0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0}, //05
        {1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0}, //06
        {0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,0,0}, //07
        {0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0}, //08
        {0,0,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,1,0}, //09
        {0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,0,0}, //10
        {0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0}, //11
        {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0}, //12
        {0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,0,0}, //13
        {0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0}, //14
        {0,0,0,0,0,1,0,0,0,0,1,0,1,0,0,0,1,0,0}, //15
        {0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,0}, //16
        {0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0}, //17
        {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1}, //18
        {0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,1,0}};//19
    int acca,reg1,reg2,mrr,mwr,mar,ir,bus;
    int pc = 0, upc = 0;

    while(pc<17) {
        //Gate系
        if(up_rom[upc][2] ==1) {bus = pc;}   //Gate PC
        if(up_rom[upc][4] ==1) {bus = acca;} //Gate AccA
        if(up_rom[upc][7] ==1) {bus = reg2;} //Gate Reg2
        if(up_rom[upc][10]==1) {bus = mrr;}  //Gate MRR
        //Load系
        if(up_rom[upc][1] ==1) {pc   = bus;} //Load PC
        if(up_rom[upc][3] ==1) {acca = bus;} //Load AccA
        if(up_rom[upc][5] ==1) {reg1 = bus;} //Load Reg1
        if(up_rom[upc][6] ==1) {reg2 = bus + reg1;} //Load Reg2
        if(up_rom[upc][8] ==1) {mwr  = bus;} //Load MWR
        if(up_rom[upc][9] ==1) {mrr  = mm[mar];} //Load MRR
        //if(up_rom[upc][9] ==1) {mrr  = mwr;} 
        if(up_rom[upc][11]==1) {mar  = bus;} //Load MAR
        if(up_rom[upc][14]==1) {
            switch (mm[pc]) {
                case 0x00B6:ir = 7;
                            break;
                case 0x00B7:ir = 10;
                            break;
                case 0x00BB:ir = 13;
                            break;
                case 0x0027:ir = 18;
                            break;
                default    :break;
            }
        }//Load IR
        //その他
        if(up_rom[upc][0] == 1) {pc++;}//IncPC
        if(up_rom[upc][13]==1) { //MAE
            if(up_rom[upc][12]==1) {mrr = mm[mar];}
            else {mm[mar] = mwr;}
        } //R/W

        //upc系
        if     (up_rom[upc][15]==1) {upc = ir;}//Lead uPC
        else if(up_rom[upc][16]==1) {upc = upc + 1;}//Inc uPc
        else if(up_rom[upc][17]==1) {upc = 0;}//Clear uPC
        else {
            if(reg2==0){upc++;}
            else{upc = 0;}
        }//Test0

        printf("μPC:%2d,　PC:%2d,　AccA:%4d,　reg1:%4d,　reg2:%4d,　0x000E:%2d, 0x0027:%3d,　ir:%2d　bus:%4d\n",upc,pc,acca,reg1,reg2,mm[5],mm[8],ir,bus);
        //printf("μPC:%2d,　PC:%2d,　AccA:%4d,　reg1:%4d,　reg2:%4d,　0x000E:%2d\n",upc,pc,acca,reg1,reg2,mm[5]);
    }
    return 0;
}