// 706. Design HashMap
import java.util.LinkedList;
import java.util.List;

public class MyHashMap {
    class Pair<K,V>{
        K first;
        V second;
        public Pair(K key, V value) {
            this.first = key;
            this.second = value;
        }
    }

    class Bucket{
        List<Pair<Integer, Integer>> container;
        public Bucket() {
            this.container = new LinkedList<Pair<Integer,Integer>>();
        }

        public void put(int key, int val){
            for(Pair<Integer, Integer> pair : this.container) {
                if (pair.first.equals(key)) {
                    pair.second = val; // Update value if key exists
                    return;
                }
            }
            this.container.add(new Pair<Integer,Integer>(key,val));
        }

        public Integer get(int key){
            for(Pair<Integer, Integer> pair : this.container) {
                if (pair.first.equals(key)) {
                    return pair.second; // Return value if key exists
                }
            }
            return -1; // Return null if key does not exist
        }
        public void remove(int key){
            for(Pair<Integer, Integer> p : this.container) {
                if (p.first.equals(key)) {
                    this.container.remove(p); // Return value if key exists
                    return;
                }
            }
        }
    }
    int numBuckets = 769;
    Bucket[] buckets;
    public MyHashMap(){
        this.buckets = new Bucket[numBuckets];
        for(int i=0; i<numBuckets; ++i){
            buckets[i] = new Bucket();
        }
    }

    private Integer getIndex(int key) {
        return key % numBuckets;
    }
    public void put(int key, int val) {
        int index = getIndex(key);
        buckets[index].put(key, val);
    }
    public void remove(int key) {
        int index = getIndex(key);
        buckets[index].remove(key);
    }
    public Integer get(int key) {
        int index = getIndex(key);
        return buckets[index].get(key);
    }
    public boolean containsKey(int key) {
        return buckets[getIndex(key)].get(key) != null;
    }

    public static void main(String[] args) {
        MyHashMap myHashMap = new MyHashMap();
        myHashMap.put(1, 1); // Insert key-value pair (1, 1)
        myHashMap.put(2, 2); // Insert key-value pair (2, 2)
        System.out.println(myHashMap.get(1)); // Returns 1
        System.out.println(myHashMap.get(3)); // Returns null (not found)
        myHashMap.put(2, 3); // Update key 2 with value 3
        System.out.println(myHashMap.get(2)); // Returns 3
        myHashMap.remove(2); // Remove key 2
        System.out.println(myHashMap.get(2)); // Returns null (not found)
    }
}