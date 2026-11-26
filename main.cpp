#include <ncurses.h>
#include <string>
using namespace std;

const int WAKTU = 25, NYAWA = 3;

// ================== FUNGSI BANTU ==================
void animasi(int y, int x, string t, int ms) {         // ANIMASI TEKS
    for (int i = 0; i < (int)t.size(); i++) {
        mvaddch(y, x + i, t[i]);
        if (ms > 0) { refresh(); napms(ms); }          // ms = 0: tampil langsung
    }
}

void garis(int y, int x, string judul, int ms) {
    mvprintw(y, x, "==============================");
    mvprintw(y + 2, x, "==============================");
    animasi(y + 1, x + (30 - (int)judul.size()) / 2, judul, ms);
}

// ================== BAGIAN 1: LOADING SCREEN ==================
void loading() {
    erase(); garis(3, 8, "GAME  SUSUN  KATA", 80);
    mvprintw(7, 8, "Loading...");
    for (int i = 0; i <= 100; i += 2) {                // PERULANGAN
        move(9, 0); clrtoeol(); move(11, 0); clrtoeol();
        mvprintw(9, 8, "[");
        for (int j = 0; j < 30; j++) {
            if (j < i * 30 / 100) printw("#"); else printw("-");
        }
        printw("] %d%%", i);
        if (i < 40) mvprintw(11, 8, "Memuat kamus kata...");          // PERCABANGAN
        else if (i < 80) mvprintw(11, 8, "Menyiapkan permainan...");
        else mvprintw(11, 8, "Hampir selesai...");
        refresh(); napms(60);
    }
    napms(300);
}
// ================== BAGIAN 2: MENU PLAY DAN EXIT ==================
int menu() {
    int k = 0;
    while (k != '1' && k != '2') {
        erase(); garis(2, 5, "GAME  SUSUN  KATA", 0);
        mvprintw(6, 8, "[1]  Play");
        mvprintw(7, 8, "[2]  Exit Game");
        mvprintw(9, 5, "Waktu per kata : %d detik", WAKTU);
        mvprintw(10, 5, "Nyawa          : %d", NYAWA);
        mvprintw(12, 5, "Pilih menu (1/2): "); refresh();
        k = getch();
    }
    return k - '0';
}

// ================== PROGRAM UTAMA ==================
int main() {
    initscr(); cbreak(); noecho(); keypad(stdscr, TRUE); curs_set(0);
    loading();
    while (menu() == 1) {
        erase();
        mvprintw(5, 5, "Bagian permainan sedang dikembangkan...");
        mvprintw(7, 5, "Tekan ENTER untuk kembali ke menu");
        refresh();
        while (getch() != '\n');
    }
    erase(); mvprintw(2, 2, "Terima kasih sudah bermain! Sampai jumpa."); refresh(); napms(1200);
    endwin();
    return 0;
}
