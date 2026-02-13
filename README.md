# uni-typing

`uni-typing` is a small Windows console tool that types the contents of a UTF-8 text file into the currently focused window by sending Unicode keyboard input events.

## Features

- Reads text from a file (default: `file.txt`).
- Converts UTF-8 content to wide characters.
- Sends each character with `SendInput` and `KEYEVENTF_UNICODE`.
- Supports configurable startup delay and per-character delay.

## Requirements

- Windows 10/11
- Visual Studio 2022 (or Build Tools) with C++ workload
- Windows SDK

## Build

### Visual Studio

1. Open `uni-typing.sln` in Visual Studio.
2. Select a configuration (for example `Release | x64`).
3. Build the solution.

### Command line (MSBuild)

```powershell
msbuild .\uni-typing.sln /p:Configuration=Release /p:Platform=x64
```

The generated executable will be in:

```text
uni-typing\x64\Release\uni-typing.exe
```

## Usage

```text
uni-typing.exe [filePath] [initialDelayMs] [charDelayMs]
```

Arguments:

- `filePath` (optional): path to a UTF-8 text file. Default: `file.txt`
- `initialDelayMs` (optional): wait time before typing starts. Default: `3000`
- `charDelayMs` (optional): delay between characters. Default: `0`

Example:

```powershell
uni-typing.exe .\demo.txt 5000 20
```

This waits 5 seconds, then types `demo.txt` into whichever window is active, with a 20 ms delay per character.

## Notes

- Make sure the target input box or editor is focused before the initial delay ends.
- The tool sends input to the active window globally; use with care.
- Save source text files as UTF-8 for correct Unicode output.

## License

This project is licensed under the terms in `LICENSE.txt`.
