
#include <tuple>
#include "Iterador.h"

class administraTuplas{
    
private:
    ListaDoble* li;
    ListaSimple* li2;
    
    
public:
    administraTuplas(ListaDoble* _li){
        li=_li;
        li2=NULL;
    }
    
    administraTuplas(ListaSimple* _li){
        li2=_li;
        li=NULL;
    }
    
    void add(tuple e){
        if (!li2) {
            Iterador* it=new Iterador(li);
            while (it->hasNext()) {
                it->next();
            }
            
            
            li->addFinal(e);
        }
        else{
            li2->addFinal(e);
        }
        
    }
    
    void remove(int pos){
        if (!li2) {
            li->remove(pos);
        }
        else{
            li2->remove(pos);
        }
        
        
    }
    
    void toString(){
        
    }
	
	/*
	 * sorts arr[] of size n using Radix Sort
	 */
    void Sort(){
        //radix sort
        
        if(!li2){ //trabajando con lista doble enlazada circular
            
            int tamTupla=tuple_size<decltype(li->get(0))>::value;
            
			int m = getMax(arr, n);
			for (int exp = 1; m / exp > 0; exp *= 10)
				countSort(arr, n, exp);
            
            
            
        }
        
        
        
    }
	
	int getMax(int arr[], int n)
	{
		
		
		Iterador<tuple> it=new Iterador<tuple>(l);
		int max = get<0>(it->next());
		while(it->hasNext()){
			it->next();
			if(get<0>(it->next())>max)
				max= get<0>(it->next());
		}
		return max;
	}
	/*
	 * count sort of arr[]
	 */
	void countSort(int arr[], int n, int exp)
	{
		int output[n];
		int i, count[10] = {0};
		for (i = 0; i < n; i++)
			count[(arr[i] / exp) % 10]++;
		for (i = 1; i < 10; i++)
			count[i] += count[i - 1];
		for (i = n - 1; i >= 0; i--)
		{
			output[count[(arr[i] / exp) % 10] - 1] = arr[i];
			count[(arr[i] / exp) % 10]--;
		}
		for (i = 0; i < n; i++)
			arr[i] = output[i];
	}
	
	
	
	
};

















