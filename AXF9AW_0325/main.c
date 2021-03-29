#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    int fp;
    char tomb[100];
    int db =0;
    int hely =0;
    int byte =0;
    tomb[0] = 0;
    //Az AXF9AW.txt megnyitása O_RDWR módon
    fp = open("AXF9AW.txt", O_RDWR);
    //Ellenõrzés, hogy mûködik e a fájl megnyitása
    if (fp == -1)
        {
            perror("Nem sikerult megnyitni a fajlt!");
            exit(-1);
        }
    //Sorok megszámolása
    db = read(fp, tomb, 100);
    printf("Ennyi byteot olvasott ki: %d ", db);

    //Kurzor helyének pozicionálása
    hely = lseek(fp, 0, SEEK_SET);
    printf("\nA %d helyre allt be", hely);

    //Megszámolja a byte-okat
    byte = write(fp,tomb, 6);
    printf("\nByteok szama: %d ", byte);

    //Az AXF9AW.txt bezárása
    close(fp);
    return 0;
}
