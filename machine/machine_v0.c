#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define macro__fde_1 \
do \
{\
    printf(" run: macro__fde_1;\n");\
\
    /* СЛОЙ 0: ТАБЛИЦА ПЕРЕХОДОВ (Direct Threaded Code) */\
    /* Наш золотой Тьюринг-полный минимум + параллельные файловые сервисы хоста */\
    static const void * const _fde_1[0x100] =\
    {\
        [0] = &&_0x00, /* M2M Копирование (MOV) */\
        [1] = &&_0x01, /* Логическое сравнение (МЕНЬШЕ) */\
        /* От 2 до 6 резервируем под остальные операции сравнения и арифметику */\
        [2 ... 6] = &&_0x02__0x06,\
        [7] = &&_0x07, /* Условный переход M2M (JNZ) */\
        \
        /* Заглушка для свободных GP/DS опкодов */\
        [8 ... 251] = &&_0x08__0xFB,\
        \
        /* Служебные I/O сервисы C-хоста (Файловая система) */\
        [252] = &&_0xFC, /* Запись байта в файл */\
        [253] = &&_0xFD, /* Открытие файла */\
        [254] = &&_0xFE, /* Чтение байта из файла */\
        [255] = &&_0xFF  /* Закрытие файла */\
    };\
\
    /* СЛОЙ 1: ИЗОЛИРОВАННАЯ ПАМЯТЬ M2M (64 КБ / Помещается в L1-кэш) */\
    unsigned char m2m[0x10000];\
    \
    /* Наш ультра-быстрый Program Counter в регистре процессора */\
    register unsigned char *_fm = m2m;\
\
    /* Очищаем всю память ленты перед стартом, забивая её стоп-кодами */\
    for (unsigned int i = 0; i < 0x10000; i++) m2m[i] = 0x08;\
\
    /* --- ВЫДЕЛЯЕМ ВИРТУАЛЬНЫЕ АДРЕСА В ПАМЯТИ m2m --- */\
    unsigned short addr_path_in  = 0x1000; /* Где лежит путь "test.asm" */\
    unsigned short addr_mode_in  = 0x1020; /* Режим "rb" */\
    unsigned short addr_desc_in  = 0x1030; /* Дескриптор файла чтения (8 байт) */\
    \
    unsigned short addr_path_out = 0x1040; /* Где лежит путь "output.bin" */\
    unsigned short addr_mode_out = 0x1060; /* Режим "wb" */\
    unsigned short addr_desc_out = 0x1070; /* Дескриптор файла записи (8 байт) */\
    \
    unsigned short addr_char     = 0x1080; /* Буферная ячейка для передачи байта */\
\
    /* --- ЗАПИСЫВАЕМ СТРОКИ С ДАННЫМИ В КОНЕЦ ЛЕНТЫ --- */\
    strcpy((char*)&m2m[addr_path_in],  "test.asm");\
    strcpy((char*)&m2m[addr_mode_in],  "rb");\
    strcpy((char*)&m2m[addr_path_out], "output.bin");\
    strcpy((char*)&m2m[addr_mode_out], "wb");\
\
    /* --- СКВОЗНОЙ ИНТЕГРАЦИОННЫЙ ТЕСТ ДЛЯ MVP --- */\
    /* Собираем бинарную прошивку из инструкций переменной длины вручную */\
    unsigned short pc = 0;\
\
    /* 1. Открываем test.asm на чтение (Длина: 7 байт) */\
    m2m[pc] = 0xFD;\
    *(unsigned short*)(m2m+pc+1) = addr_path_in;\
    *(unsigned short*)(m2m+pc+3) = addr_mode_in;\
    *(unsigned short*)(m2m+pc+5) = addr_desc_in;\
    pc += 7;\
\
    /* 2. Читаем один байт из файла в буфер addr_char (Длина: 5 байт) */\
    m2m[pc] = 0xFE;\
    *(unsigned short*)(m2m+pc+1) = addr_desc_in;\
    *(unsigned short*)(m2m+pc+3) = addr_char;\
    pc += 5;\
\
    /* 3. Открываем output.bin на запись (Длина: 7 байт) */\
    m2m[pc] = 0xFD;\
    *(unsigned short*)(m2m+pc+1) = addr_path_out;\
    *(unsigned short*)(m2m+pc+3) = addr_mode_out;\
    *(unsigned short*)(m2m+pc+5) = addr_desc_out;\
    pc += 7;\
\
    /* 4. Записываем байт из буфера в output.bin (Длина: 5 байт) */\
    m2m[pc] = 0xFC;\
    *(unsigned short*)(m2m+pc+1) = addr_desc_out;\
    *(unsigned short*)(m2m+pc+3) = addr_char;\
    pc += 5;\
\
    /* 5. Закрываем первый файл (Длина: 3 байта) */\
    m2m[pc] = 0xFF;\
    *(unsigned short*)(m2m+pc+1) = addr_desc_in;\
    pc += 3;\
\
    /* 6. Закрываем второй файл (Длина: 3 байта) */\
    m2m[pc] = 0xFF;\
    *(unsigned short*)(m2m +pc+1) = addr_desc_out;\
    pc += 3;\
\
    /* 7. Финальный Стоп-код 0x08 (Попадёт в ветку _0x08__0xFB) */\
    m2m[pc] = 0x08;\
\
    /* СТАРТ ДИСПЕТЧЕРА И ПЕРВЫЙ FETCH */\
    goto *_fde_1[_fm[0]];\
\
    /* ======================================================= */\
    /*                  ОБРАБОТЧИКИ ОПКОДОВ                     */\
    /* ======================================================= */\
\
_0x00: /* Копирование M2M (MOV) | Длина: 5 байт */\
{\
    printf(" _0x00 | MOV\n");\
    m2m[((unsigned short*)_fm)[1]] = m2m[((unsigned short*)_fm)[2]];\
    _fm += 5;\
    goto *_fde_1[_fm[0]];\
}\
\
_0x01: /* Логическое сравнение (МЕНЬШЕ) | Длина: 7 байт */\
{\
    printf(" _0x01 | CMP_LT\n");\
    m2m[((unsigned short*)_fm)[5]] = (m2m[((unsigned short*)_fm)[1]] < m2m[((unsigned short*)_fm)[3]]);\
    _fm += 7;\
    goto *_fde_1[_fm[0]];\
}\
\
_0x02__0x06:\
{\
    printf(" _0x02__0x06 | Заглушка арифметики\n");\
    _fm++;\
    goto *_fde_1[_fm[0]];\
}\
\
_0x07: /* Условный переход M2M (JNZ) | Длина: Динамическая подмена PC */\
{\
    printf(" _0x07 | JNZ\n");\
    if (m2m[((unsigned short*)_fm)[1]]) _fm = &m2m[((unsigned short*)_fm)[3]];\
    else _fm = &m2m[((unsigned short*)_fm)[5]];\
    goto *_fde_1[_fm[0]];\
}\
\
_0x08__0xFB: /* Контролируемый выход по стоп-коду */\
{\
    printf(" _0x08__0xFB | Остановить выполнение\n");\
    goto _macro__fde_1_end;\
}\
\
_0xFC: /* Запись байта в файл | Длина: 5 байт */\
{\
    printf(" _0xFC | Запись байта в файл\n");\
    FILE *fp = *(FILE**)&m2m[((unsigned short*)_fm)[1]];\
    unsigned char byte = m2m[((unsigned short*)_fm)[3]];\
    if (fp) fputc(byte, fp);\
    _fm += 5;\
    goto *_fde_1[_fm[0]];\
}\
\
_0xFD: /* Открытие файла | Длина: 7 байт */\
{\
    printf(" _0xFD | Открытие файла\n");\
    unsigned short path_addr = ((unsigned short*)_fm)[1];\
    unsigned short mode_addr = ((unsigned short*)_fm)[3];\
    unsigned short desc_addr = ((unsigned short*)_fm)[5];\
    FILE *fp = fopen((char*)&m2m[path_addr], (char*)&m2m[mode_addr]);\
    *(FILE**)&m2m[desc_addr] = fp;\
    _fm += 7;\
    goto *_fde_1[_fm[0]];\
}\
\
_0xFE: /* Чтение байта из файла | Длина: 5 байт */\
{\
    printf(" _0xFE | Чтение байта из файла\n");\
    FILE *fp = *(FILE**)&m2m[((unsigned short*)_fm)[1]];\
    unsigned short target_addr = ((unsigned short*)_fm)[3];\
    if (fp) m2m[target_addr] = (unsigned char)fgetc(fp);\
    _fm += 5;\
    goto *_fde_1[_fm[0]];\
}\
\
_0xFF: /* Закрытие файла | Длина: 3 байта */\
{\
    printf(" _0xFF | Закрытие файла\n");\
    FILE *fp = *(FILE**)&m2m[((unsigned short*)_fm)[1]];\
    if (fp) fclose(fp);\
    _fm += 3;\
    goto *_fde_1[_fm[0]];\
}\
\
_macro__fde_1_end:\
    printf(" end: macro__fde_1;\n");\
\
} while(0)

#include <locale.h>
int main()
{
    setlocale(0, "");
    FILE *f = fopen("test.asm", "w"); /* Создадим тестовый файл, чтобы нашему MVP было что читать */
    if (f)
    {
        fputs("M", f); /* Запишем букву 'M' — первый символ нашей будущей Мета-Платформы */
        fclose(f);
    }
    macro__fde_1; /* Запускаем нашу восстановленную виртуальную машину */
    return 0;
}