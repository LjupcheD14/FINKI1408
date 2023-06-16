// Implement a hash map data structure using an array and a hash function. Include methods to insert, delete, and search for key-value pairs.

public class HashMap<K, V> {
    private static final int INITIAL_CAPACITY = 16;
    private Entry<K, V>[] buckets;
    private int size;

    public HashMap() {
        this(INITIAL_CAPACITY);
    }

    public HashMap(int capacity) {
        this.buckets = new Entry[capacity];
        this.size = 0;
    }

    public void put(K key, V value) {
        int index = getBucketIndex(key);
        Entry<K, V> entry = buckets[index];
        while (entry != null) {
            if (entry.key.equals(key)) {
                entry.value = value;
                return;
            }
            entry = entry.next;
        }
        entry = buckets[index];
        Entry<K, V> newEntry = new Entry<>(key, value);
        newEntry.next = entry;
        buckets[index] = newEntry;
        size++;
    }

    public V get(K key) {
        int index = getBucketIndex(key);
        Entry<K, V> entry = buckets[index];
        while (entry != null) {
            if (entry.key.equals(key)) {
                return entry.value;
            }
            entry = entry.next;
        }
        return null;
    }

    public void remove(K key) {
        int index = getBucketIndex(key);
        Entry<K, V> entry = buckets[index];
        Entry<K, V> prev = null;
        while (entry != null) {
            if (entry.key.equals(key)) {
                if (prev == null) {
                    buckets[index] = entry.next;
                } else {
                    prev.next = entry.next;
                }
                size--;
                return;
            }
            prev = entry;
            entry = entry.next;
        }
    }

    public boolean containsKey(K key) {
        int index = getBucketIndex(key);
        Entry<K, V> entry = buckets[index];
        while (entry != null) {
            if (entry.key.equals(key)) {
                return true;
            }
            entry = entry.next;
        }
        return false;
    }

    public int size() {
        return size;
    }

    private int getBucketIndex(K key) {
        int hashCode = key.hashCode();
        return Math.abs(hashCode) % buckets.length;
    }

    private static class Entry<K, V> {
        private K key;
        private V value;
        private Entry<K, V> next;

        public Entry(K key, V value) {
            this.key = key;
            this.value = value;
            this.next = null;
        }
    }

    public static void main(String[] args) {
        HashMap<String, Integer> map = new HashMap<>();
        map.put("apple", 5);
        map.put("banana", 10);
        map.put("cherry", 15);
        System.out.println("Size: " + map.size());  // Output: 3

        System.out.println("Value for key 'apple': " + map.get("apple"));  // Output: 5
        System.out.println("Value for key 'banana': " + map.get("banana"));  // Output: 10
        System.out.println("Value for key 'cherry': " + map.get("cherry"));  // Output: 15

        map.remove("banana");
        System.out.println("Size after removing 'banana': " + map.size());  // Output: 2
        System.out.println("Contains key 'banana'? " + map.containsKey("banana"));  // Output: false
    }
}
