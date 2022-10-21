#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    FILE *file; 
    
    void funcaoPrinc (FILE *file);
    void varID (FILE *file);
    void condition (FILE *file);

    file = fopen("Compiladorzinho do k", "r");

    if (file == NULL){ //Encerra o programa caso o arquivo esteja vazio
        printf("Este arquivo esta vazio");
        return 0;
    }

    funcaoPrinc(file);
    rewind(file); //Reposiciona o ponteiro para o inicio do arquivo
    varID(file);
    condition(file);

    fclose(file);

    printf("\n** Compilado com sucesso **\n");

    return 0;
}

//Identifica a função principal
void funcaoPrinc (FILE *file){

    char func[100], idety[100], teste[2]; char opcl; int i, n = 0;
    char princ1[15] = "vicis.Primor()", princ2[15] = "vicis.Primor(){";
    char *result, *tam, c, end[14] = "recurso vacuum";

    fscanf(file, "%s", func); //Lê a primeira linha do arquivo
    
    for (i = 0; i < 15; i++){
        if(func[i] == princ1[i] || func[i] == princ2[i]) // Compara a linha lida com o vetor que contem a função principal
            n++;
    }

    if (n == 15 || n == 14){ 
        while(!feof(file)){
            n = 0;
            result = fgets(idety, 100, file);
            tam = strtok(result, ";"); //Armazena uma string até o limite informado
            if (result){
                for(i = 0; i < 14; i++){
                    if (tam[i] == end[i]) //Compara a string obtida com o comando para fechar a " f.main"
                        n++;
                }
                if(n == 14){ 
                    while ((c = fgetc(file)) != EOF){
                        if(c == '}'){
                            printf("\nFuncao principal -- ok!");
                            return; //Encerra a função
                        }
                    }
                    
                }
            }
        }
    } else { //Caso haja erro na escrita 
        printf("\nErro na sintaxe");
        return;
    }    
}

//Identifica variaveis
void varID (FILE *file){

    char idety[100]; int i, n = 0;
    char *result, *tam; 
    char str1[6] = "plenus";

    while (!feof(file)){
        result = fgets(idety, 100, file);
        tam = strtok(result, " ");
        if(result){
            for(i = 0; i < 6; i++){
                if(tam[i] == str1[i]) //Compara a string obtida com o vetor da variavel
                    n++;
            }

            if(n == 6){ 
                printf("\nVariavel(is) -- ok!");
                return;
            }
        }
    }
}

// Identifica a condição IF ELSE
void condition (FILE *file){

    char idety[100], *result, *tam, c;
    char str1[2] = "si", str2[5] = "aliud"; int i, n = 0, d = 0;

    while (!feof(file)){
        result = fgets(idety, 100, file);
        tam = strtok(result, "(");
        if(result){
            for (i = 0; i < 2; i++){
                if(tam[i] == str1[i]) //Compara a string com a variavel "if"
                    n++;
            }
            
            if(n == 2){
                while (!feof(file)){
                    c = fgetc(file);
                    if (c == '}'){
                        printf("\nCondicional 'si' -- ok!");
                        result = tam = NULL; //Zera os valores 
                        n = 0;
                        while (!feof(file)){
                            result = fgets(idety, 100, file);
                            tam = strtok(result, "{");
                            if(result){
                                for(i = 0; i < 5; i++){
                                    if(tam[i] == str2[i]){
                                        n++;
                                    } else {
                                        d++;
                                    }
                                }  
                                
                                if(n == 5){
                                    while (!feof(file)){
                                        c = fgetc(file);
                                        if(c == '}'){
                                            printf("\nCondicional 'aliud' -- ok!\n");
                                            return;
                                        }
                                    }
                                } else if (d > 5){
                                    return;
                                }
                            }
                        }  
                    }
                }  
            } 
        }
    }
}