#include <iostream>
#include <Windows.h>

BOOL mouseMacro(int opt) {
    ::ShowWindow(::GetConsoleWindow(), SW_HIDE);
    
    while (true) {
        if (GetAsyncKeyState(VK_TAB) & 0x8000) {
            break;
        }
        
        if ((GetAsyncKeyState(VK_LBUTTON) & 0x8000) && 
            (GetAsyncKeyState(VK_RBUTTON) & 0x8000)) {
            
            INPUT input = {0};
            input.type = INPUT_MOUSE;
            input.mi.dy = opt;
            input.mi.dwFlags = MOUSEEVENTF_MOVE;
            SendInput(1, &input, sizeof(INPUT));
            
            Sleep(25);
        }
        
        Sleep(1);
    }
    return true;
}

int main()    {
        
    do {
        ::ShowWindow(::GetConsoleWindow(), SW_SHOW);
        int option = 0; 

        std::cout << "----- [Recoil Controller] ----- \n\n";

        std::cout << "Reccomeneded options:\n";
        std::cout << "1 - 5 Low\n";
        std::cout << "6 - 10 Medium\n"; 
        std::cout << "11 - 20 High\n\n";

        std::cout << "[i] Press 'TAB' to stop the macro\n";
        std::cout << "--->";    
        std::cin >> option; 

        if (std::cin.fail()) {
            std::cout << "\n[!] Wrong input";
            return -1;
        }
        else {
            mouseMacro(option);
        }
        std::system("cls");

} while (true);

    return 0;
}
