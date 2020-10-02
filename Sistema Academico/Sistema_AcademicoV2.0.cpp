/******************************************************************************
SISTEMA DE CADASTRO DE ALUNOS
CRISTIANO DE SOUZA
VERSAO 1.0
28/08/2020
*******************************************************************************/
#include <iostream>
#include <locale>
#include <conio.h>
#include <time.h>

using namespace std;



int pesquisarMatricula(int matricula, int ultimoRegistro);
void mensagem(string msg, int pausa);

int main(int argc, char** argv){

    setlocale(LC_ALL,"Portuguese"); // Configura o sistema para aceitar acentuacoes em Portugues

    const int QtdMaxAluno = 00;

    int vetMatricula[QtdMaxAluno];
    string vetNome[QtdMaxAluno];
    int vetCelular[QtdMaxAluno];
    char vetSexo[QtdMaxAluno];
    bool vetMatriculado[QtdMaxAluno];
    char vetTurma[QtdMaxAluno];

    int matricula;
    bool pesquisaBemSucedida=false;
    int posicaoLocalizada=-1;

    int vetFaltas[QtdMaxAluno];
    float mtzNotas[QtdMaxAluno][4];  // linha 0 -> AV1, linha 1 -> AV2, linha 2 -> AV3, linha 3 -> mediaFinal
    float av1, av2, av3;
    float av1f, av2f, av3f;

    int menu;
    int submenu;
    int totalAlunosCadastrados=0;  // Indica a pr�xima posi��o do vetor que dever� ser preenchido, isto � a pr�xima posi��o vaga

    vetMatricula[0]=11;
    vetNome[0]="Joao";
    vetSexo[0]='M';
    vetCelular[0]=9999;
    vetMatriculado[0]=true;
    vetTurma[0]='A';
    totalAlunosCadastrados++;

    vetMatricula[1]=22;
    vetNome[1]="Maria";
    vetSexo[1]='F';
    vetCelular[1]=8888;
    vetMatriculado[1]=false;
    totalAlunosCadastrados++;

    vetMatricula[2]=33;
    vetNome[2]="Carla";
    vetSexo[2]='F';
    vetCelular[2]=7777;
    vetMatriculado[2]=false;
    totalAlunosCadastrados++;

    do{
        system("cls");
        cout << "(" << totalAlunosCadastrados << ") SISTEMA ACADEMICO\n";
        cout << "1. Alunos\n";
        cout << "2. Notas\n";
        cout << "3. Relatorios\n";
        cout << "4. Sair\n";
        cout << "   Digite uma opcao: ";
        cin >> menu;
        switch(menu){
            case 1 : {
                do{
                    system("cls");
                    cout << "ALUNOS\n";
                    cout << "1. Cadastrar alunos\n";
                    cout << "2. Alterar dados do alunos\n";
                    cout << "3. Excluir alunos\n";
                    cout << "4. Consultar dados do alunos\n";
                    cout << "5. Consultar alunos\n";
                    cout << "6. Matricular o alunos\n";
                    cout << "7. Retornar ao menu anterior\n";
                    cout << "   Escolha uma opcao: ";
                    cin >> submenu;
                    switch(submenu){
                        case 1 : {
                            cout << "CADASTRAR DADOS DO ALUNO\n\n";
                            // Permite a entrada apenas de matriculas validas, isto e, matriculas diferente de 0.
							cout << "Informe a matricula (0 p/sair): "; cin >> matricula;
							if(matricula==0){
								break;
							}
							posicaoLocalizada=pesquisarMatricula(matricula,totalAlunosCadastrados);

							// Se a pesquisa encontrou alguma matr�cula, informa que a matr�cula j� est� cadastra                            
                            if(posicaoLocalizada>=0){
                                mensagem("Matricula ja cadastrada!!!",0);
                            }else{
                            	// Caso n�o seja encontrada nenhuma matricula na pesquisa, solicita os dados do alunos
	                            vetMatricula[totalAlunosCadastrados]=matricula;
    	                        cout << "Informe o nome.....: "; cin >> vetNome[totalAlunosCadastrados];
        	                    cout << "Informe o sexo.....: "; cin >> vetSexo[totalAlunosCadastrados];
            	                cout << "Informe o celular..: "; cin >> vetCelular[totalAlunosCadastrados];
                	            vetMatriculado[totalAlunosCadastrados]=false;
                    	        totalAlunosCadastrados++;
                            }
                            break;
                        }
                        case 2 : {
                            cout << "ALTERAR DADOS DO ALUNO\n\n";
                            //digitarMatricula(matricula);
                            do{
								cout << "Informe o numero de matricula a ser pesquisada: "; cin >> matricula;
								if(matricula>1000){
									cout << "Matricula invalida!!!\n";
								}
							}while(matricula>1000);

							posicaoLocalizada=pesquisarMatricula(matricula,totalAlunosCadastrados);

                            if(posicaoLocalizada>=0){
                                cout << "Informe os novos dados para o(a) aluno(a): " << vetNome[posicaoLocalizada] << endl;
                                cout << "Informe o nome.....: "; cin >> vetNome[posicaoLocalizada];
                                cout << "Informe o sexo.....: "; cin >> vetSexo[posicaoLocalizada];
                                cout << "Informe o celular..: "; cin >> vetCelular[posicaoLocalizada];
                            }else{
                                cout << "Nao encontrei ninguem com a matricula: " << matricula << endl;
                                system("pause");
                            }
                            break;
                        }
                        case 3 : {
                            cout << "EXCLUIR DADOS DO ALUNO\n\n";
                            do{
								cout << "Informe o numero de matricula a ser pesquisada: "; cin >> matricula;
								if(matricula==0){
									cout << "Matricula invalida!!!\n";
								}
							}while(matricula==0);

							posicaoLocalizada=pesquisarMatricula(matricula,totalAlunosCadastrados);

                            if(posicaoLocalizada>=0){
								vetMatricula[posicaoLocalizada]=0;
								mensagem(vetNome[posicaoLocalizada] +" foi excluido(a)!",0);
								
                            }else{
                                mensagem("Nao encontrei ninguem com a matricula: " + matricula,0);
                            }
                            break;
                        }
                        case 4 : {
                            cout << "CONSULTAR DADOS DE UM ALUNO\n\n";
                            do{
								cout << "Informe a matricula: "; cin >> matricula;
								if(matricula==0){
									cout << "Matricula invalida!!!\n";
								}
							}while(matricula==0);
							
							posicaoLocalizada=pesquisarMatricula(matricula,totalAlunosCadastrados);

                            if(posicaoLocalizada>=0){
	                            cout << "Matricula...: " << vetMatricula[posicaoLocalizada]<<endl;
    	                        cout << "Nome........: " << vetNome[posicaoLocalizada]<<endl;
        	                    cout << "Sexo........: " << vetSexo[posicaoLocalizada]<<endl;
            	                cout << "Celular.....: " << vetCelular[posicaoLocalizada]<<endl;
                	            cout << "Matriculado?: " << ((vetMatriculado[posicaoLocalizada])? "Sim\n" : "Nao\n");
								if(vetMatriculado[posicaoLocalizada]){
									cout << "Turma.......: " << vetTurma[posicaoLocalizada] << endl;
								}
                                system("pause");
                            }else{
								mensagem("Matricula nao encontrada!!!",0);
                            }
                            break;
                        }
                        case 5 : {
                            cout << "CONSULTAR ALUNOS\n\n";
                            for(int i=0;i<totalAlunosCadastrados;i++){
								if(vetMatricula[i]!=0){
	                                cout << "<" << i << "> ";
									cout << vetMatricula[i] << "\t";
    	                            cout << vetNome[i] << "\t";
        	                        cout << vetSexo[i] << "\t";
            	                    cout << vetCelular[i] << "\n";
								}
                            }
                            system("pause");
                            break;
                        }
                        case 6 : {
                            cout << "MATRICULAR ALUNOS\n\n";
                            do{
								cout << "Informe a matricula: "; cin >> matricula;
								if(matricula==0){
									cout << "Matricula invalida!!!\n";
								}
							}while(matricula==0);
							
							posicaoLocalizada=pesquisarMatricula(matricula,totalAlunosCadastrados);

                            if(posicaoLocalizada>=0){
	                            cout << "Informe a turma do(a) " << vetNome[posicaoLocalizada] << ": ";
	                            cin >> vetTurma[posicaoLocalizada];
	                            vetMatriculado[posicaoLocalizada]=true;
                                system("pause");
                            }else{
								cout << "Matricula nao encontrada!!!\n";
                                system("pause");
                            }
                            break;
                        }
                    }
                }while(submenu!=7);
                break;
            }
            case 2 : {
                do{
                    system("cls");
                    cout << "NOTAS\n\n";
                    cout << "1. Lancar notas por turma\n";
                    cout << "2. Lancar notas por aluno\n";
                    cout << "3. Alterar notas do alunos\n";
                    cout << "4. Excluir notas do alunos\n";
                    cout << "5. Consultar notas do alunos\n";
                    cout << "6. Retornar ao menu anterior\n";
                    cout << "   Escolha uma opcao: ";
                    cin >> submenu;
                    switch(submenu){
                        case 1 : {
                            cout << "LANCAR NOTAS POR TURMA\n\n";
                            break;
                        }
                        case 2 : {
                            cout << "LANCAR NOTAS POR ALUNO\n\n";
                            do{
								cout << "Informe a matricula: "; cin >> matricula;
								if(matricula==0){
									cout << "Matricula invalida!!!\n";
								}
							}while(matricula==0);
							
							posicaoLocalizada=pesquisarMatricula(matricula,totalAlunosCadastrados);

                            if(posicaoLocalizada>=0){
	                            cout << "Matricula...: " << vetMatricula[posicaoLocalizada]<<endl;
    	                        cout << "Nome........: " << vetNome[posicaoLocalizada]<<endl;
								if(vetMatriculado[posicaoLocalizada]){
									cout << "Turma.......: " << vetTurma[posicaoLocalizada] << endl;
									cout << "Nota da AV1.: "; cin >> mtzNotas[posicaoLocalizada][0];
									cout << "Nota da AV2.: "; cin >> mtzNotas[posicaoLocalizada][1];
									cout << "Nota da AV3.: "; cin >> mtzNotas[posicaoLocalizada][2];
									av1=mtzNotas[posicaoLocalizada][0];
									av2=mtzNotas[posicaoLocalizada][1];
									av3=mtzNotas[posicaoLocalizada][2];
                                    if(av1<4){av1=0;}
                                    if(av2<4){av2=0;}
                                    if(av3<4){av3=0;}
									if(av1>av2 || av1>av3){
										if(av2>av3){
											cout << "AV1 e AV2\n";
    										mtzNotas[posicaoLocalizada][3]=(av1+av2)/2;
										}else{
											cout << "AV1 e AV3\n";
											mtzNotas[posicaoLocalizada][3]=(av1+av3)/2;
                                        }
									}else{
                                        if(av2>av1 || av2>av3){
    										if(av1>av3){
												cout << "AV2 e AV1\n";
											    mtzNotas[posicaoLocalizada][3]=(av2+av1)/2;
    										}else{
												cout << "AV2 e AV3\n";
	    										mtzNotas[posicaoLocalizada][3]=(av2+av3)/2;
                                            }
                                        }else{
       										if(av1>av2){
												cout << "AV3 e AV1\n";
        										mtzNotas[posicaoLocalizada][3]=(av3+av1)/2;
										    }else{
												cout << "AV3 e AV2\n";
											    mtzNotas[posicaoLocalizada][3]=(av3+av2)/2;
                                            }
                                        }
                                    }
                                    cout << "A media do(a) " << vetNome[posicaoLocalizada] << " eh " << mtzNotas[posicaoLocalizada][3];
                                    system("pause");
								}else{
                                    cout << "O aluno não está matriculado\n";
                                }
                            }else{
								cout << "Matricula nao encontrada!!!\n";
                                system("pause");
                            }
                            break;

                        }
                        case 3 : {
                            cout << "ALTERAR NOTAS DO ALUNO\n\n";
                            break;
                        }
                        case 4 : {
                            cout << "EXCLUIR NOTAS DO ALUNO\n\n";
                            break;
                        }
                        case 5 : {
                            cout << "CONTULTAR NOTAS DO ALUNO\n\n";
                            for(int i=0;i<totalAlunosCadastrados;i++){
								if(vetMatricula[i]!=0){
	                                cout << "<" << i << "> ";
									cout << vetMatricula[i] << "\t";
    	                            cout << vetNome[i] << "\t";
        	                        cout << vetSexo[i] << "\t";
            	                    cout << vetCelular[i] << "\t";
                                    cout << mtzNotas[i][0] << "\t";
                                    cout << mtzNotas[i][1] << "\t";
                                    cout << mtzNotas[i][2] << "\t";
                                    cout << mtzNotas[i][3] << "\t";
                                    if(mtzNotas[i][3]<6){
                                        cout << "Reprovado\n";
                                    }else{
                                        cout << "Aprovado\n";
                                    }
								}
                            }
                            system("pause");
                            break;
                        }
                    }
                }while(submenu!=6);
                break;
            }
            case 3 : {
                do{
                    system("cls");
                    cout << "RELATORIOS\n\n";
                    cout << "1. Aprovados\n";
                    cout << "2. Reprovados\n";
                    cout << "3. Dados cadastrais\n";
                    cout << "4. Alunos por turma\n";
                    cout << "5. Retornar ao menu anterior\n";
                    cin >> submenu;
                    switch(submenu){
                        case 1 : {
                            cout << "RELACAO DE ALUNOS APROVADOS\n\n";
                            break;
                        }
                        case 2 : {
                            cout << "RELACAO DE ALUNOS REPROVADOS\n\n";
                            break;
                        }
                        case 3 : {
                            cout << "DADOS CADASTRAIS DO ALUNO\n\n";
                            break;
                        }
                        case 4 : {
                            cout << "RELACAO DE ALUNOS POR TUMRA\n\n";
                            break;
                        }
                    }
                }while(submenu!=5);
                break;
            }
        }
    }while(menu!=4);
    return 0;
}


int pesquisarMatricula(int matricula, int ultimoRegistro){
	/*
	 A fun��o recebe como par�metro uma variavel do tipo inteiro contendo o n�mero da matricula a ser pesquisa no vetMatricula
	 Se encontra a matricula pesquisa retorna a posi��o no vetor onde o valor foi encontrado, caso contr�rio retorna -1, indicando
	 que nada foi encontrado.
	*/
    
    int vetMatricula[10]; // EXCLUA ASSIM QUE POSSIVEL

	for(int i=0;i<ultimoRegistro;i++){
		if(vetMatricula[i]==matricula){
			return i;
		}
	}
	return -1;
}

void mensagem(string msg, int pausa){
	cout << "\n\n------------------------------------------------------------\n ";
	cout << msg << "\n";
	cout << "------------------------------------------------------------\n\n";
	if(pausa==0){
		cout << "\tPrecione qualquer tecla para continuar...";
		getch();
	}
}


