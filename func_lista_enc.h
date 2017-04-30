
struct no{
       int info;
       no *prox;//aponta para a proxima posiação de memória que contém a variável alocada
};

//cria uma nova lista
no *criarLista();


//insere no início da lista
no *insereInicio(no *lista, int info);

/*busca o último elemento da lista*/
no *buscaUltimo(no *lista);

//insere no final da lista e retorna o elemento inserido
no *insereFinal(no *lista, int info);

void consultaValores(no *lista);

/*remove o início da lista*/
no *removerInicio(no *lista);

/*remove o último elemento da lista*/
no *removerFinal(no *lista);

/*insere um elemento na ordem crescente*/
no *insereOrdemCrescente(no *lista, int info);

/*remove um elemento da lista conforme o valor passado por parâmetro*/
no *removerElemento(no *lista, int valor);

/*recria a lista desalocando todos os elementos da memória*/
no *recriarLista(no *lista);

// 6 -i- Consulta numero de elementos na lista

int listavazia(no *lista);

int consultaprimeirolista(no *lista);

no *consultaendprimeirolista(no *lista);

/*retorna o número de elementos contidos na lista*/
int consultanlista(no *lista);

no *ordenaAsc(no *lista);



