// 134. Gas Station

public class GasStation {
  public int canCompleteCircuit(int[] gas, int[] cost) {
    int totalGas = 0, totalCost = 0, currTank = 0, startIndex = 0;
    for(int i= 0; i< gas.length; ++i){
      totalCost+= cost[i];
      totalGas+= gas[i];

      currTank += gas[i]-cost[i];
      if(currTank<0){
        startIndex = i+1;
        currTank = 0;
      }
    }
    return totalGas<totalCost?  -1: startIndex;
  }
  public static void main(String[] args) {
    int[] gas = {1,2,3,4,5}, cost = {3,4,5,1,2};
    GasStation gs = new GasStation();
    System.out.println(gs.canCompleteCircuit(gas, cost));
  }
}
