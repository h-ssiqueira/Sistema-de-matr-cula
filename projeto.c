//Henrique Sartori Siqueira   	19240472
//Jemis Dievas Jose Manhica   	19076272
//Rafael Silva Barbon         	19243633

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//estruturas de dados dos tipos
typedef struct information{
	char name[80], ID[20];
	struct information *prox;
}Info;

//redefinicao dos tipos
typedef struct sub{
	Info *mat, *alu, *prof;
	struct sub *prox;
}Subj;

typedef struct stu{
	Info *st, *disc;
	struct stu *prox;
}Stud;

typedef struct profe{
	Info *teacher, *disc;
	struct profe *prox;
}Prof;

//retorna NULL para os ponteiros de cada tipo
 Subj *cria_dis(void){
	return NULL;
}

 Prof *cria_prof(void){
	return NULL;
}

 Stud *cria_al(void){
	return NULL;
}

//funcoes para inserir dados nas listas
void InsereDis(Subj **d, char *nome, char *id){
	Info *novo;///pequena
	Subj *novo2;//grande
    
	novo2 = (Subj *)malloc(sizeof(Subj));
	novo2->prox = (*d);
	(*d) = novo2;
	novo2->alu = NULL;
	novo2->prof = NULL;
    
	novo = (Info *)malloc(sizeof(Info));
	strcpy(novo->name,nome);
	strcpy(novo->ID,id);
	novo->prox = (*d)->mat;
	(*d)->mat = novo;
}

void InsereProf(Prof **p, char *nome, char *id){
	Info *novo;//pequena
	Prof *novo2;//grande
    
	novo2=(Prof *)malloc(sizeof(Prof));
	novo2->prox = (*p);
	(*p) = novo2;

	novo2->disc = NULL;
    
	novo = (Info *)malloc(sizeof(Info));
	strcpy(novo->name,nome);
	strcpy(novo->ID,id);
	novo->prox = (*p)->teacher;
	(*p)->teacher = novo;
    
}

void InsereAluno(Stud **l,char *name, char *ra){
	Info *novo;//pequena
	Stud *novo2;//grande
    
	novo2 = (Stud *)malloc(sizeof(Stud));
	novo2->prox = (*l);
	(*l)=novo2;

	novo2->disc = NULL;
    
	novo = (Info *)malloc(sizeof(Info));
	strcpy(novo->name,name);
	strcpy(novo->ID,ra);
	novo->prox = (*l)->st;
	(*l)->st = novo;
}

//Checagem de repeticao de ID
int CheckID1(Stud *Student,char *cod){
	int check = 1;
    
	for(Stud *aux = Student; aux != NULL; aux = aux->prox){
    	if(strcmp(cod,aux->st->ID) == 0)
        	check = 0;
	}
	return check;
}

int CheckID2(Subj *Subject,char *cod){
	int check = 1;
    
	for(Subj *aux = Subject; aux != NULL; aux = aux->prox){
    	if(strcmp(cod,aux->mat->ID) == 0)
        	check = 0;
	}
	return check;
}

int CheckID3(Prof *Professor,char *cod){
	int check = 1;
    
	for(Prof *aux = Professor; aux != NULL; aux = aux->prox){
    	if(strcmp(cod,aux->teacher->ID) == 0)
        	check = 0;
	}
	return check;
}

//imprime a lista de todos os elementos de um grupo
void print_subj(Subj *subject){
	Subj *aux;
    
	system("clear");    
	printf("\n\tSubject\t\t\tID");
	for(aux = subject; aux != NULL; aux = aux->prox)
    	printf("\n\t%s\t\t\t%s",aux->mat->name,aux->mat->ID);
}

void print_stu(Stud *student){
	Stud *aux;
    
	system("clear");
	printf("\n\tStudent\t\t\t\tID");
	for(aux = student; aux != NULL; aux = aux->prox)
    	printf("\n\t%s\t\t\t%s",aux->st->name,aux->st->ID);
}

