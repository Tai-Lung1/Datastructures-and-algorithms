package canthishappen;

public class maybe {
    int array[] = {1,2,3,4,5,6,7,8,9,10}; // Moved array to class level

    public int hey(){
        return 1;
    }

    public int hey1(){
        System.out.println(array[1]);
        return 1;
    }

    public static void main(String[] args){
        maybe m = new maybe();
        int r = m.hey();
        int s = m.hey1();
    }
}
        int hey1(){
            System.out.println(array[1]);
            return 1;
        }
        int r = hey();
    }
}
