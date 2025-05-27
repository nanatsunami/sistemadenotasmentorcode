//Biblioteca que permite usar printf/scanf
#include <stdio.h> 
//Biblioteca para lidar com strings 
#include <string.h>
//Biblioteca que permite caracteres especiais
#include <locale.h>
//Biblioteca para usar system
#include <stdlib.h>


//Definindo o número máximo de alunos permitidos
#define maxAlunos 100

struct Aluno {
	char nome[50];
	int rgm;
	float a1;
	float a2;
	float af;
	float resultado;
	//Variável que recebe 1 (fez AF) ou 0 (não precisou fazer AF)
	int fezAF;
};

int main () {
	//Comando para permitir caracteres especiais
	setlocale(LC_ALL, "Portuguese");
	
	//Criando vetor chamado alunos que armazena MAX_ALUNOS (que foi definido que é 100) de struct Aluno
	struct Aluno alunos[maxAlunos];
	
	//Variável que armazena a quantidade de alunos cadastrados e é inicializada com 0
	int totalAlunos = 0;
	
	//Vetor de char com 20 posições, foi guardado como texto pois não serão feitas operações matemáticas com o RGM
	char buffer[20];
	
	//Variável que recebe a opção escolhida no CRUD
	int opcao;
	
	//Variável que recebe o curso escolhido
	char curso[50];
	//Variável que recebe o período definido
    char periodo[20];

	
	//Menu inicial
	printf("================================================================================\n");
	printf("|                       SISTEMA DE NOTAS - MENTORCODE                          |\n");
	printf("|                     Conectando mentes, guiando futuros.                      |\n");
	printf("|                                                                              |\n");
	printf("|   Condições para calcular a nota final:                                      |\n");
    printf("|    -Nota final: maior que 6 = aprovado                                       |\n");
    printf("|    -Nota final: menor que 6 = fazer a AF                                     |\n");
    printf("|    -Se a nota final, mesmo depois da AF for: menor que 6 = reprovado         |\n");
	printf("|                                                                              |\n");
	printf("================================================================================\n");
	
    // Solicita o curso e período atual
    printf("Insira o curso: ");
    fgets(curso, sizeof(curso), stdin);

    printf("Insira o período: ");
    fgets(periodo, sizeof(periodo), stdin);
    
    system("cls");
    

	//Laço de repetição (menu) que continua até o usuário escolher sair (opção 5)
	do {    	
		//Menu inicial
		printf("================================================================================\n");
		printf("|                       SISTEMA DE NOTAS - MENTORCODE                          |\n");
		printf("|                     Conectando mentes, guiando futuros.                      |\n");
		printf("|                                                                              |\n");
		printf("|   Condicoes para calcular a nota final:                                      |\n");
	    printf("|    -Nota final: maior que 6 = aprovado                                       |\n");
	    printf("|    -Nota final: menor que 6 = fazer a AF                                     |\n");
	    printf("|    -Se a nota final, mesmo depois da AF for: menor que 6 = reprovado         |\n");
		printf("|                                                                              |\n");
		printf("================================================================================\n");
	    printf("Curso: %s",curso);
		printf("Período: %s",periodo);
		
		//Mostra as opções
		printf("\n1. Cadastrar aluno\n");
		printf("2. Listar alunos\n");
		printf("3. Editar registros\n");
		printf("4. Remover aluno\n");
		printf("5. Sair\n");
		
		printf("\nEscolha uma opção:\n");
		// Lê o que o usuário digitou como texto
		fgets(buffer, sizeof(buffer), stdin);
		
		// Converte o texto para um número inteiro
		sscanf(buffer, "%d", &opcao);

		switch (opcao) {
			//Opção 1 - Cadastrar aluno
			case 1: {
				//Verifica se o número de alunos cadastrados é menor que 100
				if (totalAlunos < maxAlunos) {
					//Criando uma variável pra verificar se o RGM já foi cadastrado (1) ou não (0)
					int rgmCadastrado = 0;
					
					//Mostra o número do aluno que está sendo cadastrado (posição +1, já que vetor começa no 0)
					printf("\nAluno %d\n", totalAlunos + 1);
					
					printf("Nome do aluno:");
					//fgets consegue ler o nome do aluno incluindo espaço 
					fgets(alunos[totalAlunos].nome, sizeof(alunos[totalAlunos].nome), stdin);
					
					//Remove o caractere \n do final da string lida com fgets.
					//strcspn retorna a posição de \n, e substituímos por \0 (fim da string).
					//evita quebra de linha desnecessária ao imprimir o nome depois.
					//alunos[totalAlunos].nome[strcspn(alunos[totalAlunos].nome, "\n")] = 0;

					printf("RGM:");
					fgets(buffer, sizeof(buffer), stdin);
					sscanf(buffer,"%d", &alunos[totalAlunos].rgm);
					
					//Verificando se o RGM inserido já existe
					for (int i = 0; i < totalAlunos; i++) {
			            if (alunos[i].rgm == alunos[totalAlunos].rgm) {
			                rgmCadastrado = 1;
			                break;
			            }
			        }
			        //Se o RGM já foi cadastrado, fecha o cadastro
			        if (rgmCadastrado) {
			            printf("Erro: RGM %d já cadastrado.\n", alunos[totalAlunos].rgm);
			            system("pause");
                		system("cls");
						break; 
			        }

					//Recebe a nota A1 usando fgets mas converte para int
					printf("Digite a nota de A1 (0 a 5):");
					fgets(buffer, sizeof(buffer), stdin);
					sscanf(buffer, "%f", &alunos[totalAlunos].a1);
					
					//Só permite receber a nota entre 0 e 5
					while (alunos[totalAlunos].a1 < 0 || alunos[totalAlunos].a1 > 5) {
						printf("Nota inválida. Digite a nota de A1 (0 a 5):");
						fgets(buffer, sizeof(buffer), stdin);
						sscanf(buffer, "%f", &alunos[totalAlunos].a1);
					}
					printf("Digite a nota de A2 (0 a 5): ");
			        fgets(buffer, sizeof(buffer), stdin);
			        sscanf(buffer, "%f", &alunos[totalAlunos].a2);
			
			        while (alunos[totalAlunos].a2 < 0 || alunos[totalAlunos].a2 > 5) {
			            printf("Nota inválida. Digite a nota de A2 (0 a 5): ");
			            fgets(buffer, sizeof(buffer), stdin);
			            sscanf(buffer, "%f", &alunos[totalAlunos].a2);
			        }
			        
			        //resultado recebe a1+a2
			        alunos[totalAlunos].resultado = alunos[totalAlunos].a1 + alunos[totalAlunos].a2;
					
					//Se o resultado for suficiente, mostra que o aluno está aprovado
					if (alunos[totalAlunos].resultado >= 6) {
		            	printf("Nota final: %.1f + %.1f = %.1f. Aluno aprovado!\n", alunos[totalAlunos].a1, alunos[totalAlunos].a2, alunos[totalAlunos].resultado);
		            	// Não precisou da AF
						alunos[totalAlunos].fezAF = 0; 
					//Precisou fazer AF
        			} else {
						printf("Nota final: %.1f + %.1f = %.1f (Fazer a AF)\n", alunos[totalAlunos].a1, alunos[totalAlunos].a2, alunos[totalAlunos].resultado);
			            printf("Digite a nota da AF (0 a 5): ");
			            fgets(buffer, sizeof(buffer), stdin);
			            sscanf(buffer, "%f", &alunos[totalAlunos].af);
			            alunos[totalAlunos].fezAF = 1;
						//Só permite receber nota de 0 a 5
			            while (alunos[totalAlunos].af < 0 || alunos[totalAlunos].af > 5) {
			                printf("Nota inválida. Digite a nota de AF (0 a 5): ");
			                fgets(buffer, sizeof(buffer), stdin);
			                sscanf(buffer, "%f", &alunos[totalAlunos].af);
			            }
			            
			            //"substitui" a menor nota pela af
			          	if (alunos[totalAlunos].a1 < alunos[totalAlunos].a2) {
					    	alunos[totalAlunos].resultado = alunos[totalAlunos].af + alunos[totalAlunos].a2;
					    	printf("Nota final (A1->AF): %.1f + %.1f = %.1f. ", alunos[totalAlunos].af, alunos[totalAlunos].a2, alunos[totalAlunos].resultado);
						} else {
						    alunos[totalAlunos].resultado = alunos[totalAlunos].a1 + alunos[totalAlunos].af;
						    printf("Nota final (A1->AF): %.1f + %.1f = %.1f. ", alunos[totalAlunos].a1, alunos[totalAlunos].af, alunos[totalAlunos].resultado);
						}
						
						if (alunos[totalAlunos].resultado >= 6) {
						    printf("Aprovado!\n");
						} else {
						    printf("Reprovado.\n");
						}
					}
                    totalAlunos++;
                    printf("Aluno cadastrado com sucesso!\n");
                } else {
                    printf("Limite de alunos atingido.\n");
                }
                system("pause");
                system("cls");
                break;
			}
			//Opção 2 - Listar alunos
			case 2: {
                printf("\n=== RESUMO DA TURMA ===\n");
                printf("Curso: %s", curso);
                printf("Período: %s\n", periodo);
                printf("Total de alunos registrados: %d\n", totalAlunos);
				for (int j = 0; j < totalAlunos; j++) {
				        float resultado = alunos[j].a1 + alunos[j].a2;

						if (alunos[j].fezAF == 1) {
							if (alunos[j].a1 < alunos[j].a2) {
								resultado = alunos[j].af + alunos[j].a2;
							} else {
								resultado = alunos[j].a1 + alunos[j].af;
							}
						}
				
				        printf("\nAluno %d:\n", j + 1);
				        printf("Nome: %s", alunos[j].nome);
				        printf("RGM: %d\n", alunos[j].rgm);
				        //%.1f para que as notas sejam exibidas com 1 casa decimal
				        printf("Nota A1: %.1f\n", alunos[j].a1);
				        printf("Nota A2: %.1f\n", alunos[j].a2);
				
				        if (alunos[j].fezAF == 1) {
				            printf("Nota AF: %.1f\n", alunos[j].af);
				        } else {
				            printf("Nota AF: Não se aplica\n");
				        }
				
				        printf("Resultado Final: %.1f\n", resultado);
				
				        if (resultado >= 6.0) {
				            printf("Situação: Aprovado\n");
				        } else {
				            printf("Situação: Reprovado\n");
				        }
				    }
				system("pause");
				//Limpa a tela
				system("cls"); 
				break;
			}
			//Opção 3 - Editar registros
			case 3: {
			    printf("Digite o RGM do aluno a ser atualizado: ");
			    fgets(buffer, sizeof(buffer), stdin);
			    //Variável que vai servir pra localizaro o aluno no vetor
			    int rgmAtualizar;
			    sscanf(buffer, "%d", &rgmAtualizar);
			    //Variável que recebe se o aluno com aquele RGM existe ou não, inicia com 0 porque o usuário ainda não inseriu o RGM
			    int encontrado = 0;
				
				//Verifica todos os alunos cadastrados
			    for (int j = 0; j < totalAlunos; j++) {
			    	//Se o RGM digitado for igual a de algum aluno, permitirá a edição
			        if (alunos[j].rgm == rgmAtualizar) {
			        	//Recebe 1 pois foi encontrado
			            encontrado = 1;
			            
			            //Variável que vai receber a escolha do switch
			            int opcaoEditar;
			            //O do while serve pra repetir o menu enquanto o usuário não escolher sair, permite editar quantas coisas ele quiser sem ter que inserir o RGM novamente
			            do {
			                printf("\nEditar:\n");
			                printf("1. Nome\n");
			                printf("2. RGM\n");
			                printf("3. Nota A1\n");
			                printf("4. Nota A2\n");
			                printf("5. Nota AF\n");
			                printf("6. Sair\n");
			                printf("\nEscolha uma opção: ");
			                fgets(buffer, sizeof(buffer), stdin);
			                sscanf(buffer, "%d", &opcaoEditar);
			
			                switch (opcaoEditar) {
			                    case 1:
			                        printf("Novo nome: ");
			                        fgets(alunos[j].nome, sizeof(alunos[j].nome), stdin);
//			                        alunos[j].nome[strcspn(alunos[j].nome, "\n")] = 0;
			                        break;
			                    case 2:
			                        printf("Novo RGM: ");
			                        fgets(buffer, sizeof(buffer), stdin);
			                        sscanf(buffer, "%s", &alunos[j].rgm);
			                        break;
								case 3:
									printf("Nota atual de A1: %.1f\n", alunos[j].a1);
								    printf("Nova nota A1 (0 a 5): ");
								    fgets(buffer, sizeof(buffer), stdin);
								    sscanf(buffer, "%f", &alunos[j].a1);
								    while (alunos[j].a1 < 0 || alunos[j].a1 > 5) {
								        printf("Nota inválida. Digite a nota de A1 (0 a 5): ");
								        fgets(buffer, sizeof(buffer), stdin);
								        sscanf(buffer, "%f", &alunos[j].a1);
								    }
								
								    // Recalcular nota final
								    alunos[j].resultado = alunos[j].a1 + alunos[j].a2;
								
								    // Verificar se precisa de AF
								    if (alunos[j].resultado < 6) {
								        if (alunos[j].fezAF == 0) {
								            // Precisa de AF pela primeira vez
								            printf("Nota final: %.1f + %.1f = %.1f (Fazer AF)\n", 
								                  alunos[j].a1, alunos[j].a2, alunos[j].resultado);
								            
								            printf("Digite a nota da AF (0 a 5): ");
								            fgets(buffer, sizeof(buffer), stdin);
								            sscanf(buffer, "%f", &alunos[j].af);
								            while (alunos[j].af < 0 || alunos[j].af > 5) {
								                printf("Nota inválida. Digite AF (0 a 5): ");
								                fgets(buffer, sizeof(buffer), stdin);
								                sscanf(buffer, "%f", &alunos[j].af);
								            }
								
								            //"substitui" a menor nota pela af
								          	if (alunos[j].a1 < alunos[j].a2) {
										    	alunos[j].resultado = alunos[j].af + alunos[j].a2;
										    	printf("Nota final (A1->AF): %.1f + %.1f = %.1f. ", alunos[j].af, alunos[j].a2, alunos[j].resultado);
											} else {
											    alunos[j].resultado = alunos[j].a1 + alunos[j].af;
											    printf("Nota final (A1->AF): %.1f + %.1f = %.1f. ", alunos[j].a1, alunos[j].af, alunos[j].resultado);
											}
								            
								            // Verifica aprovação
								            if (alunos[j].resultado >= 6) {
								                printf("Aprovado!\n");
								            } else {
								                printf("Reprovado.\n");
								            }
								            alunos[j].fezAF = 1;
								        } else {
								            // Já tem AF - recalcula com AF existente
								            if (alunos[j].a1 < alunos[j].a2) {
								                alunos[j].resultado = alunos[j].af + alunos[j].a2;
								            } else {
								                alunos[j].resultado = alunos[j].a1 + alunos[j].af;
								            }
								            printf("Nota final recalculada: %.1f\n", alunos[j].resultado);
								        }
								    } else {
								        // Não precisa de AF
								        printf("Nota final: %.1f + %.1f = %.1f. Aprovado!\n",
								              alunos[j].a1, alunos[j].a2, alunos[j].resultado);
								        alunos[j].fezAF = 0;
								    }
								    break;
									case 4:
										printf("Nota atual de A2: %.1f\n", alunos[j].a2);
									    printf("Nova nota A2 (0 a 5): ");
									    fgets(buffer, sizeof(buffer), stdin);
									    sscanf(buffer, "%f", &alunos[j].a2);
									    while (alunos[j].a2 < 0 || alunos[j].a2 > 5) {
									        printf("Nota inválida. Digite a nota de A2 (0 a 5): ");
									        fgets(buffer, sizeof(buffer), stdin);
									        sscanf(buffer, "%f", &alunos[j].a2);
									    }
									
									    // Recalcular nota final
									    alunos[j].resultado = alunos[j].a1 + alunos[j].a2;
									
									    // Verificar se precisa de AF
									    if (alunos[j].resultado < 6) {
									        if (alunos[j].fezAF == 0) {
									            // Precisa de AF pela primeira vez
									            printf("Nota final: %.1f + %.1f = %.1f (Fazer AF)\n", 
									                  alunos[j].a1, alunos[j].a2, alunos[j].resultado);
									            
									            printf("Digite a nota da AF (0 a 5): ");
									            fgets(buffer, sizeof(buffer), stdin);
									            sscanf(buffer, "%f", &alunos[j].af);
									            while (alunos[j].af < 0 || alunos[j].af > 5) {
									                printf("Nota inválida. Digite AF (0 a 5): ");
									                fgets(buffer, sizeof(buffer), stdin);
									                sscanf(buffer, "%f", &alunos[j].af);
									            }
									
									            // Substitui a menor nota (A1 ou A2) pela AF
									            if (alunos[j].a1 < alunos[j].a2) {
									                alunos[j].resultado = alunos[j].af + alunos[j].a2;
									                printf("Nota final (A1->AF): %.1f + %.1f = %.1f. ",
									                      alunos[j].af, alunos[j].a2, alunos[j].resultado);
									            } else {
									                alunos[j].resultado = alunos[j].a1 + alunos[j].af;
									                printf("Nota final (A2->AF): %.1f + %.1f = %.1f. ",
									                      alunos[j].a1, alunos[j].af, alunos[j].resultado);
									            }
									            
									            // Verifica aprovação
									            if (alunos[j].resultado >= 6) {
									                printf("Aprovado!\n");
									            } else {
									                printf("Reprovado.\n");
									            }
									            alunos[j].fezAF = 1;
									        } else {
									            // Já tem AF - recalcula com AF existente
									            if (alunos[j].a1 < alunos[j].a2) {
									                alunos[j].resultado = alunos[j].af + alunos[j].a2;
									            } else {
									                alunos[j].resultado = alunos[j].a1 + alunos[j].af;
									            }
									            printf("Nota final recalculada: %.1f\n", alunos[j].resultado);
									        }
									    } else {
									        // Não precisa de AF
									        printf("Nota final: %.1f + %.1f = %.1f. Aprovado!\n",
									              alunos[j].a1, alunos[j].a2, alunos[j].resultado);
									        alunos[j].fezAF = 0;
									    }
									    break;
									case 5:
										printf("Nota atual de AF: %.1f\n", alunos[j].af);
									    printf("Nova nota AF (0 a 5): ");
									    fgets(buffer, sizeof(buffer), stdin);
									    sscanf(buffer, "%f", &alunos[j].af);
									    while (alunos[j].af < 0 || alunos[j].af > 5) {
									        printf("Nota inválida. Digite AF (0 a 5): ");
									        fgets(buffer, sizeof(buffer), stdin);
									        sscanf(buffer, "%f", &alunos[j].af);
									    }			    
									    // Verifica qual nota substituir (sempre a menor entre A1 e A2)
									    if (alunos[j].a1 < alunos[j].a2) {
									        alunos[j].resultado = alunos[j].af + alunos[j].a2;
									        printf("Substituindo A1 (%.1f) por AF (%.1f). \n", alunos[j].a1, alunos[j].af);
									        printf("Nota final: %.1f + %.1f = %.1f. ", alunos[j].a1,alunos[j].af,alunos[j].resultado);
									    } else {
									        alunos[j].resultado = alunos[j].a1 + alunos[j].af;
									        printf("Substituindo A2 (%.1f) por AF (%.1f). \n", alunos[j].a2, alunos[j].af);
									        printf("Nota final: %.1f + %.1f = %.1f. ", alunos[j].a2, alunos[j].af,alunos[j].resultado);
									    }
									    
									    // Mostra resultado final
									    if (alunos[j].resultado >= 6) {
									        printf("Aprovado!\n");
									    } else {
									        printf("Reprovado.\n");
									    }
									    alunos[j].fezAF = 1;
									    break;
				                    case 6:
			                        printf("Saindo da edição.\n");
					                system("pause");
					                system("cls");
			                        break;
			                    default:
			                        printf("Opção inválida.\n");
					                system("pause");
					                system("cls");
			                        break;
			                }
			
			                // Recalcular a nota final e verificar a necessidade de AF após a alteração
			                alunos[j].resultado = alunos[j].a1 + alunos[j].a2;
			
			                // Verificar se a soma das notas A1 + A2 é menor que 6
			                if (alunos[j].resultado < 6 && alunos[j].fezAF == 0) {
			                    // Substituir a menor nota entre A1 e A2 pela AF
			                    if (alunos[j].a1 < alunos[j].a2) {
			                        alunos[j].resultado = alunos[j].af + alunos[j].a2; // Substitui A1 por AF
			                    } else {
			                        alunos[j].resultado = alunos[j].a1 + alunos[j].af; // Substitui A2 por AF
			                    }
			                }
			            } while (opcaoEditar != 6);
			            break;
			        }
			    }
			
				//encontrado recebe 0 se o RGM não foi encontrado
			    if (encontrado == 0) {
			        printf("Aluno com RGM %d não encontrado.\n", rgmAtualizar);
			    }
                system("pause");
                system("cls");
			    break;
			}
			//Opção 4 - Remover Aluno
			case 4: {
				printf("Digite o RGM do aluno a ser removido: ");
				fgets(buffer, sizeof(buffer), stdin);
				//Variável que recebe o RGM que o usuário quer remover
				int rgmRemover;
				sscanf(buffer, "%d", &rgmRemover);
				//Variável que determina se o aluno foi encontrado ou não, inicia com 0 pois ainda não foi encontrado
				int encontrado = 0;
				
				//Laço de repetição que pesquisa por todos os alunos
				for (int j=0; j<totalAlunos; j++) {
					//Compara se o rgm do aluno no vetor é igual ao rgm a ser removido
					if (alunos[j].rgm == rgmRemover) {
						//Variável encontrado recebe 1 pois o aluno foi encontrado
						encontrado = 1;
						
			            // Pra remover um registro do vetor, tem um laço de repetição que vai empurrar, sobrepor a casa atual pela seguinte
			            for (int k = j; k < totalAlunos - 1; k++) {
			            	//Substitui a casa atual pela próxima
			                alunos[k] = alunos[k + 1];
			            }
			
			            // Diminui a contagem total de alunos, já que um foi "removido"
			            totalAlunos--;
			
			            // Mostra mensagem de sucesso e sai do loop
			            printf("Aluno removido com sucesso.\n");
                		system("pause");
                		system("cls");
			            break;
			        }
			    }
			    if (!encontrado) {
                    printf("Aluno com RGM %d não encontrado.\n", rgmRemover);
                }
                system("pause");
                system("cls");
                break;
            }
			//Opção 5 - Sair
			case 5: {
				printf("Encerrando o programa...\n");
				break;
			}
			default: {
				printf("Opção inválida.\n");
				system("pause");
                system("cls");
				break;
			} 	
		}
	//O menu continua aparecendo enquanto o usuário não selecionar a opção para sair
	} while (opcao != 5);
	
	return 0;
}



