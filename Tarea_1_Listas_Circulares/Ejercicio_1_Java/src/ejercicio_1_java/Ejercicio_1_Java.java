
package ejercicio_1_java;



public class Ejercicio_1_Java {

    public static void main(String[] args) {
        
        /*Lista_Circular_Doble<String> a=new Lista_Circular_Doble<>();
        a.addInicio("a");
        a.add(1, "b");
        a.addFinal("2");
        a.add(0, "0");
        a.add(4, "4");
        */
        
        Lista_Circular<Integer> a=new Lista_Circular<>();
        a.addFinal(4);
        a.add(0, 1);
        a.add(0, 0);
        a.add(2, 2);
        a.add(3, 3);
        a.addFinal(5);
        Lista_Circular<Integer> li2=a.clone();
        //System.out.println(li2.indexOf(2));
        
        a.to_String();
    }
    
}
