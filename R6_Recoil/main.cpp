#include <iostream>
#include <Windows.h>

BOOL mouseMacro(int opt) {

    POINT pos;

    if (opt == 1) {

        ::ShowWindow(::GetConsoleWindow(), SW_HIDE);

        while (TRUE) {

            SHORT tabKeyState = GetAsyncKeyState(VK_TAB);                  
            if ((1 << 15) & tabKeyState)
            {
                break;
            }
                
            if ((GetKeyState(VK_LBUTTON) & 0x80) && (GetKeyState(VK_RBUTTON) & 0x80) != 0)
            {
                GetCursorPos(&pos);
                SetCursorPos(pos.x, pos.y + 10);
                Sleep(25);
            }
            
        }
    }

    if (opt == 2) {

        ::ShowWindow(::GetConsoleWindow(), SW_HIDE);

        while (TRUE) {

            SHORT tabKeyState = GetAsyncKeyState(VK_TAB);
            if ((1 << 15) & tabKeyState)
            {
                break;
            }

            if ((GetKeyState(VK_LBUTTON) & 0x80) && (GetKeyState(VK_RBUTTON) & 0x80) != 0)
            {
                GetCursorPos(&pos);
                SetCursorPos(pos.x, pos.y + 12);
                Sleep(25);
            }

        }
    }

    if (opt == 3) {

        ::ShowWindow(::GetConsoleWindow(), SW_HIDE);

        while (TRUE) {

            SHORT tabKeyState = GetAsyncKeyState(VK_TAB);  
            if ((1 << 15) & tabKeyState)
            {
                break;
            }

            if ((GetKeyState(VK_LBUTTON) & 0x80) && (GetKeyState(VK_RBUTTON) & 0x80) != 0)
            {
                GetCursorPos(&pos);
                SetCursorPos(pos.x, pos.y + 15);
                Sleep(25);
            }
                
            }
        }

        return FALSE;
    }

    int main()
    {
        do {
            int option = 0; 

            std::cout << "----- [Recoil Controller] ----- \n\n";

            std::cout << "Options:\n";
            std::cout << "1. Low\n";
            std::cout << "2. Medium\n"; 
            std::cout << "3. High\n\n";

            std::cout << "[i] Press 'TAB' to stop the macro\n";
            std::cout << "--->";    
            std::cin >> option; 

            if (option == 1) {
                mouseMacro(1);
            }
            else if (option == 2) {
                mouseMacro(2);
            }
            else if (option == 3) {
                mouseMacro(3);
            }
            else {
                std::cout << "\n[!] Wrong input";
                return -1;
            }
            std::system("cls");

    } while (TRUE);

    return 0;
}