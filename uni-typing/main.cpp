#include <Windows.h>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

static wstring ReadFileAsWideString(const string& filePath) {
    ifstream file(filePath, ios::binary);
    string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    int buffer = MultiByteToWideChar(CP_UTF8, 0, content.c_str(), -1, nullptr, 0);
    wstring wcontent(buffer, L'\0');
    MultiByteToWideChar(CP_UTF8, 0, content.c_str(), -1, wcontent.data(), buffer);
    return wcontent;
}

int main(int argc, char* argv[]) {
    string filePath = argc > 1 ? argv[1] : "file.txt";
    int initialDelay = argc > 2 ? stoi(argv[2]) : 3000;
    int charDelay = argc > 3 ? stoi(argv[3]) : 0;
    wstring wide = ReadFileAsWideString(filePath);
    size_t len = wide.size();
    size_t sent = 1;
    INPUT inputs[2] = {
        {
            .type = INPUT_KEYBOARD,
            .ki = {
                .dwFlags = KEYEVENTF_UNICODE
            }
        },
        {
            .type = INPUT_KEYBOARD,
            .ki = {
                .dwFlags = KEYEVENTF_UNICODE | KEYEVENTF_KEYUP
            }
        }
    };
    Sleep(initialDelay);
    for (wchar_t wc : wide) {
        inputs[0].ki.wScan = wc;
        inputs[1].ki.wScan = wc;
        SendInput(2, inputs, sizeof(INPUT));
        cout << "\r" << sent++ << "/" << len;
        Sleep(charDelay);
    }
    return 0;
}