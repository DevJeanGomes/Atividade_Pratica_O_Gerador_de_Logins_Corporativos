#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM_BUFFER 100

// --- Protótipos das Funções ---
void extrairDominio(char* destino, const char* email);
void gerarLogin(char* destino, const char* nomeCompleto);
int validarSenha(const char* senha, const char* login);
// (Opcional) void normalizarNome(char* destino, const char* nome);

int main() {
    char nome[TAM_BUFFER] = "Carlos Drummond de Andrade";
    char email[TAM_BUFFER] = "carlos.drummond@algoritmos.com.br";
    char senha[TAM_BUFFER] = "123carlos.drummond456"; // Senha fraca
    
    char dominio[TAM_BUFFER];
    char login[TAM_BUFFER];

    printf("--- Processando Dados ---\n");
    printf("Nome Original: %s\n", nome);

    // 1. Extrair Domínio
    extrairDominio(dominio, email);
    printf("Dominio: %s\n", dominio);

    // 2. Gerar Login
    gerarLogin(login, nome); 
    printf("Login Gerado: %s\n", login);

    // 3. Validar Senha
    if (validarSenha(senha, login)) {
        printf("Status Senha: VALIDA\n");
    } else {
        printf("Status Senha: INVALIDA (Contem o login)\n");
    }

    return 0;
}

// ---------------------------------------------------------
// ESPAÇO PARA IMPLEMENTAÇÃO
// ---------------------------------------------------------

void extrairDominio(char* destino, const char* email) {
	
	// DICA: Use strchr para achar o '@'
    // Se achar, copie a string a partir do proximo caractere
    
	char *ptr = strchr(email, '@');

    if (ptr != NULL) {
        strcpy(destino, ptr + 1); // copia apos o @
    } else {
        destino[0] = '\0'; // email invalido
    }
    
}

void gerarLogin(char* destino, const char* nomeCompleto) {
	
	// DICA: Tente usar strrchr para achar o ultimo espaco
    // Use tolower para garantir minusculas
	
	char sobrenome[TAM_BUFFER];
    char *ptr = strrchr(nomeCompleto, ' ');

    // pega o sobrenome
    if (ptr != NULL) {
        strcpy(sobrenome, ptr + 1);
    } else {
        strcpy(sobrenome, nomeCompleto);
    }

    // primeira letra do nome
    destino[0] = tolower(nomeCompleto[0]);
    destino[1] = '.';
    destino[2] = '\0';

    // sobrenome em minusculo
    for (int i = 0; sobrenome[i] != '\0'; i++) {
        sobrenome[i] = tolower(sobrenome[i]);
    }

    strcat(destino, sobrenome);
    
}

int validarSenha(const char* senha, const char* login) {
	
	// DICA: Use strstr. Retorne 0 se encontrar o login, 1 se nao encontrar.
	
	if (strstr(senha, login) != NULL) {
        return 0; // senha invalida
    }
    return 1; // senha valida
    
    return 1; // Placeholder

    system("pause");
    
}