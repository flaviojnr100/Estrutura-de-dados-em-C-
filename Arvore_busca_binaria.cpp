#include<iostream>
using namespace std;

class No{

private:
	int chave;
	No* direita;
	No* esquerda;
	No* pai;
public:
	No(int chave){
		this->chave = chave;
		this->direita = NULL;
		this->esquerda = NULL;
		this->pai = NULL;
	}
	int getChave(){
		return chave;
	}

	

	No* getDireita(){
		return direita;
	}

	void setDireita(No* dir){
		direita = dir;
	}

	No* getEsquerda(){
		return esquerda;
	}

	void setEsquerda(No* esq){
		esquerda = esq;
	}

	No* getPai(){
		return pai;
	}

	void setPai(No* pa){
		pai = pa;
	}

};

class Arvore_binaria{

private:
	No* raiz;

public:
	Arvore_binaria(){
		this->raiz = NULL;
	}
	No* getRaiz(){
		return raiz;
	}
	void Inserir(int valor){
		No* novo = new No(valor);
		No* ant_pai = NULL;
		No* atual = raiz;
		while(atual!=NULL){
			ant_pai = atual;
			if(novo->getChave() > atual->getChave()){
				atual = atual->getDireita();
			}else{
				atual = atual->getEsquerda();
			}

		}
		novo->setPai(ant_pai);
		if (raiz==NULL){
			raiz = novo;

		}else if(novo->getChave() > ant_pai->getChave()){
			ant_pai->setDireita(novo);
		}else{
			ant_pai->setEsquerda(novo);
		}
	}

	No* Busca(No* inicio,int elemento){
		if(inicio!=NULL){
			if (inicio->getChave() == elemento)
			{
				return inicio;
			}else if(elemento > inicio->getChave()){
				Busca(inicio->getDireita(),elemento);
			}else if(elemento < inicio->getChave()){
				Busca(inicio->getEsquerda(),elemento);
			}
		}else{
			return NULL;
		}
	}


	void PreOrdem(No* raiz){
		if(raiz!=NULL){
			cout<<raiz->getChave()<<endl;
			PreOrdem(raiz->getEsquerda());
			PreOrdem(raiz->getDireita());
		}
	}

	void Ordem(No* raiz){
		if(raiz!=NULL){
			Ordem(raiz->getEsquerda());
			cout<<raiz->getChave()<<endl;
			Ordem(raiz->getDireita());
		}
	}
	void PosOrdem(No* raiz){
		if(raiz!=NULL){
			PosOrdem(raiz->getEsquerda());
			PosOrdem(raiz->getDireita());
			cout<<raiz->getChave()<<endl;
		}
	}

};

int main(){
	Arvore_binaria arv;
	arv.Inserir(8);
	arv.Inserir(3);
	arv.Inserir(10);
	arv.Inserir(14);
	arv.Inserir(6);
	arv.Inserir(4);
	arv.Inserir(13);
	arv.Inserir(7);
	arv.Inserir(1);
	arv.Ordem(arv.getRaiz());
	return 0;
}
