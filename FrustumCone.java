import java.util.Scanner;
public class FrustumCone {
    private double radiusBottom;
    private double radiusTop;
    private double height;

    public FrustumCone(double radiusBottom, double radiusTop, double height) {
        this.radiusBottom = radiusBottom < 0 ? 0 : radiusBottom;
        this.radiusTop = radiusTop < 0 ? 0 : radiusTop;
        this.height = height < 0 ? 0 : height;
    }

    public FrustumCone() {
        this(0, 0, 0);
    }

    public double getHeight() {
        return height;
    }
    public double getRadiusBottom() {
        return radiusBottom;
    }
    public double getRadiusTop() {
        return radiusTop;
    }
    public void setHeight(double height) {
        this.height = height;
    }
    public void setRadiusBottom(double radiusBottom) {
        this.radiusBottom = radiusBottom;
    }
    public void setRadiusTop(double radiusTop) {
        this.radiusTop = radiusTop;
    }  
    
    public double getVolume() {
        //System.err.println(Math.PI * height * (radiusBottom * radiusBottom + radiusTop * radiusTop + radiusBottom * radiusTop) / 3);
        return Math.PI * height * (radiusBottom * radiusBottom + radiusTop * radiusTop + radiusTop * height) / 3;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        double radiusBottom = input.nextDouble();
        double radiusTop = input.nextDouble();
        double height = input.nextDouble();
        FrustumCone frustumCone = new FrustumCone(radiusBottom, radiusTop, height);
        // System.err.println(frustumCone.getRadiusBottom());
        // System.err.println(frustumCone.getRadiusTop());
        // System.err.println(frustumCone.getHeight());
        System.out.printf("%.2f", frustumCone.getVolume());
    }
}
