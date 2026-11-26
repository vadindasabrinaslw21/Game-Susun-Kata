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
