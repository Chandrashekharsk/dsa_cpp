// 1899. Merge Triplets to Form Target Triplet

public class MergTriplets{
  public boolean mergeTriplets(int[][] triplets, int[] target) {
    int[] maxTrips = new int[3];
    for(int[] t: triplets){
      if(t[0]<= target[0] && t[1]<=target[1] && t[2]<=target[2]){
        maxTrips[0] = Math.max(t[0], maxTrips[0]);
        maxTrips[1] = Math.max(t[1], maxTrips[1]);
        maxTrips[2] = Math.max(t[2], maxTrips[2]);
      }
    }
    for(int i=0; i<3; ++i){
      if(maxTrips[i] != target[i]) return false;
    }
    return true;
  }

  public static void main(String[] args) {
    int[][] triplets = {
      {2,5,3}, {1, 8, 4}, {1,7,5}
    };
    int[] target = {2,7,5};

    MergTriplets mt = new MergTriplets();
    System.out.println(mt.mergeTriplets(triplets, target));
  }
}