// 853. Car Fleet
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class CarFleet{
  public static int carFleet(int target, int[] position, int[] speed) {
    double[][] cars = new double[position.length][2];
    for(int i=0; i<position.length; ++i){
      cars[i][0] = position[i];
      cars[i][1] = (double) (target-position[i])/speed[i];
    }

    Arrays.sort(cars, (a, b)-> Double.compare(b[0], a[0]));
    int fleetCnt = 0; double prevCarReachingTime = 0;

    for(double[] car: cars){
      if(car[1]>prevCarReachingTime){
        prevCarReachingTime = car[1];
        ++fleetCnt;
      }
    }
    return fleetCnt;
  }
  public static void main(String[] args) {
    int[] position = {10,8,0,5,3};
    int[] speed = {2,4,1,1,3};
    System.out.println(carFleet(12, position, speed));
  }
}