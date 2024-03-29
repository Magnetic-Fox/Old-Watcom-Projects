#include <stdio.h>
#include <conio.h>

void sound(unsigned int hz)
{
    unsigned int count=1193280/hz;    
    __asm
    {
        mov al, 00b6h
        out 0043h, al
        mov ax, count
        out 0042h, al
        mov al, ah
        out 0042h, al
        mov al, 3
        out 0061h, al
    }
    return;
}

void nosound()
{
    __asm
    {
        mov al, 0
        out 0061h, al
    }
    return;
}

int main(void)
{
    sound(440);
    nosound();
    sound(440);
    delay(50);
    nosound();
    sound(555);
    delay(50);
    nosound();
    sound(660);
    delay(50);
    nosound();
    sound(880);
    delay(50);
    nosound();
    getch();
    return 0;
}
