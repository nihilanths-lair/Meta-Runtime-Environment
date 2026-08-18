#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <stdlib.h>

void CodeEditor();

int main(int argc, char *argv[])
{
    setlocale(0, "");
    printf(" Количество аргументов: %u\n", argc);
    for (int i = 0; i < argc; i++) printf(" Аргумент %u: %s\n", i+1, argv[i]);
    if (argc == 2)
    {
        FILE *file = fopen(argv[1], "rb");
        if (!file) return 0;
        printf(" Файл: %s открыт на чтение", argv[1]);

        fseek(file, 0, SEEK_END);
        long file_size = ftell(file);
        printf("\n Размер файла (в байтах): %lu", file_size);
        fseek(file, 0, SEEK_SET); // делаем сразу, чтобы потом не забыть ..

        char *file_text = malloc(file_size);
        printf("\n %s", file_text);
        printf("\n ");
        printf("Offset(h) |");
        for (unsigned char i = 0; i <= 15; i++) printf(" %02X", i);
        printf(" | ");
        printf("Отображение в файле\n");
        for (long j = 0; j < 2; j++)
        {
            printf("\n  %08X |", 0);
            for (long i = 0; i <= 15/*file_size*/; i++) printf(" %02X", file_text[i]&0xFF);
            printf(" | ");
            for (long i = 0; i <= 15/*file_size*/; i++) printf("%c", file_text[i]);
        }
        free(file_text); // делаем сразу, чтобы потом не забыть ..
        fclose(file);
    }
    CodeEditor();
    _getch();
    return 0;
}

void CodeEditor()
{
    return;
}