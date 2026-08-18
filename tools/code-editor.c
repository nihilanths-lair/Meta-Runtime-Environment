#include <stdio.h>
#include <locale.h>
#include <conio.h>

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
        printf(" Размер файла: %lu", file_size);
        fseek(file, 0, SEEK_SET); // делаем сразу, чтобы потом не забыть ..

        char *file_text = malloc(file_size);
        // ... //
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