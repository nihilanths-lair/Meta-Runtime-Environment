## Meta Runtime Environment (MRE)

### MMIPD: Modifiable Modular Infrastructure Providing Development Tools

**MMIPD** is a high-performance, modifiable, and modular infrastructure designed to deliver robust development tools and an adaptable runtime environment. 

### Project Structure

Below is the architectural map of the infrastructure. Strikethrough items represent planned components or temporary drafts that are not active in the current initialization phase. 

### Licensing & Architecture Principles

* **Proprietary & Closed Source:** The core infrastructure components, binaries, and the main runtime routing engine are strictly proprietary.
* **Modifiable Integration:** MMIPD provides isolated interfaces allowing developers to build and hook custom DSL (Domain-Specific Language) or GPL extensions without violating the core closed-source integrity.

> **Status:** `🔒 Proprietary / Closed Source` <br>
> **Licensing:** `⚖️ All Rights Reserved`

### 🗺️ Карта навигации: общая структура (иерархия)

<pre>
 mre/
 ├── <s>bin/</s>             <-- Скрытая от пользователя папка с ядрами
 │   ├── <s>mre-cli.exe</s>  <-- Настоящий CLI-движок
 │   └── <s>mre-gui.exe</s>  <-- Настоящий GUI-интерфейс
 ├── <s>cli/</s>
 │   ├── <s>mre-cli.exe</s>
 │   └── <s>mre.exe</s>
 ├── <s>gui/</s>
 │   ├── <s>mre-gui.exe</s>
 │   └── <s>mre.exe</s>
 ├── tools/ (open-source)
 │   ├── code-editor.c
 │   └── code-editor.exe 🔒💽
 ├── <s>ui/</s>
 │   ├── <s>cli/</s>
 │   │   ├── <s>mre-cli.exe</s>
 │   │   └── <s>mre.exe</s>
 │   ├── <s>gui/</s>
 │   |   ├── <s>mre-gui.exe</s>
 │   |   └── <s>mre.exe</s>
 │   ├── <s>mre-cli.exe</s>
 │   ├── <s>mre-gui.exe</s>
 │   └── <s>mre.exe</s>
 ├── LICENSE.md
 ├── README.md
 ├── mre.cfg
 ├── <s>mre.com</s>  <-- Консольная версия (срабатывает в CMD/PowerShell)
 └── <s>mre.exe</s>  <-- Графическая версия (срабатывает при клике в проводнике)
</pre>

### 🔒 Статус исходного кода и лицензирование

* **Ядро и инструментарий:** Платформа имеет **закрытый исходный код** (Proprietary / Closed Source). Исходный код модулей компиляции (`conv`) и runtime вычислительной машины не публикуется.
* **Дистрибутив:** В данном репозитории распространяются исключительно готовые к запуску скомпилированные бинарные файлы, системные компоненты и runtime-пакеты.
* **Разработка расширений:** Сторонние разработчики имеют право создавать и распространять исключительно **зависимые языковые пакеты (модули расширения мета-синтаксиса)**. Любой созданный на платформе DSL/GPL-язык не может функционировать как независимая отдельная программа (stand-alone компилятор) и должен распространяться только в виде бинарного пакета расширения, исполняемого строго внутри Meta Runtime Environment (MRE).