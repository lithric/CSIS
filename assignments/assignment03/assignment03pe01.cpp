/******************************************************************************/
/* Programmer: Elion Oliver                                                   */
/*                                                                            */
/* Program assignment03pe01: Iterative Fibonacci                              */
/*                                                                            */
/* Approximate completion time: 330 minutes                                   */
/******************************************************************************/

/*
   This program displays a menu that allows the user to calculate the nth fibonacci number (specified by the user) or exit the program */

#include <iostream>
#include <sys/select.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <string>
    
using namespace std;

#define until(expr) while(!(expr))

int kbhit();
void openInputSettings();
void enableCLFLAG(int);
void disableCLFLAG(int);
void saveInputSettings();
void disableBufferedInput();
void enableBufferedInput();
char waitForKey(int = -1);
void printMenu();
void prevOption();
void nextOption();
void helloWorld();
int fib(int);
void calculateFibonacci();
void tryRunMenuHotkey(char &);
char parseKey(string);
void clearScreen();

const int STDIN = 0; // this single integer sentinal value represents the entire file descriptor for the input stream of the current terminal. Not very descriptive of a datatype in my opinion. Could have used something like "f_desc STDIN = 0;", you know? It is literally a struct away.
termios terminal; // holds terminal data to change the settings (mostly to disable the line buffering and echo).
const int menuSize = 3;
const string menuOptions[menuSize] = {"\"Hello, World!\"","Calculate Fibonacci","Exit"};
int menuIndex = 0;
const string menuPointer = ">";

#define KEY_0 48
#define KEY_9 57
#define KEY_UP 38
#define KEY_DOWN 40
#define KEY_ENTER 10

int main() {
    char key;
    
    openInputSettings();
    disableBufferedInput();
    clearScreen();
    printMenu();
    do {
        key = waitForKey();
        if (key == KEY_UP) prevOption();
        if (key == KEY_DOWN) nextOption();
        clearScreen();
        printMenu();
        tryRunMenuHotkey(key);
        
        if (key == KEY_ENTER && menuOptions[menuIndex] != "Exit") {
            clearScreen();
            cout << "\x1B[38;2;0;255;255mnow running: \x1B[0m\x1B[38;2;255;255;0m" << menuOptions[menuIndex] << "\x1B[0m" << endl
                 << endl;
            if (menuIndex == 0) helloWorld();
            if (menuIndex == 1) calculateFibonacci();
            cout << endl
                 << endl
                 << "\x1B[38;2;160;160;160mPress any key to go back to menu...\x1B[0m" << endl
                 << "\x1B[38;2;160;160;160mPress ENTER to restart...\x1B[0m" << endl
                 << "\x1B[38;2;160;160;160mENTER 1 or 2 to run another program (1) or exit (2)...\x1B[0m" << endl;
        }
    } until(key == KEY_ENTER && menuOptions[menuIndex] == "Exit");
    cout << "\x1B[2J\x1B[H"
         << "Exiting..." << endl
         << "Thank you!" << endl
         << endl;
    
    return 0;
}

void helloWorld() {
    cout << "Hello, World!" << endl;
}


void calculateFibonacci() {
    int num = -1;
    until (num >= 1) {
        cout << "Enter n: ";
        cin >> num;
        if (!(num >= 1)) {
            cout << "n should be a positive integer (n >= 1). Retry." << endl;
        }
    }
    
    cout << "fibonacci(" << num << ") = " << fib(num) << endl;
}

int fib(int n) {
    if (n <= 0) return 0;
    int num = 0;
    for (int i1=0,i2=1,k=1; k < n; k++) {
        num = i2 + i1;
        i1 = i2;
        i2 = num;
    }
    return num;
}

void tryRunMenuHotkey(char &key) {
    if (key < KEY_0 || key > KEY_9) return;
    int num = key-KEY_0;
    if (num >= menuSize) {
        cout << "Invalid choice. Retry." << endl;
        key = waitForKey(1000);
        if (key != 0) {
            if (key == KEY_UP) prevOption();
            if (key == KEY_DOWN) nextOption();
            clearScreen();
            printMenu();
            tryRunMenuHotkey(key);
        }
        else {
            clearScreen();
            printMenu();
        }
    }
    else {
        menuIndex = num;
        key = KEY_ENTER;
    }
}

void prevOption() {
    menuIndex--;
    if (menuIndex < 0) {
        menuIndex = menuSize - 1;
    }
}

void nextOption() {
    menuIndex++;
    if (menuIndex >= menuSize) {
        menuIndex = 0;
    }
}

