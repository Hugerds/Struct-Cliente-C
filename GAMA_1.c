#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#define MAX 50
/*Crie uma função que receba a data de fundação e o valor do faturamento,
retorne todos os clientes ativos ordenados por data de alteração onde a data de
fundação e o faturamento sejam maiores ou iguais aos enviados por parâmetro.
Crie uma função que receba uma lista de clientes e retorne os 10 maiores
faturamentos.*/

typedef struct {
	int dia;
	int mes;
	int ano;
} data;

struct clientesEmp {
	char codigo[20];
	char nome[20];
	char doc[20];
	long int fat;
	data fund, alt;
	bool ativo;
} clientes[MAX];

void leDados(int tam) {
	int a;
	for (a=0;a<tam;a++) {
		printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
		printf("Insira o nome do cliente %d\n", a+1);
		fflush(stdin);
		gets(clientes[a].nome);
		printf ("Insira o código de cliente de %s\n", clientes[a].nome);
		fflush(stdin);
		gets(clientes[a].codigo);
		fflush(stdout);
		printf("Insira o documento de %s\n", clientes[a].nome);
		fflush(stdin);
		gets(clientes[a].doc);
		fflush(stdout);
		do {
			printf("Insira a data de fundação de %s no formato DD MM AAAA (1950-2020)\n", clientes[a].nome);
			fflush(stdin);
			scanf("%d %d %d", &clientes[a].fund.dia, &clientes[a].fund.mes, &clientes[a].fund.ano);
			fflush(stdout);
			getchar();
		} while ((clientes[a].fund.dia <=0 || clientes[a].fund.dia>31) || (clientes[a].fund.mes <= 0 || clientes[a].fund.mes > 12) || (clientes[a].fund.ano < 1950 || clientes[a].fund.ano >2020));
		do {
			printf("Insira a data de alteração de %s no formato DD MM AAAA (1950-2020)\n", clientes[a].nome);
			fflush(stdin);
			scanf("%d %d %d", &clientes[a].alt.dia, &clientes[a].alt.mes, &clientes[a].alt.ano);
			fflush(stdout);
			getchar();
		} while ((clientes[a].alt.dia <=0 || clientes[a].alt.dia>31) || (clientes[a].alt.mes <= 0 || clientes[a].alt.mes > 12) || (clientes[a].alt.ano < 1950 || clientes[a].alt.ano >2020) && clientes[a].alt.ano>=clientes[a].fund.ano);
		printf("Insira o valor do faturamento de %s, apenas números\n", clientes[a].nome);
		fflush(stdin);
		scanf ("%ld", &clientes[a].fat);
		getchar();
		fflush(stdout);
		clientes[a].ativo = true;
	}
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
}

void mostrarDados(int tam, int a) {
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	printf("Nome do cliente: %s     ", clientes[a].nome);printf ("Código de %s: %s\n", clientes[a].nome, clientes[a].codigo);
	printf("Faturamento de %s: R$%d     ", clientes[a].nome, clientes[a].fat);printf ("Documento de %s: %s\n", clientes[a].nome, clientes[a].doc);
	if (clientes[a].fund.dia < 10 && clientes[a].fund.mes < 10) {
		printf("Data de fundação de %s: 0%d/0%d/%d", clientes[a].nome, clientes[a].fund.dia, clientes[a].fund.mes, clientes[a].fund.ano);
	}
	else if (clientes[a].fund.dia < 10) {
		printf("Data de fundação de %s: 0%d/%d/%d", clientes[a].nome, clientes[a].fund.dia, clientes[a].fund.mes, clientes[a].fund.ano);
	}
	else if (clientes[a].fund.mes < 10) {
		printf("Data de fundação de %s: %d/0%d/%d", clientes[a].nome, clientes[a].fund.dia, clientes[a].fund.mes, clientes[a].fund.ano);
	}
	else {
		printf("Data de fundação de %s: %d/%d/%d", clientes[a].nome, clientes[a].fund.dia, clientes[a].fund.mes, clientes[a].fund.ano);
	}
	if (clientes[a].alt.dia < 10 && clientes[a].alt.mes < 10) {
		printf("     Data de alteração de %s: 0%d/0%d/%d\n", clientes[a].nome, clientes[a].alt.dia, clientes[a].alt.mes, clientes[a].alt.ano);
	}
	else if (clientes[a].alt.dia < 10) {
		printf("     Data de alteração de %s: 0%d/%d/%d\n", clientes[a].nome, clientes[a].alt.dia, clientes[a].alt.mes, clientes[a].alt.ano);
	}
	else if (clientes[a].alt.mes < 10) {
		printf("     Data de alteração de %s: %d/0%d/%d\n", clientes[a].nome, clientes[a].alt.dia, clientes[a].alt.mes, clientes[a].alt.ano);
	}
	else {
		printf("     Data de alteração de %s: %d/%d/%d\n", clientes[a].nome, clientes[a].alt.dia, clientes[a].alt.mes, clientes[a].alt.ano);
	}
}

