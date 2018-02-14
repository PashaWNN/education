#include <iostream>
#include <ncurses.h>
#include <cstdlib>

using namespace std;

typedef enum { physics,
               math,
               chemistry,
               other } FieldOfKnowledge; 

class Knowledge {
  private:
    
    int level;
    FieldOfKnowledge field;
  public:
bool aknowledge;
    Knowledge(FieldOfKnowledge fok, int lvl) {
      level = lvl;
      if (lvl > 0) {
        aknowledge = true;
      }
      field = fok;
    }
};

int main() {
  initscr();
  noecho();
  curs_set(0);
  
  Knowledge k(physics, 3);
  if (k.aknowledge) {
    printw("I know physics!");
  } else {
    printw("I'm stupid. :(");
  }

  getch();
  endwin();
  return 0;
}
