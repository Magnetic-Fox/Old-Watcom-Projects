#include <iostream>
#include <conio.h>

int main(void)
{
    std::cout << "Tablica znak¢w" << std::endl << "(C)2019 Magnetic-Fox!" << std::endl << std::endl;
    std::cout << "   ";
    for(unsigned int x=0; x<16; ++x)
    {
        std::cout << "0" << std::hex << x << " ";
    }
    std::cout << std::endl << "00 ";
    for(unsigned int y=0; y<16; ++y)
    {
        if(y>0)
        {
            std::cout << std::hex << (y*16) << " ";
        }
        for(unsigned int x=0; x<16; ++x)
        {
            if((16*y+x)>=32)
            {
                std::cout << ' ' << (unsigned char)(16*y+x) << ' ';
            }
            else
            {
                std::cout << " . ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << "Kliknij dowolny klawisz, aby zakoäczy†..." << std::endl;
    getch();
    return 0;
}
