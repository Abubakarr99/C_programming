#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

const char* program_name;

void print_usage (FILE* stream, int exit_code)
{
  fprintf (stream, "Utilisation : %s options [fichierentrée ...]\n",
										program_name);
  fprintf (stream,
           " -h --help               Affiche ce message.\n"
           " -o --output filename    Redirige la sortie vers un fichier.\n"
           " -v --verbose            Affiche des messages détaillés.\n");
  exit (exit_code);
}


