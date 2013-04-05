#include <stdio.h>

int main(int argc, char *argv[]) {

  if (argc != 3) {
    printf("Usage: compile in.bf out.c");
    return;
  }

  FILE *in = fopen(argv[1], "r");
  FILE *out = fopen(argv[2], "w");

  fputs("#include <stdio.h>\nint main() {\nchar array[30000];\nchar *ptr = array;\n", out);

  char c;
  while ((c = fgetc(in)) != EOF) {
    switch (c) {
    case '>':
      fputs("++ptr;\n", out);
      break;
    case '<':
      fputs("--ptr;\n", out);
      break;
    case '+':
      fputs("++*ptr;\n", out);
      break;
    case '-':
      fputs("--*ptr;\n", out);
      break;
    case '.':
      fputs("putchar(*ptr);\n", out);
      break;
    case ',':
      fputs("*ptr = getchar();\n", out);
      break;
    case '[':
      fputs("while (*ptr) {\n", out);
      break;
    case ']':
      fputs("}\n", out);
      break;
    }
  }

  fputs("return 0;\n}", out);

}