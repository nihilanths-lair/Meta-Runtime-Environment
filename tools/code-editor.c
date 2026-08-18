void CodeEditor()
{
    return;
}

#include <stdio.h>
#include <locale.h>
#include <conio.h>
int main(int argc, char *argv[])
{
    setlocale(0, "");
    printf(" Количество аргументов: %u", argc);
    for (int i = 0; i < argc; i++) printf("\n Аргумент %u: %s", i+1, argv[i]);
    CodeEditor();
    _getch();
    return 0;
}