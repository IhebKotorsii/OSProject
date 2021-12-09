#include <stdio.h>
#include "request.h"
#include "io_helper.h"
#include <pthread.h>

char default_root[] = ".";


//
// ./wserver [-d <basedir>] [-p <portnum>]
//


int main(int argc, char *argv[]) {
    int c;
    char *root_dir = default_root;
    int port = 10000;
    nThreads= DEFAULT_THREADS;
    bufferMax=DEFAULT_BUFFER_TAILLE;
    pthread_t pMaster;


    while ((c = getopt(argc, argv, "d:p:t:b:")) != -1)
        switch (c) {
        case 'd':
            root_dir = optarg;
            break;
        case 'p':
            port = atoi(optarg);
            break;
        case 't':
                    nThreads = atoi(optarg);
                    break;
        case 'b':
                    bufferMax = atoi(optarg);
                            break;
        default:
            fprintf(stderr, "usage: wserver [-d basedir] [-p port] [-t nThreads] [-b bufferMax] \n");
            exit(1);
        }
    	pthread_t pool[nThreads];
         struct table tab;
            tab.nt=nThreads;
            tab.b=bufferMax;
            tab.p= &pool;
            tab.pr=port;
    // run out of this directory
    chdir_or_die(root_dir);
    pthread_create(&pMaster,NULL,threadsMaster,&tab);
    pthread_join(&pMaster,NULL);




    return 0;
}
