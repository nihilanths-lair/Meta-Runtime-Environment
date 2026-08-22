## Meta Runtime Environment (MRE)
<h4>
 Другие названия:<br>
 Runtime & Toolchain Platform (RTP) — Платформа сред исполнения и инструментария разработки.<br>
 Execution & Translation Platform (ETP) — Платформа трансляции и исполнения.<br>
 Execution & Translation Framework (ETF) — Фреймворк трансляции и исполнения.<br>
 Computational Environment Generator (CEG) — Генератор вычислительных сред.<br>
 Managed Runtime & Toolchain Architecture (MRTA) — Архитектура управляемых сред исполнения и инструментариев разработки.
</h4>

> **Status:** `🔒 Proprietary / Closed Source` <br>
> **Licensing:** `⚖️ All Rights Reserved`

### 🗺️ Карта навигации: общая структура (иерархия)

<pre>
<!-- ```text -->
meta-platform/
├── README.md
├── tools/ (open-source)
│   ├── code-editor.c
│   └── code-editor.exe 🔒💽
├── meta-platform.cfg
├── meta-platform.exe (cli) 🔒💽
└── <s>meta-platform.exe (gui)</s>
<!-- ``` -->
</pre>

### 🔒 Статус исходного кода и лицензирование

* **Ядро и инструментарий:** Платформа имеет **закрытый исходный код** (Proprietary / Closed Source). Исходный код модулей компиляции (`conv`) и runtime вычислительной машины не публикуется.
* **Дистрибутив:** В данном репозитории распространяются исключительно готовые к запуску скомпилированные бинарные файлы, системные компоненты и runtime-пакеты.
* **Разработка расширений:** Сторонние разработчики имеют право создавать и распространять исключительно **зависимые языковые пакеты (модули расширения мета-синтаксиса)**. Любой созданный на платформе DSL/GPL-язык не может функционировать как независимая отдельная программа (stand-alone компилятор) и должен распространяться только в виде бинарного пакета расширения, исполняемого строго внутри Meta Runtime Environment (MRE).