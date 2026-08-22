^Meta-platform (mp.exe/mptf.exe) / Meta-environment (me.exe)

### MMIPDT: Modifiable Modular Infrastructure Providing Development Tools

**MMIPDT** is a multi-layered, high-performance ecosystem designed as a flexible foundation for compiler construction, toolchain engineering, and application execution. 

The infrastructure is strategically architected into three distinct operational layers (or "camps") to balance core system modification with out-of-the-box developer utility. 

### 🗺️ Ecosystem Roadmap & Architecture Layers

### 🛡️ Layer 1: Core Engine (The MMICCE Camp)

* **Definition:** Modifiable Modular Infrastructure for Compiler Construction and Execution.
* **Target Audience:** Core system architects and compiler engineers.
* **Purpose:** Handles low-level bytecode compilation, optimization passes, memory management, and virtual machine execution. This is the deepest layer where the core logic of the computational platform is defined and modified.

### 🛠️ Layer 2: Developer Suite (The MMIPDT Camp)

* **Definition:** Modifiable Modular Infrastructure Providing Development Tools.
* **Target Audience:** Application developers and tool creators.
* **Purpose:** Acts as an SDK built on top of the Core Engine. It provides high-level tools like the unified launcher, code-editor.exe, linters, and resource packagers. Developers work here to build end-user software without needing to touch compiler internals.

### 🕹️ Layer 3: Runtime Environment (The MMIRE Camp)

* **Definition:** Modifiable Modular Infrastructure Runtime Environment.
* **Target Audience:** End-users and players.
* **Purpose:** A lightweight, stripped-down distribution containing only the core execution engine and configuration routing. It contains zero development tools and is optimized solely for stable, maximum-performance execution of compiled applications or games.

### 🗂️ Project Structure Blueprint

Below is the integrated architectural map. Strikethrough items represent components that are planned for the upcoming implementation phases. 

### 🔐 Licensing Principles

* **Proprietary Core:** The underlying infrastructure engines, binaries, and routing mechanisms remain strictly closed-source and proprietary.
* **Isolated Modifiability:** The infrastructure exposes safe abstraction boundaries, allowing developers to create custom DSL (Domain-Specific Language) or GPL extensions without exposing the proprietary core.

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
 ├── <s>tools/ (open-source)</s>
 │   ├── <s>code-editor.c</s>
 │   └── <s>code-editor.exe</s>
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
 ├── <s>mmipdt.cfg</s>
 ├── <s>mmipdt.com</s>  <-- Консольная версия (срабатывает в CMD/PowerShell)
 ├── mmipdt.exe (cli)
 └── <s>mmipdt.exe</s>  <-- Графическая версия (срабатывает при клике в проводнике)
</pre>

### 🔒 Статус исходного кода и лицензирование

* **Ядро и инструментарий:** Платформа имеет **закрытый исходный код** (Proprietary / Closed Source). Исходный код модулей платформы — MMIPDT не публикуется.
* **Дистрибутив:** В данном репозитории распространяются исключительно готовые к запуску скомпилированные бинарные файлы, системные компоненты и runtime-пакеты.
* **Разработка расширений:** Сторонние разработчики имеют право создавать и распространять исключительно **зависимые языковые пакеты (модули расширения мета-языка)**. Любой созданный на платформе DSL/GPL-язык не может функционировать как независимая отдельная программа (stand-alone компилятор) и должен распространяться только в виде бинарного пакета расширения, исполняемого строго внутри платформы — MMIPDT.