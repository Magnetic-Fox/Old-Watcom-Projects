#include <iostream>
#include <fstream>
#include <string.hpp>
#include <sys/stat.h>

#define MODE_1 "ANSI -> ASCII"
#define MODE_2 "ASCII -> ANSI"

unsigned char convert(unsigned char input, bool mode) // true - ANSI -> ASCII, false - ASCII -> ANSI
{
    if(mode) // ANSI -> ASCII
    {
        switch(input)
        {
            case 0xA5: // �
            {
                return 0xA4;
            }
            case 0xB9: // �
            {
                return 0xA5;
            }
            case 0xC6: // �
            {
                return 0x8F;
            }
            case 0xE6: // �
            {
                return 0x86;
            }
            case 0xCA: // �
            {
                return 0xA8;
            }
            case 0xEA: // �
            {
                return 0xA9;
            }
            case 0xA3: // �
            {
                return 0x9D;
            }
            case 0xB3: // �
            {
                return 0x88;
            }
            case 0xD1: // �
            {
                return 0xE3;
            }
            case 0xF1: // �
            {
                return 0xE4;
            }
            case 0xD3: // �
            {
                return 0xE0;
            }
            case 0xF3: // �
            {
                return 0xA2;
            }
            case 0x8C: // �
            {
                return 0x97;
            }
            case 0x9C: // �
            {
                return 0x98;
            }
            case 0x8F: // �
            {
                return 0x8D;
            }
            case 0x9F: // �
            {
                return 0xAB;
            }
            case 0xAF: // �
            {
                return 0xBD;
            }
            case 0xBF: // �
            {
                return 0xBE;
            }
            default:
            {
                return input;
            }
        }
    }
    else // ASCII -> ANSI
    {
        switch(input)
        {
            case 0xA4: // �
            {
                return 0xA5;
            }
            case 0xA5: // �
            {
                return 0xB9;
            }
            case 0x8F: // �
            {
                return 0xC6;
            }
            case 0x86: // �
            {
                return 0xE6;
            }
            case 0xA8: // �
            {
                return 0xCA;
            }
            case 0xA9: // �
            {
                return 0xEA;
            }
            case 0x9D: // �
            {
                return 0xA3;
            }
            case 0x88: // �
            {
                return 0xB3;
            }
            case 0xE3: // �
            {
                return 0xD1;
            }
            case 0xE4: // �
            {
                return 0xF1;
            }
            case 0xE0: // �
            {
                return 0xD3;
            }
            case 0xA2: // �
            {
                return 0xF3;
            }
            case 0x97: // �
            {
                return 0x8C;
            }
            case 0x98: // �
            {
                return 0x9C;
            }
            case 0x8D: // �
            {
                return 0x8F;
            }
            case 0xAB: // �
            {
                return 0x9F;
            }
            case 0xBD: // �
            {
                return 0xAF;
            }
            case 0xBE: // �
            {
                return 0xBF;
            }
            default:
            {
                return input;
            }
        }
    }
}

void errorMessage(char *argv[])
{
    std::cout << "Sk�adnia tego polecenia jest nast�puj�ca:" << std::endl << "   " << argv[0] << " <plik_wej�ciowy> <plik_wyj�ciowy> <tryb>" << std::endl;
    std::cout << std::endl << "Gdzie tryb przyjmuje nast�puj�ce warto�ci:" << std::endl << " * E - konwertuje ANSI na ASCII" << std::endl;
    std::cout << " * D - konwertuje ASCII na ANSI" << std::endl;
    return;
}

int main(int argc, char *argv[])
{
    struct stat results;
    std::fstream input, output;
    unsigned char buffer[512];
    unsigned int readcount=0, errortype=0;
    bool error=false, mode;
    std::cout << "Konwerter ANSI <-> ASCII dla MS-DOS, wersja 1.0, build " << __DATE__ << ", " << __TIME__ << std::endl << "(C)2019 Magnetic-Fox!" << std::endl << std::endl;
    if(argc==4)
    {
        input.open(argv[1], std::ios::in | std::ios::binary);
        if(input.is_open())
        {
            output.open(argv[2], std::ios::out | std::ios::binary);
            if(output.is_open())
            {
                if((strcmp("E",argv[3])==0) || (strcmp("e",argv[3])==0))
                {
                    mode=true;
                }
                else if((strcmp("D",argv[3])==0) || (strcmp("d",argv[3])==0))
                {
                    mode=false;
                }
                else
                {
                    error=true;
                    errortype=1;
                    errorMessage(argv);
                }
                if(!error)
                {
                    std::cout << "Konwertowanie plik�w..." << std::endl << std::endl << " * TRYB:           ";
                    if(mode)
                    {
                        std::cout << MODE_1;
                    }
                    else
                    {
                        std::cout << MODE_2;
                    }
                    std::cout << std::endl << " * PLIK WEJ�CIOWY: " << argv[1] << std::endl;
                    std::cout << " * PLIK WYJ�CIOWY: " << argv[2] << std::endl << std::endl;
                    if(stat(argv[1],&results)==0)
                    {
                        if(results.st_size==0)
                        {
                            std::cout << "Plik wej�ciowy pusty!" << std::endl << "Konwersja zako�czona." << std::endl;
                            errortype=7;
                            error=true;
                        }
                    }
                    else
                    {
                        std::cout << "Wyst�pi� b��d podczas dost�pu do pliku wej�ciowego!" << std::endl << "Konwersja zako�czona niepowodzeniem..." << std::endl;
                        errortype=6;
                        error=true;
                    }
                    if(!error)
                    {
                        while(!input.eof())
                        {
                            input.read(buffer,512);
                            readcount=input.gcount();
                            if((!input) && (readcount==0))
                            {
                                std::cout << "Wyst�pi� b��d podczas odczytu pliku wej�ciowego!" << std::endl << "Konwersja zako�czona niepowodzeniem..." << std::endl;
                                errortype=4;
                                error=true;
                                break;
                            }
                            for(unsigned int x=0; x<readcount; ++x)
                            {
                                buffer[x]=convert(buffer[x],mode);
                            }
                            output.write(buffer,readcount);
                            if(!output)
                            {
                                std::cout << "Wyst�pi� b��d podczas zapisu pliku wyj�ciowego!" << std::endl << "Konwersja zako�czona niepowodzeniem..." << std::endl;
                                errortype=5;
                                error=true;
                                break;
                            }
                        }
                    }
                    if(!error)
                    {
                        errortype=0;
                        std::cout << "Konwersja zako�czona powodzeniem!" << std::endl;
                    }
                }
                output.close();
            }
            else
            {
                errortype=3;
                std::cout << "Otworzenie pliku wyj�ciowego by�o niemo�liwe!" << std::endl;
            }
            input.close();
        }
        else
        {
            errortype=2;
            std::cout << "Otworzenie pliku wej�ciowego by�o niemo�liwe!" << std::endl;
        }
    }
    else
    {
        errortype=1;
        errorMessage(argv);
    }
    return errortype;
}
