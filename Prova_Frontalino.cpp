#include <stdio.h>
#include <windows.h>

void setCursorPosition(int x, int y) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position;
	position.X = x;
	position.Y = y;
	SetConsoleCursorPosition(hConsole, position);
}
	
int main() {
	
	//Preparazione e disegnpo iniziale della tabella
	
	setCursorPosition(20,5);
	printf("_________________________________\n");
	setCursorPosition(20,6);
	printf("|S O N O U L E Y O R E X Z E R O|\n");
	setCursorPosition(20,7);
	printf("|V E N T I T R E D I C I O T T O|\n");
	setCursorPosition(20,8);
	printf("|E C Q U A T T O R D I C I S E I|\n");
	setCursorPosition(20,9);
	printf("|N I U N D I C I Q U A T T R O O|\n");
	setCursorPosition(20,10);
	printf("|T N I J V E N T U N O D I E C I|\n");
	setCursorPosition(20,11);
	printf("|I Q N S E D I C I A S S E T T E|\n");
	setCursorPosition(20,12);
	printf("|D U D O D I C I A N N O V E L F|\n");
	setCursorPosition(20,13);
	printf("|U E I H E L P Q U A R A N T A X|\n");
	setCursorPosition(20,14);
	printf("|E R C K U V E N T I T R E N T A|\n");
	setCursorPosition(20,15);
	printf("|G R I N C I N Q U A N T A U N O|\n");
	setCursorPosition(20,16);
	printf("|S E D I C I D O D I C I O T T O|\n");
	setCursorPosition(20,17);
	printf("|D I E C I Q U A T T O R D I C I|\n");
	setCursorPosition(20,18);
	printf("|Q U A T T R O Q U I N D I C I O|\n");
	setCursorPosition(20,19);
	printf("|A R T R E D I C I A S S E T T E|\n");
	setCursorPosition(20,20);
	printf("|U N D I C I A N N O V E O S E I|\n");
	setCursorPosition(20,21);
	printf("|C I N Q U E D U E U M I N U T I|\n");
	setCursorPosition(20,22);
	printf("_________________________________\n");

	//Preparazione della prima riga
	setCursorPosition(20,6);
	printf("\033[37m");
	printf("|");
	printf("\033[31m");
	printf("S O N O ");
	printf("\033[37m");
	printf("U ");
	printf("\033[31m");
	printf("L E ");
	printf("\033[37m");
	printf("Y ");
	printf("\033[31m");
	printf("O R E ");
	printf("\033[37m");
	printf("X Z E R O|");







	
}