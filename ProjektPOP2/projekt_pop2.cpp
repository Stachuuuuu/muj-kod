#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <sstream>
#include <string>

using namespace std;

int main()
{

    fstream wejscie;
    fstream wyjscie;

    wejscie.open("Metar_EPGD_2013_12_05.txt", ios::in);
    wyjscie.open("wyjœcie.txt", ios::out);

    if(!wejscie)
    {
        cout << "Blad otwarcia plikow.\n";
        exit(0);
    }
    else
    {
        string linia;
        string slowo;



        wyjscie << "Data: 5.12.2013\n\n";

        while(getline(wejscie,linia))
        {
            string czas;
            string wiatr;
            string temperatura;
            string cisnienie;
            stringstream ss;
            ss << slowo;

            while (ss << slowo)
            {
            int x=0;
            for(int i=0;i<20;i++)
            {
                if(slowo[i]!=NULL)
                    x++;
                else
                    break;
            }

            switch(x)
            {
            case 7:
                if(slowo[6]=='Z')//czas
                {
                    czas=slowo[2]+slowo[3]+slowo[4]+slowo[5];
                }
                break;
            case 10:
                if(slowo[8]=='K' && slowo[9]=='T') //kierunek i predkosc wiatru
                {
                    wiatr=slowo[0]+slowo[1]+slowo[2]+slowo[3]+slowo[4]+slowo[6]+slowo[7];
                }

                break;

            case 5:
                if(slowo[2]=='/') //temperatura
                {
                    temperatura=slowo[0]+slowo[1];
                }

                break;
            case 8:
                if(slowo[0]=='Q') //cisnienie
                {
                    cisnienie=slowo[1]+slowo[2]+slowo[3]+slowo[4];
                }

                break;
            }
            }
               wyjscie << "Czas UTC: ";
               wyjscie << czas[0] << czas[1] << ":" << czas[2] << czas[3];
               wyjscie << "\n";
               wyjscie << "Wiatr: z kierunku ";
               wyjscie << wiatr[0] << wiatr[1] << wiatr[2];
               wyjscie << " stopni, predkosc ";
               wyjscie << wiatr[3] << wiatr[4];
               wyjscie << " wezlow w porywach do ";
               wyjscie << wiatr[6] << wiatr[7];
               wyjscie << "\n";
               wyjscie << "temperatura: ";
               wyjscie << temperatura[0] << temperatura[1];
               wyjscie << " stopni C \n";
               wyjscie << "cisnienie atmosferyczne: ";
               if(cisnienie[0]!='0') wyjscie << cisnienie[0];
               wyjscie << cisnienie[1] << cisnienie[2] << cisnienie[3];
               wyjscie << " hPa\n\n";






        }
    }

    wejscie.close();
    wyjscie.close();




    return 0;
}
