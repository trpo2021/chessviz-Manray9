#include "other.h"
 
struct Figura // Ôèãóðû
{   
    string Kw, Kb, Qw, Qb, Rw, Rb, Nw, Nb, Bw, Bb, Pw, Pb;  
    Figura()
        : Kw{ "Kw" }, Kb{ "Kb" }, Qw{ "Qw" }, Qb{ "Qb" }, Rw{ "Rw" }, Rb{ "Rb" }, Nw{ "Nw" },
        Nb{ "Nb" }, Bw{ "Bw" }, Bb{ "Bb" }, Pw{ "Pw" }, Pb{ "Pb" }
    {
    }
};
 
void doska_drawFigura() // Âûâîä äîñêè è ôèãóð íà ýêðàí
{
    system("cls"); // Î÷èùàåì êîíñîëü 
    char num = 'a'; // Äëÿ âûâîäà óêàçàòåëåé ñòîëáöîâ (a,b,c,d ...)
    cout << "\t\t\tÏðèìåð õîäà: 'e2 e4' ÷åðåç ïðîáåë" << endl
       << "\t\t     (ïåøêà áåëûõ ïîøëà ñ ïîçèöèè e2 íà e4)";
    cout << "\n\n";
    for (int i = 0; i < 8; i++)
    {
        cout << "\t\t\t" << 8 - i;
        for (int j = 0; j < 9; j++)
        {
            cout << doska[i][j];
        }
        cout << endl;
    }
    cout << "\t\t\t";
    for (int i = 1; i < 9; i++)
    {
        cout << "   " << num;
        ++num;
    }
    if (((sum_hod % 2 == 0) & (sum_hod > 0)) | (sum_hod == 1)) {
        cout << endl << "Õîä ÷åðíûõ: "; // Ïðèãëàøåíèå ê õîäó
    }
    else {
        cout << endl << "Õîä  áåëûõ: ";
    }
}
 
void doska_def() {  // Íà÷àëüíîå ïîëîæåíèå äîñêè è ôèãóð
    Figura f;
    for (int i = 0; i < 8; i++)
    {   
        for (int j = 1; j < 9; j++)
        {           
            doska[i][j] = "|__|";
            doska_b[i][j] = 0;
        }   
    }
    for (int i = 1; i < 9; i++)
    {                                                       
        doska[1][i] = "|" + f.Pb + "|"; doska_b[1][i] = 1;
        doska[6][i] = "|" + f.Pw + "|"; doska_b[6][i] = 1;
    }
    doska[0][1] = doska[0][8] = "|" + f.Bb + "|"; doska_b[0][1] = doska_b[0][8] = 1;
    doska[7][1] = doska[7][8] = "|" + f.Bw + "|"; doska_b[7][1] = doska_b[7][8] = 1;
    doska[0][2] = doska[0][7] = "|" + f.Nb + "|"; doska_b[0][2] = doska_b[0][7] = 1;
    doska[7][2] = doska[7][7] = "|" + f.Nw + "|"; doska_b[7][2] = doska_b[7][7] = 1;
    doska[0][3] = doska[0][6] = "|" + f.Rb + "|"; doska_b[0][3] = doska_b[0][6] = 1;
    doska[7][3] = doska[7][6] = "|" + f.Rw + "|"; doska_b[7][3] = doska_b[7][6] = 1;
    doska[0][4] = "|" + f.Qb + "|"; doska_b[0][4] = 1;
    doska[0][5] = "|" + f.Kb + "|"; doska_b[0][5] = 1;
    doska[7][4] = "|" + f.Qw + "|"; doska_b[7][4] = 1;
    doska[7][5] = "|" + f.Kw + "|"; doska_b[7][5] = 1;
    
    doska_drawFigura(); // Âûâîäèì äîñêó è ôèãóðû
}
 
void doska_figura_delete(int x, int y) // Óäàëÿåò ôèãóðó èç óêàçàííîé ïîçèöèè
{
    doska[8 - y][8 - (104 - x)] = "|__|";
}
 
void doska_hod(int x, int y) // Âûïîëíèòü õîä (òîëüêî õîä, íå îáðàáîò÷èê èãðîâîãî ñþæåòà)
{           
    if (doska_b[8 - y][8 - (104 - x)] == 1) { // Â êëåòêå ñòîèò ôèãóðà
        buff = doska[8 - y][8 - (104 - x)]; // Ôèãóðó â áóôåð
        doska_figura_delete(x, y); // Óäàëèòü ôèãóðó ñ äîñêè
        doska_b[8 - y][8 - (104 - x)] = 0; // Ñîñòîÿíèå êëåòêè â false
        flag_buff = true;   // Ïîäíÿòü ôëàã (áóôåð íå ïóñòîé)... Âîçìîæíî ïîíàäîáèòñÿ
    }
    else {                      // Â êëåòêå ïóñòî
        doska[8 - y][8 - (104 - x)] = buff; // Ïîñòàâèòü ôèãóðó èç áóôåðà â êëåòêó
        doska_b[8 - y][8 - (104 - x)] = 1; // Ñîñòîÿíèå êëåòêè â true (íå ïóñòà)
        buff = "";              // Îáíóëèòü áóôåð
        flag_buff = false;      // Îïóñòèòü ôëàã, áóôåð ñâîáîäåí
        doska_drawFigura();          // Âûâîäèì äîñêó è ôèãóðû
    }   
    ++sum_hod; // Óâåëè÷èì ñ÷åò÷èê ïîëóõîäîâ
}
 
int main() {
    setlocale(0, "Russian");
    doska_def();    
    int str = 0;
    char stb = 0;
    while (cin >> stb >> str)
    {       
         doska_hod(stb, str);           
    }
    return 0;
}
