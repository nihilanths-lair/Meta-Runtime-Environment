### MMIPDT: Modifiable Modular Infrastructure Providing Development Tools

**MMIPDT** is a high-performance, modifiable, and modular infrastructure designed to deliver robust development tools and an adaptable runtime environment. 

### Project Structure

Below is the architectural map of the infrastructure. Strikethrough items represent planned components or temporary drafts that are not active in the current initialization phase. 

### Licensing & Architecture Principles

* **Proprietary & Closed Source:** The core infrastructure components, binaries, and the main runtime routing engine are strictly proprietary.
* **Modifiable Integration:** MMIPDT provides isolated interfaces allowing developers to build and hook custom DSL (Domain-Specific Language) or GPL extensions without violating the core closed-source integrity.

<!--
MMIPDT: Модифицируемая модульная инфраструктура, предоставляющая инструменты разработки.
MMIPDT — это высокопроизводительная, модифицируемая и модульная инфраструктура, разработанная для предоставления надежных инструментов разработки и адаптируемой среды выполнения. 

Структура проекта
Ниже представлена ​​архитектурная схема инфраструктуры. Зачеркнутые элементы обозначают запланированные компоненты или временные проекты, которые не активны на текущем этапе инициализации. 

Принципы лицензирования и архитектуры
Собственная разработка с закрытым исходным кодом: основные компоненты инфраструктуры, исполняемые файлы и главный механизм маршрутизации во время выполнения являются строго конфиденциальными.
Модифицируемая интеграция: MMIPDT предоставляет изолированные интерфейсы, позволяющие разработчикам создавать и подключать пользовательские DSL (предметно-ориентированные языки программирования) или расширения GPL без нарушения основной целостности закрытого исходного кода.
-->

> **Status:** `🔒 Proprietary / Closed Source` <br>
> **Licensing:** `⚖️ All Rights Reserved`

### 🗺️ Карта навигации: общая структура (иерархия)

<pre>
 mmipdt/
 ├── <s>cli/</s>
 │   ├── <s>mmipdt-cli.exe</s>
 │   └── <s>mmipdt.exe</s>
 ├── <s>gui/</s>
 │   ├── <s>mmipdt-gui.exe</s>
 │   └── <s>mmipdt.exe</s>
 ├── tools/ (open-source)
 │   ├── code-editor.c
 │   └── code-editor.exe 🔒💽
 ├── <s>ui/</s>
 │   ├── <s>cli/</s>
 │   │   ├── <s>mmipdt-cli.exe</s>
 │   │   └── <s>mmipdt.exe</s>
 │   ├── <s>gui/</s>
 │   |   ├── <s>mmipdt-gui.exe</s>
 │   |   └── <s>mmipdt.exe</s>
 │   ├── <s>mmipdt-cli.exe</s>
 │   ├── <s>mmipdt-gui.exe</s>
 │   └── <s>mmipdt.exe</s>
 ├── LICENSE.md
 ├── README.md
 ├── mmipdt.cfg
 ├── <s>mmipdt.com</s>  <-- Консольная версия (срабатывает в CMD/PowerShell)
 └── <s>mmipdt.exe</s>  <-- Графическая версия (срабатывает при клике в проводнике)
</pre>

### 🔒 Статус исходного кода и лицензирование

* **Ядро и инструментарий:** Платформа имеет **закрытый исходный код** (Proprietary / Closed Source). Исходный код модулей компиляции (`conv`) и runtime вычислительной машины не публикуется.
* **Дистрибутив:** В данном репозитории распространяются исключительно готовые к запуску скомпилированные бинарные файлы, системные компоненты и runtime-пакеты.
* **Разработка расширений:** Сторонние разработчики имеют право создавать и распространять исключительно **зависимые языковые пакеты (модули расширения мета-синтаксиса)**. Любой созданный на платформе DSL/GPL-язык не может функционировать как независимая отдельная программа (stand-alone компилятор) и должен распространяться только в виде бинарного пакета расширения, исполняемого строго внутри платформы — MMIPDT.