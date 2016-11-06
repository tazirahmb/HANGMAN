#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>

using namespace std;

void gotoxy(int kolom, int baris) //prosedur koordinat
{
    COORD posisi = {kolom,baris}; //COORD itu identifer buat koordinat (aktifnya cuma kalo ada windows.h)
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), posisi); //set posisi kursornya in here.
}

void delay(void)
{
    for (int i=0;i<10000000;i++)
    {
        i++;
    }
}

int main()
{
    SetConsoleTitle("HANGMAN"); //buat ganti nama title

    //OPENING------------------------------------------------------------------

    system("color 1E");


        gotoxy(30,10);    cout<<"H"<<endl;
        delay();
        gotoxy(31,10);    cout<<"A"<<endl;
        delay();
        gotoxy(32,10);    cout<<"N"<<endl;
        delay();
        gotoxy(33,10);    cout<<"G"<<endl;
        delay();
        gotoxy(34,10);    cout<<"M"<<endl;
        delay();
        gotoxy(35,10);    cout<<"A"<<endl;
        delay();
        gotoxy(36,10);    cout<<"N"<<endl;
        delay();
        gotoxy(37,10);    cout<<"_"<<endl;
        delay();
        gotoxy(38,10);    cout<<"_"<<endl;
        delay();
        gotoxy(39,10);    cout<<"_"<<endl;
        delay();
        gotoxy(30,12);    cout<<"A"<<endl;
        delay();
        gotoxy(32,12);    cout<<"G"<<endl;
        delay();
        gotoxy(33,12);    cout<<"A"<<endl;
        delay();
        gotoxy(34,12);    cout<<"M"<<endl;
        delay();
        gotoxy(35,12);    cout<<"E"<<endl;
        delay();
        gotoxy(37,12);    cout<<":"<<endl;
        delay();
        gotoxy(38,12);    cout<<")"<<endl;
        delay();
        delay();
        delay();

    cout<<"\nTekan sembarang tombol untuk melanjutkan..."<<endl;
    getch();


    //------------------------------------------------------------------------
    gamez:
    //DEKLARASI
    int life = 6, betol, go = 0;
    string kata = "", petunjuk, tampil, muncul = "", used = "";
    char katin, inputin, lagi;
    bool fond, dobel, ceck;
    const char *x;

    //-------------------------------------------------------------------------

    system("color 70 && cls");
    //TAMPILAN MULAI
    cout << "\nMasukkan kata yang ingin dicoba (lowercase only) :\n"; //input kata yg mau ditebak
    katin = _getch(); //input, tapi ga nampilin
    while(katin != 13) //selama user ga pencet 'enter'/kode ASCII 13
    {
        if(katin == 8) //ASCII-nya backspace
        {
            cout<<'\b'<<' '<<'\b'; //buat ngapus
            kata.erase(kata.end()-1, kata.end()); //buat ngapus stringnya
        }
        else
        {
            cout << '*';
            kata.push_back(katin); //naro di belakang string
        }

        katin = _getch();
    }

    cout<<"\n\nmasukkan petunjuknya :\n"; //input petunjuknya
    getline(cin,petunjuk); //pake getline karena kalo pake cin, kata abis space ga kesimpen

    //---------------------------------------------------------------------------------

    //PROSES PEMBUATAN KATA TERSEMBUNYI

    betol = kata.length();

    while (go < kata.length())
    {
        if ((kata.at(go) == ' ') || (kata.at(go) == ',') || (kata.at(go) == '.') || (kata.at(go) == '\''))
        {
            muncul.push_back(kata.at(go));
            betol--;
        }
        else
        {
            muncul.push_back('_');
        }
        go++;
    }

    //----------------------------------------------------------------------------------


    //------------------------------------------------------------------------------------

    //PROSES NEBAK <GAME START>

    while((life > 0) && (betol > 0)) //selama tebakannya belum bener dan nyawa masi ada
    {
        searchh:
        //proses input
        system("cls");
        cout<<"PETUNJUK : "<<endl<<petunjuk<<endl<<endl;
        cout<<"Huruf yang sudah digunakan :"<<endl;
        cout<<used<<endl<<endl;
        cout<<"sisa nyawa : "<<life<<endl<<endl;
        cout<<muncul<<endl<<endl;
        cout<<betol<<" huruf lagi"<<endl<<endl<<endl;

        if (dobel)
        {
            cout<<"karakter "<<x<<" sudah digunakan."<<endl<<endl;
        }

        else if (ceck)
        {
            cout<<"karakter "<<x<<" ada di sini"<<endl<<endl;
        }

        else if(not ceck)
        {
            cout<<"maaf, karakter "<<x<<" tidak terdapat di sini"<<endl<<endl;
        }

        cout<<endl<<endl;

        if(life == 6)
        {
            gotoxy(45,0);    cout<<"|________________"<<endl;
            gotoxy(45,1);    cout<<"|            "<<endl;
            gotoxy(45,2);    cout<<"|            "<<endl;
            gotoxy(45,3);    cout<<"|            "<<endl;
            gotoxy(45,4);    cout<<"|            "<<endl;
            gotoxy(45,5);    cout<<"|             "<<endl;
            gotoxy(45,6);    cout<<"|            "<<endl;
            gotoxy(45,7);    cout<<"|            "<<endl;
            gotoxy(45,8);    cout<<"|            "<<endl;
            gotoxy(45,9);    cout<<"|            "<<endl;
            gotoxy(45,10);   cout<<"|            "<<endl;
            gotoxy(45,11);   cout<<"|            "<<endl;
            gotoxy(45,12);   cout<<"|            "<<endl;
            gotoxy(45,13);   cout<<"|            "<<endl;
            gotoxy(45,14);   cout<<"|            "<<endl;
            gotoxy(45,15);   cout<<"|            "<<endl;
            gotoxy(45,16);   cout<<"|"<<endl;
            gotoxy(45,17);   cout<<"|"<<endl;
            gotoxy(45,18);   cout<<"-------"<<endl;
        }
        else if(life == 5)
        {
            gotoxy(45,0);    cout<<"|________________"<<endl;
            gotoxy(45,1);    cout<<"|               |"<<endl;
            gotoxy(45,2);    cout<<"|               |"<<endl;
            gotoxy(45,3);    cout<<"|               |"<<endl;
            gotoxy(45,4);    cout<<"|               |"<<endl;
            gotoxy(45,5);    cout<<"|             00000"<<endl;
            gotoxy(45,6);    cout<<"|            0     0"<<endl;
            gotoxy(45,7);    cout<<"|            0     0"<<endl;
            gotoxy(45,8);    cout<<"|             00000"<<endl;
            gotoxy(45,9);    cout<<"|              "<<endl;
            gotoxy(45,10);   cout<<"|             "<<endl;
            gotoxy(45,11);   cout<<"|            "<<endl;
            gotoxy(45,12);   cout<<"|            "<<endl;
            gotoxy(45,13);   cout<<"|            "<<endl;
            gotoxy(45,14);   cout<<"|            "<<endl;
            gotoxy(45,15);   cout<<"|            "<<endl;
            gotoxy(45,16);   cout<<"|"<<endl;
            gotoxy(45,17);   cout<<"|"<<endl;
            gotoxy(45,18);   cout<<"-------"<<endl;
        }

        else if (life == 4)
        {
            gotoxy(45,0);    cout<<"|________________"<<endl;
            gotoxy(45,1);    cout<<"|               |"<<endl;
            gotoxy(45,2);    cout<<"|               |"<<endl;
            gotoxy(45,3);    cout<<"|               |"<<endl;
            gotoxy(45,4);    cout<<"|               |"<<endl;
            gotoxy(45,5);    cout<<"|             00000"<<endl;
            gotoxy(45,6);    cout<<"|            0     0"<<endl;
            gotoxy(45,7);    cout<<"|            0     0"<<endl;
            gotoxy(45,8);    cout<<"|             00000"<<endl;
            gotoxy(45,9);    cout<<"|               1"<<endl;
            gotoxy(45,10);   cout<<"|               1 "<<endl;
            gotoxy(45,11);   cout<<"|               1  "<<endl;
            gotoxy(45,12);   cout<<"|               1"<<endl;
            gotoxy(45,13);   cout<<"|              "<<endl;
            gotoxy(45,14);   cout<<"|             "<<endl;
            gotoxy(45,15);   cout<<"|            "<<endl;
            gotoxy(45,16);   cout<<"|"<<endl;
            gotoxy(45,17);   cout<<"|"<<endl;
            gotoxy(45,18);   cout<<"-------"<<endl;
        }

        else if (life == 3)
        {
            gotoxy(45,0);    cout<<"|________________"<<endl;
            gotoxy(45,1);    cout<<"|               |"<<endl;
            gotoxy(45,2);    cout<<"|               |"<<endl;
            gotoxy(45,3);    cout<<"|               |"<<endl;
            gotoxy(45,4);    cout<<"|               |"<<endl;
            gotoxy(45,5);    cout<<"|             00000"<<endl;
            gotoxy(45,6);    cout<<"|            0     0"<<endl;
            gotoxy(45,7);    cout<<"|            0     0"<<endl;
            gotoxy(45,8);    cout<<"|             00000"<<endl;
            gotoxy(45,9);    cout<<"|              /1"<<endl;
            gotoxy(45,10);   cout<<"|             / 1"<<endl;
            gotoxy(45,11);   cout<<"|            /  1"<<endl;
            gotoxy(45,12);   cout<<"|               1"<<endl;
            gotoxy(45,13);   cout<<"|              "<<endl;
            gotoxy(45,14);   cout<<"|             "<<endl;
            gotoxy(45,15);   cout<<"|            "<<endl;
            gotoxy(45,16);   cout<<"|"<<endl;
            gotoxy(45,17);   cout<<"|"<<endl;
            gotoxy(45,18);   cout<<"-------"<<endl;
        }

        else if (life == 2)
        {
            gotoxy(45,0);    cout<<"|________________"<<endl;
            gotoxy(45,1);    cout<<"|               |"<<endl;
            gotoxy(45,2);    cout<<"|               |"<<endl;
            gotoxy(45,3);    cout<<"|               |"<<endl;
            gotoxy(45,4);    cout<<"|               |"<<endl;
            gotoxy(45,5);    cout<<"|             00000"<<endl;
            gotoxy(45,6);    cout<<"|            0     0"<<endl;
            gotoxy(45,7);    cout<<"|            0     0"<<endl;
            gotoxy(45,8);    cout<<"|             00000"<<endl;
            gotoxy(45,9);    cout<<"|              /1\\"<<endl;
            gotoxy(45,10);   cout<<"|             / 1 \\"<<endl;
            gotoxy(45,11);   cout<<"|            /  1  \\"<<endl;
            gotoxy(45,12);   cout<<"|               1"<<endl;
            gotoxy(45,13);   cout<<"|              "<<endl;
            gotoxy(45,14);   cout<<"|             "<<endl;
            gotoxy(45,15);   cout<<"|            "<<endl;
            gotoxy(45,16);   cout<<"|"<<endl;
            gotoxy(45,17);   cout<<"|"<<endl;
            gotoxy(45,18);   cout<<"-------"<<endl;
        }

        else if (life == 1)
        {
            gotoxy(45,0);    cout<<"|________________"<<endl;
            gotoxy(45,1);    cout<<"|               |"<<endl;
            gotoxy(45,2);    cout<<"|               |"<<endl;
            gotoxy(45,3);    cout<<"|               |"<<endl;
            gotoxy(45,4);    cout<<"|               |"<<endl;
            gotoxy(45,5);    cout<<"|             00000"<<endl;
            gotoxy(45,6);    cout<<"|            0     0"<<endl;
            gotoxy(45,7);    cout<<"|            0     0"<<endl;
            gotoxy(45,8);    cout<<"|             00000"<<endl;
            gotoxy(45,9);    cout<<"|              /1\\"<<endl;
            gotoxy(45,10);   cout<<"|             / 1 \\"<<endl;
            gotoxy(45,11);   cout<<"|            /  1  \\"<<endl;
            gotoxy(45,12);   cout<<"|               1"<<endl;
            gotoxy(45,13);   cout<<"|              / "<<endl;
            gotoxy(45,14);   cout<<"|             /  "<<endl;
            gotoxy(45,15);   cout<<"|            /   "<<endl;
            gotoxy(45,16);   cout<<"|"<<endl;
            gotoxy(45,17);   cout<<"|"<<endl;
            gotoxy(45,18);   cout<<"-------"<<endl;
        }

        gotoxy(0,11);
        cout<<"masukkan 1 huruf : \n";
        inputin = _getch();
        x = new char (inputin);

        //bool
        fond = 0;        ceck = 0;          dobel = 0;

        //proses searching...
        while(not fond)
        {
            for(int z = 0; z < used.length(); z++) //buat ngecek apa kata yg diinput udhah pernah dimasukin ato belom
            {
                if(inputin == used.at(z))
                {
                    dobel = 1;
                    system("cls");
                    goto searchh;
                }
            }

            for(int o = 0; o < kata.length(); o++)
            {
                if(inputin == kata.at(o))  //the error is here
                {
                    muncul.replace(o,1,x);
                    ceck = 1;
                    betol--;
                }
            }
            fond = 1;
        }

        if (not ceck)
        {
            life--;
        }

        used.push_back(' ');
        used.push_back(inputin);
    }

    //--------------------------------------------------------------------------
    //GAME FINISH

    system("cls");

    if (life == 0)
    {
        system("color 47");
            gotoxy(45,0);    cout<<"|________________"<<endl;
            gotoxy(45,1);    cout<<"|               |"<<endl;
            gotoxy(45,2);    cout<<"|               |"<<endl;
            gotoxy(45,3);    cout<<"|               |"<<endl;
            gotoxy(45,4);    cout<<"|               |"<<endl;
            gotoxy(45,5);    cout<<"|             00000"<<endl;
            gotoxy(45,6);    cout<<"|            0     0"<<endl;
            gotoxy(45,7);    cout<<"|            0     0"<<endl;
            gotoxy(45,8);    cout<<"|             00000"<<endl;
            gotoxy(45,9);    cout<<"|              /1\\"<<endl;
            gotoxy(45,10);   cout<<"|             / 1 \\"<<endl;
            gotoxy(45,11);   cout<<"|            /  1  \\"<<endl;
            gotoxy(45,12);   cout<<"|               1"<<endl;
            gotoxy(45,13);   cout<<"|              / \\"<<endl;
            gotoxy(45,14);   cout<<"|             /   \\"<<endl;
            gotoxy(45,15);   cout<<"|            /     \\"<<endl;
            gotoxy(45,16);   cout<<"|"<<endl;
            gotoxy(45,17);   cout<<"|"<<endl;
            gotoxy(45,18);   cout<<"-------"<<endl;

            cout<<"GAME OVER"<<endl;
            cout<<"kata-kata yang benar adalah : '"<<kata<<"'"<<endl;
    }

    else if (betol == 0)
    {
        system("color 27");
        gotoxy(16,5);   cout<<kata<<endl;
        gotoxy(8,3);    cout<<"SELAMAT, TEBAKAN ANDA BENAR :D"<<endl;
        gotoxy(13,7);    cout<<"sisa nyawa anda : "<<life<<endl;

        gotoxy(45,1);   cout<<"    000000000000000000000"<<endl;
        gotoxy(45,2);   cout<<"   0     ___       ____  0"<<endl;
        gotoxy(45,3);   cout<<"  0    _/ \xdb \\_   _/ \xdb  \\_  0"<<endl;
        gotoxy(45,4);   cout<<" 0     |  \xdb  |   |  \xdb   |   0"<<endl;
        gotoxy(45,5);   cout<<"0      |  \xdb  |   |  \xdb   |    0"<<endl;
        gotoxy(45,6);   cout<<"0    _____________________   0"<<endl;
        gotoxy(45,7);   cout<<" 0  \\                   /   0"<<endl;
        gotoxy(45,8);   cout<<"  0   -------------------  0"<<endl;
        gotoxy(45,9);   cout<<"    00000000000000000000000"<<endl<<endl;

    }

    getch();

    //------------------------------------------------------------------

    lagi:
        system("cls");
        cout<<"\napakah anda ingin mengulang lagi? (y/n) "<<endl;
        lagi = gets();

        if(lagi == 'y' || lagi == 'Y')
        {
            cout<<"Selamat mengulang :)"<<endl;
            getch();
            goto gamez;
        }

        else if(lagi == 'n' || lagi == 'N')
        {
            cout<<"terima kasih sudah memakai aplikasi ini :)"<<endl;
            getch();
        }

        else
        {
            cout<<"maaf, input yang anda masukkan salah. silahkan input ulang";
            getch();
            goto lagi;
        }

    MessageBox(NULL,"~~~HANGMAN~~~\nCode by : #173\nNIM : 3115133759\nHope you like it :)\n~~~~~~~~~~~~~","CREDIT",MB_ICONINFORMATION | MB_OK);
    return EXIT_SUCCESS;
}
