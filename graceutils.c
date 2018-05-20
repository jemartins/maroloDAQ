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

int main (void)
{
	OpenGrace ();
	GravaDados ();
}

int OpenGrace(void)
{
    /* Start Grace with a buffer size of 2048 and open the pipe */
    if (GraceOpen(2048) == -1) {
        return EXIT_FAILURE;
    } else {
        return EXIT_SUCCESS;
    }
    
}

int SetEscala (float max_x, float max_y, float min_y, float major_tick_x, float minor_tick_x, float major_tick_y, float minor_tick_y)
{
 if (GraceIsOpen()) {
    /* Send some initialization commands to Grace */
    GracePrintf ("world xmax %5.2f", max_x);
    GracePrintf ("world ymax %5.2f", max_y);
    GracePrintf ("world ymin %5.2f", min_y);
    GracePrintf ("xaxis tick major %5.2f", major_tick_x);
    GracePrintf ("xaxis tick minor %5.2f", minor_tick_x);
    GracePrintf ("yaxis tick major %5.2f", major_tick_y);
    GracePrintf ("yaxis tick minor %5.2f", minor_tick_y);
    return EXIT_SUCCESS;
 } else {
    return EXIT_FAILURE;
 }
}

int SetSimbolo (int nchan) {

	//int i;

    	if (GraceIsOpen()) {
/*
        	for (i=0; i<nchan; i++)
		{
        		GracePrintf ("s%d on", i);
        		GracePrintf ("s%d symbol 1", i);
        		GracePrintf ("s%d symbol size 0.3", i);
			GracePrintf ("s%d symbol color %d", i, i+1);
        		GracePrintf ("s%d symbol fill pattern %d", i, i+1);
			GracePrintf ("s%d line color %d", i, i+1);
    		}
*/
        	GracePrintf ("s%d on", 0);
		GracePrintf ("s%d symbol 1", 0);
		GracePrintf ("s%d symbol size 0.3", 0);
		GracePrintf ("s%d symbol color %d", 0, 1);
		GracePrintf ("s%d symbol fill pattern %d", 0, 1);
		GracePrintf ("s%d line color %d", 0, 1);
	
        	GracePrintf ("s%d on", 1);
		GracePrintf ("s%d symbol 1", 1);
		GracePrintf ("s%d symbol size 0.3", 1);
		GracePrintf ("s%d symbol color %d", 1, 2);
		GracePrintf ("s%d symbol fill pattern %d", 1, 2);
		GracePrintf ("s%d line color %d", 1, 2);

    		return EXIT_SUCCESS;
    	} else {
    		return EXIT_FAILURE;
	} // end if

} // end SetSimbolo

int PlotaGrace (float x, float y, int nchan)
{

int i;
    if (GraceIsOpen()) {

        if (nchan==1) {
            GracePrintf ("g0.s0 point %5.2f, %5.2f", x, y);
        }
        else if (nchan==2) {
            GracePrintf ("g0.s1 point %5.2f, %5.2f", x, y);
        }
        else {
            return EXIT_FAILURE;
        }

        return EXIT_SUCCESS;

    } else {
        return EXIT_FAILURE;
    }             
}

int GravaDados (void)
{
    if (GraceIsOpen()) {
        /* Tell Grace to save the data */
        GracePrintf ("saveall \"sample.agr\"");

        /* Flush the output buffer and close Grace */
        // GraceClose();

        /* We are done */
        return EXIT_SUCCESS;
    } else {
        return EXIT_FAILURE;
    }
}