void print_profes(Prof *pro){
	Prof *aux;
    
	system("clear");
	printf("\n\tProfessor\t\t\tID");
	for(aux = pro; aux != NULL; aux = aux->prox)
    	printf("\n\t%s\t\t\t\t%s",aux->teacher->name,aux->teacher->ID);
}

//Mostrar as disciplinas de um aluno
void show_subjects_stu(Stud *student,char *RA){
	Info *aux;
	int flag = 0;
	Stud *auxS;
	char c;
    
	for(auxS = student; auxS != NULL; auxS = auxS->prox){
    	if(strcmp(auxS->st->ID,RA) == 0){
        	printf("\n\tSubject\t\t\tID");
        	for(aux = auxS->disc; aux != NULL; aux = aux->prox)
            	printf("\n\t%s\t\t\t\t%s",aux->name,aux->ID);
       	 
        	flag = 1;
        	break;
    	}
	}
	if(flag == 0)
    	printf("\n\tError 404: student's ID not found!\n\t");
}

//Mostrar os alunos de uma disciplina
void show_stu_subjects(Subj *subjecty,char *RA){
	Info *aux;
	int flag = 0;
	Subj *auxS;
	char c;
    
	for(auxS = subjecty; auxS != NULL; auxS = auxS->prox){
    	if(strcmp(auxS->mat->ID,RA) == 0){
        	printf("\n\tStudent\t\t\tID");
        	for(aux = auxS->alu; aux != NULL; aux = aux->prox)
            	printf("\n\t%s\t\t\t\t%s",aux->name,aux->ID);
        	flag = 1;
        	break;
    	}
	}
	if(flag == 0)
    	printf("\n\tError 404: subject's ID not found!\n\t");
}

//Mostrar as disciplinas de um professor
void show_subjects_pro(Prof *pro, char *RA){
	Info *aux;
	int flag = 0;
	Prof *auxP;
	char c;
    
	for(auxP = pro; auxP != NULL; auxP = auxP->prox){
    	if(strcmp(auxP->teacher->ID,RA) == 0){
        	printf("\n\tSubject\t\t\tID");
        	for(aux = auxP->disc; aux != NULL; aux = aux->prox)
            	printf("\n\t%s\t\t\t%s",aux->name,aux->ID);
        	flag = 1;
        	break;
    	}
	}
	if(flag == 0)
    	printf("\n\tError 404: professor's ID not found!\n\t");
}

//Mostrar os professores de uma disciplina
void show_pro_subjects(Subj *subjecty,char *RA){
	Info *aux;
	int flag = 0;
	Subj *auxS;
	char c;
    
	for(auxS = subjecty; auxS != NULL; auxS = auxS->prox){
    	if(strcmp(auxS->mat->ID,RA) == 0){
        	printf("\n\tProfessor\t\t\tID");
        	for(aux = auxS->prof; aux != NULL; aux = aux->prox)
            	printf("\n\t%s\t\t\t\t%s",aux->name,aux->ID);
        	flag = 1;
        	break;
    	}
	}
	if(flag == 0)
    	printf("\n\tError 404: subject's ID not found!\n\t");
}

//Funçao que adiciona nas listas provisorias para link e unlink
void InsereID(Info ***list,char *info, char *nome){
	Info *aux = (Info *)malloc(sizeof(Info));
    
	strcpy(aux->ID,info);
	strcpy(aux->name,nome);
	aux->prox = (**list);
	(**list) = aux;
}

//funcao que desaloca a lista provisoria
Info* liberaID(Info *disc){
	Info *aux, *aux2 = disc;
    
	while(aux2 != NULL){
    	aux = aux2->prox;
    	free(aux2);
    	aux2 = aux;/// Quando o ultimo for NULL (*disc fica com NULL)
	}
	return NULL;
}