void ordenarData(int tam, int a, int b) {
	int auxDiaalt, auxMesalt, auxAnoalt, auxDiafund, auxMesfund, auxAnofund, dia, mes, ano, fat;
	char copiaNome[20], copiaDoc[20], copiaCod[20];
	long long int auxFat;
	// Ano Data Alt
	auxAnoalt = clientes[a].alt.ano;
	clientes[a].alt.ano = clientes[b].alt.ano;
	clientes[b].alt.ano = auxAnoalt;
	// Faturamento
	auxFat = clientes[a].fat;
	clientes[a].fat = clientes[b].fat;
	clientes[b].fat = auxFat;
	// Código
	strcpy(copiaCod, clientes[a].codigo);
	strcpy(clientes[a].codigo, clientes[b].codigo);
	strcpy(clientes[b].codigo, copiaCod);
	// Nome
	strcpy (copiaNome, clientes[a].nome);
	strcpy(clientes[a].nome, clientes[b].nome);
	strcpy(clientes[b].nome, copiaNome);
	// Documento
	strcpy(copiaDoc, clientes[a].doc);
	strcpy(clientes[a].doc, clientes[b].doc);
	strcpy(clientes[b].doc, copiaDoc);
	// Dia Data Alt
	auxDiaalt = clientes[a].alt.dia;
	clientes[a].alt.dia = clientes[b].alt.dia;
	clientes[b].alt.dia = auxDiaalt;
	// Mes Data Alt
	auxMesalt = clientes[a].alt.mes;
	clientes[a].alt.mes = clientes[b].alt.mes;
	clientes[b].alt.mes = auxMesalt;
	// Ano Data Fund
	auxAnofund = clientes[a].fund.ano;
	clientes[a].fund.ano = clientes[b].fund.ano;
	clientes[b].fund.ano = auxAnofund;
	// Mes Data Fund
	auxMesfund = clientes[a].fund.mes;
	clientes[a].fund.mes = clientes[b].fund.mes;
	clientes[b].fund.mes = auxMesfund;
	// Dia Data Fund
	auxDiafund = clientes[a].fund.dia;
	clientes[a].fund.dia = clientes[b].fund.dia;
	clientes[b].fund.dia = auxDiafund;
}

void ordemTam(int tam) {
	system("cls");
	int a, b;
	for (a=0;a<(tam-1);a++) {
		for(b=a+1;b<tam;b++) {
			if (clientes[a].fat<clientes[b].fat) {
				ordenarData(tam, a, b);
			}
		}
	}
	for(a=0;a<10;a++) {
		if (tam==a) {
			break;
		}
		mostrarDados(tam, a);
	}
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	system("pause");
}

void ordenaMostraPiso(int tam) {
	int a, b, dia, mes, ano; 
	long int fat;
	system("cls");
	do {
		printf("Insira a data de fundação que deseja procurar no formato DD MM AAAA (1950-2020)\n");
		scanf ("%d %d %d", &dia, &mes, &ano);
	} while ((dia <=0 || dia>31) || (mes <= 0 || mes > 12) || (ano < 1950 || ano >2020));
	printf("Agora insira o piso de faturamento que deseja buscar\n"); scanf ("%ld", &fat);
	for (a=0;a<(tam-1);a++) {
		for (b=a+1;b<tam;b++) {
			if(clientes[a].alt.ano<clientes[b].alt.ano) {
				ordenarData(tam, a, b);
			}
			else if(clientes[a].alt.ano==clientes[b].alt.ano) {
				if(clientes[a].alt.mes<clientes[b].alt.mes) {
					ordenarData(tam, a, b);
				}
				else if(clientes[a].alt.mes==clientes[b].alt.mes) {
					if(clientes[a].alt.dia<clientes[b].alt.dia) {
						ordenarData(tam, a, b);
					}
				}
			}
		}
	}
	system("cls");
	for(a=0;a<tam;a++) {
		if(clientes[a].fund.ano>ano && clientes[a].fat>=fat) {
			mostrarDados(tam, a);
		}
		else if(clientes[a].fund.ano==ano) {
			if(clientes[a].fund.mes==mes) {
				if(clientes[a].fund.dia>=dia && clientes[a].fat>=fat) {
					mostrarDados(tam, a);
				}
				else {
					
				}
			}
			else if(clientes[a].fund.mes>mes && clientes[a].fat>=fat) {
				mostrarDados(tam, a);
			}
			else if(clientes[a].fund.mes<mes) {
				
			}
		}
		else if(clientes[a].fund.ano<ano) {
			
		}
	}
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	system("pause");
}

