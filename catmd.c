#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#if !defined(VERSION)
#define VERSION "unknown"
#endif  // VERSION

void print_usage() {
  printf("Usage: catmd [options] <file ...>\n\n");
  printf("Options:\n");
  printf("  -h, --help     output usage information\n");
  printf("  -V, --version  output the version number\n");
}

void catmd(const char* filename) {
  FILE* fp = fopen(filename, "r");
  if (fp == NULL) {
    perror(filename);
    return;
  }

  printf("*%s*\n\n", filename);
  printf("```%s\n", strrchr(filename, '.') + 1);

  int ch;
  while ((ch = fgetc(fp)) != EOF) {
    putchar(ch);
  }

  printf("```\n\n");
  fclose(fp);
}

int main(int argc, char* argv[]) {
  int opt;
  static struct option long_options[] = {{"help", no_argument, 0, 'h'},
                                         {"version", no_argument, 0, 'V'},
                                         {0, 0, 0, 0}};

  while ((opt = getopt_long(argc, argv, "hV", long_options, NULL)) != -1) {
    switch (opt) {
      case 'h':
        print_usage();
        exit(0);
      case 'V':
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