//funcao que coleta os dados provisorios p/ manipulacao de vinculo de estudante e disciplina
void CollectSS(Subj *subject, Stud *student, Info **alu, Info **disc){
	char lida[20];//ID selecionado
	int conf1, flag = 1;//flag -> conferencia p/ permanencia nos loops
	Info *auxalu, *auxdisc;  
	Stud *aux;
	Subj *auxS;
    
    	do{
        	print_stu(student);    
        	printf("\n\tInsert which ID would you like to link: ");
        	fflush(stdin);
        	scanf("%s",lida);
        	for(aux = (student); aux != NULL; aux = aux->prox){
            	conf1 = strcmp(lida,aux->st->ID);
            	if(conf1 == 0){ //se houver o ID do aluno
                	InsereID(&alu,lida,aux->st->name); //insere na lista auxiliar
                	break;
            	}
        	}
        	if(conf1 != 0){//Nao existe aluno
            	printf("\n\tError 404: student's ID not found!\n\tPress enter to continue...");
            	fflush(stdin);
            	getchar();
        	}
        	else{
            	do{
                	printf("\n\tWould you like to add more students?\n\t\t1 - yes.\n\t\t0 - No.\n\t-> ");
                	scanf("%d",&flag);
                	if(flag > 1 || flag < 0){
                    	system("clear");
                    	printf("\tERROR INVALID VALUE! Try again.\n\n");
                	}
            	}while(flag > 1 || flag < 0);    
            	system("clear");
        	}
	}while(flag == 1);    
	flag = 1;
	do{
    	print_subj(subject);  
    	printf("\n\tInsert which ID would you like to link: ");
    	fflush(stdin);
    	scanf("%s",lida);
    	for(auxS = (subject); auxS != NULL; auxS = auxS->prox){
        	conf1 = strcmp(lida,auxS->mat->ID);
        	if(conf1 == 0){ //se houver o ID da disciplina
            	InsereID(&disc,lida,auxS->mat->name);
            	break;
        	}
    	}
    	if(conf1 != 0){//Nao existe disciplina
        	printf("\n\tError 404: subject's ID not found!\n\tPress enter to continue...");
        	fflush(stdin);
        	getchar();
    	}
    	else{
        	do{
            	printf("\n\tWould you like to add more subjects?\n\t\t1 - yes.\n\t\t0 - No.\n\t-> ");
            	scanf("%d",&flag);
            	if(flag > 1 || flag < 0){
                	system("clear");
                	printf("\tERROR INVALID VALUE! Try again.\n\n");
            	}
        	}while(flag > 1 || flag < 0);    
        	system("clear");
    	}
	}while(flag == 1);
}

