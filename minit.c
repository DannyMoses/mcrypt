#include <stdio.h>
#include <string.h>

int main(int argc, char** argv[]) {
  FILE* pScript;
  char* compilestr1 = "echo Compiling";
  char* compilestr2 = "gcc";
  char* compilestr3 =  "-o";
  char* shebangstr = "#! /bin/bash";
  char* installstr1 = "echo";
  char* installstr2 = "if [[ $? -eq 0 ]]; then";
  char* installerstr3 = "sudo mv";
  char* installerstr4 = "/usr/bin";
  char* installerstr5 = "fi";
  char scriptName[256];
  char sourceName[256];
  
  printf("Welcom to minit, the automatic install script generator!\n");
  printf("What is the name of your program? ");
  fscanf(stdin, "%s", scriptName );

  printf("What is the name of your source file? ");
  fscanf(stdin, "%s", sourceName);

  printf("Generating...\n");
  pScript = fopen("setup", "w");
  if (pScript == NULL) {
    perror("Fatal Error");
  } else if (pScript != NULL){
    fprintf(pScript, "%s", shebangstr);
    fprintf(pScript, "%s", "\n");
    fprintf(pScript, "%s", compilestr1); 
    fprintf(pScript, "%s", " ");
    fprintf(pScript, "%s", sourceName);
    fprintf(pScript, "%s", "...");
    fprintf(pScript, "%s", "\n");
    fprintf(pScript, "%s", compilestr2);
    fprintf(pScript, "%s", " ");
    fprintf(pScript, "%s", sourceName);
    fprintf(pScript, "%s", " ");
    fprintf(pScript, "%s", compilestr3);
    fprintf(pScript, "%s", " ");
    fprintf(pScript, "%s", scriptName);
    fprintf(pScript, "%s", "\n");
    fprintf(pScript, "%s", installstr1);
    fprintf(pScript, "%s", " ");
    fprintf(pScript, "Moving to /usr/bin... \n");
    fprintf(pScript, "%s", "\n");
    fprintf(pScript, "%s", installstr2);
    fprintf(pScript, "%s", "\n");
    fprintf(pScript, "%s", installerstr3);
    fprintf(pScript, "%s", " ");
    fprintf(pScript, "%s", scriptName);
    fprintf(pScript, "%s", " ");
    fprintf(pScript, "%s", installerstr4);
    fprintf(pScript, "%s", "\n");
    fprintf(pScript, "%s", installerstr5);
    fprintf(pScript, "%s", "\n");
    system("chmod +x setup");
  }
  return 0;
}
