# Makefile para compilar e executar arquivos .c em linguagem C

# Nome do executável a ser gerado
EXECUTABLE = main

# Lista de arquivos .c que fazem parte do projeto
SOURCES = main.c sensor.c 

# Comando do compilador
CC = gcc

# Opções do compilador
CFLAGS = -Wall -g

# Comando para compilar todos os arquivos .c em um executável
$(EXECUTABLE): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(EXECUTABLE)

# Comando para executar o programa
run: $(EXECUTABLE)
	./$(EXECUTABLE)

# Comando para limpar os arquivos gerados pela compilação
clean:
	rm -f $(EXECUTABLE)

.PHONY: run clean