//funcao que coleta os dados provisorios p/ manipulacao de vinculo de professor e disciplina
void CollectPS(Subj *subject, Prof *pro, Info **prof, Info **disc){
	char lida[20];//ID selecionado
	int conf1, flag = 1;//flag -> conferencia p/ permanencia nos loops
	Info *auxprof, *auxdisc;  
	Prof *aux;
	Subj *auxS;
    
	do{
    	print_profes(pro);  
    	printf("\n\tInsert which ID would you like to link: ");
    	fflush(stdin);
    	scanf("%s",lida);
    	for(aux = (pro); aux != NULL; aux = aux->prox){
        	conf1 = strcmp(lida,aux->teacher->ID);
        	if(conf1 == 0){ //se houver o ID do professor
            	InsereID(&prof,lida,aux->teacher->name);
            	break;
        	}
    	}
    	if(conf1 != 0){//Nao existe professor
        	printf("\n\tError 404: professor's ID not found!\n\tPress enter to continue...");
        	fflush(stdin);
        	getchar();
    	}
    	else{
        	do{
            	printf("\n\tWould you like to add more professors?\n\t\t1 - yes.\n\t\t0 - No.\n\t-> ");
            	scanf("%d",&flag);
            	if(flag > 1 || flag < 0){
                	system("clear");
                	printf("\tERROR INVALID VALUE! Try again.\n\n");
            	}
        	}while(flag > 1 || flag < 0);    
        	system("clear");
    	}
	}while(flag == 1);    
	flag = 1;
	do{
    	print_subj(subject);  
    	printf("\n\tInsert which ID would you like to link: ");
    	fflush(stdin);
    	scanf("%s",lida);
    	for(auxS = (subject); auxS != NULL; auxS = auxS->prox){
        	conf1 = strcmp(lida,auxS->mat->ID);
        	if(conf1 == 0){ //se houver o ID da disciplina
            	InsereID(&disc,lida,auxS->mat->name);
            	break;
        	}
    	}
    	if(conf1 != 0){//Nao existe disciplina
        	printf("\n\tError 404: subject's ID not found!\n\tPress enter to continue...");
        	fflush(stdin);
        	getchar();
    	}
    	else{
        	do{
            	printf("\n\tWould you like to add more subjects?\n\t\t1 - yes.\n\t\t0 - No.\n\t-> ");
            	scanf("%d",&flag);
            	if(flag > 1 || flag < 0){
                	system("clear");
                	printf("\tERROR INVALID VALUE! Try again.\n\n");
            	}
        	}while(flag > 1 || flag < 0);    
        	system("clear");
    	}
	}while(flag == 1);
}

//funcao que inscreve o aluno na disciplina
void locS(Subj ***subjj,char ra[],char nome[]){
	Info *novo;
    
	novo = (Info *)malloc(sizeof(Info));
	strcpy(novo->name,nome);
	strcpy(novo->ID,ra);
	novo->prox = (**subjj)->alu;
	(**subjj)->alu = novo;
}

//inscreve a disciplina no aluno
void locSU(Stud ***estu,char nome[],char ID[]){
	Info *novo;
    
	novo = (Info *)malloc(sizeof(Info));
	strcpy(novo->name,nome);
	strcpy(novo->ID,ID);
	novo->prox = (**estu)->disc;
	(**estu)->disc = novo;
}

//inscreve o professor na disciplina
void locP(Subj ***subject,char ID[],char nome[]){
	Info *novo;
    
	novo = (Info*)malloc(sizeof(Info));
	strcpy(novo->name,nome);
	strcpy(novo->ID,ID);
	novo->prox = (**subject)->prof;
	(**subject)->prof = novo;
}

//inscreve disciplina no professor
void locDP(Prof ***pro,char nome[],char ID[]){
	Info *novo;
    
	novo = (Info*)malloc(sizeof(Info));
	strcpy(novo->name,nome);
	strcpy(novo->ID,ID);
	novo->prox = (**pro)->disc;
	(**pro)->disc = novo;
}

//vincula um aluno a uma disciplina
void SLinkS(Stud **student,Subj **subject){
	Info *alu = NULL, *disc = NULL, *auxsub, *auxalu;  
	int conf;
	Subj *auxS;
	Stud *auxs;
    
	CollectSS(*subject,*student,&alu,&disc);
	for(auxalu = alu; auxalu != NULL; auxalu = auxalu->prox){//alunos que quero cadastrar
    	auxs = (*student);
    	for(; (*student) != NULL; (*student) = (*student)->prox){//Buscando o aluno na grande
        	conf = strcmp((*student)->st->ID,auxalu->ID);
        	if(conf == 0){//ACHOU
            	for(auxsub = disc ; auxsub != NULL; auxsub = auxsub->prox)//disciplinas que quero cadastrar nesse estudante
                	locSU(&student,auxsub->name,auxsub->ID);
            	break;
        	}
    	}
    	(*student) = auxs;
	}
	for(auxsub = disc ; auxsub != NULL; auxsub = auxsub->prox){//disciplinas que quero cadastrar
    	auxS = (*subject);
    	for(; (*subject) != NULL; (*subject) = (*subject)->prox){//Buscando a disciplina na grande
        	conf = strcmp((*subject)->mat->ID,auxsub->ID);
        	if(conf == 0){//ACHOU
            	for(auxalu = alu; auxalu != NULL; auxalu = auxalu->prox)//disciplinas que quero cadastrar nesse estudante
                	locS(&subject,auxalu->ID,auxalu->name);
            	break;
        	}
    	}
    	(*subject) = auxS;
	}  
}

