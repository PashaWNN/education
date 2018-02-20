import curses

stdscr = curses.initscr()
stdscr.addstr("Привет, мир!")
stdscr.getch()
curses.endwin()
