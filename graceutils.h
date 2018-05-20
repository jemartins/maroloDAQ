#ifndef graceutils_H
#define graceutils_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <grace_np.h>

#ifndef EXIT_SUCCESS
#  define EXIT_SUCCESS 0
#endif

#ifndef EXIT_FAILURE
#  define EXIT_FAILURE -1
#endif

int OpenGrace(void);
int SetSimbolo (int nchan);
int PlotaGrace (float x, float y, int nchan);
int GravaDados (void);

#endif // graceutils_H
