#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void encrypt(char* Message, int pKey) {
  char c;

  while(*Message) {
    *Message = *Message ^ pKey;
    Message++;
  }
}

int parsekey(char* keyfile) {
  FILE* pFile;
  pFile = fopen(keyfile, "r");
  if (pFile != NULL) {
    int i;
    return fscanf(pFile, "%d", &i);
  } else {
    perror("The following error has occurred");
  }
}


int main(int argc, char** argv) {
	
  int key;
  int c;
  char msg[80];

  opterr = 0;

  while ((c = getopt (argc, argv, "k:f:")) != -1) {
    switch (c) {
    case 'k':
      key = strtol(optarg, NULL, 0);
      break;
    case 'f':
      key = parsekey(optarg);
      break;
    case '?':
      if (optopt == 'k') 
        fprintf(stderr, "Option -%c requires an argument.\n", optopt);
    
      else if (isprint (optopt))
        fprintf(stderr, "Unknown option '-%c'.\n", optopt);

      else 
        fprintf(stderr, "Unknown option character '\\x%x'.\n", optopt);
      return 1;

    default:
    break;
    }
  }
 
  while (fgets(msg, 80, stdin)) {
    encrypt(msg, key);
    printf("%s", msg);
  }


  return 0;
}
	