///Vincular professor com disciplina
void PlinkS(Prof **pro,Subj **subject){
	Info *prof = NULL, *disc = NULL, *auxsub, *auxprof;
	int conf;
	Subj *auxS;
	Prof *auxP;
    
	CollectPS(*subject,*pro,&prof,&disc);
	for(auxprof = prof; auxprof != NULL; auxprof = auxprof->prox){//professores que quero cadastrar
    	auxP = (*pro);
    	for(; (*pro) != NULL; (*pro) = (*pro)->prox){//Buscando o professor na grande
        	conf = strcmp((*pro)->teacher->ID,auxprof->ID);
        	if(conf == 0){//ACHOU
            	for(auxsub = disc ; auxsub != NULL; auxsub = auxsub->prox)//disciplinas que quero cadastrar nesse estudante
                	locDP(&pro,auxsub->name,auxsub->ID);
            	break;
        	}
    	}
    	(*pro) = auxP;
	}
	for(auxsub = disc ; auxsub != NULL; auxsub = auxsub->prox){//disciplinas que quero cadastrar
    	auxS = (*subject);
    	for(; (*subject) != NULL; (*subject) = (*subject)->prox){//Buscando a disciplina na grande
        	conf = strcmp((*subject)->mat->ID,auxsub->ID);
        	if(conf == 0){//ACHOU
            	for(auxprof = prof; auxprof != NULL; auxprof = auxprof->prox)//disciplinas que quero cadastrar nesse professor
                	locP(&subject,auxprof->ID,auxprof->name);
            	break;
        	}
    	}
    	(*subject) = auxS;
	}  
}

//Cancelamento de matricula
void cancel_StudantOnSubj(Stud *student,Subj *discs){
	Info *q, *Q, *auxalu = NULL, *auxdisc = NULL ;
	Subj *p;
	Stud *stu;
	char lida[20], lida2[20], c;
	int j = 0, conf;
    
	print_subj(discs);
	printf("\n\tInsert which ID would you like to remove:");
	fflush(stdin);
	scanf("%s",lida);
	for(p = discs; (p != NULL) && (j == 0); p = p->prox){//Procura na grande de disciplinas a disciplina
    	conf = strcmp(p->mat->ID,lida);
    	if(conf == 0){//ID Materia
        	system("clear");
        	show_stu_subjects(discs,lida);//Mostra os alunos discritos nas matéria
        	printf("\n\tInsert which ID would you like to remove:");
        	fflush(stdin);
        	scanf("%s",lida2);
        	for(q = p->alu; q != NULL; auxdisc = q, q = q->prox){//Procura na grande de disciplina o aluno
            	conf = (strcmp(q->ID,lida2));
            	if(conf == 0){//ID Estudante
                	for(stu = student; stu != NULL; stu = stu->prox){//Procura na grande do Aluno(quem e o aluno)
                    	conf = strcmp(stu->st->ID,lida2);
                    	if(conf == 0){
                        	for(Q = stu->disc; Q != NULL; auxalu = Q, Q = Q->prox){//Procura na grande do aluno a materia
                            	conf = strcmp(Q->ID,lida);
                            	if(conf == 0){
                                	if(auxalu == NULL){
                                    	stu->disc = stu->disc->prox;
                                    	free(Q);
                                	}
                                	else{
                                    	auxalu->prox = Q->prox;
                                    	free(Q);
                                	}
                                	j++;
                                	break;
                            	}
                        	}
                    	}
                	}
                	if(auxdisc == NULL){
                    	p->alu = p->alu->prox;
                    	free(q);
                	}
                	else{
                    	auxdisc->prox = q->prox;
                    	free(q);
                	}
                	break;
            	}
        	}
    	}
	}
	if(j == 0){
    	printf("\n\t ERROR 404 ID NOT FOUND!\n\tPress enter to continue...\n");
    	fflush(stdin);
    	scanf("%c",&c);
    	getchar();
	}
}

