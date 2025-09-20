// 277. Find the Celebrity
public class FindCelebrity {
  public int findCelebrity(int[][] persons) {
    int N = persons.length;
    int possibleCeleb = 0;

    for (int i = 1; i < N; ++i) {
      if (persons[possibleCeleb][i] == 1) {
        // possibleCeleb knows i → possibleCeleb cannot be celeb
        possibleCeleb = i;
      }
      // else i cannot be celeb, do nothing
    }
    
    for(int j=0; j<N; ++j){
      if(j==possibleCeleb) continue;
      if(persons[possibleCeleb][j]==1 || persons[j][possibleCeleb]==0) return -1;
    }
    return possibleCeleb;
  }

  public static void main(String[] args) {
    int[][] persons = {{1, 1, 1}, {0, 1, 0}, {1, 1, 1}};
    FindCelebrity fc = new FindCelebrity();
    System.out.println(fc.findCelebrity(persons));
  }
}
