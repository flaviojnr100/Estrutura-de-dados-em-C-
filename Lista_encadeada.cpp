#include<iostream>
using namespace std;

class No{

private:
	int chave;
	No* proximo;
	No* anterior;
public:
	No(int chave){
		this->chave = chave;
		this->proximo = NULL;
		this->anterior = NULL;

	}
	void setChave(int nova){
		chave = nova;
	}
	int getChave(){
		return chave;
	}
	No* getProximo(){
		return proximo;
	}
	void setProximo(No* prox){
		proximo = prox;
	}
	No* getAnterior(){
		return anterior;
	}
	void setAnterior(No* ant){
		anterior = ant;
	}


};

class Lista_encadeada{

private:
	int tamanho;
	No* primeiro;
	No* ultimo;

	int Busca(int indice){

		No* atual = primeiro;
		for (int i = 0; i < tamanho; i++)
		{
			if(i==indice){
				return atual->getChave();
			}
			atual = atual->getProximo();
		}
	}
	
	No* BuscarCedula(int indice){
		No* atual = primeiro;
		for (int i = 0; i < tamanho; i++)
		{
			if(i==indice){
				return atual;
			}
			atual = atual->getProximo();
		}

	}

public:
	Lista_encadeada(){
		this->tamanho = 0;
		this->primeiro = NULL;
		this->ultimo = 0;
	}
	void Append(int elemento){
		No* novo = new No(elemento);
		if(tamanho==0){
			primeiro = novo;
			ultimo = novo;
		}else{
			ultimo->setProximo(novo);
			novo->setAnterior(ultimo);
			ultimo = novo;
		}
		tamanho++;
	}

	void Inserir_inicio(int elemento){
		No* novo = new No(elemento);
		if(tamanho==0){
			primeiro = novo;
			ultimo = novo;
		}else{
			primeiro->setAnterior(novo);
			novo->setProximo(primeiro);
			primeiro = novo;
		}
		tamanho++;
	}
	void ToString(){
		No* atual = primeiro;
		cout<<"[";
		for(int i=0;i<tamanho;i++){
			cout<<atual->getChave();
			if(i<tamanho-1){
				cout<<", ";
			}
			atual = atual->getProximo();

		}
		cout<<"]"<<endl;
		
	}
	void Inserir(int posicao, int elemento){
		No* novo = new No(elemento);
		if(posicao==0){
			Inserir_inicio(elemento);
		}else if(posicao==tamanho){
			Append(elemento);
		}else if(posicao>0 && posicao<tamanho){
			No* atual = primeiro;
			for(int i=0;i<tamanho;i++){
				if(i==posicao){
					break;
				}
				atual = atual->getProximo();
			}
			No* anterior = atual->getAnterior();
			anterior->setProximo(novo);
			novo->setAnterior(anterior);
			novo->setProximo(atual);
			atual->setAnterior(novo);
			tamanho++;
		}else{
			cout<<"Erro de índice!!"<<endl;
		}

	}

	void Remover(int elemento){
		if(primeiro->getChave() == elemento){
			No* proximo = primeiro->getProximo();
			primeiro->setProximo(NULL);
			proximo->setAnterior(NULL);
			primeiro = proximo;
			tamanho--;

		}else if(ultimo->getChave() == elemento){
			No* anterior = ultimo->getAnterior();
			ultimo->setAnterior(NULL);
			anterior->setProximo(NULL);
			ultimo = anterior;
			tamanho--;

		}else{
			No* atual = primeiro;
			for(int i=0;i<tamanho;i++){
				if(atual->getChave() == elemento){
					No* anterior = atual->getAnterior();
					No* proximo = atual->getProximo();
					anterior->setProximo(proximo);
					proximo->setAnterior(anterior);
					atual->setAnterior(NULL);
					atual->setProximo(NULL);
					tamanho--;
					return;
				}
				atual = atual->getProximo();
			}
			cout<<"Elemento não existente na lista!!"<<endl;

		}
	}

	int Pop(int indice){
		if(indice>=0 && indice<=tamanho-1){
		int elemento = Busca(indice);
		Remover(elemento);
		cout<<elemento<<endl;	
		}else{
			cout<<"Erro de indice"<<endl;
		}
		
	}

	void Clear(){
		primeiro = NULL;
		ultimo = NULL;
		tamanho=0;
	}

	int Count(int elemento){
		int q=0;
		No* atual = primeiro;
		for(int i=0;i<tamanho;i++){
			if(atual->getChave() == elemento){
				q++;
			}
			atual = atual->getProximo();
		}
		return q;
	}
	int Length(){
		return tamanho;
	}
	
	void SubString(int indice){
		if(indice>=0 && indice<tamanho){
		No* elemento= BuscarCedula(indice);
		cout<<"["<<elemento->getChave()<<"]"<<endl;
	}else{
		cout<<"Erro de indice!!"<<endl;
	}
	}

	void SubString(int comeco, int fim){

		if(comeco<fim && fim<tamanho){
			No* parte1 = BuscarCedula(comeco);
			No* parte2 = BuscarCedula(fim);
			cout<<"[";
			for (int i = 0; i < fim-comeco; i++)
			{
				cout<<parte1->getChave();
				if(i<fim-comeco-1){
					cout<<", ";
				}
				parte1 = parte1->getProximo();
			}
			cout<<"]"<<endl;
		}else if(comeco>fim && comeco<tamanho){
			No* parte1 = BuscarCedula(comeco);
			No* parte2 = BuscarCedula(fim);
			cout<<"[";
			for(int i=0;i<comeco-fim;i++){
				cout<<parte1->getChave();
				if(i<comeco-fim-1){
					cout<<", ";
				}
				parte1 = parte1->getAnterior();
			}
			cout<<"]"<<endl;
		}else{
			cout<<"Erro de indice!!"<<endl;
		}
	}


};

int main(int argc, char const *argv[])
{
	Lista_encadeada le;
	le.Append(2);
	le.Append(3);
	le.Append(6);
	le.Inserir(2,45);
	le.ToString();
	cout<<le.Count(3)<<endl;
	
	return 0;
}