void cancel_ProfOnSubj(Prof *pro,Subj *discs){
	Info *q, *Q, *auxdisc = NULL, *auxprof = NULL;
	Subj *p;
	Prof *Prf;
	char lida[20], lida2[20], c;
	int j = 0, conf;
    
	print_subj(discs);
	printf("\n\tInsert which ID would you like to remove:");
	fflush(stdin);
	scanf("%s",lida);
	for(p = discs; (p != NULL) && (j == 0); p = p->prox){//Procura na grande de disciplinas a disciplina
    	conf=strcmp(p->mat->ID,lida);
    	if(conf == 0){//ID Materia
        	system("clear");
        	show_pro_subjects(discs,lida);//Mostra os professores discritos nas matéria
        	printf("\n\tInsert which ID would you like to remove:");
        	fflush(stdin);
        	scanf("%s",lida2);
        	for(q = p->prof; q != NULL; auxprof = q, q = q->prox){//Procura na grande de disciplina o professor
            	conf = (strcmp(q->ID,lida2));
            	if(conf == 0){//ID do professor
                	for(Prf = pro; Prf != NULL; Prf = Prf->prox){//Procura na grande do professor (quem e o professor)
                    	conf = strcmp(Prf->teacher->ID,lida2);
                    	if(conf == 0){
                        	for(Q = Prf->disc; Q != NULL; auxdisc = Q, Q = Q->prox){//Procura na grande do aluno a materia
                            	//Guardar o anterior
                            	conf=strcmp(Q->ID,lida);
                            	if(conf == 0){
                                	if(auxdisc == NULL){
                                    	Prf->disc = Prf->disc->prox;
                                    	free(Q);
                                	}
                                	else{
                                    	auxdisc->prox = Q->prox;
                                    	free(Q);
                                	}
                                	j++;
                                	break;
                            	}
                        	}
                    	}
                	}
                	if(auxprof == NULL){
                    	p->prof = q->prox;
                    	free(q);
                	}
                	else{
                    	auxprof->prox = q->prox;
                    	free(q);
                	}
                	break;
            	}
        	}
    	}
	}
	if(j == 0){
    	printf("\n\t ERROR 404 ID NOT FOUND!\n\tPress enter to continue...\n");
    	fflush(stdin);
    	scanf("%c",&c);
    	getchar();
	}
}

///Libera Student
void desalocaStudent(Stud *student){
	Stud *temp, *temp2 = student;
	Info *p, *q;
    
	while(temp2 != NULL){
    	p = temp2->disc;
    	while(p != NULL){//Libera disciplinas
        	q = p->prox;
        	free(p);
        	p = q;
    	}
    	free(temp2->st);//Libera estudante
    	temp = temp2->prox;
    	free(temp2);
    	temp2 = temp;
	}
}

///Libera Professor
void desalocaProfessor(Prof *pro){
	Prof *temp, *temp2 = pro;
	Info *p, *q;
    
	while(temp2 != NULL){
    	p = temp2->disc;
    	while(p!=NULL){//Libera disciplinas
        	q = p->prox;
        	free(p);
        	p = q;
    	}
    	free(temp2->teacher);//Libera professor
    	temp = temp2->prox;
    	free(temp2);
    	temp2 = temp;
	}
}

