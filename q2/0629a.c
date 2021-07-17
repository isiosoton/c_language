#include<stdio.h>
#define MAX 48
#define UPC 30
#define BIT 20

int main(void) {
    int mm[MAX] = {0x00B6,0x000C,0x00BB,0x000D,0x00B7,0x000E,0x00B6,0x000F,0x00BB,0x000F,0x0027,0xFFFF,0x0123,0x0456,0x0000,0x0000};
    int up_rom[UPC][BIT] = {
        {0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,1,0,0,1}, //00
        {0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0,1}, //01
        {0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,0,1}, //02
        {1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,1}, //03
        {0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,1,0,0,1}, //04
        {0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0,1}, //05
        {1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,1}, //06
        {0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,0,0,1}, //07
        {0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0,1}, //08
        {0,0,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,1,0,1}, //09
        {0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,0,0,1}, //10
        {0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1}, //11
        {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1}, //12
        {0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,0,0,1}, //13
        {0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0,1}, //14
        {0,0,0,0,0,1,0,0,0,0,1,0,1,0,0,0,1,0,0,1}, //15
        {0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,0,1}, //16
        {0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,1}, //17
        {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1}, //18
        {0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,1,0,1}, //19
        {0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,0,0,1}, //20
        {0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0,1}, //21
        {0,0,0,0,0,1,0,0,0,0,1,0,1,0,0,0,1,0,0,1}, //22
        {0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0}, //23
        {0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,1}, //24
        {0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,1,0,1}};//25
    int acca,reg1,reg2,mrr = 0,mwr,mar,ir,bus,i;
    int pc = 0, upc = 0, er = 0;
    while(mm[pc]<65535 && pc<MAX/*1*/ && er == 0) {
        //bus = 0;
        if(upc==0)
        {
            printf("\nreset\n");
        }
        //Gate系
        if(up_rom[upc][2] ==1) {bus = pc;} //Gate PC
        if(up_rom[upc][4] ==1) {bus = acca;} //Gate AccA
        if(up_rom[upc][7] ==1) {bus = reg2;} //Gate Reg2
        if(up_rom[upc][10]==1) {bus = mrr;} //Gate MRR
        //Load系
        if(up_rom[upc][1] ==1) {pc   = bus;} //Load PC
        if(up_rom[upc][3] ==1) {acca = bus;} //Load AccA
        if(up_rom[upc][5] ==1) {reg1 = bus;} //Load Reg1
        if(up_rom[upc][6] ==1) { //Load Reg2
            if(up_rom[upc][19] ==1) {reg2 = bus + reg1;} //加算処理
            else                    {reg2 = bus - reg1;} //減算処理
        }
        if(up_rom[upc][8] ==1) {mwr = bus;} //Load MWR
        if(up_rom[upc][9] ==1) {mrr = mm[mar];} //Load MRR
        if(up_rom[upc][11]==1) {mar = bus;} //Load MAR
        if(up_rom[upc][14]==1) {
            switch (mm[pc]) {
                case 0x00B6:ir = 7; //LDAA命令
                            break;
                case 0x00B7:ir = 10; //STAA命令
                            break;
                case 0x00BB:ir = 13; //ADDA命令
                            break;
                case 0x0027:ir = 18; //JEQZ命令
                            break;
                case 0x00BC:ir = 20; //SUBA命令
                            break;
                case 0x0036:ir = 25; //JUMP命令
                            break;
                default    :printf("error\n");
                            er = 1;
                            break;
            }
        } //Load IR
        //その他
        if(up_rom[upc][0] ==1) {pc++;} //IncPC
        if(up_rom[upc][13]==1) { //MAE
            if(up_rom[upc][12]==1) {mrr = mm[mar];} //読み出し処理
            else {mm[mar] = mwr;} //R/W　//書き出し処理
        }
        //upc系
        if(up_rom[upc][15]==1)     {upc = ir;
                                    switch(ir){
                                        case  7:printf("LDAA命令\n");
                                                break;
                                        case 10:printf("STAA命令\n");
                                                break;
                                        case 13:printf("ADDA命令\n");
                                                break;
                                        case 18:printf("JEQZ命令\n");
                                                break;
                                        case 20:printf("SUBA命令\n");
                                                break;
                                        case 25:printf("JUMP命令\n");
                                                break;
                                        default:printf("error\n");
                                                er = 1;
                                                break;
                                        }
                                    } //Lead uPC
        else if(up_rom[upc][16]==1) {upc++;} //Inc uPC
        else if(up_rom[upc][17]==1) {upc = 0;} //Clear uPC
        else{
            if(reg2<=0){upc++;} //upcをincする
            else{upc = 0;} //upcをclearする
        } //Test
        //printf("μPC:%2d,　PC:%2d,　AccA:%4d,　reg1:%4d,　reg2:%4d,　mm[pc]:%3d, mm[mar]:%3d,　ir:%2d　bus:%4d　mar:%3d\n",upc,pc,acca,reg1,reg2,mm[pc],mm[mar],ir,bus,mar);
        //printf("μPC:%2d,　PC:%2d,　AccA:%4d,　reg1:%4d,　reg2:%4d,　0x000E:%2d\n",upc,pc,acca,reg1,reg2,mm[5]);
        printf("μPC:%2d,　PC:%2d,　mar:%2d,　mm[mar]:%4d,　mm[pc]:%5d, mrr:%4d,　AccA:%4d,　reg1:%4d,　reg2:%4d,　bus:%4d\n",upc-1,pc,mar,mm[mar],mm[pc],mrr,acca,reg1,reg2,bus);

    }
    for(i=0;i<MAX;i++)
    {
        printf("mm[%2d]:%5d\n",i,mm[i]);
    }
    return 0;
}
//偶数：命令　奇数：値
//加算試し 0x00B6,0x000C,0x00BB,0x000D,0x00B7,0x000E,0x00B6,0x000F,0x00BB,0x000F,0x0027,0xFFFF,0x0123,0x0456,0x0000,0x0000
//乗算試し 0x00B6,0x002B,0x00BB,0x002D,0x0027,0x0006,0x00B6,0x002C,0x00BB,0x002A,0x00B7,0x002C,0x00B6,0x002B,0x00BC,0x002E,0x00B7,0x002B,0x0027,0x0016,0x0036,0x0006,0x0036,0x002F,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0005,0x0003,0x0000,0x0000,0x0001,0xFFFF
//除算試し 0x00B6,0x002B,0x00BB,0x002D,0x0027,0x0006,0x00B6,0x002A,0x00BC,0x002B,0x00B7,0x002A,0x0027,0x0016,0x00B6,0x002C,0x00BB,0x002E,0x00B7,0x002C,0x0036,0x0006,0x00B6,0x002A,0x00BB,0x002B,0x00B7,0x002A,0x0036,0x002F,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x000C,0x0005,0x0000,0x0000,0x0001,0xFFFF
