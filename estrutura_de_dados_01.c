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
	Destiny destiny;
	Origin origin;
	bool round_trip;
} Travel;

typedef struct {
	Identity identity;
	Travel travel;
	float price;
	bool confirm;
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

Order new_order(Order order);


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
		puts("\n\nOPCAO DESEJADA: ");
		scanf("%d", &confirm);
	} while (confirm <1 || confirm > number);

	return confirm;
}

Order set_identity(Order id) {

	display("CADASTRO: DADOS PESSOAIS");

	printf("NOME: ");
	fgets(id.identity.name, 100, stdin);

	printf("CPF: ");
	fgets(id.identity.cpf, 20, stdin);

	printf("IDADE: ");
	scanf("%d", &id.identity.age);

	return id;
}

Order get_identity(Order id) {

	break_line();
	printf("IDENTIDADE:");
	break_line();
	
	printf("\n\nNOME: %s",id.identity.name);
	printf("CPF: %s",id.identity.cpf);
	printf("IDADE: %d",id.identity.age);
	break_line();
}

Order get_origin(Order order) {
	break_line();
	printf("SAIDA: %s", order.travel.origin.capital);
	break_line();
}

Order get_destiny(Order order) {
	break_line();
	printf("DESTINO: %s", order.travel.destiny.capital);
	break_line();
}

Order get_price(Order order) {
	break_line();
	printf("TOTAL: R$ %f", order.price);
	break_line();
}

void display_region() {
	for(int i = 0; i< Norte; i++)
	printf("\n%d - %s", i+1, regionA[i]);
}

Order set_region(Order order, int origin_or_destiny) {
	
	if (origin_or_destiny == 1) {
		
		display("ORIGEM: REGIÃO");
		display_region();
		
		break_line();
		int take_region = read_where(5);
		order.travel.origin.region = take_region;
		
		return order;
	}
	
	if (origin_or_destiny == 2) {
		
		display("DESTINO: REGIÃO");
		display_region();
		
		break_line();
		int take_region = read_where(5);
		order.travel.destiny.region = take_region;
		
		return order;
	}
}

Order body_set_origin_or_destiny_capital(Order order, const char** array, int origin_or_destiny) {
	
	if (origin_or_destiny == 1) {

		display_capitals(array);
		int j = read_where(sizeof(array));
		order.travel.origin.capital = array[j - 1];
		
		return order;
	}
	
	if (origin_or_destiny == 2) {

		display_capitals(array);
		int j = read_where(sizeof(array));
		order.travel.destiny.capital = array[j - 1];
		
		return order;
	}
}

Order set_capital(Order order, int origin_or_destiny) {
	
	int chose;
	
	if (origin_or_destiny == 1) {
		display("ORIGEM: CAPITAL");
		
		chose = order.travel.origin.region;
	}
	
	else if (origin_or_destiny == 2) {
		display("DESTINO: CAPITAL");

		chose = order.travel.destiny.region;
	}
	
	switch (chose) {
		case 1: {

			order = body_set_origin_or_destiny_capital(order, southA, origin_or_destiny);

			return order;
			break;
		}

		case 2: {

			order = body_set_origin_or_destiny_capital(order, southeastA, origin_or_destiny);

			return order;
			break;
		}

		case 3: {

			order = body_set_origin_or_destiny_capital(order, midwestA, origin_or_destiny);

			return order;
			break;
		}

		case 4: {

			order = body_set_origin_or_destiny_capital(order, northeastA, origin_or_destiny);

			return order;
			break;
		}

		case 5: {

			order = body_set_origin_or_destiny_capital(order, northA, origin_or_destiny);
			
			return order;
			break;
		}
	}
}

Order price_calc(Order order) {
	
	int origin = order.travel.origin.region;
	int destiny = order.travel.destiny.region;
	
	order.price = 100;
	
	if (origin > destiny) {
		while (origin > destiny) {
			order.price += 100;
			destiny++;
		}
	}
	
	if (origin < destiny) {
		while (origin < destiny) {
			order.price += 100;
			origin++;
		}
	}
	return order;
}

Order two_tickets(Order order) {
	display("IDA E VOLTA?");
	printf("1 - SIM\n");
	printf("2 - NÃO");
	break_line();
	
	int option = read_where(2);
	
	if (option == 1) {
		order.price = order.price * 2;
		order.travel.round_trip = true;
	};
	return order;
}

Order print_order(Order order) {
	
	get_identity(order);
	get_origin(order);
	get_destiny(order);
	
	if (order.travel.round_trip == true)
		printf("IDA E VOLTA: SIM");
	
	else {
		printf("IDA E VOLTA: NÃO");	
	}
	
	get_price(order);
}

void success() {
	display("PARABENS!");
	printf("Obrigado por testar meu codigo! Volte sempre!\n\n");
	
	int i;
	for(i=3; i>0; i--) {
		printf("Finalizando em em %d \r", i);
		Sleep(1000);
	}
}

Order confirm(Order order) {
	break_line();
	printf("CONFIRMAR? \n1 - SIM\n2 - NÃO");
	int confirm = read_where(2);
	
	if (confirm == 1) {
		order.confirm = true;
		success();
	}
	
	display("GOSTARIA DE TENTAR NOVAMENTE? \n1 - SIM\n2 - NÃO");
	confirm = read_where(2);
		
	if (confirm == 1) {
		new_order(order);
	}
}


int main() {

	setlocale(LC_ALL, "Portuguese");
	
	welcome();
	
	Order order;
	
	order = set_identity(order);
	
	order = set_region(order, 1);
	order = set_capital(order, 1);
	
	order = set_region(order, 2);
	order = set_capital(order, 2);
	
	order = price_calc(order);
	order = two_tickets(order);
	
	print_order(order);
	
	confirm(order);
	
	
	return 0;
}


Order new_order(Order order) {
	main();
}