///Libera Subject
void desalocaSubject(Subj *subject){
	Subj *temp, *temp2 = subject;
	Info *p, *q;
    
	while(temp2 != NULL){
    	p = temp2->alu;
    	while(p != NULL){//Libera alunos
        	q = p->prox;
        	free(p);
        	p = q;
    	}
    	p = temp2->prof;
    	while(p!=NULL){//Libera professores
        	q = p->prox;
        	free(p);
        	p = q;
    	}
    	free(temp2->mat);//LIbera materia
    	temp = temp2->prox;
    	free(temp2);
    	temp2 = temp;
	}
}


int main(){
	int stu = 0, sub = 0, pro = 0, option, op, check;
	char nome[80], COD[20], c;
    
	//inicializa as listas como vazias
	Stud *Student = cria_al();
	Prof *Professor = cria_prof();
	Subj *Subject = cria_dis();
    
	system("clear");
	do{
    	do{//menu de escolha
        	printf("\tThere are %d students, %d subjects and %d professors.\n",stu,sub,pro);
        	printf("\n\tChoose an option:");
        	printf("\n\t\t 1 -> Enroll.");
        	printf("\n\t\t 2 -> Enroll students in a group of subjects.");
        	printf("\n\t\t 3 -> Cancel enrollment of students in a subject.");
        	printf("\n\t\t 4 -> Link professors to a subject.");
        	printf("\n\t\t 5 -> Unlink professors to a subject.");
        	printf("\n\t\t 6 -> Show all students.");
        	printf("\n\t\t 7 -> Show all subjects.");
        	printf("\n\t\t 8 -> Show all professors.");
        	printf("\n\t\t 9 -> Show the student's subject list.");
        	printf("\n\t\t10 -> Show the list of students in a subject.");
        	printf("\n\t\t11 -> Show the professor's subjects list.");
        	printf("\n\t\t12 -> Show the list of professors in a subject.");
        	printf("\n\t\t13 -> Exit.");
        	printf("\n\t-> ");
        	fflush(stdin);
        	scanf("%d",&option);
        	if(option < 1 || option > 13){
            	system("clear");
            	printf("\n\tERROR! Insert an acceptable value in the range (1-13).\n\n");
        	}
    	}while(option < 1 || option > 13);
    	system("clear");
    	switch(option){
        	case 1://cadastramento de alunos, disciplinas e professores (sem nenhuma relacao entre eles)
            	do{            	 
                	system("clear");
                	printf("\n\tWhich type of data do you want to enroll?");
                	printf("\n\t\t1 - Student.");
                	printf("\n\t\t2 - Subject.");
                	printf("\n\t\t3 - Professor.");
                	printf("\n\t-> ");
                	scanf("%d",&op);
                	if(op > 3 || op < 1){
                    	system("clear");
                    	printf("\tERROR INVALID VALUE! Try again.\n\n");
                	}else{
                    	if(op == 1){
                        	printf("\n\tInsert the student's name -> ");
                        	fflush(stdin);
                        	scanf("%s",nome);
                        	do{
                            	printf("\n\tInsert the student's ID -> ");
                            	fflush(stdin);
                            	scanf("%s",COD);
                            	check = CheckID1(Student,COD);
                            	if(check == 1){
                                	InsereAluno(&Student,nome,COD);
                                	stu++;
                            	}
                            	else
                                	printf("\n\tERROR! ID \"%s\" is already used. Try again.\n",COD);
                        	}while(check == 0);
                    	}else if(op == 2){
                        	printf("\n\tInsert the subject's name -> ");
                        	fflush(stdin);
                        	scanf("%s",nome);
                        	do{
                            	printf("\n\tInsert the subject's ID -> ");
                            	fflush(stdin);
                            	scanf("%s",COD);
                            	check = CheckID2(Subject,COD);
                            	if(check == 1){
                                	InsereDis(&Subject,nome,COD);
                                	sub++;
                            	}
                            	else
                                	printf("\n\tERROR! ID \"%s\" is already used. Try again.\n",COD);
                        	}while(check == 0);
                    	}else{
                        	printf("\n\tInsert the professor's name -> ");
                        	getchar();
                        	fflush(stdin);
                        	scanf("%s",nome);
                        	do{
                            	printf("\n\tInsert the professor's ID -> ");
                            	fflush(stdin);
                            	scanf("%s",COD);
                            	check = CheckID3(Professor,COD);
                            	if(check == 1){
                                	InsereProf(&Professor,nome,COD);
                                	pro++;
                            	}
                            	else
                                	printf("\n\tERROR! ID \"%s\" is already used. Try again.\n",COD);
                        	}while(check == 0);
                    	}
                    	do{
                        	printf("\n\tWould you like to keep enrolling?\n\t\t1 - yes.\n\t\t0 - No.\n\t-> ");
                        	scanf("%d",&op);
                        	if(op > 1 || op < 0){
                            	system("clear");
                            	printf("\tERROR INVALID VALUE! Try again.\n\n");
                        	}
                    	}while(op > 1 || op < 0);	 
                	}
            	}while(op == 1);
            	break;
        	case 2://matricular alunos em um grupo de disciplinas
            	SLinkS(&Student,&Subject);
            	break;
        	case 3://desvincular alunos em disciplinas.
            	cancel_StudantOnSubj(Student,Subject);
            	break;
        	case 4://vincular professores em disciplinas.
            	PlinkS(&Professor,&Subject);
            	break;
        	case 5://desvincular professores a dsciplinas
            	cancel_ProfOnSubj(Professor,Subject);
            	break;
        	case 6://mostrar alunos
            	print_stu(Student);
            	printf("\n\tPress enter to continue...");
            	fflush(stdin);
            	scanf("%c",&c);
            	getchar();
           	 
            	break;
        	case 7://mostrar disciplinas
            	print_subj(Subject);
            	printf("\n\tPress enter to continue...");
            	fflush(stdin);
            	scanf("%c",&c);
            	getchar();
            	break;
        	case 8://mostrar professores
            	print_profes(Professor);
            	printf("\n\tPress enter to continue...");
            	fflush(stdin);
            	scanf("%c",&c);
            	getchar();
            	break;
        	case 9://mostrar a lista de disciplinas de um aluno
            	print_stu(Student);
            	printf("\n\tInsert which ID do you like to consult:");
            	fflush(stdin);
            	scanf("%s",COD);
            	show_subjects_stu(Student,COD);
            	printf("\n\tPress enter to continue...");
            	fflush(stdin);
            	scanf("%c",&c);
            	getchar();
            	break;
        	case 10://mostrar a lista de alunos de uma disciplina
            	print_subj(Subject);
            	printf("\n\tInsert which ID do you like to consult: ");
            	fflush(stdin);
            	scanf("%s",COD);
            	show_stu_subjects(Subject,COD);
            	printf("\n\tPress enter to continue...");
            	fflush(stdin);
            	scanf("%c",&c);
            	getchar();
            	break;
        	case 11://lista de disciplinas de um professor
            	print_profes(Professor);
            	printf("\n\tInsert which ID do you like to consult: ");
            	fflush(stdin);
            	scanf("%s",COD);
            	show_subjects_pro(Professor,COD);
            	printf("\n\tPress enter to continue...");
            	fflush(stdin);
            	scanf("%c",&c);
            	getchar();
            	break;
        	case 12://lista de professores de uma disciplina
            	print_subj(Subject);
            	printf("\n\tInsert which ID do you like to consult: ");
            	fflush(stdin);
            	scanf("%s",COD);
            	show_pro_subjects(Subject,COD);
            	printf("\n\tPress enter to continue...");
            	fflush(stdin);
            	scanf("%c",&c);
            	getchar();
            	break;
    	}
    	system("clear");
	}while(option != 13);
	///Desalocar a memória
	desalocaStudent(Student);
	desalocaProfessor(Professor);
	desalocaSubject(Subject);
	return 0;
}