void clearScreen() {
    cout << "\x1B[2J\x1B[H";
}

void printMenu() {
    for (int i = 0; i < menuSize; i++) {
        if (i == menuIndex) {
            cout << menuPointer;
        }
        cout << i << ": " << menuOptions[i] << endl;
    }
    cout << "(Enter 1 or 2)" << endl;
}

char waitForKey(int timeout) {
    fflush(stdout);
    static char bufferedInput[BUFSIZ];
    string input = "";
    
    disableCLFLAG(ICANON); // disables canonical mode, making it read input immediately rather than waiting for a line delimeter.
    disableCLFLAG(ECHO); // disables echo, making the input stay in the input and not output to the terminal. This does not re-enable by itself. Found out the hard way. It's actually pretty cool to see though.
    saveInputSettings();
    while(!kbhit() && timeout != 0) {
        usleep(1000);
        if (timeout > 0) timeout--;
    }
    if (timeout != 0) {
        read(STDIN,&bufferedInput,BUFSIZ); // gets the input before it gets absolutely demolished.
    }
    enableCLFLAG(ICANON); // re-enables the ICANON thing.
    enableCLFLAG(ECHO); // re-enables the ECHO thing.
    saveInputSettings();
    int i = 0;
    until(bufferedInput[i] == 0) {
        input += bufferedInput[i];
        bufferedInput[i] = 0;
        i++;
    }
    if (timeout == 0) {
        return 0;
    }
    return parseKey(input);
}

char parseKey(string keySig) {
    if (keySig[2] == 65) return static_cast<char>(38); // UP
    if (keySig[2] == 66) return static_cast<char>(40); // DOWN
    if (keySig[2] == 67) return static_cast<char>(39); // RIGHT
    if (keySig[2] == 68) return static_cast<char>(37); // LEFT
    return keySig[0];
}

// enables one of the settings for the input (or output) of the terminal and how it's processed.
// there's an entire list of things you can do with this, it's incredibly powerful.
void enableCLFLAG(int flag) {
    terminal.c_lflag |= flag; // uses bitwise OR to set all the bits that represent the flag to 1. 
}

// disables one of the settings for the input (or output) of the terminal and how it's processed.
// there's also an entire list of things you can do with this, it's also incredibly powerful.
void disableCLFLAG(int flag) {
    terminal.c_lflag &= ~flag; // Uses bitwise NOT to turn the flag int into it's compliment bit representation in combination with bitwise AND to set all the bits that represents the flag to 0 while keeping all the other ones the same.
}

// gets the data for the current terminal and stores it inside of the terminal global variable. Specifically the input stream of the current terminal because that is the file descriptor that was chosen to get the attributes of. This can be used on other things that are not the terminal (like raw files for example).
void openInputSettings() {
    tcgetattr(STDIN,&terminal);
}

// assigns any settings that were changed to the file with the file descriptor of STDIN (0).
// makes the changes to the input settings official basicaly.
void saveInputSettings() {
    tcsetattr(STDIN, TCSANOW /*specifies immediate change*/, &terminal);
}

// turns off buffering for stdin. So, whenever something is sent to the buffer (like an input for example), it immediately outputs to the stream instead of waiting for more data.
void disableBufferedInput() {
    setbuf(stdin, NULL);
}

// enables the buffered input (is already buffered by default... I think)
void enableBufferedInput() {
    setvbuf(stdin, NULL, _IOFBF, 4096);
}

int kbhit() {
    timeval timeout; // basically a type that stores two unsigned integers with one labeled as seconds and the other labeled as microseconds. Nothing special. Just needed for safe communication with system types without undefined type coercion behavior.
    fd_set rdset; // a datatype that stores a set of file descriptors (which are just integers but apparently they actually wanted to use a different type for this one).
    FD_ZERO(&rdset); // removes all file descriptors stored inside the set from the set.
    FD_SET(STDIN, &rdset); // adds the file descriptor of the terminal's input stream (STDIN which is just 0) to the rdset file descriptor set (why did they call it FD_SET if it ADDS the file descriptor to the set?).
    timeout.tv_sec = 0; // sets the timeout seconds to 0
    timeout.tv_usec = 0; // sets the timeout microseconds to 0
    
    return select(
        STDIN + 1, // the output stream
        &rdset, // the input stream
        NULL, // n/a (turned off)
        NULL, // n/a (turned off)
        &timeout // since timeout was set to 0, it never blocks the program to wait for the input stream to become available. If it is not available, that's what it tells you; it doesn't wait until it does become available, it just tells you the current state as it is.
    );
}