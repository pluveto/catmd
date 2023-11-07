#include <ctype.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wchar.h>
#include <wctype.h>

#if !defined(VERSION)
#define VERSION "unknown"
#endif  // VERSION

void print_usage() {
  printf("Usage: catmd [options] <file ...>\n\n");
  printf("Options:\n");
  printf("  -h, --help     output usage information\n");
  printf("  -v, --version  output the version number\n");
}

void catmd(const char* filename) {
  FILE* fp = fopen(filename, "r");
  if (fp == NULL) {
    perror(filename);
    return;
  }

  wprintf(L"*%s*\n\n", filename);

  const char* extension = strrchr(filename, '.');
  if (extension != NULL) {
    wprintf(L"```%s\n", extension + 1);
  } else {
    wprintf(L"```text\n");
  }

  wint_t ch;
  while ((ch = fgetwc(fp)) != WEOF) {
    if (iswprint(ch) || ch == L'\n' || ch == L'\t') {
      putwchar(ch);
    } else {
      wprintf(L"\\x%02x", ch);
    }
  }
  fclose(fp);

  if (ch != L'\n') {
    putwchar(L'\n');
  }

  wprintf(L"```\n\n");
}

int main(int argc, char* argv[]) {
  int opt;
  static struct option long_options[] = {{"help", no_argument, 0, 'h'},
                                         {"version", no_argument, 0, 'v'},
                                         {0, 0, 0, 0}};

  while ((opt = getopt_long(argc, argv, "hv", long_options, NULL)) != -1) {
    switch (opt) {
      case 'h':
        print_usage();
        exit(0);
      case 'v':
        printf("catmd version %s\n", VERSION);
        exit(0);
      default:
        print_usage();
        exit(1);
    }
  }

  if (optind >= argc) {
    print_usage();
    exit(1);
  }

  for (int i = optind; i < argc; i++) {
    catmd(argv[i]);
  }

  return 0;
}
