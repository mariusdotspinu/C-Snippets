#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct si_number{
	int number;
	char mark;
};

typedef struct si_number si;

void enumerate_Multiples(int p, si* m_List, int n){
	int i, j, k = 2;

	for(j = 0 ; j < n - 1; j++){
		for(i = 0; i < n - 1; i++){
			if(m_List[i].number == k * p){

			/*mark them*/
			m_List[i].mark = '1';
		}
		
	}

	k++;
}

}

void remove_Marked_Numbers(si *m_List, int *n){
	int i;
	for (i = 0 ; i < *n - 1; i++){
		if(m_List[i].mark == '1'){
			memmove(m_List + i, m_List + i + 1, (*n - i - 1) *sizeof(*m_List));
			(*n)--;
			i--;
			realloc(m_List, *n *sizeof(*m_List));
		}
	}

}

void sieve(int n){

	si* m_List = malloc(sizeof(si) * (n - 1));
	int i, p = 2;

	for(i = 2 ; i <= n ; i++){
		m_List[i - 2].number = i;
		m_List[i - 2].mark = '0';
	}

	for(i = 0 ; i < n - 1; i++){
		if(m_List[i].number > p && m_List[i].mark == '0'){
			enumerate_Multiples(p, m_List, n);
			p = m_List[i].number;
		}
	}

	remove_Marked_Numbers(m_List, &n);

	for(i = 0 ; i < n - 1 ; i++){
		printf("%d ", m_List[i].number);
	}

	free(m_List);
}

int main(int argc, char *argv[]){
	sieve(atoi(argv[1]));
	return 0;
}