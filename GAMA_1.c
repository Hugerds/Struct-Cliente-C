#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>

#define MAX 50

typedef struct {
	int dia;
	int mes;
	int ano;
} data;

struct clientesEmp {
	int codigo;
	char nome[20];
	char doc[20];
	int fat;
	data fund, alt;
	bool ativo;
} clientes[MAX];

/*Crie uma função que receba a data de fundação e o valor do faturamento,
retorne todos os clientes ativos ordenados por data de alteração onde a data de
fundação e o faturamento sejam maiores ou iguais aos enviados por parâmetro. */

void leDados(tam) {
	printf("%d\n", tam);
	int a;
	for (a=0;a<tam;a++) {
		printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
		printf("Insira o nome do cliente\n");
		fflush(stdin);
		gets(clientes[a].nome);
		printf ("Insira o código de cliente de %s\n", clientes[a].nome);
		fflush(stdin);
		scanf("%d", &clientes[a].codigo);
		fflush(stdout);
		printf("Insira o documento de %s\n", clientes[a].nome);
		fflush(stdin);
		gets(clientes[a].doc);
		fflush(stdout);
		do {
			printf("Insira a data de fundação de %s(No formato DD MM AAAA)\n", clientes[a].nome);
			fflush(stdin);
			scanf("%d %d %d", &clientes[a].fund.dia, &clientes[a].fund.mes, &clientes[a].fund.ano);
			fflush(stdout);
			getchar();
		} while ((clientes[a].fund.dia <=0 || clientes[a].fund.dia>31) || (clientes[a].fund.mes <= 0 || clientes[a].fund.mes > 12) || (clientes[a].fund.ano < 1950 || clientes[a].fund.ano >2020));
		do {
			printf("Insira a data de alteração de %s(No formato DD MM AAAA)\n", clientes[a].nome);
			fflush(stdin);
			scanf("%d %d %d", &clientes[a].alt.dia, &clientes[a].alt.mes, &clientes[a].alt.ano);
			fflush(stdout);
			getchar();
		} while ((clientes[a].alt.dia <=0 || clientes[a].alt.dia>31) || (clientes[a].alt.mes <= 0 || clientes[a].alt.mes > 12) || (clientes[a].alt.ano < 1950 || clientes[a].alt.ano >2020));
		printf("Insira o valor do faturamento de %s, apenas números\n", clientes[a].nome);
		fflush(stdin);
		scanf ("%d", &clientes[a].fat);
		fflush(stdout);
		clientes[a].ativo = true;
	}
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
}

/*
void a(tam) {
	int a, b, dia, mes, ano, cod, i, j, c, d, e, f, g, h, k, l;
	long long int diaMin, mesMin, anoMin, auxDia, auxMes, auxAno;
	system("cls");
	do {
		printf("Insira a data de fundação que deseja procurar no formado DD MM AAAA\n");
		scanf ("%d %d %d", &dia, &mes, &ano);
	} while ((dia <=0 || dia>31) || (mes <= 0 || mes > 12) || (ano < 1950 || ano >2020));
	printf("Agora insira o código que deseja buscar\n"); scanf ("%d", &cod);
	// */ /*
	for (a=0;a<(tam-1);a++) {
		for(b=a+1;b<tam;b++) {
			diaMin = clientes[a].alt.dia*1440; mesMin = clientes[a].alt.mes*43800; anoMin = clientes[a].alt.ano*525600;
			if (clientes[a].alt.ano==clientes[b].alt.ano) {
				for (j=0;j<(tam-1);j++) {
					for (i=j+1;i<tam;i++) {
						if (clientes[j].alt.ano>clientes[i].alt.ano) {
							auxAno = clientes[j].alt.ano;
							clientes[j].alt.ano = clientes[i].alt.ano;
							clientes[i].alt.ano = auxAno;
						}
						for (c=0;c<(tam-1);c++) {
							for(d=c+1;d<tam;d++) {
								if (clientes[c].alt.mes==clientes[d].alt.mes) {
									for(e=0;e<(tam-1);e++) {
										for(f=e+1;f<tam;f++) {
											if (clientes[e].alt.mes>clientes[f].alt.mes) {
												auxMes = clientes[e].alt.ano;
												clientes[e].alt.ano = clientes[f].alt.ano;
												clientes[f].alt.ano = auxMes;
											}
											for (h=0;h<(tam-1);h++) {
												for (g=h+1;g<tam;g++) {
													if (clientes[h].alt.dia==clientes[g].alt.dia) {
														for (k=0;k<(tam-1);k++) {
															for (l=k+1;l<tam;l++) {
																if(clientes[k].alt.dia>clientes[l].alt.dia) {
																	auxDia = clientes[e].alt.ano;
																	clientes[e].alt.ano = clientes[f].alt.ano;
																	clientes[f].alt.ano = auxDia;
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	mostrarDados(tam);
}
*/

