#include "foxcodealgorithm.hpp"

bool encode(char* inputFile, char* outputFile, char* password, bool usePassword, unsigned char startByteAddition, unsigned char* errorCode)
{
    std::fstream input, output;
    bool error=false;
    unsigned char buffer[512];
    struct stat results;
    unsigned int readcount=0, y=0, passwordLength=strlen(password);
    unsigned char buf=0, buf2=0, buf3=0, buf4=0;
    bool first=true, plot=false;
    input.open(inputFile, std::ios::in | std::ios::binary);
    if(input.is_open())
    {
        if(stat(inputFile,&results)==0)
        {
            if(results.st_size==0)
            {
                *errorCode=EMPTY_FILE;
                error=true;
            }
            else
            {
                output.open(outputFile, std::ios::out | std::ios::binary);
                if(output.is_open())
                {
                    while(!input.eof())
                    {
                        if(kbhit())
                        {
                            if(getch()==0x1B)
                            {
                                *errorCode=ENCODING_STOPPED_CODE;
                                error=true;
                                input.close();
                                output.close();
                                break;
                            }
                        }
                        input.read(buffer,512);
                        readcount=input.gcount();
                        if((!input) && (readcount==0))
                        {
                            *errorCode=READ_ERROR;
                            error=true;
                            break;
                        }
                        for(unsigned int x=0; x<readcount; ++x)
                        {
                            buf=buffer[x];
                            if(first)
                            {
                                buf4=buf;
                                buf4+=startByteAddition;
                                if(usePassword)
                                {
                                    buf4+=startByteAddition*password[y];
                                    y=(y+1)%passwordLength;
                                }
                                buf2=buf;
                                first=false;
                            }
                            else
                            {
                                buf3=buf-buf2;
                                if(plot)
                                {
                                    buf4=buf3-startByteAddition;
                                    if(usePassword)
                                    {
                                        buf4-=startByteAddition*password[y];
                                        y=(y+1)%passwordLength;
                                    }
                                    plot=false;
                                }
                                else
                                {
                                    buf4=buf3+startByteAddition;
                                    if(usePassword)
                                    {
                                        buf4=buf3+startByteAddition;
                                        if(usePassword)
                                        {
                                            buf4+=startByteAddition*password[y];
                                            y=(y+1)%passwordLength;
                                        }
                                        plot=true;
                                    }
                                }
                                buf2=buf;
                            }
                            buffer[x]=buf4;
                        }
                        output.write(buffer,readcount);
                        if(!output)
                        {
                            *errorCode=WRITE_ERROR;
                            error=true;
                            break;
                        }
                    }
                    output.close();
                }
                else
                {   
                    *errorCode=OUTPUT_FILE_OPEN_ERROR_CODE;
                    error=true;
                }
            } 
        }
        else
        {
            *errorCode=INPUT_FILE_ACCESS_ERROR;
            error=true;
        }
        input.close();
    }
    else
    {
        *errorCode=INPUT_FILE_OPEN_ERROR_CODE;
        error=true;
    }
    return !error;
}

bool decode(char* inputFile, char* outputFile, char* password, bool usePassword, unsigned char startByteAddition, unsigned char* errorCode)
{
    std::fstream input, output;
    bool error=false;
    unsigned char buffer[512];
    struct stat results;
    unsigned int readcount=0, y=0, passwordLength=strlen(password);
    unsigned char buf=0, buf2=0;
    bool first=true, plot=false;
    input.open(inputFile, std::ios::in | std::ios::binary);
    if(input.is_open())
    {
        if(stat(inputFile,&results)==0)
        {
            if(results.st_size==0)
            {
                *errorCode=EMPTY_FILE;
                error=true;
            }
            else
            {
                output.open(outputFile, std::ios::out | std::ios::binary);
                if(output.is_open())
                {
                    while(!input.eof())
                    {
                        if(kbhit())
                        {
                            if(getch()==0x1B)
                            {
                                *errorCode=DECODING_STOPPED_CODE;
                                error=true;
                                input.close();
                                output.close();
                                break;
                            }
                        }
                        input.read(buffer,512);
                        readcount=input.gcount();
                        if((!input) && (readcount==0))
                        {
                            *errorCode=READ_ERROR;
                            error=true;
                            break;
                        }
                        for(unsigned int x=0; x<readcount; ++x)
                        {
                            buf=buffer[x];
                            if(first)
                            {
                                buf-=startByteAddition;
                                if(usePassword)
                                {
                                    buf-=startByteAddition*password[y];
                                    y=(y+1)%passwordLength;
                                }
                                buf2=buf;
                                first=false;
                            }
                            else
                            {
                                if(plot)
                                {
                                    buf+=startByteAddition;
                                    if(usePassword)
                                    {
                                        buf+=startByteAddition*password[y];
                                        y=(y+1)%passwordLength;
                                    }
                                    plot=false;
                                }
                                else
                                {
                                    buf-=startByteAddition;
                                    if(usePassword)
                                    {
                                        buf-=startByteAddition*password[y];
                                        y=(y+1)%passwordLength;
                                    }
                                    plot=true;
                                }
                                buf2+=buf;
                            }
                            buffer[x]=buf2;
                        }
                        output.write(buffer,readcount);
                        if(!output)
                        {
                            *errorCode=WRITE_ERROR;
                            error=true;
                            break;
                        }
                    }
                    output.close();
                }
                else
                {
                    *errorCode=OUTPUT_FILE_OPEN_ERROR_CODE;
                    error=true;
                }
            } 
        }
        else
        {
            *errorCode=INPUT_FILE_ACCESS_ERROR;
            error=true;
        }
        input.close();
    }
    else
    {
        *errorCode=INPUT_FILE_OPEN_ERROR_CODE;
        error=true;
    }
    return !error;
}
