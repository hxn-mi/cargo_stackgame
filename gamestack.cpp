#include<iostream>
#include<conio.h>
#include<dos.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

int muatan=1;
int skorTot=0;
int check=1;
//var yang akan dirandom
string jenis="Gula merah";
int skorA=0;
int beratB=0;
//array nama produk
string jenisproduk[6]={"Pala","Gula","Teh","Susu","Kopi","Kelapa"};


struct kapal
{
   string nama;
   int skor;
   int berat;
};

struct kapal kargo[13];

int Randoms(int bawah, int atas,int count)
{
    srand(time(0));
    int i;
    int num = (rand() %
    (atas - bawah + 1)) + bawah;
    return num;
}

void gotoxy(int x, int y)
{
   	COORD k = {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), k);
}

void kosong(int top)
{
	if(top==1)
	{
		gotoxy(20,25);cout<<"your boat is Empty...";
	}	
}

void cek(int top)
{
	int a;
	for(a=1;a<=10;a++)
	{
		gotoxy(10,16-a);printf("                              ");
	}
	for(a=1;a<top;a++)
	{
		gotoxy(10,16-a);cout<<a<<"."<<kargo[a].nama<<" point- "<<kargo[a].skor<<" berat- "<<kargo[a].berat;
	}
	gotoxy(62,19);cout<<"                   ";
	gotoxy(62,19);cout<<"skor total==>"<<skorTot;
}

void push(int top)
{
	
	if(muatan!=13)
	{
		kargo[top].nama=jenis;
		kargo[top].skor=skorA;
        kargo[top].berat=beratB;
		muatan+=beratB;
        skorTot+=skorA;
        check++;
	}
}

void pop(int top)
{
	if(muatan!=1)
	{
		gotoxy(10,21);cout<<"                                 ";
		gotoxy(10,21);cout<<kargo[top-1].nama<<" point "<<kargo[top-1].skor<<" berat "<<kargo[top-1].berat<<" dibuang";
		muatan-=kargo[top-1].berat;
        skorTot-=kargo[top-1].skor;
        check--;

	}
}

void barangAcak(){
    int skorbarang=rand()%300+1;
    int beratbarang=rand()%3+1;
    skorA=skorbarang;
    beratB=beratbarang;
    jenis=jenisproduk[rand()%5];
    gotoxy(71,6);cout<<"         ";
	gotoxy(71,6);cout<<jenis;
	gotoxy(71,7);cout<<"         ";
	gotoxy(71,7);cout<<"Skor: "<<skorA;
	gotoxy(71,8);cout<<"         ";
	gotoxy(71,8);cout<<"Berat: "<<beratB;
}

int main()
{
    int pilih;
    int x;
	int lol;
    barangAcak();

    // garis game & kapal
    for(x=0;x<60;x++)
	  	{
	    	gotoxy(x,0);printf("%c",196);
	    	gotoxy(x,24);printf("%c",196);
	  	}
    for(x=1;x<24;x++)
	  	{
	   		gotoxy(0,x);printf("%c",179);
			gotoxy(60,x);printf("%c",179);
	  	}
    for(x=3;x<57;x++)
        {
        	gotoxy(x,18);printf("%c",196);
        }
    for(x=7;x<53;x++)
        {
        	gotoxy(x,23);printf("%c",196);
        }
    gotoxy(7,23);printf("%c",192);
    gotoxy(6,22);printf("%c",192);
    gotoxy(5,21);printf("%c",192);
    gotoxy(4,20);printf("%c",192);
    gotoxy(3,19);printf("%c",192);
    gotoxy(52,23);printf("%c",217);
    gotoxy(53,22);printf("%c",217);
    gotoxy(54,21);printf("%c",217);
    gotoxy(55,20);printf("%c",217);
    gotoxy(56,19);printf("%c",217);
	gotoxy(0,0);printf("%c",218);
	gotoxy(60,24);printf("%c",217);	
	gotoxy(0,24);printf("%c",192);	
	gotoxy(60,0);printf("%c",191);	

    //garis cargo A,B,C,D
    for(x=3;x<57;x++)
        {
        	gotoxy(x,3);printf("%c",196);
			gotoxy(x,17);printf("%c",196);
        }
    for(x=4;x<17;x++)
        {
			gotoxy(3,x);printf("%c",179);
        	gotoxy(57,x);printf("%c",179);
        }
	gotoxy(3,3);printf("%c",218);
	gotoxy(57,17);printf("%c",217);	
	gotoxy(3,17);printf("%c",192);	
	gotoxy(57,3);printf("%c",191);

    //garis menu
    for(x=61;x<90;x++)
		{
	    	gotoxy(x,0);printf("%c",196);
	    	gotoxy(x,24);printf("%c",196);
		}
    for(x=0;x<24;x++)
		{
	    	gotoxy(61,x);printf("%c",179);
	    	gotoxy(90,x);printf("%c",179);
		}
    gotoxy(61,0);printf("%c",218);
	gotoxy(90,24);printf("%c",217);	
	gotoxy(61,24);printf("%c",192);	
	gotoxy(90,0);printf("%c",191);	
	
	gotoxy(63,1);cout<<"CARGO STACK GAME";
	gotoxy(63,2);cout<<"achieve the highest score!";
	gotoxy(63,3);cout<<"";
	gotoxy(63,22);cout<<"Oleh : ";
	gotoxy(63,23);cout<<"Hanif,Fandy,Michael,Theo";

    //garis container pada menu
	for(x=70;x<80;x++)
		{
			gotoxy(x,4);printf("%c",196);
			gotoxy(x,9);printf("%c",196);
		}
	for(x=5;x<9;x++)
		{
			gotoxy(70,x);printf("%c",179);
			gotoxy(80,x);printf("%c",179);
		}
	gotoxy(70,4);printf("%c",218);
	gotoxy(80,9);printf("%c",217);	
	gotoxy(70,9);printf("%c",192);	
	gotoxy(80,4);printf("%c",191);
	
    while (muatan<=13) {
        kosong(muatan);
        gotoxy(62,12);cout<<"1. Ambil muatan";
		gotoxy(62,13);cout<<"2. Buang muatan";
		gotoxy(62,14);cout<<"3. skip dan lihat isi kapal";
		gotoxy(62,16);cout<<"                 ";
        gotoxy(62,16);cout<<" kapasitas 12/"<<muatan-1;
		gotoxy(62,17);cout<<"pilihan anda : ";
		gotoxy(62,18);cout<<" ";
		gotoxy(62,18);cin>>pilih;
        if(pilih==1) {
		gotoxy(20,25);cout<<"                      ";
		gotoxy(10,21);cout<<"                                 ";
		push(check),barangAcak();
		}
		if(pilih==2) {pop(check);}
		if(pilih==3) {cek(check),barangAcak();}
		cek(check);
        if (muatan==13){
            gotoxy(20,25);cout<<"                      ";
            gotoxy(20,25);cout<<"Menang!";
            gotoxy(20,26);cout<<"Total point: "<<skorTot;cin>>lol;
            break;
        }
        if (muatan>13){
            gotoxy(20,25);cout<<"                      ";
            gotoxy(20,25);cout<<"Kapal tenggelam :(";cin>>lol;
            break;
        }
    };

    return 0;
}
