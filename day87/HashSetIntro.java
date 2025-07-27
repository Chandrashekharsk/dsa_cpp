// 705. Design HashSet

import java.util.LinkedList;


class MyHashSet {
  class Bucket {
    private LinkedList<Integer> container;

    public Bucket() {
      this.container = new LinkedList<Integer>();
    }

    public void insert(int key) {
      if (!this.container.contains(key)) {
        this.container.addFirst(key);
      }
    }

    public void remove(int key) {
      if (this.container.contains(key)) {
        this.container.remove(Integer.valueOf(key));
      }
    }

    public boolean contains(int key) {
      return this.container.contains(key);
    }
  }

  int numBuckets = 769;
  Bucket[] buckets;

  public MyHashSet(){
    this.buckets = new Bucket[numBuckets];
    for(int i=0; i<numBuckets; ++i){
        buckets[i] = new Bucket();
    }
}

  private Integer getIndex(int key) {
    return key % numBuckets;
  }

  public void add(int key) {
    int index = getIndex(key);
    if (!buckets[index].contains(key)) {
      buckets[index].insert(key);
    }
  }

  public void remove(int key) {
    int index = getIndex(key);
    if (buckets[index].contains(key)) {
      buckets[index].remove(key);
    }
  }

  public boolean contains(int key) {
    return this.buckets[getIndex(key)].contains(key);
  }
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * boolean param_3 = obj.contains(key);
 */