#include <stdio.h>
#include <windows.h>

// Stampa una parola con colore e cursore in posizione
void evidenziaParola(int x, int y, const char* parola, int colore) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = {x, y};
    SetConsoleCursorPosition(hConsole, position);
    printf("\033[%dm%s\033[0m", colore, parola); // ANSI colorato
}

// Pausa in millisecondi
void sleep_ms(int milliseconds) {
    Sleep(milliseconds);
}

// Mostra la griglia (fissa)
void mostraGriglia() {
    int y = 5;
    const char* righe[] = {
        "_________________________________",
        "|S O N O U L E Y O R E X Z E R O|",
        "|V E N T I T R E D I C I O T T O|",
        "|E C Q U A T T O R D I C I S E I|",
        "|N I U N D I C I Q U A T T R O O|",
        "|T N I J V E N T U N O D I E C I|",
        "|I Q N S E D I C I A S S E T T E|",
        "|D U D O D I C I A N N O V E L F|",
        "|U E I H E L P Q U A R A N T A X|",
        "|E R C K U V E N T I T R E N T A|",
        "|G R I N C I N Q U A N T A U N O|",
        "|S E D I C I D O D I C I O T T O|",
        "|D I E C I Q U A T T O R D I C I|",
        "|Q U A T T R O Q U I N D I C I O|",
        "|A R T R E D I C I A S S E T T E|",
        "|U N D I C I A N N O V E O S E I|",
        "|C I N Q U E D U E U M I N U T I|",
        "_________________________________"
    };

    for (int i = 0; i < 18; i++) {
        COORD pos = {20, y++};
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
        printf("%s\n", righe[i]);
    }
}

// Mappa le ore nel formato (x, y, "testo")
void mostraOra(int ora) {
    // "SONO LE"
    evidenziaParola(21, 6, "S O N O", 31); // rosso
    evidenziaParola(29, 6, "L E", 31);     // rosso

    // Ora in lettere (mappate)
    switch (ora % 12) {
        case 1: evidenziaParola(32, 10, "U N O", 32); break;
        case 2: evidenziaParola(22, 21, "D U E", 32); break;
        case 3: evidenziaParola(20, 13, "T R E", 32); break;
        case 4: evidenziaParola(24, 18, "Q U A T T R O", 32); break;
        case 5: evidenziaParola(21, 20, "C I N Q U E", 32); break;
        case 6: evidenziaParola(34, 20, "S E I", 32); break;
        case 7: evidenziaParola(30, 13, "S E T T E", 32); break;
        case 8: evidenziaParola(28, 6, "O T T O", 32); break;
        case 9: evidenziaParola(26, 13, "N O V E", 32); break;
        case 10: evidenziaParola(31, 10, "D I E C I", 32); break;
        case 11: evidenziaParola(22, 14, "U N D I C I", 32); break;
        case 0: evidenziaParola(22, 12, "D O D I C I", 32); break;
    }
}

void mostraMinuti(int minuti) {
    // Approssimazione al più vicino multiplo di 5
    int m = (minuti + 2) / 5 * 5;
    if (m == 60) m = 0;

    switch (m) {
        case 5:  evidenziaParola(24, 21, "C I N Q U E", 36); break;
        case 10: evidenziaParola(21, 17, "D I E C I", 36); break;
        case 15: evidenziaParola(24, 18, "Q U A T T R O", 36); break; // per "un quarto"
        case 20: evidenziaParola(22, 8, "V E N T I", 36); break;
        case 25: evidenziaParola(22, 8, "V E N T I", 36);
                 evidenziaParola(28, 21, "C I N Q U E", 36); break;
        case 30: evidenziaParola(21, 10, "M E Z Z A", 36); break; // puoi usare una parola a tua scelta
        case 35: evidenziaParola(21, 10, "M E Z Z A", 36);
                 evidenziaParola(28, 21, "C I N Q U E", 36); break;
        case 40: evidenziaParola(22, 8, "V E N T I", 36);
                 evidenziaParola(21, 17, "D I E C I", 36); break;
        case 45: evidenziaParola(24, 18, "Q U A T T R O", 36); break; // meno un quarto?
        case 50: evidenziaParola(21, 17, "D I E C I", 36);
                 evidenziaParola(28, 21, "C I N Q U E", 36); break;
        case 55: evidenziaParola(28, 21, "C I N Q U E", 36); break;
        default: break;
    }
}

int main() {
    while (1) {
        system("cls");
        mostraGriglia();

        SYSTEMTIME time;
        GetLocalTime(&time);

        mostraOra(time.wHour);
        mostraMinuti(time.wMinute);

        sleep_ms(60000); // aggiorna ogni minuto
    }

    return 0;
}
