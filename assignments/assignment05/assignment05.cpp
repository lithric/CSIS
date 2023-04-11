/*****************************************************************************/
/* Skeleton provided by S. Bassil (Spring 2023)                                */
/*                                                                           */
/* Programmer:                                                               */
/*                                                                           */
/* Program: assignment05                                                     */
/*                                                                           */
/* Approximate Completion Time:                                              */
/*****************************************************************************/

/*
   This program builds a linked list and traverses it iteratively.
*/

#include <iostream>
#include <unistd.h>
#include <termios.h>
#include <sys/select.h>
#include <string>

using namespace std;

/* declaration of structure */
struct node{
	int data;
	node *next;
};

struct termioc {
	termios settings;
	int descriptor;
	termioc() : descriptor(0) {
		tcgetattr(0,&settings);
	}
	int tcselect(int fd = 0) {
		descriptor = fd;
		tcgetattr(fd,&settings);
	}
	void setc_lflag(int lflag,bool set = true) {
		if (set) {
			settings.c_lflag |= lflag;
		}
		else {
			settings.c_lflag &= ~lflag;
		}
	}
	int tcsave(int option = TCSANOW) {
		return tcsetattr(descriptor,option,&settings);
	}
} terminal;

struct cool_menu {
	int selected_item = 0;
	int menu_items;
	string menu_item[50];
	cool_menu(string arr_item[],int size) {
		menu_items = size;
		for (int i=0; i<size; i++) {
			menu_item[i] = arr_item[i];
		}
	}
	void print_menu() {
		cout << "\x1B[2J\x1B[H";
		for (int i=0; i<menu_items; i++) {
			if (i==selected_item) {
				cout << "->";
			}
			cout << i << "     ";
			cout << menu_item[i] << endl;
		}
		cout << endl;
		cout << "Enter";
		if (menu_items == 0) {
			cout << " any key...";
		}
		for (int i=0; i<menu_items; i++) {
			cout << " ";
			if (menu_items == 1) {
				cout << i+1 << ":";
			}
			else if (i+1==menu_items) {
				cout << "or" << i+1 << ":";
			}
			else {
				cout << i+1;
				if (menu_items > 2) {
					cout << ",";
				}
			}
		}
	}
	void next() {
		if (!(selected_item >= menu_items-1)) { // unless
			selected_item++;
		}
	}
	void prev() {
		if (!(selected_item <= 0)) { // unless
			selected_item--;
		}
	}
};

/* functions prototypes */
node* insert_node(node *ptr, node *new_ptr);
node* find_node(node *ptr, int n);
node* delete_node(node *ptr, int n, bool &success_flag);
void print_backward(node *ptr);

cool_menu menu = {
	(string[]){
		"Insert integer into linked list",
		"Find integer in linked list",
		"Delete integer from linked list",
		"Print out integers",
		"Quit"
	},
	5
};

int main()
{
	// Write your code here.
	char user_input;
	menu.print_menu();
	waitForKey();
	user_input = getch();
	switch (user_input)
	{
	case 17:
		menu.prev();
		menu.print_menu();
		break;
	case 18:
		menu.next();
		menu.print_menu();
		break;
	case '1':
		node *user_node;
		cin >> user_node -> data;
	
	default:
		break;
	}
	if (user_input == 17) {
		menu.prev();
		menu.print_menu();
	}
	else if (user_input == 18) {
		menu.next();
		menu.print_menu();
	}
	return 0;
}

/******************************************************************************/
/* Function: insert_node                                                      */
/*                                                                            */
/* Description: Write a brief description of what the function does           */
/*                                                                            */
/* Data in: ptr to first node in linked list, ptr to the node to be inserted  */
/*                                                                            */
/* Data out: ptr to the first node in new linked list                         */
/******************************************************************************/

node* insert_node(node *ptr, node* new_ptr)
{

}

/******************************************************************************/
/* Function: find_node                                                        */
/*                                                                            */
/* Description: Write a brief description of what the function does           */
/*                                                                            */
/* Data in: ptr to first node in linked list, the integer searching for       */
/*                                                                            */
/* Data out: ptr to the node with data equals to integer searched for,        */
/*           nullptr if integer searched for was not found                    */
/******************************************************************************/

node* find_node(node *ptr, int n)
{

}

/******************************************************************************/
/* Function: delete_node                                                      */
/*                                                                            */
/* Description: Write a brief description of what the function does           */
/*                                                                            */
/* Data in: ptr to first node in linked list, the integer searching for,      */
/*          flag to be set to:                                                */
/*            - true if integer was found and corresponding node deleted      */
/*            - false otherwise                                               */
/*                                                                            */
/* Data out: ptr to the first node in new linked list                         */
/******************************************************************************/

node* delete_node(node *ptr, int n, bool &success_flag)
{

}

/******************************************************************************/
/* Function: print_backward                                                   */
/*                                                                            */
/* Description: Write a brief description of what the function does           */
/*                                                                            */
/* Data in: ptr to first node in linked list                                  */
/*                                                                            */
/* Data out: none                                                             */
/******************************************************************************/

void print_backward(node *ptr)
{

}

void waitForKey() {
	terminal.setc_lflag(ICANON,false);
	terminal.setc_lflag(ECHO,false);
	terminal.tcsave(TCSADRAIN);
	while(!kbhit()) {
		microSleep(1000);
	}
	terminal.setc_lflag(ICANON,true);
	terminal.setc_lflag(ECHO,true);
	terminal.tcsave();
}

char getch() {
	char buffer[3];
	read(0,&buffer,3);
	return parseKey(buffer);
}

char parseKey(char keySig[3]) {
	if (keySig[2] == 65) return static_cast<char>(17); // UP
    if (keySig[2] == 66) return static_cast<char>(18); // DOWN
    if (keySig[2] == 67) return static_cast<char>(19); // RIGHT
    if (keySig[2] == 68) return static_cast<char>(20); // LEFT
	return keySig[0];
}

void microSleep(unsigned long __usec) {
    struct timespec ts, rts;
    ts.tv_nsec = __usec*1000;

    ts.tv_sec = ts.tv_nsec/1000000000;
    ts.tv_nsec = ts.tv_nsec%1000000000;
    
    while(nanosleep(&ts,&rts)==-1) {
        if (errno==EINTR) {
            ts=rts;
        }
        else {
            break;
        }
    }
    return;
}

int kbhit() {
	timeval timeout;

	fd_set rdset;

	FD_ZERO(&rdset);
	FD_SET(0,&rdset);

	timeout.tv_sec = 0;
	timeout.tv_usec = 0;

	return select(
		1,
		&rdset,
		NULL,
		NULL,
		&timeout
	);
}