public class MinHeap {
  private int[] heap;
  private int size;
  private int capacity;

  public MinHeap(int capacity) {
    this.capacity = capacity;
    heap = new int[capacity];
    this.size = 0;
  }

  // helper methods
  private int parent(int i) { return (i - 1) / 2; }
  private int leftChild(int i) { return 2 * i + 1; }
  private int rightChild(int i) { return 2 * i + 2; }

  public void insert(int element) {
    if (size == capacity)
      throw new IllegalStateException("Heap is full");

    heap[size] = element;
    int curr = size++;
    while (curr > 0 && heap[curr] < heap[parent(curr)]) {
      swap(curr, parent(curr));
      curr = parent(curr);
    }
  }

  public int removeMin() {
    if (size == 0)
      throw new IllegalStateException("Heap is empty");
    int min = heap[0];
    heap[0] = heap[--size];
    heapify(0);
    return min;
  }

  private void heapify(int i) {
    int left = leftChild(i), right = rightChild(i), smallest = i;

    if (left < size && heap[left] < heap[smallest])
      smallest = left;
    if (right < size && heap[right] < heap[smallest])
      smallest = right;

    if (smallest != i) {
      swap(i, smallest);
      heapify(smallest);
    }
  }

  private void swap(int a, int b) {
    int temp = heap[a];
    heap[a] = heap[b];
    heap[b] = temp;
  }
}
