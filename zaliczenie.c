#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>


int main(int iargs, char* argv[]){

	int plikbad;


	int pid;
	if ( iargs != 3 ) {
		printf("Sposob uzycia: %s wynik.txt badany.txt\n gdzie wynik.txt zawiera sciezke pliku z wynikami.\n A badany.txt to badany plik\n",iargs, argv[0]);
		return -1;
 	}

	if ( ( pid = fork() ) == -1 ){
		printf("Blad przy tworzeniu dziecka\n");
		return -1;
	}
	int dlpliku;
	FILE *wynik;
	if (pid == 0) {// Działania dziecka
		if ( ( plikbad = open(argv[2], O_RDONLY | O_APPEND ) ) == -1 ) return 250;
		else {
			dlpliku = lseek(plikbad, 0, SEEK_END);
			printf("Dlugosc pliku %s: %i\n",argv[2],  dlpliku);
			close( plikbad );
			wynik = fopen(argv[1], "a");
		}

		if ( !wynik ) return 251;
		else {
			fprintf(wynik,"Plik %s ma wielkość: %i bajtów\n",argv[2],  dlpliku);
       			fclose( wynik );
		}
		if ( dlpliku > 100 ) return 10;
		else return 1;

	}
	else{
	int kodwyj;
	wait(&kodwyj);
	if ( WIFEXITED(kodwyj) ) kodwyj = WEXITSTATUS(kodwyj);
	if ( kodwyj > 200 ) printf("Proces nie powiodl sie blad %d\n", kodwyj);
	else printf("Kod wyjscia: %i\n", kodwyj);
	printf("Program zostanie zamkniety\n");
	}
	return 0;
}

