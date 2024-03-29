#include <iostream>
#include <conio.h>

#include "foxcodealgorithm.hpp"
#include "foxcodeinfo.hpp"
#include "useful.hpp"
#include "foxcodestringtable.hpp"
#include "fileerrorcodes.hpp"

int main(int argc, char** argv)
{
    std::cout << "         ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»" << std::endl;
    std::cout << "         º FoxCode Converter 1.0, MS-DOS, build " << __DATE__ << ", " << __TIME__ << " º" << std::endl;
    std::cout << "         ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼" << std::endl;
    std::cout << "         ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿" << std::endl;
    std::cout << "         ³" << PROGRAM << ": Bartˆomiej \"Magnetic-Fox\" W©grzyn         ³" << std::endl;
    std::cout << "         ³" << ALGORITHM << ": Bartˆomiej \"Magnetic-Fox\" W©grzyn         ³" << std::endl;
    std::cout << "         ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´" << std::endl;
    std::cout << "         ³      (C)2016-2019 Bartˆomiej \"Magnetic-Fox\" W©grzyn!       ³" << std::endl;
    std::cout << "         ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ" << std::endl << std::endl;
    if(argc>1)
    {
        upCharArray(argv[1]);
    }
    if(argc==2)
    {
        if((strcmp(argv[1],"ENCODE")==0) || (strcmp(argv[1],"E")==0) || (strcmp(argv[1],"DECODE")==0) || (strcmp(argv[1],"D")==0))
        {
            std::cout << NO_FILES << std::endl << WARNING_NO_PASSWORD << std::endl;
        }
        else if(strcmp(argv[1],"/I")==0)
        {
            std::cout << INFO_TEXT_01 << std::endl << std::endl;
            std::cout << INFO_TEXT_02 << std::endl << std::endl;
            std::cout << INFO_TEXT_03 << std::endl;
            std::cout << INFO_TEXT_04 << std::endl;
            std::cout << INFO_TEXT_05 << std::endl;
            std::cout << INFO_TEXT_06 << std::endl;
            std::cout << INFO_TEXT_07 << std::endl << std::endl;
            std::cout << PRESS_ANY_KEY << std::endl << std::endl;
            getch();
            std::cout << INFO_TEXT_08 << std::endl << std::endl;
            std::cout << INFO_TEXT_09 << std::endl;
            std::cout << INFO_TEXT_10 << std::endl;
            std::cout << INFO_TEXT_11 << std::endl;
            std::cout << INFO_TEXT_12 << std::endl;
            std::cout << INFO_TEXT_13 << std::endl;
            std::cout << INFO_TEXT_14 << std::endl << std::endl;
            std::cout << INFO_TEXT_15 << std::endl << std::endl;
            std::cout << INFO_TEXT_16 << __DATE__ << std::endl;
            std::cout << INFO_TEXT_17 << __TIME__ << std::endl;
            std::cout << INFO_TEXT_18 << std::endl << std::endl;
            std::cout << INFO_TEXT_19 << std::endl << std::endl;
            std::cout << INFO_TEXT_20 << std::endl;
            std::cout << INFO_TEXT_21 << std::endl;
            std::cout << INFO_TEXT_22 << std::endl;
            std::cout << INFO_TEXT_23 << std::endl << std::endl;
            std::cout << PRESS_ANY_KEY << std::endl << std::endl;
            getch();
            std::cout << INFO_TEXT_24 << std::endl;
            std::cout << INFO_TEXT_25 << std::endl;
            std::cout << INFO_TEXT_26 << std::endl;
            std::cout << INFO_TEXT_27 << std::endl << std::endl;
            std::cout << INFO_TEXT_28 << std::endl << std::endl << std::endl << std::endl;
            std::cout << "   ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿" << std::endl;
            std::cout << "   ³ Bartˆomiej \"Magnetic-Fox\" W©grzyn             magnetic-fox@hotmail.com ³" << std::endl;
            std::cout << "   ³                                                    bwegrzyn9@gmail.com ³" << std::endl;
            std::cout << "   ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´" << std::endl;
            std::cout << "   ³ " << HOMESITE << "               http://magnetic-fox.ppa.pl/ ³" << std::endl;
            std::cout << "   ³ SoundCloud:                        https://soundcloud.com/magnetic-fox ³" << std::endl;
            std::cout << "   ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ" << std::endl << std::endl << std::endl << std::endl;
            std::cout << INFO_TEXT_29 << std::endl;
            std::cout << INFO_TEXT_30 << std::endl << std::endl;
            std::cout << " Magnetic-Fox." << std::endl;
        }
        else if(strcmp(argv[1],"/?")==0)
        {
            std::cout << PROGRAM_USAGE << std::endl << std::endl;
            std::cout << "   " << argv[0] << " <" << OPTION << "> <" << INPUT_FILE_ARGUMENT << "> <" << OUTPUT_FILE_ARGUMENT << "> <" << PASSWORD_ARGUMENT << ">" << std::endl << std::endl;
            std::cout << OPTIONS << std::endl << std::endl;
            std::cout << "   " << "encode (" << OR << " e) - " << ENCODING_FILE << std::endl;
            std::cout << "   " << "decode (" << OR << " d) - " << DECODING_FILE << std::endl << std::endl;
            std::cout << NO_OTHER_ARGUMENTS << std::endl << std::endl;
            std::cout << "   " << "/i - " << PROGRAM_INFORMATION << std::endl;
            std::cout << "   " << "/? - " << SHOWS_THIS_HELP << std::endl;
        }
        else
        {
            std::cout << " " << UNKNOWN_ARGUMENT << " \"" << argv[1] << "\"." << std::endl << " " << INFO_GET_HELP << " /?" << std::endl;
        }
    }
    else if(argc==3)
    {
        if(!((strcmp(argv[1],"ENCODE")==0) || (strcmp(argv[1],"E")==0) || (strcmp(argv[1],"DECODE")==0) || (strcmp(argv[1],"D")==0)))
        {
            std::cout << " " << UNKNOWN_ARGUMENT << " \"" << argv[1] << "\"." << std::endl;
        }
        std::cout << NO_OUTPUT_FILE << std::endl << WARNING_NO_PASSWORD << std::endl;
    }
    else if(argc==4)
    {
        unsigned char errorCode=0;
        char empty[1];
        empty[0]=0x00;
        if((strcmp(argv[1],"ENCODE")==0) || (strcmp(argv[1],"E")==0))
        {
            std::cout << WARNING_NO_PASSWORD << std::endl << std::endl;
            displayInfo(argv[2],argv[3],false,0,true);
            if(encode(argv[2],argv[3],empty,false,0,&errorCode))
            {
                std::cout << ENCODE_SUCCESS << std::endl;
            }
            else
            {
                displayError(errorCode);
                if(!(errorCode==ENCODING_STOPPED_CODE))
                {
                    std::cout << ENCODE_FAULT << std::endl;
                }
            }
        }
        else if((strcmp(argv[1],"DECODE")==0) || (strcmp(argv[1],"D")==0))
        {
            std::cout << WARNING_NO_PASSWORD << std::endl << std::endl;
            displayInfo(argv[2],argv[3],false,0,false);
            if(decode(argv[2],argv[3],empty,false,0,&errorCode))
            {
                std::cout << DECODE_SUCCESS << std::endl;
            }
            else
            {
                displayError(errorCode);
                if(!(errorCode==DECODING_STOPPED_CODE))
                {
                    std::cout << DECODE_FAULT << std::endl;
                }
            }
        }
        else
        {
            std::cout << " " << UNKNOWN_ARGUMENT << " \"" << argv[1] << "\"." << std::endl << WARNING_NO_PASSWORD << std::endl;
        }
    }
    else if(argc==5)
    {
        unsigned char errorCode=0;
        unsigned char passByte=0;
        for(unsigned int x=0; x<strlen(argv[4]); ++x)
        {
            passByte+=argv[4][x];
        }
        if((strcmp(argv[1],"ENCODE")==0) || (strcmp(argv[1],"E")==0))
        {
            displayInfo(argv[2],argv[3],true,strlen(argv[4]),true);
            if(encode(argv[2],argv[3],argv[4],true,passByte,&errorCode))
            {
                std::cout << ENCODE_SUCCESS << std::endl;
            }
            else
            {
                displayError(errorCode);
                if(!(errorCode==ENCODING_STOPPED_CODE))
                {
                    std::cout << ENCODE_FAULT << std::endl;
                }
            }
        }
        else if((strcmp(argv[1],"DECODE")==0) || (strcmp(argv[1],"D")==0))
        {
            displayInfo(argv[2],argv[3],true,strlen(argv[4]),false);
            if(decode(argv[2],argv[3],argv[4],true,passByte,&errorCode))
            {
                std::cout << DECODE_SUCCESS << std::endl;
            }
            else
            {
                displayError(errorCode);
                if(!(errorCode==DECODING_STOPPED_CODE))
                {
                    std::cout << DECODE_FAULT << std::endl;
                }
            }
        }
        else
        {
            std::cout << " " << UNKNOWN_ARGUMENT << " \"" << argv[1] << "\"." << std::endl;
        }
    }
    else if(argc>=6)
    {
        std::cout << TOO_MUCH_ARGUMENTS << std::endl;
    }
    else
    {
        std::cout << NO_ARGUMENTS << std::endl;
    }
    return 0;
}
