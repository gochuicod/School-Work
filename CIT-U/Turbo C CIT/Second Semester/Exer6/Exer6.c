#include <stdio.h>
#include <windows.h>
#include <string.h>

int countWords(char sent[]);
int strlength(const char str[]);
int countVowels(char *str);
int countCons(char str[]);
int countNotAlnum(char str[]);
char *stringcpy(char *string1, char *string2);
int palindrome(char *st);
char *strupr(char *string);
void insLetter(char sent[], char letra);
int getChar();
void menu();
void Exit(void);
void drawDBox(int x1, int y1, int x2, int y2);
void gotoxy(int x, int y);

int main(){
	char s, choice, rep, num, len, vow, letra, string1[99999], string2[99999], st[99999], string[99999], str[99999], sent[99999];
		do{
			system("cls");
			drawDBox(4,0,27,17);
			menu();
			s = getche(choice);
			switch(s){
				case 'a':
					gotoxy(0,19);printf("Enter string: ");
					gets(sent);
					printf("\nWords: %d", countWords(sent));
					break;
				case 'b':
					gotoxy(0,19);printf("Enter string: ");
					gets(str);
					printf("\nLength: %d", strlength(str));
					break;
				case 'c':
					gotoxy(0,19);printf("Enter string: ");
					gets(str);
					printf("\nVowels: %d", countVowels(str));
					break;
				case 'd':
					gotoxy(0,19);printf("Enter string: ");
					gets(str);
					printf("\nConsonants: %d", countCons(str));
					break;
				case 'e':
					gotoxy(0,19);printf("Enter string: ");
					gets(str);
					printf("\nAlphanumeric: %d", countNotAlnum(str));
					break;
				case 'f':
					gotoxy(0,19);printf("\nEnter string: ");gets(string1);printf("\nEnter string: ");gets(string2);
					stringcpy(string1,string2);
					printf("\nNew string: %s", &string1);
					break;
				case 'g':
					gotoxy(0,19);printf("Enter string: ");gets(st);
					palindrome(st);
					break;
				case 'h':
					gotoxy(0,19);printf("Enter string: ");gets(string);
					gotoxy(3,20);printf("Uppercase: %s", strupr(string));
					break;
				case 'i':
					gotoxy(0,19);printf("Enter string: ");gets(sent);
					printf("Enter Letter: ");letra = getche();
					insLetter(sent,letra);
					//gotoxy(2,21);printf("New String: %s", sent);
					break;
				case 'j':
					Exit();
					return 0;
					break;
				default:
					gotoxy(0,19);printf("Enter a valid choice!");
					rep = 'y';
			}
			printf("\n\nPress any key to return to the main menu...");
			rep = getche(num);
		}while (rep == '\r' || '\r');
	return 0;
}

int countWords(char sent[]){					//THIS IS CASE A
	int word = 0, i;
		for (i = 0; sent[i] != '\0'; i++){
			if (isspace(sent[0]) > 0 || isspace(sent[i - 1]) > 0){
				word+=0;
				break;
			} else if (isspace(sent[i]) > 0){
				word++;
			}
		}
	return word+1;
}           

int strlength(const char str[]){				//THIS IS CASE B
	int len = 0, i;
		for (i = 0; str[i] != '\0'; i++){		
			len++;
		}
	return len;
}

int countVowels(char *str){						//THIS IS CASE C
	int i, vow = 0;
		for (i = 0; str[i] != '\0'; i++){
				if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' ||
				str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' 
				|| str[i] == 'I' ||	str[i] == 'O' || str[i] == 'U'){
					vow++;
				}
			}
	return vow;
}

int countCons(char str[]){						//THIS IS CASE D
	int i, cons = 0;
		for (i = 0; str[i] != '\0'; i++){
			if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' ||
				str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' 
				|| str[i] == 'I' ||	str[i] == 'O' || str[i] == 'U'){
					cons+=0;
				} else if (str[i] != 'a' || str[i] != 'e' || str[i] != 'i' || str[i] != 'o'
				|| str[i] != 'u' || str[i] != 'A' || str[i] != 'E' || str[i] != 'I' || str[i] != 'O'
				|| str[i] != 'U'){
					cons++;
				}
		}
	return cons;
}

int countNotAlnum(char str[]){					//THIS IS CASE E
	int i, AlNum = 0;
		for (i = 0; str[i] != '\0'; i++){
			if (isalnum(str[i]) < 1){
				AlNum++;
			}
		}
	return AlNum;
}

char *stringcpy(char *string1, char *string2){	//THIS IS CASE F
	int i, string_1, string_2;
		string_1 = strlen(string1);
		string_2 = strlen(string2);
			if (string_1 != string_2){
				printf("\nString value must be equal!\n");
			} else {
				strcpy(string1,string2);
			}
}

int palindrome(char *st){ 						//THIS IS CASE G
	int i, begin = 0, middle, end, length = 0, beg;
		for (i = 0; st[i] != '\0'; i++){
			if (isupper(st[i]) > 0){
				st[i] = tolower(st[i]);
			}
		}
		for (;st[length] != '\0';){
			length++;
		}
			end = length - 1;
			middle = length / 2;
				for (begin = 0; begin < middle; begin++, end--){
					if (st[begin] != st[end]){
						printf("\nIt is not a palindrome!");
						break;
					}
				}
					if (begin == middle){
						printf("\nIt is a palindrome!");
					}
	return 0;
}

char *strupr(char *string){						//THIS IS CASE H
	int i;
		for (i = 0; string[i] != '\0'; i++){
			if (islower(string[i]) > 0){
				string[i] = toupper(string[i]);
			}
		}
	return string;
}

void insLetter(char sent[], char letra){		//THIS IS CASE I
	int i = 0, j = 0, n = 0;
		for (n = 0; sent[n] != '\0';){
			if (tolower(sent[n]) == 'a' ||
				tolower(sent[n]) == 'e' ||
				tolower(sent[n]) == 'i' ||
				tolower(sent[n]) == 'o' ||
				tolower(sent[n]) == 'u'){
					break;
				}
			n++;
		}
		for (i = strlen(sent); i > n; i--){
			sent[i] = sent[i - 1];
		}
		sent[n] = letra;
		printf("\n%s", sent);
	return;
}	

void menu(){
		gotoxy(7,2);printf("Character Handling");
		gotoxy(6,4);printf("[a] Words");
		gotoxy(6,5);printf("[b] String Length");
		gotoxy(6,6);printf("[c] Vowels");
		gotoxy(6,7);printf("[d] Consonants");
		gotoxy(6,8);printf("[e] Not Alphanumeric");
		gotoxy(6,9);printf("[f] String Copy");
		gotoxy(6,10);printf("[g] Palindrome");
		gotoxy(6,11);printf("[h] String Upper");
		gotoxy(6,12);printf("[i] Insert Letter");
		gotoxy(6,13);printf("[j] Exit");
		gotoxy(6,15);printf("Choice: ");
	return;
}

void Exit(void){
	system("cls");printf("Program terminated. Thank you!");
	return;
}

void drawDBox(int x1, int y1, int x2, int y2){
	int x, y;
			gotoxy(x1,y1);putchar(201);
			gotoxy(x2,y1);putchar(187);
			gotoxy(x2,y2);putchar(188);
			gotoxy(x1,y2);putchar(200);
		for(x = x1 + 1; x < x2; x++){
			gotoxy(x,y1);putchar(205);
			gotoxy(x,y2);putchar(205);
		}
		for(y = y1 + 1; y < y2; y++){
			gotoxy(x1, y);putchar(186);
			gotoxy(x2, y);putchar(186);
		}
	return;
}

void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
