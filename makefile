all: main.o empresa.o cargos.o cargo.o personas.o persona.o
	g++ -o main main.o empresa.o cargos.o cargo.o personas.o persona.o
main.o: main.c
	g++ -c main.c
empresa.o: empresa.h empresa.c
	g++ -c empresa.c
cargos.o: cargos.h cargos.c
	g++ -c cargos.c
cargo.o: cargo.h cargo.c
	g++ -c cargo.c
personas.o: personas.h personas.c
	g++ -c personas.c
persona.o: persona.h persona.c
	g++ -c persona.c
clean:
	rm *.o
	rm main