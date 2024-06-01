class Kompleks {
    private static int n_kompleks = 0;
    private int real;
    private int imaginer;

    public Kompleks(){
        this.real = 0;
        this.imaginer = 0;
        n_kompleks++;
    }

    public Kompleks(int real, int imaginer){
        this.real = real;
        this.imaginer = imaginer;
        n_kompleks++;
    }

    public int getReal(){
        return this.real;
    }

    public int getImaginer(){
        return this.imaginer;
    }

    public void setReal(int real){
        this.real = real;
    }

    public void setImaginer(int imaginer){
        this.imaginer = imaginer;
    }

    public Kompleks plus(Kompleks b){
        Kompleks c = new Kompleks();
        c.imaginer = this.imaginer + b.imaginer;
        c.real = this.real + b.real;
        return c;
    }

    public Kompleks minus(Kompleks b){
        Kompleks c = new Kompleks();
        c.imaginer = this.imaginer - b.imaginer;
        c.real = this.real - b.real;

        return c;
    }

    public Kompleks multiply(Kompleks b){
        Kompleks c = new Kompleks();
        c.real = (this.real * b.real) - (this.imaginer * b.imaginer);
        c.imaginer = (this.imaginer * b.real) + (this.real * b.imaginer);
        
        return c;
    }
    
    public Kompleks multiply(int a){
        Kompleks c = new Kompleks();
        c.real =  this.real * a;
        c.imaginer = this.imaginer * a;

        return c;
    }

    public static int countKompleksInstance(){
        return n_kompleks;
    }

    public void print(){
        if (this.real != 0 || this.imaginer == 0) {
            System.out.print(this.real);
        }
        if (this.real != 0 && this.imaginer > 0) {
            System.out.print("+");
        }
        if (this.imaginer != 0) {
            if (this.imaginer == 1) {
                System.out.println("i");
            } else if (this.imaginer == -1) {
                System.out.println("-i");
            } else {
                System.out.println(this.imaginer + "i");
            }
        } else {
            System.out.println();
        }
    }
}