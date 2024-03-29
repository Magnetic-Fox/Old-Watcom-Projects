#include "foxcodeinfo.hpp"

void displayError(unsigned char which)
{
    switch(which)
    {
        case EMPTY_FILE:
        {
            std::cout << INPUT_FILE_EMPTY << std::endl;
            return;
        }
        case ENCODING_STOPPED_CODE:
        {
            std::cout << ENCODING_STOPPED << std::endl;
            return;
        }
        case READ_ERROR:
        {
            std::cout << INPUT_FILE_READ_ERROR << std::endl;
            return;
        }
        case WRITE_ERROR:
        {
            std::cout << OUTPUT_FILE_WRITE_ERROR << std::endl;
            return;
        }
        case OUTPUT_FILE_OPEN_ERROR_CODE:
        {
            std::cout << OUTPUT_FILE_OPEN_ERROR << std::endl;
            return;
        }
        case INPUT_FILE_ACCESS_ERROR:
        {
            std::cout << INPUT_FILE_GET_INFO_ERROR << std::endl;
            return;
        }
        case INPUT_FILE_OPEN_ERROR_CODE:
        {
            std::cout << INPUT_FILE_OPEN_ERROR << std::endl;
            return;
        }
        case DECODING_STOPPED_CODE:
        {
            std::cout << DECODING_STOPPED << std::endl;
            return;
        }
    }
    return;
}

void displayInfo(char* inputFile, char* outputFile, bool withPassword, unsigned int passwordSize, bool mode)
{
    std::cout << IN_PROGRESS;
    if(mode)
    {
        std::cout << ENCODING;
    }
    else
    {
        std::cout << DECODING;
    }
    std::cout << "..." << std::endl << std::endl;
    std::cout << INPUT_FILE << inputFile << std::endl;
    std::cout << OUTPUT_FILE << outputFile << std::endl;
    if(withPassword)
    {
        std::cout << PASSWORD_STRING;
        for(unsigned int x=0; x<passwordSize; ++x)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << BREAK_INFO << std::endl << std::endl;
    return;
}