void a(tam) {
	system("cls");
	int a, b, auxDiaalt, auxMesalt, auxAnoalt, auxDiafund, auxMesfund, auxAnofund;
	char copiaNome[20], copiaDoc[20];
	long long int auxCodigo, auxFat;
	for (a=0;a<(tam-1);a++) {
		for (b=a+1;b<tam;b++) {
			
		}
	}
}

void ordemTam(tam) {
	/*Crie uma função que receba uma lista de clientes e retorne os 10 maiores
	faturamentos.*/
	system("cls");
	int a, b, auxDiaalt, auxMesalt, auxAnoalt, auxDiafund, auxMesfund, auxAnofund;
	char copiaNome[20], copiaDoc[20];
	long long int auxCodigo, auxFat;
	for (a=0;a<(tam-1);a++) {
		for(b=a+1;b<tam;b++) {
			if (clientes[a].fat<clientes[b].fat) {
				// Faturamento
				auxFat = clientes[a].fat;
				clientes[a].fat = clientes[b].fat;
				clientes[b].fat = auxFat;
				// Código
				auxCodigo = clientes[a].codigo;
				clientes[a].codigo = clientes[b].codigo;
				clientes[b].codigo = auxCodigo;
				// Nome
				strcpy (copiaNome, clientes[a].nome);
        		strcpy(clientes[a].nome, clientes[b].nome);
        		strcpy(clientes[b].nome, copiaNome);
        		// Documento
        		strcpy (copiaDoc, clientes[a].doc);
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
				// Ano Data Alt
				auxAnoalt = clientes[a].alt.ano;
				clientes[a].alt.ano = clientes[b].alt.ano;
				clientes[b].alt.ano = auxDiaalt;
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
		}
	}
	for(a=0;a<10;a++) {
		if (tam==a) {
			break;
		}
		printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
		printf("Nome do cliente: %s", clientes[a].nome); printf("	"); printf ("Código de %s: %d\n", clientes[a].nome, clientes[a].codigo);
		printf("Faturamento de %s: R$%d", clientes[a].nome, clientes[a].fat); printf("	"); printf ("Documento de %s: %s\n", clientes[a].nome, clientes[a].doc);
		if (clientes[a].fund.dia < 10) {
			printf("Data de fundação de %s: 0%d/%d/%d	", clientes[a].nome, clientes[a].fund.dia, clientes[a].fund.mes, clientes[a].fund.ano);
		}
		else if (clientes[a].fund.mes < 10) {
			printf("Data de fundação de %s: %d/0%d/%d	", clientes[a].nome, clientes[a].fund.dia, clientes[a].fund.mes, clientes[a].fund.ano);
		}
		else if (clientes[a].fund.mes < 10 && clientes[a].fund.dia < 10) {
			printf("Data de fundação de %s: 0%d/0%d/%d	", clientes[a].nome, clientes[a].fund.dia, clientes[a].fund.mes, clientes[a].fund.ano);
		}
		else {
			printf("Data de fundação de %s: %d/%d/%d	", clientes[a].nome, clientes[a].fund.dia, clientes[a].fund.mes, clientes[a].fund.ano);
		}
		if (clientes[a].alt.dia < 10) {
			printf("Data de alteração de %s: 0%d/%d/%d\n", clientes[a].nome, clientes[a].alt.dia, clientes[a].alt.mes, clientes[a].alt.ano);
		}
		else if (clientes[a].alt.mes < 10) {
			printf("Data de alteração de %s: %d/0%d/%d\n", clientes[a].nome, clientes[a].alt.dia, clientes[a].alt.mes, clientes[a].alt.ano);
		}
		else if (clientes[a].alt.mes < 10 && clientes[a].alt.dia < 10) {
			printf("Data de alteração de %s: 0%d/0%d/%d\n", clientes[a].nome, clientes[a].alt.dia, clientes[a].alt.mes, clientes[a].alt.ano);
		}
		else {
			printf("Data de alteração de %s: %d/%d/%d\n", clientes[a].nome, clientes[a].alt.dia, clientes[a].alt.mes, clientes[a].alt.ano);
		}
	}
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
}

void menu() {
	int tam, op;
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
		printf("Você deseja:\n1-Inserir a data de fundação e o valor do faturamento e retorná-los em ordem\n2-Retornar os 10 maiores faturamentos entre clientes\nSua opção: ");
		scanf("%d", &op);
	} while (op<1 || op>2);
	if (op==1) {
		a(tam);
	}
	if (op==2) {
		ordemTam(tam);
	}
}

int main () {
	setlocale(LC_ALL, "Portuguese");
	menu();
}


