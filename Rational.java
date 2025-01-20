import java.util.*;
import java.lang.*;
public class Rational extends java.lang.Number implements Comparable<Rational>{
    private long numerator;
    private long denominator;
    public Rational(){
        this(0, 1);
    }
    public Rational(long numerator, long denominator) throws IllegalArgumentException{
        if(denominator == 0) {
            throw new IllegalArgumentException("分母不能为0");
        }
        long gcd = gcd(numerator, denominator);
        this.numerator = ((denominator > 0) ? 1 : -1) * numerator / gcd;
        this.denominator = Math.abs(denominator) / gcd;
    }
    private static long gcd(long n, long d){
        long n1 = Math.abs(n);
        long n2 = Math.abs(d);
        int gcd = 1;
        for (int k = 1; k <= n1 && k <= n2; k++){
            if (n1 % k == 0 && n2 % k == 0){
                gcd = k;
            }
        }
        return gcd;
    }
    public long getNumerator(){
        return numerator;
    }
    public long getDenominator(){
        return denominator;
    }
    public Rational add(Rational secondRational){
        long n = numerator * secondRational.getDenominator() + denominator * secondRational.getNumerator();
        long d = denominator * secondRational.getDenominator();
        return new Rational(n, d);
    }
    public Rational subtract(Rational secondRational){
        long n = numerator * secondRational.getDenominator() - denominator * secondRational.getNumerator();
        long d = denominator * secondRational.getDenominator();
        return new Rational(n, d);
    }
    public Rational multiply(Rational secondRational){
        long n = numerator * secondRational.getNumerator();
        long d = denominator * secondRational.getDenominator();
        return new Rational(n, d);
    }
    public Rational divide(Rational secondRational){
        long n = numerator * secondRational.getDenominator();
        long d = denominator * secondRational.numerator;
        return new Rational(n, d);
    }
    @Override
    public String toString(){
        return (denominator == 1) ? numerator + "" : numerator + "/" + denominator;
    }
    @Override
    public boolean equals(Object other){
        if ((this.subtract((Rational)(other))).getNumerator() == 0){
            return true;
        } else {
            return false;
        }
    }
    @Override
    public int intValue(){
        return (int)doubleValue();
    }

    @Override
    public float floatValue(){
        return (float)doubleValue();
    }

    @Override
    public double doubleValue(){
        return numerator * 1.0 / denominator;
    }

    @Override
    public long longValue(){
        return (long)doubleValue();
    }

    @Override
    public int compareTo(Rational o){
        if (this.subtract(o).getNumerator() > 0){
            return 1;
        } 
        else if (this.subtract(o).getNumerator() < 0){
            return -1;
        } 
        else {
            return 0;
        }
    }

    @Override
    public int hashCode(){
        return (int)(numerator * denominator);
    }

    // public static void main(String[] args) {
    //     Scanner input = new Scanner(System.in);
    //     long numerator1 = input.nextLong();
    //     long denominator1 = input.nextLong();
    //     long numerator2 = input.nextLong();
    //     long denominator2 = input.nextLong();
    //     try{
    //         Rational r1 = new Rational(numerator1, denominator1);
    //         Rational r2 = new Rational(numerator2, denominator2);
    //         char operator = input.next().charAt(0);
    //         switch (operator){
    //             case '+':
    //                 System.out.println(r1.add(r2));
    //                 break;
    //             case '-':
    //                 System.out.println(r1.subtract(r2));
    //                 break;
    //             case '*':
    //                 System.out.println(r1.multiply(r2));
    //                 break;
    //             case '/':
    //                 try{
    //                     System.out.println(r1.divide(r2));
    //                 } 
    //                 catch (IllegalArgumentException e){
    //                     System.out.println("NaN");
    //                 }
    //                 break;
    //         }
    //     } 
    //     catch (IllegalArgumentException e){
    //         System.out.println("NaN");
    //         return;
    //     }

    // }
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Set<Rational> set = new TreeSet<>();
        try{
            String[] line = input.nextLine().split(" ");
            // System.out.println(line);
            // for(int i = 0; i < line.length; i += 2){
            //     System.out.println(line[i]);
            //     System.out.println(line[i + 1]);
            // }
            for(int i = 0; i < line.length; i += 2){
                int n = Integer.parseInt(line[i]);
                int d = Integer.parseInt(line[i + 1]);
                Rational r = new Rational(n, d);
                set.add(r);              
            }
            double s = 1.0;
            for(Rational r : set){
                s *= r.doubleValue();
                System.out.printf("%s ", r.toString());
            }
            System.out.printf("%.3f", s);
        }
        catch (IllegalArgumentException e){
            System.out.println("NaN");
            return;
        }
    }
    
}
 