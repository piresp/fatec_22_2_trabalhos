#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <locale.h>

typedef struct {
	int age;
	char name[60];
	char cpf[20];
} Identity;

typedef struct {
	int region;
	const char* capital;
} Destiny;

typedef struct {
	int region;
	const char* capital;
} Origin;

typedef struct {
	Identity identity;
	Destiny destiny;
	Origin origin;
	float price;
} Order;

enum All_regions { // REGION
    Sul=1, Sudeste, CentroOeste, Nordeste, Norte, LastRegion
} region;

const char* regionA[] = {"SUL", "SUDESTE", "CENTRO-OESTE", "NORDESTE", "NORTE", 0};

typedef enum { // SUL
    Curitiba=1, Florianopolis, RioGrandeDoSul ,LastSouth
} south;

const char* southA[] = {"CURITIBA", "FLORIANÓPOLIS", "RIO GRANDE DO SUL", 0};

typedef enum { // SUDESTE
    SaoPaulo=1, BeloHorizonte, RioDeJaneiro, Vitoria, LastSouthEast
} southeast;

const char* southeastA[] = {"SÃO PAULO", "BELO HORIZONTE", "RIO DE JANEIRO", "VITÓRIA", 0};

typedef enum { // CENTRO OESTE
    Brasilia, Goiania, Cuiaba, CampoGrande, LastMidWest
} midwest;

const char* midwestA[] = {"BRASÍLIA", "GOIANIA", "CUIABA", "CAMPO GRANDE", 0};

typedef enum { // NORDESTE
    Salvador, SaoLuis, Teresina, Fortaleza, Natal, JoaoPessoa, Recife, Maceio, Aracaju, LastNortheast
} northeast;

const char* northeastA[] = {"SALVADOR", "SAO LUÍS", "TERESINA", "FORTALEZA", "NATAL", "JOÃO PESSOA", "RECIFE", "MACEIÓ", "ARACAJU", 0};

typedef enum { // NORTE
    RioBranco, Macapa, Manaus, Belem, PortoVelho, BoaVista, Palmas, LastNorth
} north;

const char* northA[] = {"RIO BRANCO", "MACAPÁ", "MANAUS", "BELÉM", "PORTO VELHO", "BOA VISTA", "PALMAS", 0};

void clear() {
	system("@cls||clear");
}

void break_line() {
	printf("\n--------------------------------\n");
}

void display(const char* menu) {
	clear();
	printf("\n\n");
	printf(menu);
	break_line();
}

void display_capitals(const char* capitals[]) {
	int i;
	while (capitals[i] != '\0') {
		printf("\n%d - %s", i+1, capitals[i]);
		i++;
	}

}


void welcome() {
	display("BEM VINDO!");
	printf("O programa a seguir simula a compra de tickets para viajar\npor uma companhia ficticia de viacao.\n\nDesenvolvido com fins academicos\npor: Gabriel Firmino Pires Pereira\n\nLinkedIn: https://www.linkedin.com/in/devpires/\n\n");
	Sleep(2000);

	int i;
	for(i=3; i>0; i--) {
		printf("Iniciado em %d \r", i);
		Sleep(1000);
	}
}

void restart() {
	display("FIQUEI COM PREGUIÇA DE IMPLEMENTAR!");
	break_line();
	printf("Ele não vai reiniciar sozinho kkkk...\n\n");
	int i;
	for(i=5; i>0; i--) {
		printf("Finalizando programa em em %d \r", i);
		Sleep(1000);
	}
}

void end() {
	display("OBRIGADO, VOLTE SEMPRE!");

	int i;
	for(i=5; i>0; i--) {
		printf("Finalizando programa em em %d \r", i);
		Sleep(1000);
	}
}

int read_where(int number) {
	int confirm = 0;

	do {
		puts("\n\nINSIRA NUMERO CORRESPONDENTE: ");
		scanf("%d", &confirm);
	} while (confirm <1 || confirm > number);

	return confirm;
}

Identity set_identity(Identity id) {

	display("CADASTRO: DADOS PESSOAIS");

	printf("NOME: ");
	fgets(id.name, 100, stdin);

	printf("CPF: ");
	fgets(id.cpf, 20, stdin);

	printf("IDADE: ");
	scanf("%d", &id.age);

	return id;
}

Identity get_identity(Identity id) {

	break_line();
	printf("IDENTIDADE:");
	printf("\n\nNOME: %s",id.name);
	printf("CPF: %s",id.cpf);
	printf("IDADE: %d",id.age);

	break_line();
}

Origin set_origin_region(Origin origin) {

	display("ORIGEM: REGIÃO");
	for(int i = 0; i< Norte; i++) {
		printf("\n%d - %s", i+1, regionA[i]);
	}

	int take_region = read_where(5);
	origin.region = take_region;

	return origin;
}

Origin get_origin_region(Origin origin) {
	break_line();
	printf("%d - %s", origin.region, regionA[origin.region - 1]);
}

Origin body_set_origin_capital(Origin origin, const char** array) {

	display_capitals(array);
	int j = read_where(sizeof(array));
	origin.capital = array[j - 1];

	return origin;

}

Origin set_origin_capital(Origin origin) {

	display("ORIGEM: CAPITAL");

	switch (origin.region) {
		case 1: {

			origin = body_set_origin_capital(origin, southA);

			return origin;
			break;
		}

		case 2: {

			origin = body_set_origin_capital(origin, southeastA);

			return origin;
			break;
		}

		case 3: {

			origin = body_set_origin_capital(origin, midwestA);

			return origin;
			break;
		}

		case 4: {

			origin = body_set_origin_capital(origin, northeastA);

			return origin;
			break;
		}

		case 5: {

			origin = body_set_origin_capital(origin, northA);
			
			return origin;
			break;
		}
	}
}

int main() {

	setlocale(LC_ALL, "Portuguese");
	/*
	welcome();

	Identity id;
	id = set_identity(id);
	get_identity(id);

	*/
	Origin ori;
	ori = set_origin_region(ori);
	// get_origin_region(ori);

	ori = set_origin_capital(ori);
	// get_origin_capital();

	return 0;
}
