# uni-typing

An **automatic typing tool** for Windows that reads a text file and simulates keyboard input to type its content automatically. It supports Unicode characters and allows customizable initial and per-character delays.

---

## Features

* Read text files (UTF-8) and automatically type their content.
* Supports Unicode characters, including non-Latin scripts.
* Configurable initial delay before typing starts.
* Configurable delay between each character.
* Shows real-time progress in the console.

---

## Requirements

* Windows OS
* C++17 or later (for safe `wstring::data()` writing)
* Visual Studio or any compiler that supports Windows API (`Windows.h`)

---

## Usage

### Build

Compile the project with your preferred C++ compiler. For example, using Visual Studio:

1. Create a new Console Application project.
2. Add `main.cpp`.
3. Set C++ standard to C++17 or later.
4. Build the project.

---

### Run

```bash
uni-typing.exe [filePath] [initialDelay(ms)] [charDelay(ms)]
```

* **filePath** *(optional)*: Path to the text file to type. Default is `file.txt`.
* **initialDelay** *(optional)*: Delay in milliseconds before typing starts. Default is `3000` (3 seconds).
* **charDelay** *(optional)*: Delay in milliseconds between each character. Default is `0`.

**Example:**

```bash
uni-typing.exe "example.txt" 5000 50
```

* Starts typing the content of `example.txt` after 5 seconds, with a 50ms delay between each character.

---

## Notes

* Ensure the text file is encoded in **UTF-8**.
* The tool may not correctly type **high Unicode characters** (like certain emojis) on older Windows versions.
* Be careful when running this tool, as it will send keystrokes to the **currently active window**.
* Make sure the target application window is focused and ready to receive input.

---

## License

This project is licensed under the [![license](https://img.shields.io/github/license/rbxluau/uni-typing)](https://github.com/rbxluau/uni-typing/blob/main/LICENSE).

---
