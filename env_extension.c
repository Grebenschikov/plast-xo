int _consoleWidth() {
  struct winsize size;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
  return size.ws_col;
}

int _consoleHeight() {
  struct winsize size;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
  return size.ws_row;
}

int _consoleReadInteger() {
  char line[256];
  int output;
  if(fgets(line, 256, stdin) && sscanf(line, "%d", &output) != 1) {
    return -1;
  }

  return output;
}

int _integerRand() {
  static bool init = false;
  if (!init) {
    srand(time(0));
    init = true;
  }

  return rand();
}