void menuRep(int tam) {
	int op, opRep;
	system("cls");
	do {
		printf("Você deseja:\n1-Inserir a data de fundação e o valor do faturamento e retorná-los em ordem de data de alteração\n2-Retornar os 10 maiores faturamentos entre clientes\nSua opção: ");
		scanf("%d", &op);
	} while (op<1 || op>2);
	if (op==1) {
		ordenaMostraPiso(tam);
		system("cls");
		do {
		printf("Você deseja reutilizar o programa com os dados inseridos ou deseja inserir outros?\n1-Reutilizar com os mesmos dados\n2-Reutilizar com novos dados\n3-Sair\nSua opção: ");
		scanf("%d", &opRep);
		} while(opRep<0&&opRep>3);
		if (opRep==1) {
			menuRep(tam);
		}
		if (opRep==2) {
			main();
		}
		else {
			system("cls");
			printf("Obrigado por utilizar o programa!\nDesenvolvido por Hugo Esteves\n");
			system("exit");
		}
	}
	if (op==2) {
		ordemTam(tam);
		system("cls");
		do {
		printf("Você deseja reutilizar o programa com os dados inseridos ou deseja inserir outros?\n1-Reutilizar com os mesmos dados\n2-Reutilizar com novos dados\n3-Sair\nSua opção: ");
		scanf("%d", &opRep);
		} while(opRep<0&&opRep>3);
		if (opRep==1) {
			menuRep(tam);
		}
		if (opRep==2) {
			main();
		}
		else {
			system("exit");
		}
	}
}

void menu() {
	int tam, op, opRep;
	system("cls");
	do {
		printf("Quantos clientes você deseja cadastrar?(MAX 50)\n");
		fflush(stdin);
		scanf("%d", &tam);
		fflush(stdout);
		getchar();
		system("cls");
	} while (tam<=0 || tam >50);
	leDados(tam);
	system("cls");
	do {
		printf("Você deseja:\n1-Inserir a data de fundação e o valor do faturamento e retorná-los em ordem de data de alteração\n2-Retornar os 10 maiores faturamentos entre clientes\nSua opção: ");
		scanf("%d", &op);
	} while (op<1 || op>2);
	if (op==1) {
		ordenaMostraPiso(tam);
		system("cls");
		do {
		printf("Você deseja reutilizar o programa com os dados inseridos ou deseja inserir outros?\n1-Reutilizar com os mesmos dados\n2-Reutilizar com novos dados\n3-Sair\nSua opção: ");
		scanf("%d", &opRep);
		} while(opRep<0&&opRep>3);
		if (opRep==1) {
			menuRep(tam);
		}
		if (opRep==2) {
			main();
		}
		else {
			system("cls");
			printf("Obrigado por utilizar o programa!\nDesenvolvido por Hugo Esteves\n");
			system("exit");
		}
	}
	if (op==2) {
		ordemTam(tam);
		system("cls");
		do {
		printf("Você deseja reutilizar o programa com os dados inseridos ou deseja inserir outros?\n1-Reutilizar com os mesmos dados\n2-Reutilizar com novos dados\n3-Sair\nSua opção: ");
		scanf("%d", &opRep);
		} while(opRep<0&&opRep>3);
		if (opRep==1) {
			menuRep(tam);
		}
		if (opRep==2) {
			main();
		}
		else {
			system("exit");
		}
	}
}

int main () {
	setlocale(LC_ALL, "Portuguese");
	menu();
}
